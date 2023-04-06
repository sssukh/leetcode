#include<vector>
using namespace std;

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int mn,sum,answer = mn = sum = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            sum += nums[i];

            if (mn < 0)
                answer = max(answer, sum - mn);
            else
                answer = max(answer, sum);

            mn = min(mn, sum);
        }

        return answer;
    }
};