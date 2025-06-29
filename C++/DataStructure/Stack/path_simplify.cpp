#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int len = path.length();
        stack<string> s;
        int l = 0, r = 0;
        while(r < len && l < len) {
            if(path[l] == '/') {
                ++l;
            }
            else {
                r = l;
                while(r < len && path[r] != '/') {
                    ++r;
                }
                string sub_path = path.substr(l, r-l);
                if(sub_path == "..") {
                    if(!s.empty()) {
                        s.pop();
                    }
                } 
                else if(sub_path == ".") {
                    // do nothing
                }
                else {
                    s.push(sub_path);
                }
                l = r;
            }
        }
        string ans = "";
        while(!s.empty()) {
            string sub_path = s.top(); s.pop();
            ans = "/" + sub_path + ans;
        }
        return ans.empty()? "/" : ans;
    }
};

int main(void) {
    string path = "/a/./b/../../c/";
    Solution sol;
    string res = "test";
    res += path;

    cout << "res: " << res << endl;

    return 0;
}