#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()                                                                                                                                                                                  
{
    int first, second;
    cout << "Enter the first number (Be sure that first number is greater and greater than zero) \n";
    cin >> first;
    cout << "Enter the second number \n";
    cin >> second;
    cout << "The GCD of two numbers is : " << gcd(first, second);
    return 0;
}
