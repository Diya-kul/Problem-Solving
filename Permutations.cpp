/*
LeetCode Problem:  46. Permutations
       Level: Medium 
       Topics: Array, Backtracking
  
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
*/

//Solution:
/*
  Time complexity: O(n!)
  Space complexity: O(n)
  Approach: a classic backtracking solution
*/

#include <bits/stdc++.h>

using namespace std;
class Solution {
private:
    void logic( vector<int>& num, vector<int>& temp, vector<bool>& used, vector<vector<int>>& ans)
    {
        //base case
        if(temp.size() == num.size())
        {
            ans.push_back(temp);
            return;
        }

        for(int i=0; i< num.size(); i++)
        {
            if(!used[i])
            {
                temp.push_back(num[i]);
                used[i]=true;
                logic(num,temp,used,ans);
                //Backtrack
                temp.pop_back();
                used[i]=false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
       vector<int> temp;
       vector<bool> used(nums.size(), false);
       vector<vector<int>> ans;

       logic(nums,temp,used,ans);

       return ans;
    }
};
