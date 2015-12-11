#include "../include/pre.h"

class NumArray {
public:
    NumArray(vector<int> &nums)
    {
        MakeBIT(nums);
    }

    void update(int i, int val)
    {
        val = val - GetN(i);
        i += 1;
        while (i < BIT_.size()) {
            BIT_[i] += val;
            i += i & (i ^ (i - 1));
        }
    }

    int sumRange(int i, int j)
    {
        return sumToN(j + 1) - sumToN(i);
    }
private:
    int sumToN(int n)
    {
        int sum = 0;
        while (n != 0)
        {
            sum += BIT_[n];
            int k = n & (n ^ (n - 1));
            n -= k;
        }
        return sum;
    }
    int GetN(int n)
    {
        return sumRange(n, n);
    }
    void MakeBIT(const vector<int>& nums)
    {
        BIT_.resize(nums.size() + 1, 0);
        for (int i = 1; i != BIT_.size(); i++) {
            int k = i & (i ^ (i - 1)); // 2^k, k : count of zero from end
            int sum = nums[i - 1];
            for (int j = 1; j != k; j *= 2) {
                sum += BIT_[i - j];
            }
            BIT_[i] = sum;
        }
    }
    vector<int> BIT_;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

int main()
{
    NumArray p {vector<int>{1, 2, 3, 4, 5, 6, 7, }};
    //cout << p.sumToN(1) << endl;
    cout << p.sumRange(0, 5) << endl;
    p.update(1, 10);
    cout << p.sumRange(0, 5) << endl;
    return 0;
}