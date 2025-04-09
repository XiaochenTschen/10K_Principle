/**
 * Buffer 是 Node.js 提供的一个全局类，用于处理和操作二进制数据。
 * 它特别适用于网络通信、文件 I/O、加密等通常涉及到原始的二进制数据的场景
 */

const buf = Buffer.from("Hello World", "utf-8");
console.log(buf); // 输出: <Buffer 48 65 6c 6c 6f 20 57 6f 72 6c 64>

const str = buf.toString('utf-8');
console.log(str);

// create a buffer with specific size, bytes unit
const buf2 = Buffer.alloc(10);
console.log(buf2);

const buf3 = Buffer.alloc(20);
const bytesWritten = buf3.write("Node.js Buffer", "utf-8");
console.log(`Bytes written: ${bytesWritten}`);  // 输出写入的字节数
console.log(buf3.toString("utf-8", 0, bytesWritten)); // 输出: Node.js Buffer

const bufA = Buffer.from("Hello ");
const bufB = Buffer.from("World!");
const bufC = Buffer.concat([bufA, bufB]);
console.log(bufC.toString("utf-8")); // 输出: Hello World!

const bufD = Buffer.from("This is a sample text");
const slice = bufD.slice(10, 16);
console.log(slice.toString("utf-8")); // 输出: sample
