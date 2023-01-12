#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution 
{
public:
    int romanToInt(string s) 
    {
        map<char, int> romanNum;
        vector<int> stack;
        int last, answer = 0;
        romanNum.insert({ 'I',1});
        romanNum.insert({ 'V',5});
        romanNum.insert({ 'X',10});
        romanNum.insert({ 'L',50});
        romanNum.insert({ 'C',100});
        romanNum.insert({ 'D',500});
        romanNum.insert({ 'M',1000});
        

        for (int i = 0; i < s.size(); ++i)
        {
            stack.push_back(romanNum[s[i]]);
        }
        last = stack.back();
        stack.pop_back();
        while (!stack.empty())
        {
            while (!stack.empty()&&stack.back() < last)
            {
                last -= stack.back();
                stack.pop_back();
            }
            answer += last;
            last = 0;
            if (!stack.empty())
            {
                last = stack.back();
                stack.pop_back();
            }
        }
        answer += last;
        return answer;
    }

};