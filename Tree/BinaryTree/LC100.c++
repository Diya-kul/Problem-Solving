/*
    PROBLEM STATEMENT: 100. Same Tree

        Given the roots of two binary trees p and q, write a function to check if they are the same or not.

        Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

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

class Solution1 {
public:


    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }

        if(p==NULL || q==NULL)
            return false;

        //check equality here
        if(p->val != q->val)
            return false;
        
        if(!isSameTree(p->left,q->left))
            return false;
        if(!isSameTree(p->right, q->right))
            return false;

        return true; 
    }
};

// It can also be written like this
class Solution2 {
public:


    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }

        if(p==NULL || q==NULL)
            return false;

        //check equality here
        if(p->val != q->val)
            return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};