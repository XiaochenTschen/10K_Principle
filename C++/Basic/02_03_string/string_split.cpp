#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> split_strig(const string& s, const string& delimiter) {
    vector<string> tokens;
    string token;
    size_t start = 0;
    size_t pos = 0;
    size_t dlen = delimiter.length();
    
    while((pos = s.find(delimiter, start)) != string::npos) {
        token = s.substr(start, pos - start);
        tokens.push_back(token);
        start = pos + dlen;
    }
    tokens.push_back(s.substr(start));

    return tokens;
}

void print_vector_strings(const vector<string> vs) {
    for(string s:vs) {
        cout << s << endl;
    }
}

int main(void) {
    vector<string> tests = {
        "hello world", 
        "helloworld", 
        "hello  world"
    };

    for( auto test:tests) {
        vector<string> results = split_strig(test, " ");
        print_vector_strings(results);
        cout << endl;
    }

    return 0;
}