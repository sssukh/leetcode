#include<vector>
using namespace std;

class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        // index �ΰ� ����
        // �ϳ��� �ߺ������� array�� ������ index, �ٸ� �ϳ��� ���� ���� ã�� index

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