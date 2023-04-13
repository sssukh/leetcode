#include <vector>
using namespace std;

class Solution 
{
public:
    void addSubsets(vector<int>& nums, int qty, int idx, vector<int>& visited,vector<vector<int>>& answer)
    {
        if (visited.size() == qty)
        {
            vector<int> tmp;
            for (int i = 0; i < visited.size(); ++i)
                tmp.push_back(visited[i]);
            answer.push_back(tmp);
            return;
        }
        if (idx >= nums.size())
            return;
        for (int i = idx; i < nums.size(); ++i)
        {
            visited.push_back(nums[i]);
            addSubsets(nums, qty, i + 1, visited, answer);
            visited.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> answer;
        vector<int> visited;
        for (int qty = 0; qty <= nums.size(); ++qty)
        {
           
            addSubsets(nums, qty, 0,  visited, answer);
        }

        return answer;
    }
};

int main()
{
    Solution sol;
    vector<int> tmp = { 1,2,3 };
    sol.subsets(tmp);
}