#include <utility>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str = "hello";
    vector<string> v;

    v.push_back(str);
    cout << "after copy, str is \"" << str << "\"" << endl;

    /*
     * move cast lvalue to rvalue
     * after function call, rvalue exists not any more
    */
    v.push_back(move(str));
    cout << "after move, str is \"" << str << "\"" << endl;

    cout << "contents of vector are: " <<  "\n\t" << v[0] << "\n\t" << v[1] << endl;

    return 0;
}