/*
    PROBLEM STATEMENT:- 20. Valid Parentheses

        Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
        An input string is valid if:
            - Open brackets must be closed by the same type of brackets.
            - Open brackets must be closed in the correct order.
            - Every close bracket has a corresponding open bracket of the same type.
 
        Example 1:
            Input: s = "()"
            Output: true
        Example 2:
            Input: s = "()[]{}"
            Output: true
        Example 3:
            Input: s = "(]"
            Output: false
        Example 4:
            Input: s = "([])"
            Output: true
        Example 5:
            Input: s = "([)]"
            Output: false

        Constraints:
            1 <= s.length <= 104
            s consists of parentheses only '()[]{}'.
*/

# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch : s) {

            // opening brackets
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            // closing brackets
            else {

                // stack empty means invalid
                if(st.empty()) {
                    return false;
                }

                char top = st.top();

                // check matching pair
                if((ch == ')' && top == '(') ||
                   (ch == '}' && top == '{') ||
                   (ch == ']' && top == '[')) {

                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        // all brackets should be matched
        return st.empty();
    }
};

int main(){
    string s="([)]";

    Solution sol;

    if(sol.isValid(s))
        cout << "True";
    else
        cout << "False";
    return 0;
}