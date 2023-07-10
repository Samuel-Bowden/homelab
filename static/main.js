setInterval(async () => {
  const response = await fetch("status/uptime");
  const uptime = await response.text();
  document.getElementById('uptime').innerHTML = "Uptime: " + uptime;
}, 60000);

function suspend() {
  fetch("power/suspend", { method: 'POST' });
}
