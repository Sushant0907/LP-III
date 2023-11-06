#include <iostream>
using namespace std;
// Recursive approach
int factorial(int n)
{
    if (n < 2)
        return 1;
    return n * factorial(n - 1);
}


int main()
{
    int num;
    cout << "Enter the number to find factorial \n";
    cin >> num;
    cout << "The factorial of number Using   Recursive approach is :"<<factorial(num);
    int fact = 1;



    for (int i = 2; i <= num; i++)
    {
        fact *= i;
    }




    cout << "\nThe factorial of number Using Non-Recursive approach is : " << fact;
    return 0;
}
