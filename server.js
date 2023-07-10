const express = require('express');
const status = require('./routes/status');
const power = require('./routes/power');

const app = express();
app.set('view engine', 'ejs');
app.use(express.static('static'));

app.get('/', (_, res) => {
  let services = require('./services.json');
  
  services.forEach(service => {
    service.status = status.service(service.name);
  });

  res.render('index', { uptime: status.uptime(), services: services });
});

const powerRouter = power.router;
app.use('/power', powerRouter);

const statusRouter = status.router;
app.use('/status', statusRouter);

app.listen(3000);
