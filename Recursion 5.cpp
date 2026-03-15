/*
Problem 5

Fibonacci number.
Hidden pattern:  F(n) = F(n-1) + F(n-2)
*/
// SOLUTION:-
# include <iostream>
int func( int n)
{
  if( n==1) return 1;  //BASE CASE 1
  if (n==0) return 0;  //BASE CASE 2
  return func(n-1) + func(n-2);  //RECURSIVE CALL
}

int main()
{
  int n=0, fib=0;
  std::cout << "Enter no.: ";
  std::cin >> n;
  fib= func(n);  //FUNCTION CALL
  std::cout << "Fibonacci number = " << fib;
  return 0;
}
