#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int pivot(vector<int>& nums, int str, int end) {
    int idx = str - 1;
    int piv = nums[end];

    for (int j = str; j < end; j++) {
        if (nums[j] < piv) {
            idx++;
            swap(nums[idx], nums[j]);
        }
    }

    idx++;
    swap(nums[idx], nums[end]);
    return idx;
}

void quickSort(vector<int>& nums, int str, int end) {
    if (str < end) {
        int pivIdx = pivot(nums, str, end);

        // ✅ Correct ranges
        quickSort(nums, str, pivIdx - 1);
        quickSort(nums, pivIdx + 1, end);
    }
}

int main() {
    vector<int> numbers = {1,3,3,34,5,6,7,8,3,5,2,4};

    quickSort(numbers, 0, numbers.size() - 1);

    // Print sorted array
    for (int num : numbers) {
        cout << num << " ";
    }

    return 0;
}