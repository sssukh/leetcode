#include <vector>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
       /* int startIdx = nums.size() - 1;
        for (int idx = nums.size() - 1; idx >= 0; --idx)
        {
            if (nums[idx] >= startIdx-idx)
                startIdx = idx;
        }
        
        return startIdx == 0;*/
        int i = 0;
        while (i<nums.size()-1)
        {
            if (nums[i] == 0)
            {
                int zeroIdx = i;
                while (i > 0 && zeroIdx - i >= nums[i])
                {
                    --i;
                }
                if (i == 0)
                    return false;
                else
                    i += nums[i];
            }
            else
            {
                i += nums[i];
            }
       
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> test = { 2,2,0,2,0,2,0,0,2,0 };
    sol.canJump(test);
}