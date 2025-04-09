/**
 * use tuple to emulate pair
 */
function processPair(pair: [string, number]): void {
    const first: string = pair[0];
    const second: number = pair[1];
    console.log('First:', first);
    console.log('Second:', second);
}
  
processPair(["hello", 42]);

/**
 * forEach of tuple/array
 * forEach has two parameters: item and index, but has no return value
 */
const tuple_test: [string, string, number] = ["hello", "world", 100];
tuple_test.forEach((item) => {
    console.log(item);
});

const arr = [1, 2, 3, 4, 5];

console.log(arr);

arr.forEach((item, index) => {
  console.log(`idex: ${index}, value: ${item}`);
});


/**
 * map
 * map has one parameter: item, but has return value and create a new array same length as the original array
 */
const arr2 = arr.map((item) => item * 2);
console.log(arr2);


/**
 * filter
 * filter has one parameter: item, but has return value and create a new array contains the items that pass the filter condition
 */
const arr3 = arr.filter((item) => item % 2 === 0);
console.log(arr3);  

const arr1 = [1,2,[3,4], 5];

console.log(arr1); 

const arr4 = arr1.flat();
console.log(arr4);

const arr5 = arr1.flat().map((item) => item * 2);
console.log(arr5);

// 基本用法
const numbers = [1, 2, 3, 4, 5];
const doubled = numbers.map(num => num * 2);
console.log(doubled);  // [2, 4, 6, 8, 10]

// 使用索引
const withIndexes = numbers.map((num, index) => {
    return `${index}: ${num}`;
});
console.log(withIndexes);  // ["0: 1", "1: 2", "2: 3", "3: 4", "4: 5"]

// 对象转换
const users = [
    { name: "Tom", age: 20 },
    { name: "Jerry", age: 18 }
];
const names = users.map(user => user.name);
console.log(names);  // ["Tom", "Jerry"]

// 可以链式调用
const processedNumbers = numbers
    .map(num => num * 2)     // 先将每个数字翻倍
    .map(num => num + 1);    // 再给每个数字加1
console.log(processedNumbers);  // [3, 5, 7, 9, 11]

// 在对象方法中使用
const total = {
    sum: 0,
    addNumbers: function(numbers: number[]) {
        numbers.forEach(num => {
            this.sum += num;
        });
    }
};
