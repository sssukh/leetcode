#include<vector>
#include<string>
using namespace std;

class Solution 
{
public:
    void addLetterCombination(string letters, string digits,
        int index,vector<string>& answer,vector<string>& letterMap)
    {
        if (letters.size() == digits.size())
        {
            answer.push_back(letters);
            return;
        }
        for (char a : letterMap[digits[index] - '0'])
            addLetterCombination(letters + a, digits, index + 1, answer, letterMap);
    }
    vector<string> letterCombinations(string digits) 
    {
        if (digits == "")
            return {};
        vector<string> letterMap = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
        vector<string> answer;
        addLetterCombination("", digits, 0, answer, letterMap);
        return answer;
    }
};