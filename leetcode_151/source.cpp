#include <string>
#include <vector>
using namespace std;

class Solution 
{
public:
    string reverseWords(string s) 
    {
        vector<string> words;
        string tmp = "";
        for (char c : s)
        {
            if (c == ' '&&!tmp.empty())
            {
                words.push_back(tmp);
                tmp = "";
            }
            else if(c != ' ')
            {
                tmp += c;
            }

            

        }
        if (!tmp.empty())
            words.push_back(tmp);

        string answer = words.back();
        for (int i = words.size() - 2; i >= 0; --i)
        {
            answer += ' ';
            answer += words[i];
        }
        return answer;
    }
};