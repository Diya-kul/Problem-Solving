/*
    LeetCode 904 — Fruit Into Baskets

    PROBLEM STATEMENT:-

        You are given an integer array fruits where fruits[i] represents the type of fruit produced by the i-th tree.

        You want to collect fruits using two baskets, where:

        Each basket can hold only one type of fruit
        There is no limit on how many fruits each basket can hold

        You must start from any tree and pick exactly one fruit from each tree moving to the right, stopping when you cannot pick a fruit (i.e., when you encounter a third type).

        Return the maximum number of fruits you can collect.

    Example Test Cases:-
                        Example 1:
                            Input: fruits = [1,2,1]  
                            Output: 3
                        Example 2:
                            Input: fruits = [0,1,2,2]  
                            Output: 3
                            Explanation:
                                Pick from [1,2,2]
                        Example 3:
                            Input: fruits = [1,2,3,2,2]  
                            Output: 4
                            Explanation:
                                Pick from [2,3,2,2]
                         Example 4:
                            Input: fruits = [3,3,3,1,2,1,1,2,3,3,4]  
                            Output: 5
                        Edge Case:
                            Input: fruits = [1]  
                            Output: 1
                        
    Constraints:
                1 <= fruits.length <= 105
                0 <= fruits[i] < fruits.length
*/

// SOLUTION:-
/*
    Approach:
            Sliding window(variable size)
            Track the values of array in the window
            Shrink- when more than 2 distinct value element present in the window
            To track the values we use map

*/

# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;

int main()
{
    // INPUT
    vector<int> fruit={1,2,3,2,2};

    //LOGIC 
    unordered_map<int ,int> mp;
    int ans=0;
    for(int left=0, right=0; right <fruit.size(); right++)
    {
        mp[fruit[right]]++;

        //shrink
        while( mp.size()>2)
        {
            mp[fruit[left]]--;
            if( mp[fruit[left]]==0)
                mp.erase(fruit[left]);
            left++;
        }

        ans=max(right-left+1,ans);
    }

    //OUTPUT
    cout << "The lenght of longest substring is " << ans;
    return 0;
}
