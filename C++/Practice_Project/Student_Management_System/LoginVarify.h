#ifndef _LOGINVARIFY_H_
#define _LOGINVARIFY_H_

#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<regex>

std::unordered_map<std::string, std::string>& loadLoginInfo(const std::string& filename)
{
    std::unordered_map<std::string, std::string> loginInfo;
    std::ifstream file(filename);
    std::string line, userID, password;

    if(file.is_open())
    {
        while(std::getline(file, line))
        {
            if(getUserIDAndPassword(line, userID, password))
            {
                loginInfo[userID] = password;
            }
        }
        file.close();
    }
    else
    {
        std::cerr << "can not open the file";
    }

    return loginInfo;
}

bool getUserIDAndPassword(const std::string& line, std::string& userID, std::string& password)
{
    std::regex expression(R"(\w+\|(\w+)\|(w+))");
    std::smatch match;
    if(std::regex_search(line, match, expression))
    {
        userID = match.str(1);
        password = match.str(2);
        return true;
    }
    else
    {
        return false;
    }
}
#endif