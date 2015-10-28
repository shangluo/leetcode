/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode const* root)
	{
		auto encode = [](TreeNode const *node) -> string
		{
			return node ? to_string(node->val) : "";
		};

		string str = "(";
		str += encode(root);
		if (root && (root->left || root->right))
		{
			str += serialize(root->left);
			str += serialize(root->right);
		}

		return str + ")";
	}

	TreeNode* deserialize(const char * &ptr)
	{
		TreeNode *root = nullptr;
		if (ptr && *ptr == '(')
		{
			++ptr;
			string str = "";
			while (*ptr && (*ptr != '(' && *ptr != ')'))
			{
				str += *ptr++;
			}

			if (!str.empty())
			{
				root = new TreeNode(stoi(str));		
				root->left = deserialize(ptr);	
				root->right = deserialize(ptr);
			}
			if (*ptr == ')')
			{
				++ptr;
			}
		}
		return root;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) 
	{
	    auto ptr = data.c_str();
		return deserialize(ptr);
	}
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));