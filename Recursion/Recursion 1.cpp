Problem 1

Print numbers: 1 2 3 ... N

Topic: Recursion
Think:
    * What is the base case?
    * What is the smaller problem?
Time Complexity: O(n)
Space Complexity: O(n)

SOLUTION:-

# include <iostream>

void Rprint( int n)
  {
    if( n==0)    return ;    //BASE CASE
    Rprint(n-1);      //RECURSIVE CASE
    std::cout << n << " " ;  //OUTPUT
  }
int main()
{
  int n;
  std::cout << "Enter no.: ";
  std::cin >> n;

  Rprint(n);
  return 0;
}
