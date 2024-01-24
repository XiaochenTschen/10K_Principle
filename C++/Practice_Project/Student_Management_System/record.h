#ifndef _RECORD_H_
#define _RECORD_H_

#include<vector>
#include<string>
#include<fstream>
#include <iostream>

std::vector<std::string>& loadRecord(const std::string& filename)
{
    std::vector<std::string> records;
    std::string line;
    std::ifstream file(filename);

    if(file.is_open())
    {
        while(std::getline(file, line))
        {
            records.push_back(line);
        }
        file.close();
    }
    else
    {
        std::cerr << "can not open record\n";
    }
    return records;
}

void writeFile(const std::string& filename, std::vector<std::string>& records)
{
    std::ofstream file(filename);
    if(file.is_open())
    {
        for(const auto& element:records)
        {
            file << element << "\n";
        }
        file.close();
    }
    else
    {
        std::cerr << "can not open the file";
    }
}

#endif