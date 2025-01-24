/* Objects
{
    key{propertyName} : value{propertyValue},
    key{propertyName} : value{propertyValue},
    key{propertyName} : value{propertyValue},
    key{propertyName} : value{propertyValue},
}
*/

/* a = [10, 12, 11, 12];
console.log(typeof a);
for (const i of a.entries()) {
  console.log(i);
} 

const a = new Object(undefined);
console.log(typeof a);
console.log(a);
*/

/* declaration vs definition */
/* 
let a;
let b;
const c = 5;
var d = 10;
void swap(int a, int b); // declaration

void swap(int a, int b){ // definition
    // actual function 
}
*/

/* null vs undefined */
/* function add(a, b) {
  return a + b;
}
let sai = {
  name: "sainadth",
  age: 25,
};
console.log(typeof 1);
console.log(typeof 1n);
console.log(typeof true);
console.log(typeof "afsdf");
console.log(typeof Symbol("afsadf"));
console.log(typeof undefined);
console.log(typeof null);
console.log(typeof add);
console.log(typeof sai); */

/* let target = {
  name: "",
  age: 0,
};
let source1 = {
  name: "sainadth",
  age: 25,
};

let source2 = {
  name: "vasavi",
  age: 27,
};

target = Object.assign(target, source2);
console.log(target);

target = Object.assign(target, source2, source1);
console.log(target);
 */

/* const person = {
  isHuman: false,
  printIntroduction: function () {
    console.log(`My name is ${this.name}. Am I human? ${this.isHuman}`);
  },
};

const sai = Object.create(person);

sai.printIntroduction();
sai.isHuman = true;
sai.name = "sainadth";

sai.printIntroduction(); */

/* let target = {
  name: "sainadth",
  age: 25,
  "education background": "Graduation",
  laptops: [
    {
      madeBy: "Lenovo",
      processor: "i7",
      ram: "4GB",
      hardware: {
        keyborad: "wireless",
        mouse: "wireless",
        dispaly: true,
      },
    },
    {
      madeBy: "HP",
      processor: "i3",
      ram: "4GB",
    },
  ],
};

a = "madeBy"; */

// console.log(target["name"]);
// console.log(target.laptop[a]);
/* for (let ele of target.laptops) {
  console.log(ele.hardware?.keyborad);
} */

// delete target.laptops;
// console.log(target);

// console.log(target[a]);
/* 
for (let property of Object.entries(target)) {
  console.log(property);
}

for (let propertyKey of Object.keys(target)) {
  console.log("propertyKey = ", propertyKey);
}

for (let propertyValue of Object.values(target)) {
  console.log("propertyValue = ", propertyValue);
}
 */

/* Object.defineProperty(target, "education", {
  value: "SSC",
}); */

// Object.defineProperties(target, {
//   "education"
// })

// firstName = "sai";
// lastName = "pagadala";

// const person = {
//   firstName: "John",
//   "last name": "Doe",
//   id: 5566,
//   background: {
//     ssc: "9.7",
//     inter: "975",
//   },
//   fullName: function () {
//     return this.firstName + " " + this["last name"];
//   },
// };

// console.log(person.id);
// console.log(person.fullName());

// for (let ele of Object.entries(person)) {
//   console.log(ele[0], ele[1]);
// }

// for (let [key, value] of Object.entries(person)) {
//   console.log(key, value);
// }

// console.log(JSON.stringify(person));

/* Object Constructor function */
/* function Person(fname, lname, age, color) {
  this.fname = fname;
  this.lname = lname;
  this.age = age;
  this.color = color;
  this.nationality = "India";
}

const f = new Person("John", "Doe", 50, "blue");
const s = new Person("Johnny", "Rally", 22, "green");

console.log(f);
console.log(s); */
/* console.log(s);

Person.prototype.company = "Infosys";

console.log(f.company);
console.log(s.company); */

/* const obj = {
  a: 1,
  b: 2,
  c: 3,
};

const { a, b, c } = obj;
console.log(a, b, c);

console.log(Object.entries(obj));

/* for (let ele of Object.entries(obj)) {
  console.log(ele);
} */

/*
const obj2 = Object.fromEntries(
  Object.entries(obj).map(([key, value]) => {
    return [key, value * 2];
  })
);

/* 
  [key, value] = ['a', 1] 
  key = 'a'
  value = 1
  console.log(obj2); 
*/

const inventory = [
  { name: "asparagus", type: "vegetables", quantity: 5 },
  { name: "bananas", type: "fruit", quantity: 0 },
  { name: "goat", type: "meat", quantity: 23 },
  { name: "cherries", type: "fruit", quantity: 5 },
  { name: "fish", type: "meat", quantity: 22 },
];

const r = Object.groupBy(inventory, (ele) => {
  console.log(ele);
  return 0;
});
