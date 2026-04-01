/*
    930. Binary Subarrays With Sum
    
        Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

        A subarray is a contiguous part of the array.

            Example 1:
                Input: nums = [1,0,1,0,1], goal = 2
                Output: 4
                Explanation: The 4 subarrays are bolded and underlined below:
                [1,0,1,0,1]
                [1,0,1,0,1]
                [1,0,1,0,1]
                [1,0,1,0,1]

            Example 2:
                Input: nums = [0,0,0,0,0], goal = 0
                Output: 15
            

            Constraints:
                1 <= nums.length <= 3 * 104
                nums[i] is either 0 or 1.
                0 <= goal <= nums.length
*/

/*
    APPROACH:
        prefixSum + hashMap
    COMPLEXITY:
        Time=O(n)
        Space=O(1)
    OUTPUT:
        no. of non-empty subarray whose sum equal to goal
*/

# include <bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal)
{
    int prefixSum=0, count=0;
    unordered_map<int, int> mp;

    mp[0]=1;
    for(int left=0, right=0; right<nums.size(); right++)
    {
        prefixSum+=nums[right];

        int need = prefixSum-goal;

        if( mp.find(need)!=mp.end())
            count+=mp[need];
        
        mp[prefixSum]++;
    }

    return count;
}

int main()
{
    vector<int> nums={1,0,1,0,1};
    int goal=2;

    cout << numSubarraysWithSum(nums,goal);
    return 0;
}