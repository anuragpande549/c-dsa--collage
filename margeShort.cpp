#include <iostream>
#include <vector>
using namespace std;

//  Merge function: combines two sorted halves
void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp; // temporary array

    int left = low;       // start of left half
    int right = mid + 1;  // start of right half

    //  Compare elements from both halves
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Add remaining elements from left half
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  Add remaining elements from right half
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    //  Copy back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

//  Recursive Merge Sort function
void mergeSort(vector<int>& arr, int low, int high) {

    // Base case: single element
    if (low >= high) return;

    // Find middle
    int mid = low + (high - low) / 2;

    // Sort left half
    mergeSort(arr, low, mid);

    // Sort right half
    mergeSort(arr, mid + 1, high);

    // Merge both halves
    merge(arr, low, mid, high);
}

int main() {
    vector<int> arr = {4,5,3,7,8,9,9,55,0,35,2,4,64};

    mergeSort(arr, 0, arr.size() - 1);

    // Print sorted array
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}