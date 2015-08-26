#include "../include/prevector.h"
#include <stack>
using std::stack;
#include <algorithm>
using std::pow;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode* CreateTree(vector<TreeNode>& completeTree)
{
    for (int i = 0; i != completeTree.size(); i++){
        completeTree[i].left = i * 2 + 1 >= completeTree.size() ? NULL : &completeTree[i * 2 + 1];
        completeTree[i].right = i * 2 + 2 >= completeTree.size() ? NULL : &completeTree[i * 2 + 2];
    }
    return &completeTree[0];
}

int lDeep(TreeNode* node)
{
    if (!node)  return 0;
    return 1 + lDeep(node->left);
}
int rDeep(TreeNode* node)
{
    if (!node)  return 0;
    return 1 + lDeep(node->right);
}

int test(int h, TreeNode* node, size_t height)
{
    if (height == h - 1){
        if (node->right != NULL) return 2;
        else if (node -> left != NULL) return 1;
        else return 0;
    }
    auto right = test(h, node->right, height + 1);
    return right == 0 ? test(h, node->left, height + 1) : right + (1 << (h - height - 1));
}
int countNodes(TreeNode* root)
{
    auto it = root;
    stack<TreeNode*> route;
    while (it != NULL){
        route.push(it);
        it = it->left;
    }
    auto h = route.size() - 1;
    int size;
    route.pop();
    for (int i = h - 1; i >= 0; i--){
        size = test(h, route.top(), i);
        route.pop();
        if (size != (1 << (h - i))) return (1 << h) - 1 + size;
    }
    return (1 << (h + 1)) - 1;
}

bool Test_case(int size)
{
    vector<TreeNode> completeTree;
    for (int i = 0; i != size; i++){
        completeTree.push_back(TreeNode(i));
    }
    auto root = CreateTree(completeTree);
    return countNodes(root);
}

int Mymain()
{
    int sizes[] = {1, 7, 15, 8732, 39871, 938722, };
    for (int& size : sizes)
    {
        if (!Test_case(size))
        {
            std::cout << "Error at: " << size << endl;
            return 1;
        }
    }
    cout << "OK!" << endl;
    return 0;
}
