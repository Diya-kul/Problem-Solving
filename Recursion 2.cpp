/*
Problem 2

Print numbers: N N-1 N-2 ... 1
Time Complexity: O(n)

*/

// SOLUTION 
# include <iostream>

void Fprint( int n)
{
  if( n==0) return;    // Base Case
  std::cout << n << " " ;    //Output
  Fprint(n-1);      //Recursive Case
}
int main()
{
  int n;
  std::cout << "Enter no.: ";
  std::cin >> n;

  Fprint(n);
  return 0;
}
