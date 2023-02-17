#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
   
public: 
   

    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int numsSize = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        set<vector<int>> tmp;
        for (int i = 0; i < numsSize; ++i)
        {
            int leftIdx = i + 1, rightIdx = numsSize - 1;
            while (leftIdx < rightIdx)
            {
                int sum = nums[leftIdx] + nums[rightIdx] + nums[i];
                if (sum == 0)
                {
                    tmp.insert({ nums[i], nums[leftIdx], nums[rightIdx] });
                    --rightIdx;
                    ++leftIdx;
                }
                else if (sum > 0)
                    --rightIdx;
                else
                    ++leftIdx;
            }
        }
        for (auto iter = tmp.begin(); iter != tmp.end(); iter++)
        {
            answer.push_back(*iter);
        }
        
        return answer;
    }
};


int main()
{
    Solution so;
    vector<int> test = { -1,0,1,2,-1,-4 };
    so.threeSum(test);
}