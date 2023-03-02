#include<string>
using namespace std;

class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int leng = s.length();
        string answer="";
        for (int i = 0; i < leng; ++i)
        {
            int offset = 0;
            // odd length Palindrome
            while (i - offset >= 0 && i + offset < leng && s[i - offset] == s[i + offset])
            {
                if(answer.length()<2*offset + 1)
                    answer = s.substr(i - offset, 2 * offset + 1);
                ++offset;
            }
            offset = 0;
            // even length Palindrome - 1
            while (i - offset >= 0 && i + offset + 1< leng && s[i - offset] == s[i + offset + 1])
            {
                if (answer.length() < 2 * offset + 2)
                    answer = s.substr(i - offset, 2 * offset + 2);
                ++offset;
            }
            offset = 0;
            // even length Palindrome - 2
            while (i - offset - 1 >= 0 && i + offset < leng && s[i - offset - 1] == s[i + offset])
            {
                if (answer.length() < 2 * offset + 2)
                    answer = s.substr(i - offset - 1, 2 * offset + 2);
                ++offset;
            }
        }

        return answer;
    }
};


int main()
{
    Solution sol;
    sol.longestPalindrome("babad");
}