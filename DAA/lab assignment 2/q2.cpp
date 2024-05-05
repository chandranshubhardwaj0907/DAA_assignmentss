#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a job
struct Job {
    char id;
    int deadline;
    int profit;
};

// Function to compare jobs based on their profit
bool compareJobs(const Job& a, const Job& b) {
    return a.profit > b.profit;
}

// Function to find the maximum profit job sequence
void jobSequencing(vector<Job>& jobs) {
    // Sort jobs based on their profit
    sort(jobs.begin(), jobs.end(), compareJobs);

    // Find the maximum deadline
    int maxDeadline = 0;
    for (const Job& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Array to track whether a slot is occupied
    vector<bool> slot(maxDeadline + 1, false);

    // Array to store the result (sequence of jobs)
    vector<char> result;

    // Assign jobs to slots starting from the one with the highest profit
    for (const Job& job : jobs) {
        for (int i = min(maxDeadline, job.deadline); i >= 1; --i) {
            // If the slot is not occupied, assign the job to this slot
            if (!slot[i]) {
                slot[i] = true;
                result.push_back(job.id);
                break;
            }
        }
    }

    // Print the sequence of jobs
    cout << "Job Sequence: ";
    for (char jobId : result) {
        cout << jobId << " ";
    }
    cout << endl;
}

int main() {
    vector<Job> jobs = {{'a', 4, 20}, {'b', 1, 10}, {'c', 1, 40}, {'d', 1, 30}};
    jobSequencing(jobs);
    return 0;
}
