#include "../include/pre.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool isPalindrome(ListNode* head)
{
    if (!head || !head->next) return true;
    if (!head->next->next) return head->val == head->next->val;
    ListNode *st, *mid, *priMid,*end;
    priMid = NULL;
    st = mid = end = head;
    while (end->next && end->next->next) {
        end = end->next->next;
        ListNode* tmp;
        tmp = priMid;
        priMid = mid;
        mid = mid->next;
        priMid->next = tmp;
    }
    ListNode *mr;
    mr = mid->next;
    if (end->next == NULL) {
        ListNode* tmp;
        tmp = mid;
        mid = priMid;
        priMid = priMid->next;
        mid->next = tmp;
    }
    if (mid->val != mr->val) return false;
    while (priMid) {
        mr = mr->next;
        ListNode* tmp;
        tmp = mid;
        mid = priMid;
        priMid = priMid->next;
        mid->next = tmp;
        if (mid->val != mr->val) return false;
    }
    return true;
}