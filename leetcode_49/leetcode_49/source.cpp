#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> answer;
        unordered_map < string, vector<string>> hash;
        int size = strs.size();
        for (int i = 0; i < size; ++i)
        {
            string tempStr = strs[i];
            sort(strs[i].begin(),strs[i].end());
            hash[strs[i]].push_back(tempStr);
        }
        for (auto iter = hash.begin(); iter != hash.end(); iter++)
        {
            answer.push_back(iter->second);
        }

        return answer;
    }
};