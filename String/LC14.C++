/*

    PROBLEM STATEMENT: 14. Longest Common Prefix

        Write a function to find the longest common prefix string amongst an array of strings.
        If there is no common prefix, return an empty string "".

        Example 1:
            Input: strs = ["flower","flow","flight"]
            Output: "fl"
     
        Example 2:
            Input: strs = ["dog","racecar","car"]
            Output: ""
            Explanation: There is no common prefix among the input strings.
        
        Constraints:
            1 <= strs.length <= 200
            0 <= strs[i].length <= 200
            strs[i] consists of only lowercase English letters if it is non-empty.

*/

/*
    APPROACH:

        Sort karo
            ↓
        First string aur Last string compare karo
            ↓
        prefix find kro

    Sorting → O(n log n)
    Comparison → O(m)
*/

# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if( size==0)
            return "";

        string result = "";

        sort(strs.begin(), strs.end());
    
        for(int i=0; i<strs[0].length(); i++){
            if( strs[0][i]!=strs[size-1][i])
                break;
            
            result += strs[0][i];
        }
        return result;
    }
};

int main() {

    vector<string> strs = {"flower", "flow", "flight"};

    Solution obj;

    cout << obj.longestCommonPrefix(strs);

    return 0;
}