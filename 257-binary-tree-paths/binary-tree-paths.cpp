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
void Solve(TreeNode* root , string Path , vector<string> &ans){
    if(root==NULL) return;
    if(Path==""){
        Path += to_string(root->val);
    }
    else{
        Path += "->" + to_string(root->val);
    }
    if(root->left==NULL && root->right==NULL){
        ans.push_back(Path);
        return ;
    }
    Solve(root->left,Path,ans);
    Solve(root->right,Path,ans);
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        Solve(root , "" , ans);
        return ans;
    }
};