const path = require('path');

const express = require('express');

const Router = express.Router();

Router.get('/users', (req, res) => {
    res.sendFile(path.join(__dirname, "../", "views", "user.html"));
});

module.exports = Router;