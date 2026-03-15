/*
Problem 3

Find:  Sum of first N numbers
Think mathematically:  sum(n) = n + sum(n-1)
Time complexity: O(n)
*/
// SOLUTION:-

# include <iostream>
int Rsum( int n)
{
  if( n==1) return 1;  //BASE CASE
  return n+Rsum(n-1);  //RECURSIVE CALL
}

int main()
{
  int n=0, sum=0;
  std::cout << "Enter no.: ";
  std::cin >> n;
  sum=Rsum(n);  //FUNCTION CALL
  std::cout << "sum = " << sum;
  return 0;
}
