#include <string>
#include <vector>
using namespace std;


class Solution 
{
    // aab
    // aaa
public:
    vector<int> getFunc(string tmp)
    {
        vector<int> func(tmp.size(),0);
        int i = 1, j = 0;
        while (i < tmp.length())
        {
            if (tmp[i] == tmp[j])
            {
                func[i] = ++j;
                ++i;
            }
            else if (j > 0)
            {
                j = func[j - 1];
            }
            else
            {
                func[i] = 0;
                ++i;
            }
        }
        return func;
    }
    int strStr(string haystack, string needle) 
    {
        vector<int> func = getFunc(needle);

        int i = 0, j = 0;
        while(i<haystack.size())
        {
            if (haystack[i] == needle[j])
            {
                ++j;
                ++i;
                if (j == needle.length())
                    return i - j;
            }
            else
            {
                if (j > 0)
                    j = func[j - 1];
                else
                    ++i;
            }
        }
        return -1;
    }
};