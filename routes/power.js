const express = require('express');
const router = express.Router();
const { execSync } = require('node:child_process');

router.post('/suspend', () => {
  execSync('systemctl suspend');
});

module.exports = { router }
