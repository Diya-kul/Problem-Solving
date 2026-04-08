/*
Problem: Palindrome Number
Given an integer x, return true if x is a palindrome, and false otherwise.

Example :
  Input: x = 121
  Output: true
  Explanation: 121 reads as 121 from left to right and from right to left.
*/

//SOLUTION
bool isPalindrome(int x) {

     if (x < 0) return false; 
    
    int original = x;
    long reversed = 0;
    
    while (x > 0) {
        int digit = x % 10;           // take last digit
        reversed = reversed * 10 + digit; // build reversed number
        x = x / 10;                   // remove last digit
    }
    
    return original == reversed;
    }
