#include "../include/pre.h"

bool isNumber(string s)
{
    auto is_digit = [](char ch)->bool{ return ch >= '0' && ch <= '9'; };
    auto is_flag = [](char ch)->bool{ return ch == '+' || ch == '-'; };
    size_t i = 0;
    auto skip_digit = [&is_digit, &s, &i](){
        int count = i;
        for (; i != s.size(); i++)
            if (!is_digit(s[i])) break;
        return i - count;
    };
    auto skip_space = [&s, &i](){
        for (; i != s.size(); i++)
            if (s[i] != ' ') break;
    };
    skip_space();
    if (is_flag(s[i])) i++;
    int count = skip_digit();
    if (s[i] == '.') {
        i++;
        count += skip_digit();
    }
    if (s[i] == 'e') {
        i++;
        if (is_flag(s[i])) i++;
        if (skip_digit() == 0) return false;
    }
    skip_space();
    if (count == 0 || i != s.size()) return false; else return true;
}

int main()
{
    vector<string> tests {
        " ",
        ".e12",
        ".09e",
        ".12    ", //treat as true
        " +1.02 ",
        "-1.9e4",
        "1e",
        ".",
        "sdf4325",
        "0.2",
        "1 a"
    };
    for (auto& x : tests) {
        cout << x << "\t:\t" << isNumber(x) << "\n";
    }
    return 0;
}
