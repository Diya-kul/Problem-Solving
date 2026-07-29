/*
    LC- 1456. Maximum Number of Vowels in a Substring of Given Length

    PROBLEM STATEMENT:
        Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

        Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

        Example 1:
        Input: s = "abciiidef", k = 3
        Output: 3
        Explanation: The substring "iii" contains 3 vowel letters.

        Example 2:
        Input: s = "aeiou", k = 2
        Output: 2
        Explanation: Any substring of length 2 contains 2 vowels.

        Example 3:
        Input: s = "leetcode", k = 3
        Output: 2
        Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

        Constraints:
            1 <= s.length <= 105
            s consists of lowercase English letters.
            1 <= k <= s.length
*/

/*
    Approach:
            Sliding window(fixed size)
            count no, of vowels in a window
*/

//SOLUTION:
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char ch){
        return ch=='a'|| ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
        

    int maxVowels(string s, int k) {
        int left=0, right=k, count=0,i,ans=0;

        for(i=left; i<right; i++)
        {
            if(isVowel(s[i]))
                count++;
        }
        ans=count;
        while(right<s.length())
        {
            if(isVowel(s[right]))
                count++;
            if(isVowel(s[left]))
                count--;

            ans=max(ans,count);
             right++;
             left++;
        }

        return ans;
    }
};

int main(){
    string  s = "leetcode";
    int k = 3;

    Solution sol;
    cout << sol.maxVowels(s,k); 
    return 0;
}