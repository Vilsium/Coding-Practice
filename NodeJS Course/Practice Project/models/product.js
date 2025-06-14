const fs = require("fs");
const path = require("path");

const pathToFile = path.join(
  path.dirname(process.mainModule.filename),
  "data",
  "products.json"
);

const getProductsFromFile = (cb) => {
  fs.readFile(pathToFile, (err, fileContent) => {
    if (err) return cb([]);
    cb(JSON.parse(fileContent));
  });
};

module.exports = class Product {
  constructor(title) {
    this.title = title;
  }

  save() {
    getProductsFromFile((products) => {
      products.push(this);
      fs.writeFile(pathToFile, JSON.stringify(products), (err) => {
        console.error(err);
      });
    });
  }

  static fetchAllProducts(cb) {
    getProductsFromFile(cb);
  }
};
