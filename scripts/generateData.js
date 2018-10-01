let min = -10000;
let max = 10000;
let sizeOfVector = 1000000;

let random = function (min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

let x = random(min, max);
let a = [];
let b = [];
let results = [];

let output = "";

for (let i = 0; i < sizeOfVector; i++) {
  a[i] = random(min, max);
  b[i] = random(min, max);
  results[i] = (a[i] * x) + b[i];
}

// console.log("x: " + x);
// console.log("a: " + a);
// console.log("b: " + b);
// console.log("results: " + results);

output += sizeOfVector + " ";

for (let i = 0; i < sizeOfVector; i++) {
  output += a[i] + " ";
}

for (let i = 0; i < sizeOfVector; i++) {
  output += b[i] + " ";
}

// for (let i = 0; i < sizeOfVector; i++) {
//   output += results[i] + " ";
// }

console.log(output);

