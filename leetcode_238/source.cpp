#include<vector>
using namespace std;

class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int size = nums.size();
        vector<int> numsright(size);
        vector<int> numsleft(size);
        vector<int> ans(size);
        int pro = 1;
        for (int i = size - 1; i >= 0; --i)
        {
            pro *= nums[i];
            numsleft[i] = pro;
        }
        ans[0] = numsleft[1];
        int left = 1;
        for (int i = 1; i < size; ++i)
        {
            left *= nums[i-1];
            
            int right;
            if (i + 1 >= size)
                right = 1;
            else
                right = numsleft[i + 1];

            ans[i] = left * right;
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