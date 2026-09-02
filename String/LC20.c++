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

/*
    APPROACH: 
        Opening bracket → PUSH
        Closing bracket →
            Stack empty? → FALSE
            Match top?   → POP
            No match?    → FALSE
        End →
            Stack empty? → TRUE

    COMPLEXITY:
        Time  → O(n)
        Space → O(n)
*/

# include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {

    stack<char> st;

    for (char ch : s) {

        // Opening brackets
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        }

        // Closing brackets
        else {

            // No opening bracket available
            if (st.empty()) {
                return false;
            }

            // Check matching pair
            if ((ch == ')' && st.top() != '(') ||
                (ch == ']' && st.top() != '[') ||
                (ch == '}' && st.top() != '{')) {

                return false;
            }

            st.pop();
        }
    }

    return st.empty();
}

int main() {

    string s = "{[]}";

    if (isValid(s)) {
        cout << "Valid";
    }
    else {
        cout << "Invalid";
    }

    return 0;
}