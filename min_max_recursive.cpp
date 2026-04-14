#include <iostream>
#include <vector>
using namespace std;

// Function to find both minimum and maximum using recursion
pair<int, int> findMinMax(vector<int>& nums, int low, int high) {

  
    // If low and high are same, only one element exists
    if (low == high) {
        return {nums[low], nums[low]}; // min = max = that element
    }

    
    // If exactly two elements, compare once and return min & max
    if (high == low + 1) {
        if (nums[low] < nums[high]) {
            return {nums[low], nums[high]}; // {min, max}
        } else {
            return {nums[high], nums[low]}; // {min, max}
        }
    }

    // Divide step
    // Find middle index to split array into two halves
    int mid = (low + high) / 2;

    // Conquer step
    // Recursively find min & max in left half
    pair<int, int> left = findMinMax(nums, low, mid);


    // Recursively find min & max in right half
    pair<int, int> right = findMinMax(nums, mid + 1, high);

    // Combine step
    // Compare results of both halves
    int finalMin = min(left.first, right.first);
    int finalMax = max(left.second, right.second);

    return {finalMin, finalMax};
}

int main() {

    // Input array
    vector<int> nums = {4,5,3,7,8,9,9,55,0,35,2,4,64};

    // Edge case check (important in interviews)
    if (nums.empty()) {
        cout << "Array is empty!" << endl;
        return 0;
    }

    // Call recursive function
    pair<int, int> result = findMinMax(nums, 0, nums.size() - 1);

    // Output result
    cout << "Minimum: " << result.first << endl;
    cout << "Maximum: " << result.second << endl;

    return 0;
}