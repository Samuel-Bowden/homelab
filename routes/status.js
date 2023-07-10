const express = require('express');
const router = express.Router();
const { execSync } = require('node:child_process');

function uptime() {
  let seconds = require('os').uptime();

  let hours = Math.floor(seconds / (60*60));
  let minutes = Math.floor(seconds % (60*60) / 60);

  return hours + " hours " + minutes + " minutes";
}

function service(name) {
  try {
    execSync('systemctl is-active --quiet ' + name);
    return "Running";
  } catch (_) {
    return "Inactive";
  }
}

router.get('/uptime', (_, res) => {
  res.send(uptime());
});

router.get('/service', (_, res) => {
  res.send(service(req.query.name));
});

module.exports = { router, uptime, service }
