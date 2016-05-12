#include "../include/pre.h"

int strStr(string haystack, string needle)
{
    if (haystack.empty()) return -1;
    if (needle.empty()) return 0;
    vector<int> next(needle.size(), 0);
    int k = 0;
    for (int i = 1; i < needle.size() - 1; i++)
    {
        if (needle[k] == needle[i]) next[i + 1] = k + 1, k++;
        else k = 0;
    }
    k = 0;
    for (int i = 0; i != haystack.size(); i++)
    {
        while (k > 0 && haystack[i] != needle[k]) k = next[k];
        if (haystack[i] == needle[k]) k++; 
        if (k == needle.size()) return i - k + 1; 
    }
    return -1;
}
int main()
{
    cout << strStr(string("a"), string("a"));
    return 0;
}