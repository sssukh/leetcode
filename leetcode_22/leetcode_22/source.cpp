#include <vector>
#include <string>
using namespace std;


class Solution 
{
public:
    void operateCombination(vector<string>& answer,vector<bool>& parenthesis, int index,int count,int max)
    {
        if (index == parenthesis.size())
            return;
        if (max == count)
        {
            string tmp;
            short check=0;
            for (int i = 0; i < parenthesis.size(); ++i)
            {
                if (parenthesis[i])
                {
                    ++check;
                    tmp += '(';
                }
                else
                {
                    --check;
                    tmp += ')';
                }
                if (check < 0)
                    return;
            }
            answer.push_back(tmp);
            return;
        }
        parenthesis[index] = true;
        operateCombination(answer, parenthesis, index + 1, ++count, max);
        parenthesis[index] = false;
        operateCombination(answer, parenthesis, index + 1, --count, max);
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> answer;
        vector<bool> checkParenthesis(2*n, 0);
        operateCombination(answer, checkParenthesis, 0, 0, n);

        return answer;
    }
};