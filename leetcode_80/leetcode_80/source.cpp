#include<vector>
using namespace std;

class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        // index 두개 놓기
        // 하나는 중복제거한 array에 지정할 index, 다른 하나는 다음 수를 찾는 index

        int arrayIdx = 0, dupIdx = 0, size = nums.size(),currentNum=nums[0],count=0;

        while (dupIdx < size&&arrayIdx<size)
        {
            while (dupIdx < size && nums[dupIdx] == currentNum)
            {
                ++dupIdx;
                ++count;
            }
            for (int i = 0; i < 2 && i < count; ++i)
                nums[arrayIdx++] = currentNum;

            if(dupIdx<size)
                currentNum = nums[dupIdx];

            count = 0;

        }
        return arrayIdx;
    }
};