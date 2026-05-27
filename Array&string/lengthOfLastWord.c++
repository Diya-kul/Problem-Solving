/*
    PROBLEM STATEMENT:- 58. Length of Last Word

        Given a string s consisting of words and spaces, return the length of the last word in the string.
        A word is a maximal substring consisting of non-space characters only.

        Example 1:
            Input: s = "Hello World"
            Output: 5
            Explanation: The last word is "World" with length 5.

        Example 2:
            Input: s = "   fly me   to   the moon  "
            Output: 4
            Explanation: The last word is "moon" with length 4.

        Example 3:
            Input: s = "luffy is still joyboy"
            Output: 6
            Explanation: The last word is "joyboy" with length 6.
        
        Constraints:
            1 <= s.length <= 104
            s consists of only English letters and spaces ' '.
            There will be at least one word in s.

        Complexity
            Time  : O(n)
            Space : O(1)
*/

# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();        
        int i = len-1, count = 0;

        // skip trailing  spaces
        while( i>=0 && isspace(s[i])){
            i--;
        }

        // Count the Value
        for( ; i>=0 && !isspace(s[i]); i--)
        {
            count = count+1 ;
        }

        return count;
    }
};

int main(){
    string s="   fly me   to   the moon  ";

    Solution sl;
    cout << sl.lengthOfLastWord(s);

    return 0;
}