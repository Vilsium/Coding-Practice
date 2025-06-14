const Product = require("../models/product");

exports.getAddProducts = (req, res, next) => {
  res.render("add-product", {
    pageTitle: "Add Product",
    path: "/add-products",
  });
};

exports.postAddProducts = (req, res, next) => {
  const product = new Product(req.body.title);
  product.save();
  res.redirect("/");
};

exports.getProducts = (req, res, next) => {
  const products = Product.fetchAllProducts();
  res.render("shop", { products: products, pageTitle: "Shop", path: "/" });
};
