#include <iostream>
using namespace std;
class Solution
{
public:
    double myPow(double x, int n) 
    {
        if (n == 0)
            return 1;
        int absoluteN = abs(n);
       /* if (n < 0)
            absoluteN = -n;*/

        double tmp = myPow(x, absoluteN / 2);
        double answer;
        if (absoluteN % 2)
        {   
            answer = tmp * tmp * x;
        }
        else
        {
            answer = tmp * tmp;
        }

        if (n < 0)
            return 1 / answer;
        else
            return answer;

    }
};

int main()
{
    cout << "Int Min : " << (INT_MIN) << "\nInt Min abs : " << abs(INT_MIN)<<"\nInt max :  "<<INT_MAX;
}