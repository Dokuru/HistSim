#include <vector>
#include <string>

std::vector<std::string> explode(const std::string& str, const std::string& delimiters = " ")
{
    std::vector<std::string> tokens;
 
    int subStrBeginPos = str.find_first_not_of(delimiters, 0);
    int subStrEndPos = str.find_first_of(delimiters, subStrBeginPos);
 
    while(std::string::npos != subStrBeginPos || std::string::npos != subStrEndPos)
    {
        tokens.push_back(str.substr(subStrBeginPos, subStrEndPos-subStrBeginPos));
 
        subStrBeginPos = str.find_first_not_of(delimiters, subStrEndPos);
        subStrEndPos = str.find_first_of(delimiters, subStrBeginPos);
    }
 
    return tokens;
}
