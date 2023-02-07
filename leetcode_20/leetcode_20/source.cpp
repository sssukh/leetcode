#include<string>
#include <vector>
using namespace std;

class Solution 
{
public:
    bool isValid(string s)
    {
        vector<short> st;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
                st.push_back(1);
            else if (s[i] == '{')
                st.push_back(2);
            else if (s[i] == '[')
                st.push_back(3);
            else if (s[i] == ')')
            {
                if (st.empty() || st.back() != 1)
                    return false;
                else
                    st.pop_back();
            }
            else if (s[i] == '}')
            {
                if (st.empty() || st.back() != 2)
                    return false;
                else
                    st.pop_back();
            }
            else if (s[i] == ']')
            {
                if (st.empty() || st.back() != 3)
                    return false;
                else
                    st.pop_back();
            }
            
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};
