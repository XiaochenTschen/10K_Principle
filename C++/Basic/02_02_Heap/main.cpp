#include<queue>
#include<vector>
#include<map>
#include<iostream>
#include<string>

struct Comapare
{
    bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
    {
        return a.second > b.second;
    }
};

template<typename T>
void print(std::string_view name, T const& q)
{
    std::cout << name << ": ";
    for(auto const& n:q)
    {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::map<std::string, int> m{{"i",3},{"love",2},{"coding",1},{"leet",0}};
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, Comapare> pq; 

    for(auto ele:m)
    {
        pq.push(ele);
    }

    while(!pq.empty())
    {
        std::cout << pq.top().first << std::endl;
        pq.pop();
    }

    return 0;
}
