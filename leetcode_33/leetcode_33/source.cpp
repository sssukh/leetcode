#include <vector>
using namespace std;

class Solution
{
public:

    void binarySearchRotation(vector<int>& nums, int target, int leftIdx, int rightIdx, int& answer)
    {
        if (answer != -1)
            return;
        if (nums[leftIdx] <= nums[rightIdx])
        {
            if (nums[leftIdx] <= target && target <= nums[rightIdx])
            {
                int mid;
                while (leftIdx <= rightIdx)
                {
                    mid = (leftIdx + rightIdx) / 2;
                    if (nums[mid] == target)
                    {
                        answer = mid;
                        return;
                    }
                    else if (nums[mid] < target)
                    {
                        leftIdx = mid+1;
                    }
                    else
                    {
                        rightIdx = mid-1;
                    }
                }

            }
        }
        else
        {
            int mid = (leftIdx + rightIdx) / 2;
            binarySearchRotation(nums, target, leftIdx, mid,answer);
            binarySearchRotation(nums, target, mid+1, rightIdx,answer);
        }
    }

    int search(vector<int>& nums, int target) 
    {
        int answer=-1, left = 0, right = nums.size() - 1;

        binarySearchRotation(nums, target, left, right, answer);

        return answer;
    }
};


int main()
{
    Solution sol;
    vector<int> test{ 1,3 };
    sol.search(test, 2);
}