#include <vector>
#include <unordered_set>
using namespace std;

class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        //unordered_set<int> zeroRows;
        unordered_set<int> zeroCols;
        vector<int> zeros(matrix[0].size(), 0);
       
        for (int i = 0; i < matrix.size(); ++i)
        {
            bool isZeroRow = false;
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    isZeroRow = true;
                    //zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
            if (isZeroRow)
                matrix[i] = zeros;
        }
        //for (auto iter : zeroRows)
        //{
        //    /*for (int cols = 0; cols < matrix[0].size(); ++cols)
        //    {
        //        matrix[iter][cols] = 0;
        //    }*/
        //    matrix[iter] = zeros;
        //}
        for (auto iter : zeroCols)
        {
            for (int rows = 0; rows < matrix.size(); ++rows)
            {
                matrix[rows][iter] = 0;
            }
        }
    }
};