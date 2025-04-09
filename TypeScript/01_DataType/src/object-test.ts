const jsonObject = {
    data: [
        { name: "Alice", type: "admin", id: 100 },
        { name: "Bob", type: "user", id: 101 }
    ]
};
// Object.keys(): 返回给定对象自身的所有可枚举属性的键（key）的数组，类型为 string[]
console.log('******** Object.keys() test ******** ')
const obj_key1 = Object.keys(jsonObject);         // ['data']
const obj_key2 = Object.keys(jsonObject.data);    // ['0', '1']
const obj_key3 = Object.keys(jsonObject.data[0]); // ['name', 'type', 'id']
console.log(`keys of jsonObject: ${obj_key1}`);
console.log(`keys of jsonObject.data: ${obj_key2}`);
console.log(`keys of jsonObject.data[0]: ${obj_key3}`);
console.log();

// Object.entries(): 将对象的可枚举属性转换为一个二维数组
console.log('******** Object.entries() test ******** ')
const [obj_entry0] = Object.entries(jsonObject);
console.log(`jsonObject entry0: ${obj_entry0}`);
console.log(`obj_entry0 key: ${obj_entry0[0]}, value: ${obj_entry0[1]}`);
console.log();

const [data_entry0, data_entry1] = Object.entries(jsonObject.data);
console.log(`jsonObject.data entry0: ${data_entry0}, entry1: ${data_entry1}`);
console.log(`data_entry0 key: ${data_entry0[0]}, value: ${data_entry0[1]}`);
console.log();

const [data0_entry0, data0_entry1, data0_entry2] = Object.entries(jsonObject.data[0]);
console.log(`jsonObject.data[0] entry0: ${data0_entry0}, entry1: ${data0_entry1}, entry2: ${data0_entry2}`);
console.log(`data0_entry0 key: ${data0_entry0[0]}, value: ${data0_entry0[1]}`);
console.log();

/**
 * Traverse json object
 */
function printObject(obj: any, indent: number = 0) {
    const indentStr = ' '.repeat(indent);
    for (const [key, value] of Object.entries(obj)) {
        if (typeof value === 'object' && value !== null) {
            console.log(`${indentStr}${key}: {`);
            printObject(value, indent + 2);
            console.log(`${indentStr}}`);
        } else {
            console.log(`${indentStr}${key}: ${value}`);
        }
    }
}
console.log('******** printObject() test ******** ')
printObject(jsonObject);

// 基本用法
const person = {
    name: "Tom",
    age: 25,
    city: "Beijing"
};
const keys = Object.keys(person);
console.log(keys);  // ["name", "age", "city"]

// 结合forEach使用
Object.keys(person).forEach(key => {
    console.log(`${key}: ${person[key as keyof typeof person]}`);
});

// 获取对象的属性数量
const propertyCount = Object.keys(person).length;
console.log(propertyCount);  // 3

// 检查对象是否为空
const isEmpty = (obj: object) => Object.keys(obj).length === 0;
console.log(isEmpty({}));  // true
console.log(isEmpty(person));  // false

// 结合map使用
const upperKeys = Object.keys(person).map(key => key.toUpperCase());
console.log(upperKeys);  // ["NAME", "AGE", "CITY"]

// 用于数组（数组的键是索引）
const arr_test = ["a", "b", "c"];
console.log(Object.keys(arr_test));  // ["0", "1", "2"]


/********************Object.entries() test ********************/
// 基本用法
const person2 = {
    name: "Tom",
    age: 25
};

const entries = Object.entries(person2);
console.log(entries); 
// 输出: [["name", "Tom"], ["age", 25]]

// 1. 结合解构赋值使用
const [[key1, value1], [key2, value2]] = Object.entries(person2);
console.log(key1, value1);   // "name" "Tom"
console.log(key2, value2);   // "age" 25

// 2. 结合 for...of 循环使用
for (const [key, value] of Object.entries(person2)) {
    console.log(`${key}: ${value}`);
}
// 输出:
// name: Tom
// age: 25

// 3. 数组的 entries
const arr2_test = ['a', 'b', 'c'];
console.log(Object.entries(arr2_test));
// 输出: [["0","a"], ["1","b"], ["2","c"]]

// 4. 转换回对象
const entriesArray = [['name', 'Tom'], ['age', 25]];
const objFromEntries = Object.fromEntries(entriesArray);
console.log(objFromEntries); // { name: "Tom", age: 25 }
