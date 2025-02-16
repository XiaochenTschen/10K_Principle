/**
 * anonymous function: function without name
 */
const foo = function(x:number) {
    return x*x;
}
console.log(`foo(3): ${foo(3)}`);

/**
 * lambda expression
 */
const foo_1 = (x: number) => x*x;
console.log(`foo_1(3): ${foo_1(3)}`);