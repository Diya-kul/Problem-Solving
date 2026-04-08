// PROBLEM STATEMENT:-
/*You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

    Example 1:

    Input: s = "ABAB", k = 2
    Output: 4
    Explanation: Replace the two 'A's with two 'B's or vice versa.
    Example 2:

    Input: s = "AABABBA", k = 1
    Output: 4
    Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
    The substring "BBBB" has the longest repeating letters, which is 4.
    There may exists other ways to achieve this answer too.
*/

// SOLUTION:-
/*
    APPROACH:
        Sliding window (variable size)
        Frequency array (size 26)
        characters to replace = window size - most frequent char
    COMPLEXITY:
        Time=O(n)
        Space=O(1)
*/

# include <iostream>
using namespace std;

int main()
{
    // INPUT
    string s;
    int k;

    cout <<"Enter string(in upper case): ";
    cin >> s;

    cout <<"Enter the value of k: ";
    cin >> k;

    //LOGIC START:
    int freq[26]={0}, maxfreq=0, ans=0;

    for(int left=0, right=0; right <s.length(); right++)
    {
        freq[ s[right]-'A']++;
        maxfreq=max( maxfreq, freq[ s[right]-'A']);
        int windowSize = right - left + 1;

        //characters to replace = window size - most frequent char
        while(windowSize - maxfreq > k)
        {
            //Window Shrinking
            freq[ s[left]-'A']--;
            left++;
        }
        ans=max(windowSize,ans);
    }

    cout << "The lenght of longest substring is " << ans;
    return 0;
}
