#include <vector>
using namespace std;

class Solution 
{
public:
   
    void rotate(vector<int>& nums, int k)
    {
        int size = nums.size();
        /*vector<int> copy = nums;
        for (int i = 0; i < size; ++i)
        {
            nums[i] = copy[(i - k%size + size) % size];
        }*/

        int modK = k % size;

        reverse(nums.begin(), nums.begin() + (size - modK));
        reverse(nums.begin() + (size-modK), nums.end());
        reverse(nums.begin(), nums.end());
    }
};