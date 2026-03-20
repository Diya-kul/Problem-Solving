LeetCode: 47. Permutations II
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
Example :
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]


  Approach: To handle duplicates we sort the array first and then skip duplicates during the backtracking process.
  This prevents the duplicate permutations from ever being generated in the first place.


solution:
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
            if (used[i] || (i > 0 && num[i] == num[i-1] && !used[i-1])) {
                continue;
            }

            used[i] = true;
            temp.push_back(num[i]);
            
            logic(num, temp, used, ans);

            // Backtrack
            temp.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        
       
       sort(nums.begin(), nums.end());
       logic(nums,temp,used,ans);

       return ans;
    
    }
};
