#include<vector>
using namespace std;

class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int size = nums.size();
        vector<int> ans(size);
        ans[0] = 1;
        for (int i =1;i<size;++i)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int pro = 1;
        for (int i = size - 2; i >= 0; --i)
        {
            pro *= nums[i + 1];
            ans[i] = ans[i] * pro;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int>  test = { 1,2,3,4 };
    sol.productExceptSelf(test);
}