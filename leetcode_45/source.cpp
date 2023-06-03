#include<vector>
#include <queue>
using namespace std;

// ���� i ���� j ���� ��ȯ�ϸ鼭 ���� �������� �� �� �ִ� ���� �� �Ÿ��� ���Ѵ�.

class Solution 
{
public:
  

    int jump(vector<int>& nums) 
    {
        //int longestJump = 0, jump=0, size = nums.size(), index=0;
        //while (longestJump < size-1)
        //{
        //    // ��ȯ���� ��� ~ ��ȯ ����
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