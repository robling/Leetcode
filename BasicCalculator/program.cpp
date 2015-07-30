/**********************************************************
 * Time : 36 ms
 * https://leetcode.com/submissions/detail/34495065/
 **********************************************************/
#include "../include/prevector.h"
#include <stack>
using std::stack;

int calculate(string s)
{
    vector<char> operations;
    vector<char> rever_marks;

    stack<bool> reversions;
    bool rever_mark = false;

    for (char& ch : s)
    {
        switch (ch)
        {
            case '+':
            case '-':
                operations.push_back(ch);
                rever_marks.push_back(rever_mark);
                ch = ' ';
                break;
            case '(':
                if (!operations.empty() && operations.rbegin()[0] == '-') rever_mark = !rever_mark;
                reversions.push(!operations.empty() && operations.rbegin()[0] == '-');
                ch = ' ';
                break;
            case ')':
                if (reversions.top()) rever_mark = !rever_mark;
                reversions.pop();
                ch = ' ';
                break;
        }
    }

    stringstream ss(s);
    int rst = 0;
    ss >> rst;
    cout << endl;
    // PrintVector(operations);
    // PrintVector(rever_marks);
    for (int i = 0; i != operations.size(); i++)
    {
        int n = 0;
        ss >> n;
        switch (operations[i]) {
            case '+':
                rst += rever_marks[i] ? -n : n;
                break;
            case '-':
                rst -= rever_marks[i] ? -n : n;
                break;
        }
    }
    return rst;
}

int Mymain()
{
    string tests[] = {
        "2  ",
        "1 + 1",
        " 2-1 + 2 ",
        "2-(5-6)",
        "(3-(2-(5-(9-(4)))))",
        "(1+(4+5+2)-3)-(6-8)"
    };
    for (string& s : tests)
    {
        cout << s << ":\t" << calculate(s) << endl;
    }
}
