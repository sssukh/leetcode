#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool comp(vector<int> a, vector<int> b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    void swap(vector<int>& a, vector<int>& b)
    {
        vector<int> temp = a;
        a = b;
        b = temp;
    }
    void mSort(vector<vector<int>>& intervals, int left, int right)
    {
        if (left >= right)
            return;
       

        int i = left, j = right;
        int pivot = left;
        while (i < j)
        {
            while (comp(intervals[i], intervals[pivot]))
            {
                ++i;
            }
            while (i<j && comp(intervals[pivot], intervals[j]))
            {
                --j;
            }
            swap(intervals[i], intervals[j]);
            if (intervals[i] == intervals[j])
                --j;
        }
        swap(intervals[left], intervals[i]);

        mSort(intervals, left, i - 1);
        mSort(intervals, i + 1, right);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> answer;
        //mSort(intervals, 0, intervals.size()-1);
        sort(intervals.begin(), intervals.end());
        for (auto tmp : intervals)
        {
           
            if (!answer.empty()&&answer.back()[1] >= tmp[0] && answer.back()[0] <= tmp[1])
            {
                int  end;
                if (answer.back()[1] <= tmp[1])
                    end = tmp[1];
                else
                    end = answer.back()[1];

                answer.back()[1] = end;
                
            }
            else
                answer.push_back(tmp);
        }

        return answer;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> test = { {4,5},{6,7},{8,9},{1,10} };
    vector<vector<int>> test1 = { {2,3} ,{5,5},{2,2},{3,4},{3,4} };
    sol.merge(test1);
}