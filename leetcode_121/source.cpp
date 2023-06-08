#include<vector>
using namespace std;

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int size = prices.size(),ans=0, buy=INT_MAX,sell=INT_MAX;

        for (int i = 0; i < size; ++i)
        {
            if (prices[i] < buy)
            {
                ans = max(ans, sell - buy);
                buy = sell = prices[i];
            }
            else if (prices[i] > sell)
                sell = prices[i];
        }

        ans = max(ans, sell - buy);

        return ans;
    }
};