//itrative methord

#include <iostream>
#include <vector>
using namespace std;

void findMinMax(vector<int>& nums) {
    int minVal = nums[0];
    int maxVal = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < minVal) {
            minVal = nums[i];
        }
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }

    cout << "Min: " << minVal << endl;
    cout << "Max: " << maxVal << endl;
    
}

int main() {
    vector<int> arr = {1,3,3,34,5,6,7,8,3,5,2,4};

    findMinMax(arr);
    
    return 0;
}