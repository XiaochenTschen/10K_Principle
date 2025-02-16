/**
 * use interface to emulate the pair
 */
interface pair<T, U> {
    first: T;
    second: U;
}

function pair_test(pair_data: pair<string, number>): void {
    console.log('First:', pair_data.first);
    console.log('Second:', pair_data.second);
}

pair_test({first: "world", second:100});

// creat a pair object
const pair_obj: pair<string, string> = {first: "hello", second: "world"};
function pair_test_01(pair_data: pair<string, string>): void {
    console.log('First:', pair_data.first);
    console.log('Second:', pair_data.second);
}
pair_test_01(pair_obj);