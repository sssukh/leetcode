
  struct ListNode 
  {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int counts = n;
        ListNode* cursur = head;
        ListNode* answer = head;
        ListNode* interval = head;

        while (counts--)
        {
            interval = interval->next;
        }

        if (interval != nullptr)
        {
            while (interval->next != nullptr)
            {
                cursur = cursur->next;
                interval = interval->next;
            }
            cursur->next = cursur->next->next;

        }
        else // interval == nullptr
        {
            answer = answer->next;
        }



        return answer;
    }
};


int main()
{
    Solution sol;
    ListNode* test = new ListNode();
    sol.removeNthFromEnd(test,1);
}