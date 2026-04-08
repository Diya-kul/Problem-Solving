/*
PROBLEM STATEMENT:-
    LC: 1991. Find the Middle Index in Array

    Given a 0-indexed integer array nums, find the leftmost middleIndex (i.e., the smallest amongst all the possible ones).

    A middleIndex is an index where nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1].

    If middleIndex == 0, the left side sum is considered to be 0. Similarly, if middleIndex == nums.length - 1, the right side sum is considered to be 0.

    Return the leftmost middleIndex that satisfies the condition, or -1 if there is no such index.

    

    Example 1:
        Input: nums = [2,3,-1,8,4]
        Output: 3
        Explanation: The sum of the numbers before index 3 is: 2 + 3 + -1 = 4
                 The sum of the numbers after index 3 is: 4 = 4
  
    Example 2:
        Input: nums = [1,-1,4]
        Output: 2
        Explanation: The sum of the numbers before index 2 is: 1 + -1 = 0
                    The sum of the numbers after index 2 is: 0
  
    Example 3:
        Input: nums = [2,5]
        Output: -1
        Explanation: There is no valid middleIndex.
        

    Constraints:
        1 <= nums.length <= 100
        -1000 <= nums[i] <= 1000
*/


/*
    APPROCH:-
            prefixSum array
            set prefix[0]=0
        Time Complexity = O(n)
        Space Complexity = O(1)
*/

# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();

        int prefix[n+1];
        prefix[0]=0;
        for(int i=0; i<n;i++)
        {
            prefix[i+1]=nums[i]+prefix[i];
        }

        for(int i=0; i<n; i++){
            if(prefix[i] == prefix[n]-prefix[i+1])
                return i;
        }
        
        return -1;

    }
};

int main(){
    vector<int> nums={1,-1,4};

    Solution sol;
    cout << sol.findMiddleIndex(nums); 
    return 0;
}