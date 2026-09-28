/*
PROBLEM STATEMENT:- 75. Sort Colors
    You are given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
    You must solve this problem without using the library's sort function.


        Example 1:
            Input: nums = [2,0,2,1,1,0]
            Output: [0,0,1,1,2,2]
            Explanation: 
                The array has two 0s, two 1s, and two 2s. Sorting them in-place places all 0s first, then all 1s, then all 2s.

        Example 2:
            Input: nums = [2,0,1]
            Output: [0,1,2]
            Explanation:
                The array has one each of 0, 1, and 2, arranged in-place in the order 0, 1, 2.

        

        Constraints:

            n == nums.length
            1 <= n <= 300
            nums[i] is either 0, 1, or 2.


*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size()-1;

        int i = 0;
        while( i<= high){
            if(nums[i]==0){
                swap(nums[i], nums[low]);
                low++;
                i++;
            }
            else{
                if(nums[i]==2){
                    swap(nums[i], nums[high]);
                    high--;
                }
                else
                    i++;
            }
            
        }
        
    }
};

int main(){

    vector<int> nums = {1,0,2};
    Solution sol;

    cout << "before sorting" << endl;
    for(int i:nums)
        cout << i << " ";

    sol.sortColors(nums);

    cout << endl << "After sorting" << endl;
    for(int i:nums)
        cout << i << " ";


    return 0;
}