const path = require('path');

const express = require('express');

const app = express();

const rootRoute = require('./routes/root');
const userRoute = require('./routes/user');

app.use(userRoute);
app.use(rootRoute);

app.listen(3000);