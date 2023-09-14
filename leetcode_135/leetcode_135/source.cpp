#include<vector>
using namespace std;

class Solution
{
public:
    int candy(vector<int>& ratings)
    {
        int vecSize = ratings.size(), upCount=0, downCount=0, peak=0, total=0;
        for (int i = 1; i < vecSize; ++i)
        {
            if (ratings[i - 1] < ratings[i])
            {
                upCount += 1;
                peak = upCount + 1;
                total += upCount;
                downCount = 0;
            }
            else if (ratings[i - 1] > ratings[i])
            {
                downCount += 1;
                total += downCount - (peak>downCount);
                upCount = 0;
            }
            else
            {
                peak = 0;
                upCount = 0;
                downCount = 0;
            }
        }

        return total + vecSize;
    }
};

// 1 2 2 1 2
// 1 2 1 1 2 