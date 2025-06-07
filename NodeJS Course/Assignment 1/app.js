const http = require("http");

const server = http.createServer((req, res) => {
    const url = req.url;
    if(url === '/') {
        res.setHeader("Context-Type", "text.html");
        res.write("<html>");
        res.write("<head><title> Assignment 1 </title></head>");
        res.write("<body>");
        res.write("<h1> Hello, I am Vyom Singhal and I am solving Assignment 1! </h1>");
        res.write('<form action="/create-users" method="POST">');
        res.write("<label> Username: </label>");
        res.write('<input type="text" name="username"><br>');
        res.write('<button type="submit">SEND</button>')
        res.write("</form>");
        res.write("</body>");
        res.write("</html>");
        return res.end();
    }
    if(url === '/users') {
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
});

server.listen(3000);