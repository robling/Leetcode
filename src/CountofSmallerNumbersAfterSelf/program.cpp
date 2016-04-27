#include "../include/pre.h"
#include <map>

class BST
{
public:
    int val;
    int countOfSmaller; //number of elements in left sub-tree
    int count;
    BST* left;
    BST* right;
public:
    BST(int n) : val(n), countOfSmaller(0), count(1), left(nullptr), right(nullptr){}
    int insert(int n, int nSmaller = 0)
    {
        if (n < this->val)
        {
            this->countOfSmaller++;
            if (left == nullptr) 
            {
                left = new BST(n);
                return nSmaller;
            }
            else
            {
                return left->insert(n, nSmaller);
            }
        }
        else if (n > this->val)
        {
            nSmaller += (this->countOfSmaller + this->count);
            if (right == nullptr)
            {
                right = new BST(n);
                return nSmaller;
            }
            else
            {
                return right->insert(n, nSmaller);
            }
        }
        else //(n == this->val)
        {
            count++;
            return nSmaller + this->countOfSmaller;
        }
    }
        
    ~BST(){/*Should have*/}
};

vector<int> countSmaller(vector<int>& nums)
{
    if (nums.size() == 0) return {};
    vector<int> rst_(1, 0);
    auto root = new BST(nums.back());
    for (auto it = nums.rbegin() + 1; it != nums.rend(); it++)
    {
        rst_.push_back(root->insert(*it));
    }
    std::reverse(rst_.begin(), rst_.end());
    return rst_;
}
int main()
{
    vector<int> test = {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
    cout << countSmaller(test) << endl;
    return 0;
}