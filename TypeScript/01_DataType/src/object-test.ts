const jsonObject = {
    data: [
        { name: "Alice", type: "admin", id: 100 },
        { name: "Bob", type: "user", id: 101 }
    ]
};
// Object.keys(): 返回给定对象自身的所有可枚举属性的键（key）的数组，类型为 string[]
console.log('******** Object.keys() test ******** ')
const obj_key1 = Object.keys(jsonObject);
const obj_key2 = Object.keys(jsonObject.data);
const obj_key3 = Object.keys(jsonObject.data[0]);
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
