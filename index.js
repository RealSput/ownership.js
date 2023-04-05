const addon = require('./build/Release/addon.node');

let arr = addon.createOwner(1n);
console.log(typeof arr); // should return 'object'

let value = addon.getValue(arr, 0); // pass the external object as argument
console.log(value); // should return 1n
