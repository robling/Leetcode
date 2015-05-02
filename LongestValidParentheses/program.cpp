#include "../include/prevector.h"

/// \return false when no barckets can be matched
inline bool MatchBrackets(int* triMask, int length)
{
	int num = 0;
	for (int i = 0; i != length; i++)
	{
		if (triMask[i] == 1)
		{
			for (int j = i + 1; j != length; j++)
			{
				if (triMask[j] == 0)
					continue;
				if (triMask[j] == 1)
					break;
				if (triMask[j] == 2)
				{
					++num;
					triMask[i] = 0;
					triMask[j] = 0;
					break;
				}
			}
		}
	}
	if (num != 0)
		return true;
	else
		return false;
}
int longestValidParentheses(string s) {
	int *triMask = new int[s.length()];
	for (int i = 0; i != s.length(); i++)
	{
		int tmp = 100;
		switch (s[i])
		{
		case '(':
			tmp = 1;
			break;
		case ')':
			tmp = 2;
			break;
		default:
			assert(false);
			break;
		}
		triMask[i] = tmp;
	}
	while (MatchBrackets(triMask, s.length())){}
	int maxLength = 0;
	for (int i = 0; i != s.length(); i++)
	{
		int tmp = 0;
		if (triMask[i] == 0)
		{
			++tmp;
			for (int j = i + 1; j != s.length(); j++)
			{
				if (triMask[j] == 0)
					++tmp;
				else
					break;
			}
			if (tmp > maxLength)
				maxLength = tmp;
		}
	}
	delete[] triMask;
	return maxLength;
}

int Mymain()
{
    vector<string> testData = {"()()())))(((", "()))((())((()(("};
    for (auto s : testData)
    {
        cout << s << ": ";
        cout << longestValidParentheses(s) << "\n";
    }
}