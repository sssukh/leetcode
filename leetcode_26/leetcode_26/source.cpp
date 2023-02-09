#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int tmp = -101;
        int searchIdx = 0;
        int length = nums.size();
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] <= tmp)
            {
                // wrong
                while (nums[searchIdx] <= tmp)
                {
                    ++searchIdx;
                    if (searchIdx >= length)
                        return length - (searchIdx - i);
                }
                nums[i] = nums[searchIdx];
                tmp = nums[i];
            }
            else
            {
                // right
                tmp = nums[i];
            }
        }
        

        return nums.size()
    }
};