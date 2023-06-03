#include<vector>
#include <queue>
using namespace std;

// 현재 i 에서 j 까지 순환하면서 현재 점프에서 갈 수 있는 가장 먼 거리를 구한다.

class Solution 
{
public:
  

    int jump(vector<int>& nums) 
    {
        //int longestJump = 0, jump=0, size = nums.size(), index=0;
        //while (longestJump < size-1)
        //{
        //    // 순환끝난 계단 ~ 순환 범위
        //    int currentJumpRange = longestJump;
        //    ++jump;
        //    for (index = 0; index <= currentJumpRange; ++index)
        //    {
        //        longestJump = max(index + nums[index], longestJump);
        //    }
        //}
        //return jump;

        int size = nums.size();
        for (int i = 1; i < size; ++i)
        {
            nums[i] = max(nums[i - 1], nums[i] + i);
        }

        int ans = 0, idx = 0;

        while (idx < size - 1)
        {
            ++ans;
            idx = nums[idx];
        }
        return ans;
    }
};