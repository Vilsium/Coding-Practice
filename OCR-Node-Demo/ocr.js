const path = require('path');

const Tesseract = require('tesseract.js');

const imagePath = path.join(__dirname, 'img.png');

Tesseract.recognize(imagePath, 'eng', { logger: m => console.log(m) }).then(({ data : { text } }) => {
    console.log("Extracted text: \n");
    console.log(text);
}).catch((err) => {
    console.error(err);
});