#include <vector>
using namespace std;

class Solution 
{
public:
  
    void sortColors(vector<int>& nums) 
    {

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] > nums[j + 1])
                {
                    int tmp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = tmp;
                }
            }
        }
    }
};