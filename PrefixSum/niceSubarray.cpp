/*
    LC 1248- Count Number of Nice Subarrays

        Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

        Return the number of nice sub-arrays.

        Example 1:
            Input: nums = [1,1,2,1,1], k = 3
            Output: 2
            Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
        
        Example 2:
            Input: nums = [2,4,6], k = 1
            Output: 0
            Explanation: There are no odd numbers in the array.

        Example 3:
            Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
            Output: 16
*/

/*
    APPROACH: 
            subarray that contain exactly K odd no.
            Sliding window (at most K)
            track the count of odd no.
            exactly(k)= atmost(K)-atmost(K-1)
    Complexity:
            Time: O(n) 
            Space: O(1)
    OUTPUT:
            Count of subarray that contains exactly k odd numbers.
*/

# include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int atMost( vector<int>& nums, int k)
    {
        int oddCount=0, subCount=0;
        for(int left=0, right=0; right<nums.size(); right++)
        {
            //tracking count of add no. in the window
            if(nums[right]%2!=0)
            {
                oddCount++;
            }

            //shrinking the window
            while(oddCount>k)
            {
                if(nums[left]%2!=0)
                    oddCount--;
                left++;
            }
            subCount+= right-left+1;
        }
        return subCount;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
};

int main()
{
    vector <int> nums ={2,2,2,1,2,2,1,2,2,2};
    int k=2;

    Solution sol;
    cout << sol.numberOfSubarrays(nums,k);

    return 0;
}