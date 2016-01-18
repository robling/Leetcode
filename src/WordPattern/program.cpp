#include "../include/pre.h"
#include <set>

const size_t MAXPATTERN = 26;
bool wordPattern(string pattern, string str)
{
    string dict[MAXPATTERN];
    std::set<string> strPool;
    std::stringstream ss{str};
    string tmp;
    for (auto p : pattern)
    {
        if (ss.eof()) return false;
        ss >> tmp;
        if (dict[p - 'a'] == "") {
            if (strPool.find(tmp) != strPool.end()) return false;
            strPool.insert(tmp);
            dict[p - 'a'] = tmp;
            continue;
        }
        if (dict[p - 'a'] != tmp) return false; 
    }
    if (!ss.eof()) return false;
    return true;
}

int main()
{
    cout << std::boolalpha << wordPattern("abcd", "as as erqw dfsa");
    return 0;
}