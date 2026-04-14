#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binarySearchRecursive(vector<int>& nums, int i, int j, int target) {

    if (i > j) {
        return -1;
    }

    int mid = (i + j) / 2;

    if (nums[mid] == target) {
        return mid;
    }
    else if (nums[mid] > target) {
        return binarySearchRecursive(nums, i, mid - 1, target);
    }
    else {
        return binarySearchRecursive(nums, mid + 1, j, target);
    }
}

int main() {
    vector<int> numbers = {1,3,3,34,5,6,7,8,3,5,2,4};
    int target = 34;

    // Sort before applying binary search
    sort(numbers.begin(), numbers.end());

    int result = binarySearchRecursive(numbers, 0, numbers.size() - 1, target);

    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found" << endl;
    }

    return 0;
}

