/*
    PROBLEM STATEMENT: 404. Sum of Left Leaves

Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

*/


# include <bits/stdc++.h>
using namespace std;

//l  Definition for a binary tree node.
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
    int sum(TreeNode* root, bool isLeft){
        // for empty tree
        if(root == NULL)
            return 0;

        // for leaf node
        if(root->left==NULL && root->right==NULL)
            return (isLeft==true)?root->val:0;

        int leftSum = sum(root->left, true);
        int rightSum = sum(root->right, false);

        return leftSum + rightSum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return sum(root, false);        
    }
};

int main(){
    return 0;
}