const http = require("http");

const server = http.createServer((req, res) => {
  const url = req.url;
  const method = req.method;
  if (url === "/") {
    res.setHeader("Context-Type", "text.html");
    res.write("<html>");
    res.write("<head><title> Assignment 1 </title></head>");
    res.write("<body>");
    res.write(
      "<h1> Hello, I am Vyom Singhal and I am solving Assignment 1! </h1>"
    );
    res.write('<form action="/create-user" method="POST">');
    res.write("<label> Username: </label>");
    res.write('<input type="text" name="username"><br>');
    res.write('<button type="submit">SEND</button>');
    res.write("</form>");
    res.write("</body>");
    res.write("</html>");
    return res.end();
  }
  if (url === "/users") {
    res.setHeader("Context-Type", "text.html");
    res.write("<html>");
    res.write("<head><title> Assignment 1 </title></head>");
    res.write("<body>");
    res.write("<h1> List of users </h1>");
    res.write("<ul>");
    res.write("<li> User 1 </l1>");
    res.write("<li> User 2 </l1>");
    res.write("<li> User 3 </l1>");
    res.write("</ul>");
    res.write("</body>");
    res.write("</html>");
    return res.end();
  }
  if (url === "/create-user" && method === "POST") {
    const body = []; //to store the data received
    req.on("data", (chunk) => {
      body.push(chunk);
    });
    req.on("end", () => {
      const parsedBody = Buffer.concat(body).toString();
      const username = parsedBody.split("=")[1];
      console.log("Username received: " + username);
    });
    // Redirecting to '/'
    res.statusCode = 302; //Status code for redirecting
    res.setHeader("Location", "/");
    res.end();
  }
});

server.listen(3000);
