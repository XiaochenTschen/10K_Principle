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
 * for each of tuple/pair
 */
const pair: [string, string, number] = ["hello", "world", 100];
pair.forEach((item) => {
    console.log(item);
});

const arr = [1, 2, 3, 4, 5];
arr.forEach((item, index) => {
  console.log(`idex: ${index}, value: ${item}`);
});
