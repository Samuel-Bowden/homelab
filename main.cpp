#include "crow.h"
#include <format>
#include <cstdlib>
#include <vector>

using namespace std;

string uptime() {
  auto seconds = 0;
  ifstream("/proc/uptime", ios::in) >> seconds;

  int hours, minutes;
  minutes = seconds / 60;
  hours = minutes / 60;
  stringstream ss;

  ss << "Uptime: " << int(hours) << " hours " << int(minutes%60) << " minutes";
  return ss.str();
}

string service_status(string name) {
  if (system(format("systemctl is-active --quiet {}", name).c_str()))
    return "Inactive";
  else
    return "Running";
}

vector<crow::json::wvalue> services() {
  vector<crow::json::wvalue> services;

  crow::json::wvalue git;
  git["url_name"] = "git";
  git["name"] = "Git";
  git["status"] = service_status("gitea");
  services.push_back(git);

  crow::json::wvalue invidious;
  invidious["url_name"] = "invidious";
  invidious["name"] = "Invidious";
  invidious["status"] = service_status("invidious");
  services.push_back(invidious);

  crow::json::wvalue search;
  search["url_name"] = "search";
  search["name"] = "Search";
  search["status"] = service_status("searxng");
  services.push_back(search);

  crow::json::wvalue music;
  music["url_name"] = "music";
  music["name"] = "Music";
  music["status"] = service_status("beatbump");
  services.push_back(music);

  return services;
}

int main() {
  crow::SimpleApp app;

  CROW_ROUTE(app, "/")([](){
    auto page = crow::mustache::load("home.html");
    crow::mustache::context ctx ({{"uptime", uptime()}, {"services", services()}});
    return page.render(ctx);
  });

  CROW_ROUTE(app, "/uptime")([](){
    return uptime();
  });

  CROW_ROUTE(app, "/service_status")([](const crow::request& req){
    auto name = req.url_params.get("name");
    if (name != nullptr)
      return crow::response(service_status(name));
    else {
      return crow::response(400);
    }
  });

  app.port(8080)
    .multithreaded()
    .run();
}
