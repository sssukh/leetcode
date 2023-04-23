#include<vector>
using namespace std;

class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> answer;
        int rowIdx = 0, colIdx = 0, rowAdd = 1, colAdd = 1,count=0;
        bool AddtoRow = false;
        while (count<2)
        {
            if (rowIdx == matrix.size() || rowIdx<0)
            {
                if (rowIdx == matrix.size())
                {
                    rowIdx = matrix.size() - 1;
                }
                else if (rowIdx < 0)
                {
                    rowIdx = 0;
                }
                AddtoRow = false;
                rowAdd = -rowAdd;
                ++count;
            }
            else if (colIdx == matrix[0].size() || colIdx<0)
            {
                if (colIdx == matrix[0].size())
                {
                    colIdx = matrix[0].size() - 1;
                }
                else if (colIdx < 0)
                {
                    colIdx = 0;
                }
                AddtoRow = true;
                colAdd = -colAdd;
                ++count;
            }
            else if (matrix[rowIdx][colIdx] == -101)
            {
                if (AddtoRow)
                {
                    AddtoRow = false;
                    rowAdd = -rowAdd;
                    rowIdx += rowAdd;
                }
                else
                {
                    AddtoRow = true;
                    colAdd = -colAdd;
                    colIdx += colAdd;
                }
                ++count;
            }
            else
            {
                answer.push_back(matrix[rowIdx][colIdx]);
                matrix[rowIdx][colIdx] = -101;
                count = 0;
            }
            if (AddtoRow)
            {
                rowIdx += rowAdd;
            }
            else
            {
                colIdx += colAdd;
            }
         } 
        return answer;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> tmp = { {1,2,3},{4,5,6},{7,8,9} };
    sol.spiralOrder(tmp);
}