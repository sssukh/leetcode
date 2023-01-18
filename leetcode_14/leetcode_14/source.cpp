#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i)
        {
            int minSize = min(prefix.size(), strs[i].size());
            int prefixSize = minSize;
            for (int j = minSize; j >= 0; --j)
            {
                if (prefix[j] != strs[i][j])
                    prefixSize = j;
            }
            prefix.resize(prefixSize);
        }
        return prefix;
    }
};