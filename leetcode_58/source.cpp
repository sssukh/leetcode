#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int answer = 0;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] != ' ')
                ++answer;
            else if (answer > 0)
                break;
        }
        return answer;
    }
};