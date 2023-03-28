#include<vector>
using namespace std;

class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int mid,start=-1,end=-1, left = 0, right = nums.size() - 1;
        if (nums.size() == 0)
            return { -1,-1 };
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
            { 
                start = mid;
                right = mid - 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                end = mid;
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return { start,end };
    }
};

int main()
{
    Solution sol;
    vector<int> test = { 1 };
    sol.searchRange(test,1);
}