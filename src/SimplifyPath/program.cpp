#include "../include/pre.h"

string simplifyPath(string path)
{
    std::vector<string> real;
    std::stringstream ss(path);
    while (!ss.eof())
    {
        while ('/' == ss.peek()) ss.get();
        std::stringstream oss;
        while ('/' != ss.peek() && std::char_traits<char>::eof() != ss.peek()) oss << static_cast<char>(ss.get());
        auto node = oss.str();
        for (int i : node) cout << i << ", ";
        if ("" == node) continue;
        if ("." == node) continue;
        if (".." == node) 
        {
            if (!real.empty()) real.pop_back();
            continue; 
        }
        real.push_back(node);
        cout << node << endl;
    }
    if (real.empty()) return "/";
    std::stringstream oss;
    for (auto& node : real)
        oss << '/' << node;
    return oss.str();
}

int main()
{
    cout << simplifyPath("//..");
    return 0;
}