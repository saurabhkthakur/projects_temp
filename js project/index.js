/*
1. ways to print in javascript
console.log('Hello world');
alert('me');
document.write('this is document write');

2. console API
console.log('HELLO WORLD');
console.warn('This is warning');
console.error('this is error');
*/


// 3. JavaScript Variables
var num1 = 34;
var num2 = 35;
console.log(num1+num2);


// 4. Datatype in javascript

    //      Numbers
var num = 34;

    //      String
var str1 = "this is string 1";
var str2 = "this is string 2";

    //      Object Is (like dictionary in python)
var obj = {
    "a":2,
    "b":3
};

    // Booleans 
s = true;

    //undefined when intialize var
var und;

var d = null;
/*
At a very high level, there are two types of data types in JavaScript
1. Primitive datatypes - Number, string,boolean,null,undefined,symbol
2. Reference datatypes - arr,object 

*/

//function

// function avg(a,b){
//     return (a+b)/2;
// }
// console.log(avg(2,4));


//Let has one block scope 
let j = 0;
const a = 1;

// selecting using query selector
// sel = document.querySelector('.container')
// console.log(sel)

// console.log(document.querySelectorAll('.container'))

// Event Selector


/*
function clicked(){
    console.log('The button was clicked')
}

window.onload  = function(){ 
    console.log('The document was loaded')
}

// Event in Javascript
// firstcontainer.addEventListener('mouseover', function(){
//     console.log("Mouse over the container")
// })

firstcontainer.addEventListener('click', function(){
    document.querySelectorAll('.container')[1].innerHTML = "<b> we have clicked </b>"
    console.log(" click the container")
})
*/