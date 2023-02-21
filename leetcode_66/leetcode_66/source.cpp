#include<vector>
using namespace std;

class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        ++digits.back();
        for (int idx = digits.size() - 1; idx > 0; --idx)
        {
            if (digits[idx] >= 10)
            {
                digits[idx] -= 10;
                ++digits[idx - 1];
            }
        }
        if (digits.front() >= 10)
        {
            digits.front() -= 10;
            vector<int> addDigit{ 1 };
            addDigit.insert(addDigit.end(), digits.begin(), digits.end());
            return addDigit;
        }
        return digits;
    }
};

int main()
{
    Solution sol;
    vector<int> tmp{ 9,9,9,9 };
    sol.plusOne(tmp);
}