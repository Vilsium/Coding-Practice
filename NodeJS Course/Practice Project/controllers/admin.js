const Product = require("../models/product");

exports.getAddProducts = (req, res, next) => {
  res.render("admin/add-product", {
    pageTitle: "Add Product",
    path: "/add-products",
  });
};

exports.postAddProducts = (req, res, next) => {
  const title = req.body.title;
  const imageURL = req.body.imageURL;
  const price = req.body.price;
  const description = req.body.description;
  const product = new Product(title, imageURL, description, price);
  product.save();
  res.redirect("/");
};

exports.getProducts = (req, res, next) => {
  Product.fetchAllProducts((products) => {
    res.render("admin/product-list", {
      products: products,
      pageTitle: "Admin Products",
      path: "/admin/products",
    });
  });
};
