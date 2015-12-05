#include "../include/pre.h"

int firstBadNum = 1;

bool isBadVersion(int version)
{
    if (version >= firstBadNum) return true;
    return false;
}
int firstBadVersion(int n)
{
    auto mid = [](int i, int j){uint64_t k = (uint64_t)i + j; return k / 2;};
    int s = 1, e = n;
    while (e - s > 1)
    {
        if (isBadVersion(mid(s, e)))
            e = mid(s, e);
        else
            s = mid(s, e);
        cout << s << ", " << e << endl;
    }
    return isBadVersion(s) ? s : e;
}

int main()
{
    firstBadNum = 1702766719;
    cout << firstBadVersion(2126753390) << endl;
    return 0;
}