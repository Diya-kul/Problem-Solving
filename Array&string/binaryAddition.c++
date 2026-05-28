/*
    PROBLEM STATEMENT:- 67. Add Binary
        Given two binary strings a and b, return their sum as a binary string.

        Example 1:
            Input: a = "11", b = "1"
            Output: "100"

        Example 2:
            Input: a = "1010", b = "1011"
            Output: "10101"
        

        Constraints:
            1 <= a.length, b.length <= 104
            a and b consist only of '0' or '1' characters.
            Each string does not contain leading zeros except for the zero itself.
*/


# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1, j=b.length()-1, carry=0;
        // resultant string
        string result="";

        while( i>=0 || j>=0 || carry){

            int sum = carry;

            // string a
            if(i>=0){
                sum += a[i]- '0';
                i=i-1;
            }

            // String b
            if( j >= 0){
                sum += b[j] - '0';
                j = j - 1;
            }

            result += (sum % 2 ) + '0';
            carry = sum/2;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main(){
    string a="1001", b = "1010";

    Solution sl;
    
    cout << sl.addBinary(a,b);

    return 0;
}