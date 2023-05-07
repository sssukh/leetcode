#include <vector>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int startIdx = nums.size() - 1;
        for (int idx = nums.size() - 1; idx >= 0; --idx)
        {
            if (nums[idx] >= startIdx-idx)
                startIdx = idx;
        }
        
        return startIdx == 0;
    }
};