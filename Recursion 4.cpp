/*
Problem 4
FACTORIAL:-
Compute:  n!
Think:  n! = n × (n-1)!
*/
// SOLUTION:-

# include <iostream>
int fact( int n)
{
  if( n==1) return 1;  //BASE CASE
  return n*fact(n-1);  //RECURSIVE CALL
}

int main()
{
  int n=0, factorial=0;
  std::cout << "Enter no.: ";
  std::cin >> n;
  factorial=fact(n);  //FUNCTION CALL
  std::cout << "Factorial = " << factorial;
  return 0;
}
