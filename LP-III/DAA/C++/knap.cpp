#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int weight;
    int value;
};

int maxProfit = 0;






void knapsackBacktracking(vector<Item>& items, int capacity, int currentWeight, int currentValue, int currentIndex) {

    if (currentIndex == items.size() || currentWeight == capacity) {    
        if (currentValue > maxProfit) {
            maxProfit = currentValue;
        }
        return;
    }

    if (currentWeight + items[currentIndex].weight <= capacity) {   
        knapsackBacktracking(items, capacity, currentWeight + items[currentIndex].weight, currentValue + items[currentIndex].value, currentIndex + 1);
    }

    knapsackBacktracking(items, capacity, currentWeight, currentValue, currentIndex + 1);
}


int main() {
    vector<Item> items = {{2, 10}, {3, 5}, {5, 15}, {7, 7}, {1, 6}};
    int capacity = 10;

    knapsackBacktracking(items, capacity, 0, 0, 0);

    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}