#include<iostream>
#include<string>
#include<map>

struct Compare
{
    bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
    {
        return a.second > b.second;
    }
};

int main()
{
    std::map<std::string, int> m{{"i",3},{"love",2},{"coding",1},{"leet",0}};
    Compare cmp;
    bool ans = cmp({"i",3}, {"love",2});
    std::cout << "ans: " << ans << '\n';

    return 0;
}