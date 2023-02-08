using namespace std;


struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution {
public:
    void putNext(ListNode* current, int nextValue)
    {
        ListNode* tmp = new ListNode(nextValue, current->next);
        current->next = tmp;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* answer = list1;
        ListNode* tmp1 = list1;
        ListNode* tmp2 = list2;
        if (tmp1 == nullptr)
            return list2;
        else if (tmp2 == nullptr)
            return list1;
        if (tmp1->val > tmp2->val)
        {
            tmp1 = list2;
            tmp2 = list1;
            answer = list2;
        }
        while (tmp1 != nullptr && tmp2 != nullptr)
        {
            if ((tmp1->next == nullptr && tmp1->val <= tmp2->val) || 
                (tmp1->val <= tmp2->val && tmp2->val <= tmp1->next->val))
            {
                putNext(tmp1, tmp2->val);
                tmp2 = tmp2->next;
            }
            else
            {
                tmp1 = tmp1->next;
            }
        }
        return answer;
    }
};