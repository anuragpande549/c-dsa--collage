//Given jobs with deadlines and profits, schedule jobs to maximize total profit.
//Each job takes 1 unit time.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id, deadline, profit;
};

int main() {
    vector<Job> jobs = {
        {1,2,100},
        {2,1,50},
        {3,2,10},
        {4,1,20}
    };


    sort(jobs.begin(), jobs.end(), [](Job a, Job b) {
        return a.profit > b.profit;
    });

    int maxDeadline = 0;

    // Find maximum deadline
    for (auto j : jobs) {
        if (j.deadline > maxDeadline)
            maxDeadline = j.deadline;
    }

    vector<int> slot(maxDeadline, -1);
    int totalProfit = 0;

    // Assign jobs
    for (auto j : jobs) {
        for (int i = j.deadline - 1; i >= 0; i--) {
            if (slot[i] == -1) {
                slot[i] = j.id;
                totalProfit += j.profit;
                break;
            }
        }
    }

    // Output
    cout << "Jobs: ";
    for (int x : slot) {
        if (x != -1) cout << "J" << x << " ";
    }

    cout << "\nProfit: " << totalProfit;
}