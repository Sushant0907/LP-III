#include <bits/stdc++.h>
using namespace std;
int dp[1007][1007];
int solve(int i, int wt[], int val[], int w, int n)
{
    if (i >= n || w == 0)
        return 0;
    if (dp[i][w] != -1)
        return dp[i][w];
    int take = 0, not_take = 0;
    if (wt[i] <= w)
        take = val[i] + solve(i + 1, wt, val, w - wt[i], n);
    not_take = solve(i + 1, wt, val, w, n);
    return dp[i][w] = max(take, not_take);
}
int main()
{
    int n, W;
    cout << "Enter the number of weights you have\n";
    cin >> n;
    int wt[n], value[n];
    cout << "Enter the values in weight array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    cout << "Enter the values in values array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    cout << "Enter the capacity of sack\n";
    cin >> W;
    // Starting index as 0
    memset(dp, -1, sizeof(dp)); // Initialize array with default values.
    cout << "The maximum value we get : " << solve(0, wt, value, W, n);
}