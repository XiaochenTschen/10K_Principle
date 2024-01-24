#include<iostream>
#include<string>
#include<regex>

int main()
{
    std::string teststr = "chen|0110|user";
    std::regex expression(R"(\w+\|(\w+)\|(\w+))");
    std::smatch match;
    if(std::regex_search(teststr, match, expression))
    {
        std::cout << match.str(0) << "\n";
        std::cout << "userID: " << match.str(1) << "\n";
        std::cout << "password: " << match.str(2) << "\n";
    }
    else
    {
        std::cout << "No match found" << std::endl;
    }

    return 0;
}