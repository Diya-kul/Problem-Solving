/*
    PROBLEM STATEMENT:- 101. Symmetric Tree

        Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/

# include <bits/stdc++.h>
using namespace std;



// Definition for a binary tree node.
 struct TreeNode {
     int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:

    bool isMirror(TreeNode* t1, TreeNode* t2){

        // if both are null
        if(t1 == NULL && t2 == NULL)
            return true;

        // if one become null
        if(t1 ==NULL || t2 == NULL)
            return false;

        // if the have different values
        if(t1->val != t2->val)
            return false;

        if(!isMirror(t1->left, t2->right) || !isMirror(t1->right, t2->left))
            return false;
        
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root== nullptr)
            return true;

        return isMirror(root->left, root->right);
    }
};

