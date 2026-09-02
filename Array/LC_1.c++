/*
  PROBLEM STATEMENT: Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example :
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

/*
  INPUT:-
      + nums (array)
      + target (int)
  
    nums[i] + nums[j] == target

  OUTPUT:- return i,j

  BRUTE FORCE APPROACH:
    - check every posible pair
    - like bobule sort comparing each pair
    - time complexity O(n x n)

  
  PATTERN: Complement + Hashing

  APROACH:
    -Instead of checking every pair: "Let's search for the complement."
    - complement = target - current_number
    - unordered map is used to keep track of complements unordered_map<int, int> mp;
    - map stores number -> index, mp[nums[i]] = i;
    - check if complement exist ? if (mp.find(complement) != mp.end())
    - mp[complement] return the index of complement 
    - check first the complement inside map then insert if not exist.
    - time complexity: O(n)
    - space complexity: O(n)

  ALGO:
    1. Current number lo
    2. Complement nikalo
          target - current
    3. Hash Map me complement check karo
    4. Mil gaya?
          → Return indices
    5. Nahi mila?
          → Current number + index map me store karo
  
    
*/

//Solution
# include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    
  unordered_map<int,int> mp; // to keep track of complements
  
  for (int i = 0; i <nums.size(); i++){
    
    int complement = target - nums[i];  // target = nums[i] + complement 

    // checking if the complement already exist in the array
    if( mp.find(complement) != mp.end())
    {
       return {mp[complement], i}; // if exist, mp[complement] → pehle mila hua index & i → current index
    }

    mp[nums[i]] = i; // storing values in the map, num[i]->key, i->value

  }
 
    return {}; // no solution
}

int main() {

    vector<int> nums = {2,3,5,6,8,9,4,2};
    int target = 9;

    vector<int> answer = twoSum(nums, target);

    cout << answer[0] << " " << answer[1];

    return 0;
}
