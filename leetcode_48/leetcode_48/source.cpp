#include<vector>
using namespace std;


// x,y -> y, n - x
class Solution 
{
public:
    void change(vector<vector<int>>& matrix, int row, int col, vector<vector<bool>>& hasChanged, int num)
    {
        if (hasChanged[row][col])
            return;
        int tmp = matrix[row][col];
        matrix[row][col] = num;
        hasChanged[row][col] = true;
        change(matrix, col, matrix.size() - 1 - row, hasChanged, tmp);
    }

    void rotate(vector<vector<int>>& matrix)
    {
        int size = matrix.size();
        vector<vector<bool>> hasChanged(size, vector<bool>(size, 0));
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if(!hasChanged[i][j])
                change(matrix, j, size - 1 - i, hasChanged, matrix[i][j]);
            }
        }
    }
};