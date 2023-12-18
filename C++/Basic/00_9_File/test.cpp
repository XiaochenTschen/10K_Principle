#include <fstream>
#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> readFile(const std::string& filename)
{
    std::vector<std::string> lines;
    std::string line;
    std::ifstream file(filename);

    if(file.is_open())
    {
        while(getline(file, line))
        {
            lines.push_back(line);
        }

        file.close();
    }
    else
    {
        std::cerr << "can not open file";
    }
    return lines;
} 

void modifyLine(std::vector<std::string>& lines, int lineNumber, const std::string& newText)
{
    if(lineNumber >= 0 && lineNumber < lines.size())
    {
        lines[lineNumber] = newText;
    }
}

void deleteLine(std::vector<std::string>& lines, int lineNumber)
{
    if(lineNumber >= 0 && lineNumber < lines.size())
    {
        lines.erase(lines.begin() + lineNumber);
    }
}

void writeFile(const std::string filename, const std::vector<std::string>& lines)
{
    std::ofstream file(filename);

    if(file.is_open())
    {
        for(const auto& line : lines)
        {
        file << line << "\n";
        }
        file.close();
    }
    else
    {
        std::cerr << "can not open file";
    }
}

int main()
{
    std::string filename = "test.txt";

    auto lines = readFile(filename);

    modifyLine(lines, 2, "change this line");
    deleteLine(lines, 5);

    writeFile(filename, lines);

    return 0;
}