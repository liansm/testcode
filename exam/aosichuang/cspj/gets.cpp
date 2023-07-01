#include <iostream>
#include <vector>
#include <string>
 
int main()
{
    std::string line;
    std::vector<std::string> v;
 
    while (std::getline(std::cin, line))
    {
        if (line.empty()) {
            break;
        }
        v.push_back(line);
    }
 
    for (std::string &s: v){
        std::cout << s << std::endl;
    }
 
    return 0;
}