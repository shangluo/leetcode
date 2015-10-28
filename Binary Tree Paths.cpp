/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string appendValue(string orig, int val)
    {
        if (!orig.empty())
        {
            return orig + "->" + to_string(val);
        }
        
        return to_string(val);
    }

    void midTrans(TreeNode *root, string path, vector<string> &res){
        if (root)
        {
            if (!root->left && !root->right)
            {
                res.push_back(appendValue(path, root->val));
            }
            
            if (root->left)
            {
                midTrans(root->left, appendValue(path, root->val), res);
            }
            
            if (root->right)
            {
                midTrans(root->right, appendValue(path, root->val), res);
            }
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        midTrans(root, "", res);
        return res;
    }
};
