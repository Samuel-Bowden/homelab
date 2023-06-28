setInterval(async () => {
  const response = await fetch("uptime");
  const uptime = await response.text();
  document.getElementById('uptime').innerHTML = uptime;
}, 60000);
