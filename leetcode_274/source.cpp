#include<vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    int hIndex(vector<int>& citations)
    {
        /*int mx = 0;
        int ans = 0;
        vector<int> cita(1001, 0);
        for (int citation : citations)
        {
            ++cita[citation];
            mx = max(mx, citation);
        }
        for (int i = mx; ans<=i; --i)
        {
            cita[i] += cita[i + 1];
            ans = max(ans, min(cita[i], i));
        }

        return ans;*/


        //sort(citations.begin(), citations.end());
        //int count = 0,size= citations.size(), ans=0 ;
        //for (int i = size - 1; i >= 0; --i)
        //{
        //    if (ans >= citations[i])
        //        return ans;
        //    ++count;
        //    // size - i = 논문 수, citations[i]에는 인용 수
        //     ans =  min(citations[i], count);
        //     
        //     if (++count >= citations[i])
        //         return min(count,citations[i]);
        //}

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

int main()
{
    Solution sol;
    vector<int> test = { 3,0,6,1,5 };
    sol.hIndex(test);
}