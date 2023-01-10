#include <iostream>
#include<list>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* answer = new ListNode();
        ListNode* iter = answer;
        int list1 = l1->val;
        int list2 = l2->val;
        int up = 0;
        while (l1->next!=nullptr||l2->next!=nullptr)
        {
            iter->val = (list1 + list2 + up) % 10;
            up = (list1 + list2 + up) / 10;
            iter->next = new ListNode();
            iter = iter->next;
            if (l1->next == nullptr)
                list1 = 0;
            else
            {
                l1 = l1->next;
                list1 = l1->val;
            }
            if (l2->next == nullptr)
                list2 = 0;
            else
            {
                l2 = l2->next;
                list2 = l2->val;
            }
        }
        iter->val = (list1 + list2 + up) % 10;
        up = (list1 + list2 + up) / 10;
        if (up > 0)
        {
            iter->next = new ListNode();
            iter = iter->next;
            iter->val = up;
        }
        return answer;
    }
};