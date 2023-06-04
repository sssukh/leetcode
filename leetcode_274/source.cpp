#include<vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int>& citations)
    {
        sort(citations.begin(), citations.end());
        int count = 1, size = citations.size(), ans = 0;
        for (int i = size - 1; i >= 0; --i)
        {
            if (count > citations[i])
                return count - 1;
            ++count;
        }
        return size;
    }
};