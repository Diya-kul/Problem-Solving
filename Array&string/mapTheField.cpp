/*
LC-168. Excel Sheet Column Title

Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnNumber = 1
Output: "A"
Example 2:

Input: columnNumber = 28
Output: "AB"
Example 3:

Input: columnNumber = 701
Output: "ZY"
 

Constraints:

1 <= columnNumber <= 231 - 1
*/
/*
    APPROACH:
        Excel column naming is like base-26, but:
            Normal base-26 → digits are 0–25
            Excel → letters are 1–26 (A–Z)
            So there is no 0

        Problem-

        Because there’s no 0:
            Direct % 26 won’t work properly
            Example: 26 % 26 = 0 → but there’s no “0 letter”

        Before using modulo, subtract 1
            n--
      

        Now it behaves like:
            0 → A
            1 → B
            …
            25 → Z

        Final Logic (Step-by-Step)
            1. While n > 0
            2. Do n--
            3. Find n % 26 → gives letter
            4. Convert to char: 'A' + remainder
            5. Divide n = n / 26
            6. Reverse answer
        
        Quick Example
            For `n = 28`:
            28 → 27 → 27 % 26 = 1 → B 1 → 0 → 0 % 26 = 0 → A
            Answer ="AB"
        
        “Excel columns = base-26 without zero, so subtract 1 before modulo.”
*/

# include <bits/stdc++.h>
using namespace std;


int main(){
    //INPUT
    int n;
    cout<<"Enter no.: ";
    cin >> n;

    //LOGIC
    int rem=0;
    string ch;
    while(n>0){
        n--;
        rem=n%26;
        ch+=('A'+rem);
        n=n/26;
    }

    //OUTPUT
    for(int i=ch.length()-1; i>=0;i--)
        cout << ch[i];

    return 0;
}