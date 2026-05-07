/*
    PROBLEM:- 523. Continuous Subarray Sum

        Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

        A good subarray is a subarray where:

        its length is at least two, and
        the sum of the elements of the subarray is a multiple of k.
        Note that:

        A subarray is a contiguous part of the array.
        An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

        Example 1:
            Input: nums = [23,2,4,6,7], k = 6
            Output: true
            Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

        Example 2:
            Input: nums = [23,2,6,4,7], k = 6
            Output: true
            Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
            42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.

        Example 3:
            Input: nums = [23,2,6,4,7], k = 13
            Output: false
        

        Constraints:
            1 <= nums.length <= 105
            0 <= nums[i] <= 109
            0 <= sum(nums[i]) <= 231 - 1
            1 <= k <= 231 - 1

            
*/

# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        
        // remainder 0 seen at index -1
        mp[0] = -1;

        int prefixSum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];

            int rem = prefixSum % k;

            // handle negative remainder
            if(rem < 0)
                rem += k;

            // if same remainder seen before
            if(mp.find(rem) != mp.end())
            {
                // subarray size must be >= 2
                if(i - mp[rem] >= 2)
                    return true;
            }
            else
            {
                // store first occurrence only
                mp[rem] = i;
            }
        }

        return false;
    }
};


int main() {
    vector<int> nums = {23,2,6,4,7};
    int k=13;
    Solution sol;
    cout << sol.checkSubarraySum(nums,k);

    return 0;
}