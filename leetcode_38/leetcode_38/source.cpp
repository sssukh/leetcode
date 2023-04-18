#include <string>
using namespace std;

class Solution 
{
public:
    string countAndSay(int n) 
    {
        if (n == 1)
            return "1";
        string say = countAndSay(n - 1);
        string ret = "";
        char tmp = say[0];
        int idx = 1;
        int count = 1;
        while (idx < say.length())
        {
            if (tmp == say[idx])
            {
                ++count;
            }
            else
            {
                ret += to_string(count) + tmp;
                count = 1;
                tmp = say[idx];
            }
            ++idx;
        }
        ret += to_string(count) + tmp;
        return ret;
    }
};