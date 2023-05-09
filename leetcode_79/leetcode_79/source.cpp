#include<vector>
#include <queue>
#include <string>
using namespace std;

class Solution 
{
public:
    void search(vector<vector<char>>& board, int idx, int row, int col, string word, vector<vector<bool>>& visit, bool& answer)
    {
        if (idx == word.size())
        {
            answer = true;
            return;
        }
        if (row>=board.size()||col>=board[0].size()||row<0||col<0||visit[row][col])
            return ;
        if (board[row][col] == word[idx])
        {
            visit[row][col] = true;
            search(board, idx + 1, row + 1, col, word, visit,answer);
            search(board, idx + 1, row - 1, col, word, visit,answer);
            search(board, idx + 1, row, col + 1, word, visit,answer);
            search(board, idx + 1, row, col - 1, word, visit,answer);
            visit[row][col] = false;
        }
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        bool answer=false;
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == word[0])
                {
                    vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(),0));
                    search(board, 0, i, j, word, visit,answer);
                    if (answer)
                        return  true;
                }
            }
        }
        return false;

      
    }
};