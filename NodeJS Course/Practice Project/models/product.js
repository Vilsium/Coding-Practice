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
  constructor(title, imageURL, description, price) {
    this.title = title;
    this.imageURL = imageURL;
    this.description = description;
    this.price = price;
  }

  save() {
    this.id = Math.random().toString();
    getProductsFromFile((products) => {
      products.push(this);
      fs.writeFile(pathToFile, JSON.stringify(products), (err) => {
        console.error(err);
      });
    });
  }

  static findById(productId, cb) {
    getProductsFromFile((products) => {
      const product = products.find((prod) => {
        return prod.id === productId;
      });
      cb(product);
    });
  }

  static fetchAllProducts(cb) {
    getProductsFromFile(cb);
  }
};
