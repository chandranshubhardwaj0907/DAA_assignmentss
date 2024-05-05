#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
};

bool compareItems(const Item& a, const Item& b) {
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;
    return ratioA > ratioB;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (const Item& item : items) {
        if (currentWeight + item.weight <= capacity) {
            // Take the whole item
            totalValue += item.value;
            currentWeight += item.weight;
        } else {
            // Take a fraction of the item
            int remainingCapacity = capacity - currentWeight;
            totalValue += (double)item.value * remainingCapacity / item.weight;
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    int capacity = 50;
    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value in knapsack: " << maxValue << endl;
    return 0;
}
