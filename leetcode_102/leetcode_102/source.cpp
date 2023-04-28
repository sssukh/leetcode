#include <vector>
using namespace std;


  struct TreeNode
  {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    void levelOrderTraversal(TreeNode* curNode, int level,vector<vector<int>>& answer)
    {
        if (curNode == nullptr)
            return;
        while (level >= answer.size())
        {
            vector<int> tmp;
            answer.push_back(tmp);
        }
        answer[level].push_back(curNode->val);
        levelOrderTraversal(curNode->left, level + 1, answer);
        levelOrderTraversal(curNode->right, level + 1, answer);
    }
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> answer;
        levelOrderTraversal(root, 0, answer);
        return answer;
    }
};