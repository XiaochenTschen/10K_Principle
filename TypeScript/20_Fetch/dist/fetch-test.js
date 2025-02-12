"use strict";
console.log('fetch test');
// 如果你使用的是 node-fetch 2.x 版本：
// import fetch from 'node-fetch';
// 示例：调用 fetch 获取数据
async function getData(url) {
    const response = await fetch(url);
    const data = await response.json();
    return data;
}
getData('https://api.example.com/data')
    .then(data => console.log(data))
    .catch(err => console.error(err));
