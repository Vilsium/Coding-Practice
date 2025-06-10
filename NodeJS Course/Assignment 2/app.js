const express = require("express");
const app = express();

// app.use((req, res, next) => {
//   console.log("Middleware no. 1");
//   next();
// });

// app.use((req, res, next) => {
//   console.log("Middleware no. 2");
//   res.send("<h1>Assignment 2 - task 2</h1>");
// });

app.use("/users", (req, res, next) => {
  res.send("<h1>Welcome to the users page of Assignment 2</h1>");
});

app.use("/", (req, res, next) => {
  res.send("<h1>Welcome to the root page of Assignment 2</h1>");
});

app.listen(3000);
