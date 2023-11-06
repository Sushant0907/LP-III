#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int n; // Number of cities
vector<vector<int>> graph; // Adjacency matrix representing distances between cities
vector<bool> visited;
int minCost = INF;

void tspBranchAndBound(int currentCity, int currentCost, int visitedCities) {
    if (visitedCities == (1 << n) - 1) {
        // All cities have been visited. Return to the starting city.
        minCost = min(minCost, currentCost + graph[currentCity][0]);
        return;
    }

    for (int nextCity = 0; nextCity < n; ++nextCity) {
        if (!visited[nextCity] && graph[currentCity][nextCity] != 0) {
            visited[nextCity] = true;
            tspBranchAndBound(nextCity, currentCost + graph[currentCity][nextCity], visitedCities | (1 << nextCity));
            visited[nextCity] = false;
        }
    }
}

int main() {
    cout << "Enter the number of cities: ";
    cin >> n;

    // Initialize the graph with distances
    graph.resize(n, vector<int>(n));
    cout << "Enter the distance matrix (0 for the same city, INF for disconnected cities):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    visited.resize(n, false);
    visited[0] = true; // Start from the first city

    tspBranchAndBound(0, 0, 1);

    cout << "Minimum cost: " << minCost << endl;

    return 0;
}
