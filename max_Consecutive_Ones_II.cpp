// PROBLEM STATEMENT— Max Consecutive Ones II

/*
    LeetCode 487 

    Given a binary array nums (containing only 0s and 1s), return the maximum number of consecutive 1s in the array if you can flip at most one 0.

    Example Test Cases:-
                        Example 1:
                        Input: nums = [1,0,1,1,0]  
                        Output: 4

                        Explanation:
                        Flip the first 0 → [1,1,1,1,0] → longest consecutive ones = 4

                        Example 2:
                        Input: nums = [1,0,1,1,0,1]  
                        Output: 4
                        Example 3:
                        Input: nums = [1,1,1]  
                        Output: 3
                        Example 4:
                        Input: nums = [0,0,0]  
                        Output: 1
                        Edge Case:
                        Input: nums = [0]  
                        Output: 1

*/

// SOLUTION:-
/*
    Approach: 
            Sliding window (variable size)
            count the occurence of 0's in the window
            Shrink- when more than 1 0 present in the window
    
    Output:
            max no. of consecutive 1's.

            that means max size of window containg 1's and a 0 in it.
    
    Complexity:
            Time=O(n)
            Space=O(1)
*/


# include <iostream>
# include <vector>
using namespace std;

int main()
{
    // INPUT
    vector<int> num={1,0,1,0,0,1,0,1,1,0,1,0};

    //LOGIC START:
    int ans=0,zeroCount=0;
    
    for(int left=0, right=0; right <num.size(); right++)
    {
        if(num[right]==0)
            zeroCount++;

        //shrink
        while(zeroCount>1)
        {
            if(num[left]==0)
                zeroCount--;
            left++;
        }
        
        ans=max(right-left+1,ans);
    }

    //OUTPUT
    cout << "The lenght of longest substring is " << ans;
    return 0;
}
