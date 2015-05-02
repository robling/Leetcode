#include "../include/prevector.h"
#include "hash_map"
#include "map"
using std::map;
using std::hash_map;

const int MAX_10DNA_TYPE = (1 << 20) - 1;
int ConvertSubDNAToInt(const string& s, int id = 0, int length = 10)
{
    int val = 0;
    for (int i = 0; i < length; i++)
    {
        switch (s[id + 9 - i])
        {
        case 'A':
            break;
        case 'G':
            val |= (1 << (2 * i));
            break;
        case 'C':
            val |= (2 << (2 * i));
            break;
        case 'T':
            val |= (3 << (2 * i));
            break;
        }
    }
    return val;
}

string ConvertIntToDNAseq(int val, int length = 10)
{
    string str(length, 0);
    for (int i = length - 1; i != -1; i--)
    {
        switch (val & 3/*11b*/)
        {
        case 0:
            str[i] = 'A';
            break;
        case 1:
            str[i] = 'G';
            break;
        case 2:
            str[i] = 'C';
            break;
        case 3:
            str[i] = 'T';
            break;
        }
        val >>= 2;
    }
    return str;
}

#define STD_MAP
vector<string> findRepeatedDnaSequences(string s)
{
    // Exceed memory limit
    //char* hashTable = new char[MAX_10DNA_TYPE];
    //memset(hashTable, 0, MAX_10DNA_TYPE - 100);
#ifdef STD_MAP
    map<int, int> hashTable;
#else
#ifdef STD_HASH_MAP
    hash_map<int, int> hashTable;
#endif
#endif
    vector<string> rst;
    if (s.size() < 10)
        return rst;
    //For each sub string of input string
    for (int i = 0; i != s.size() - 9; i++)
    {
        int tmp = ConvertSubDNAToInt(s, i);
        //cout << tmp << "\t : " << hashTable[tmp] << " -> ";
        ++hashTable[tmp];
        //cout << hashTable[tmp] << "\n";
    }
    for (auto i : hashTable)
    {
        if (i.second > 1)
            rst.push_back(ConvertIntToDNAseq(i.first));
    }
    return rst;
}

int Mymain()
{
    TIC
    vector<string> testData = {"AAAAAAAAAAA", "", "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT", "AAAAACCCCCAAAAACCCCCAAAAAGGGTTT"};
    for (string s : testData)
    {
        cout << s << ": \n";
        PrintVector(findRepeatedDnaSequences(s), " \n");
        //PrintToBinary(ConvertSubDNAToInt(s));
        cout << "=========\n";
    }
    TOC
}