/*
  Problem: Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without duplicate characters.

Example :
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
*/

//SOLUTION:
int lengthOfLongestSubstring(string s) {
        if( s.size() == 0)  return 0;

        int count = 0, frequency[256]={0};

        for(int left=0, right=0; right< s.size(); right++)
        {
            frequency[s[right]]++;

            while( frequency[s[right]] > 1)
            {
                frequency[s[left]]--;
                left++;
            }

            count= max(count, right-left +1);
        }

        return count;

    }
