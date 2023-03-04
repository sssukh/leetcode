#include <iostream>
using namespace std;

class Solution 
{
public:
    int mySqrt(int x) 
    {
        unsigned int current=x,left = 0, right = x;

        while (right-left>1)
        {
            current = (left + right) / 2;
            int temp = current * current;
            
            if (temp<0||temp/current < current || temp > x)
            {
                right = current;
            }
            else if (temp < x)
            {
                left = current;
            }
            else if (temp == x)
                break;
        }

        if (current * current > x)
            current -= 1;

        return current;
    }
};


int main()
{
    Solution sol;
    sol.mySqrt(2147395599);
}