/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 1) return new TreeNode(preorder[0]);
        vector<int> preL, preR, inL, inR;
        // preL.reserve(preorder.size()-1);
        // preR.reserve(preorder.size()-1);
        // inL.reserve(preorder.size()-1);
        // inR.reserve(preorder.size()-1);
        int i;
        for (i=0; inorder[i] != preorder[0]; ++i)
        {
            printf("%d ", inorder[i]);
            inL.push_back(inorder[i]);
            preL.push_back(inorder[i+1]);
        }
        int val = preorder[i++]; // remove subtree root
        for (; i<inorder.size(); ++i)
        {
            printf("%d ", inorder[i]);
            inR.push_back(inorder[i]);
            preR.push_back(inorder[i]);
        }
        for (int j=0; j<preL.size(); ++j) printf("%d %d\n", preL[i], inL[i]); printf("\n");
        for (int j=0; j<preL.size(); ++j) printf("%d %d\n", preR[i], inR[i]); printf("\n");
        // return new TreeNode(val, buildTree(preL, inL), buildTree(preR, inR));
        return new TreeNode(val);
    }
};


