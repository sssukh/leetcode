#include<vector>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {

        int n = gas.size();
        int accu = 0;
        int curGas = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            accu += gas[i] - cost[i];
            curGas += gas[i] - cost[i];
            if (curGas < 0)
            {
                ans = i + 1;
                curGas = 0;
            }
        }
        if (accu < 0)
            return-1;
        else
            return ans;

    }

};

int main()
{

}