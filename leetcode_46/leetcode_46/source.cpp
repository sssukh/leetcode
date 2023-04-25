#include<vector>
using namespace std;

class Solution
{
public:
    void perm(vector<int>& nums, vector<bool>& visited,vector<vector<int>>& answer,vector<int>& tmp)
    {
        if (tmp.size() == nums.size())
        {
            answer.push_back(tmp);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!visited[i])
            {
                tmp.push_back(nums[i]);
                visited[i] = true;
                perm(nums, visited, answer, tmp);
                tmp.pop_back();
                visited[i] = false;
            }
        }
            
        
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> answer;
        vector<bool> visited(nums.size(),0);
        vector<int> tmp;
        perm(nums, visited, answer, tmp);

        return answer;
    }
};