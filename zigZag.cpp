/*
    LC 6- Zigzag Conversion

    PROBLEM STATEMENT:
        The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

        P   A   H   N
        A P L S I I G
        Y   I   R
        And then read line by line: "PAHNAPLSIIGYIR"

        Write the code that will take a string and make this conversion given a number of rows:

        string convert(string s, int numRows);
        

        Example 1:
            Input: s = "PAYPALISHIRING", numRows = 3
            Output: "PAHNAPLSIIGYIR"

        Example 2:
            Input: s = "PAYPALISHIRING", numRows = 4
            Output: "PINALSIGYAHRPI"
            Explanation:
                    ROW[0] =    P     I    N
                    ROW[1] =    A   L S  I G
                    ROW[2] =    Y A   H R
                    ROW[3] =    P     I

        Example 3:
            Input: s = "A", numRows = 1
            Output: "A"
        

        Constraints:
        1 <= s.length <= 1000
        s consists of English letters (lower-case and upper-case), ',' and '.'.
        1 <= numRows <= 1000
*/
/*

*/

# include <iostream>
# include <vector>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        
        // Edge case
        if(numRows == 1 || s.size() <= numRows)
            return s;

        vector<string> rows(numRows);
        
        int currentRow = 0;
        bool goingDown = true;

        for(char ch : s)
        {
            rows[currentRow] += ch;

            // Change direction
            if(currentRow == 0)
                goingDown = true;
            else if(currentRow == numRows - 1)
                goingDown = false;

            // Move row
            if(goingDown)
                currentRow++;
            else
                currentRow--;
        }

        // Combine all rows
        string result = "";
        for(string row : rows)
            result += row;

        return result;
    }
};


int main(){
    string  s = "PAYPALISHIRING";
    int numRows = 3;

    Solution sol;
    cout << sol.convert(s,numRows); 
    return 0;
}