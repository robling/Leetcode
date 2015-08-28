/**************************************************************
 * Author   : Robin Liu
 * Date     : 2015-05-01
 * Detail   : https://leetcode.com/submissions/detail/26726307/
 **************************************************************/
#include "../include/pre.h"

void rotate(int nums[], int n, int k)
{
    k = k%n;
    cout << k << endl;
    if (k == 0)
        return;
    int* tmp = new int[n - k];
    for (int i = 0; i != n; i++)
    {
        if (i < n - k)
            tmp[i] = nums[i];
        nums[i] = (i < k)?nums[n - k + i]:tmp[i - k];
    }
    delete[] tmp;
}

#define SWAP(a, b) {int swaptmp = a;a = b;b = swaptmp;}
void BadRotateWith1Bitbuff(int nums[], int n, int k)
{
    k = k%n;
    if (k == 0)
        return;
    for (; k != 0; k--)
    {
        MoveRight(nums, n);
    }
}
void MoveRight(int nums[], int n)
{
    int tmp = nums[0];
    nums[0] = nums[n];
    for (int i = 1; i != n; i++)
    {
        SWAP(tmp, nums[i])
    }
}

class LoopCount
{
    public:
        LoopCount(int num):max(num - 1){
            i = 0;
        }
        int& operator+=(int k)
        {
            i += k;
            if (k >= max)
                k -= max;
            return i;
        }
        int& operator*()
        {
            return this->i;
        }
    private:
        int i;
        int max;
}
void rotateWith1Bitbuff(int nums[], int n, int k)
{
    k = k%n;
    int tmp = nums[0];
    LoopCount i(n);
    for (int i = 0; i != n; i++)
    {
        //TODO:
    }
}

void Mymain()
{
    TIC
    int nums[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45};
    for (int i : nums)
    {
        cout << i << ", ";
    }
    cout << endl;
    //rotate(nums, 45, 56);
    rotateWith1Bitbuff(nums, 45, 56);
    for (int i : nums)
    {
        cout << i << ", ";
    }
    cout << endl;
    TOC
}
