#include "../include/pre.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* makeListNode(const vector<int>& in)
{
    auto p = new ListNode(0);
    auto rst = p;
    for (auto i : in)
    {
        auto pp = new ListNode(i);
        p->next = pp;
        p = pp;
    }
    return rst;
}
void insert(ListNode* cur, ListNode* node)
{
    auto cp = cur->next;
    cur->next = node;
    node->next = cp;
}

ListNode* insertionSortList(ListNode* head) 
{    
    auto insertSort = [&](ListNode* node){
        auto cur  = head;
        ListNode* pri = nullptr;;
        while (cur != nullptr && node->val > cur->val)
        {
            pri = cur;
            cur = cur->next;
        }
        if (pri == nullptr) {
            node->next = head;
            head = node;
        }
        else {
            insert(pri, node);
        }
    };
    auto next = head->next;
    head->next = nullptr;
    while (next != nullptr)
    {
        std::cout << next->val << std::endl;
        auto tmp = next->next;
        insertSort(next);
        next = tmp;
    }
    return head;
}

int main()
{
    vector<int> vals = {70, 3, 4, 5, 623, 231, 45, 63};
    auto rst = insertionSortList(makeListNode(vals));
    while (rst != nullptr)
    {
        std::cout << rst->val << ", ";
        rst = rst->next;
    }
    std::cout << std::endl;
    return 0;
}