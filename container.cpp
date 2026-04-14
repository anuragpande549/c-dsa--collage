//Load maximum number of containers without exceeding capacity

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // List of container weights
    vector<int> weights = {10, 5, 7, 3, 2};

    // Maximum capacity of the ship
    int capacity = 15;

    // Step 1: Sort the weights in ascending order
    // This allows us to pick smaller containers first
    sort(weights.begin(), weights.end());

    // Variable to count how many containers are loaded
    int count = 0;

    // Variable to store current total weight
    int total = 0;

    // Step 2: Iterate through sorted weights
    for (int w : weights) {

        // Check if adding this container exceeds capacity
        if (total + w <= capacity) {
            total += w;   // Add weight to total
            count++;      // Increase container count
        } else {
            // Stop if capacity would be exceeded
            break;
        }
    }

    // Output the results
    cout << "Max containers loaded: " << count << endl;
    cout << "Total weight: " << total << endl;

    return 0;
}