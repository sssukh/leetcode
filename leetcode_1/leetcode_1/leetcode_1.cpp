#include<iostream>
#include<vector>
#include<algorithm>
#include <set>
using namespace std;


class Solution {
public:
    struct cmp
    {
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            return a.first < b.first;
        }
    };

    vector<int> twoSum(vector<int>& nums, int target)
    {
        int left, right;
        left = 0;
        right = nums.size() - 1;
        vector<pair<int, int>> numPairs;
        for (int i = 0; i < nums.size(); ++i)
        {
            numPairs.push_back({ nums[i],i });
        }
        sort(numPairs.begin(), numPairs.end(), cmp());
        while (true)
        {
            int result = numPairs[left].first + numPairs[right].first;
            if (result < target)
            {
                ++left;
            }
            else if (result > target)
            {
                --right;
            }
            else
            {
                return { numPairs[left].second,numPairs[right].second };
            }
        }

    }
};