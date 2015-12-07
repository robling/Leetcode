#include "../include/pre.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    int carry = 0;
    auto head = new ListNode(0);
    auto current = head;
    auto get = [](ListNode*& l){
        auto rst = l ? l->val : 0;
        l = l ? l->next : NULL;
        return rst;
    };
    while(l1 || l2 || carry)
    {
        current->next = new ListNode(0);
        current = current->next;
        current->val = get(l1) + get(l2) + carry;
        carry = current->val / 10;
        current->val %= 10;
    }
    return head->next;
}        
