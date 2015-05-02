#include "../include/pre.h"

bool isIsomorphic(string s, string t)
{
    assert(s.length() == t.length());
    int feature_s[255]; int top_s = 0;
    int feature_t[255]; int top_t = 0;
    for (int i = 0; i != 255; i++)
    {
    	feature_s[i] = 0;
    	feature_t[i] = 0;
    }
    auto it_s = s.begin();
    auto it_t = t.begin();
    while (it_s != s.end())
    {
    	if (feature_s[it_s[0]] == 0)
    	{
    			feature_s[it_s[0]] = ++top_s;
    	}
    	int var_s = feature_s[it_s[0]];
   
    	if (feature_t[it_t[0]] == 0)
    	{
    		feature_t[it_t[0]] = ++top_t;
    	}
		int var_t = feature_t[it_t[0]];
    	if (var_s != var_t)
    			return false;
    	it_s++;
    	it_t++;
    }
    return true;
}

int Mymain()
{
    cout \
    << isIsomorphic("egg", "lkk") << ", " \
    << isIsomorphic("kdsjaf", "oigjhk") << ", ";
}