/*
    1493. Longest Subarray of 1's After Deleting One Element
    
        Given a binary array nums, you should delete one element from it.

        Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

        Example 1:
            Input: nums = [1,1,0,1]
            Output: 3
            Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

        Example 2:
            Input: nums = [0,1,1,1,0,1,1,0,1]
            Output: 5
            Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
        
        Example 3:
            Input: nums = [1,1,1]
            Output: 2
            Explanation: You must delete one element.
        

        Constraints:

            1 <= nums.length <= 105
            nums[i] is either 0 or 1.
*/
// Solution

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(nums.size()==0) return 0;

        int zeroCount=0, ans=0;
        for(int left=0, right=0; right<nums.size(); right++)
        {
            if(nums[right]==0)
                zeroCount++;
            //shrink
            while(zeroCount > 1)
            {
                if( nums[left]==0)
                    zeroCount--;
                left++;
            }

            //update answer
            ans=max(right-left+1-zeroCount, ans);
        }

        return (zeroCount==0)? ans-1:ans;
    }
};