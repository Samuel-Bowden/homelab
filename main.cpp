#include "crow.h"

std::string uptime() {
  auto seconds = 0;
  std::ifstream("/proc/uptime", std::ios::in) >> seconds;

  int hours, minutes;
  minutes = seconds / 60;
  hours = minutes / 60;
  std::stringstream ss;

  ss << "Uptime: " << int(hours) << " hours " << int(minutes%60) << " minutes";
  return ss.str();
}

int main() {
  crow::SimpleApp app;

  CROW_ROUTE(app, "/")([](){
    auto page = crow::mustache::load("home.html");
    crow::mustache::context ctx ({{"uptime", uptime()}});
    return page.render(ctx);
  });

  CROW_ROUTE(app, "/uptime")([](){
    return uptime();
  });

  app.port(8080)
    .multithreaded()
    .run();
}
