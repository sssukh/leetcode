#include<vector>
using namespace std;

class Solution 
{
public:
    
    int maxArea(vector<int>& height)
    {
        int answer = 0,left = 0,right = height.size()-1;

        while (left < right)
        {
            answer = max(answer, (right - left) * min(height[left], height[right]));
            if (height[left] <= height[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
        return answer;
    }
};