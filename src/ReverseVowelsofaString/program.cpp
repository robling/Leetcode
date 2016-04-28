#include "../include/pre.h"

string reverseVowels(string s)
{
    const auto N = s.size();
    int i = 0, j = N - 1;
    auto isVowel = [](char ch){
        if (ch <= 'Z') ch += ('a' - 'A');
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    };
    while(true)
    {
        while (!isVowel(s[i]) && i < N) i++;
        while (!isVowel(s[j]) && j > 0) j--;
        if (i >= j) break;
        std::swap(s[i], s[j]);
        i++, j--;
    }
    return s;
}
int main()
{
    cout << reverseVowels("leetcode") << endl;
    return 0;
}