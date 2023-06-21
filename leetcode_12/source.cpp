#include<string>
#include <vector>
using namespace std;


class Solution 
{
    vector<int> integers = { 1,5,10,50,100,500,1000 };
    vector<char> roman = { 'I','V','X','L','C','D','M' };
public:
    string intToRoman(int num) 
    {
        string answer = "";
        for (int i = integers.size()-1; i >= 0; --i)
        {
            int count = num / integers[i];
            num = num % integers[i];
            if (count == 4)
            {
                if (answer.back() == roman[i+1])
                {
                    answer.pop_back();
                    answer += roman[i];
                    answer += roman[i+2];
                    
                }
                else
                {
                    answer += roman[i];
                    answer += roman[i+1];
                }
            }
            else
            {
                for (int j = 0; j < count; ++j)
                {
                    answer += roman[i];
                }
            }
           
        }

        return answer;

    }
};


int main()
{
    Solution sol;
    sol.intToRoman(1994);

}