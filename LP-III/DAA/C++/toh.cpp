#include <bits/stdc++.h>
using namespace std;
void towerOfHanoi(int n, char from_rod, char to_rod,
                  char aux_rod)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod
         << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
int main()
{
    int N;
    cout << "Enter number of disks\n";
    cin >> N;
    // A, B and C are names of rods
    towerOfHanoi(N, 'A', 'C', 'B');
    cout << "Here are all disks at rod C";
    return 0;
}