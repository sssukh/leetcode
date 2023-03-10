#include <vector>
#include <queue>
using namespace std;


class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int idx2 = 0, backIdx = m;
        queue<int> tmp;
        if (n == 0)
            return;
        if (m == 0)
        {
            nums1 = nums2;
            return;
        }
        for (int idx1 = 0; idx1 < m; ++idx1)
        {
            
            
                if (tmp.empty()&&nums1[idx1]>nums2[idx2])
                {
                    tmp.push(nums1[idx1]);
                    nums1[idx1] = nums2[idx2++];
                    continue;
                }
                if (idx2 >= n)
                {
                    tmp.push(nums1[idx1]);
                    nums1[idx1] = tmp.front();
                    tmp.pop();
                    continue;
                }
                tmp.push(nums1[idx1]);
                if (tmp.front() < nums2[idx2])
                {
                    nums1[idx1] = tmp.front();
                    tmp.pop();
                }
                else
                {
                    nums1[idx1] = nums2[idx2];
                    ++idx2;
                }
            
        }
        for (int idx1 = m; idx1 < m + n; ++idx1)
        {
                if (tmp.empty())
                {
                    nums1[idx1] = nums2[idx2++];
                    continue;
                }
                if (idx2 >= n)
                {
                    nums1[idx1] = tmp.front();
                    tmp.pop();
                    continue;
                }
                if (tmp.front() < nums2[idx2])
                {
                    nums1[idx1] = tmp.front();
                    tmp.pop();
                }
                else
                {
                    nums1[idx1] = nums2[idx2];
                    ++idx2;
                }
            
        }

        
    }
    
};

int main()
{
    Solution sol;
    vector<int> tmp1 = {0};
    vector<int> tmp2 = { 1 };
    sol.merge(tmp1, tmp1.size() - tmp2.size(), tmp2, tmp2.size());
}