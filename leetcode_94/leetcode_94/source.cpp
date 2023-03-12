#include <vector>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
 
class Solution
{
public:
    void inorder(vector<int>& visit, TreeNode* current)
    {
        if (current == nullptr)
            return;
        if (current->left != nullptr)
            inorder(visit, current->left);
        visit.push_back(current->val);
        if (current->right != nullptr)
            inorder(visit, current->right);
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> inorderTraversal;
        inorder(inorderTraversal, root);
        return inorderTraversal;
    }
};