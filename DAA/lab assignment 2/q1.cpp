#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an activity
struct Activity {
    int start;
    int finish;
};

// Function to compare activities based on their finish time
bool compareActivities(const Activity& a, const Activity& b) {
    return a.finish < b.finish;
}

// Function to find the maximum number of activities that can be performed
void activitySelection(vector<Activity>& activities) {
    // Sort activities based on their finish times
    sort(activities.begin(), activities.end(), compareActivities);
    
    // Select the first activity
    cout << "Selected Activities: ";
    cout << "(" << activities[0].start << ", " << activities[0].finish << ") ";

    // Initialize the index of the last selected activity
    int lastSelected = 0;

    // Iterate through remaining activities
    for (int i = 1; i < activities.size(); ++i) {
        // If this activity has a start time greater than or equal to
        // the finish time of the last selected activity, then select it
        if (activities[i].start >= activities[lastSelected].finish) {
            cout << "(" << activities[i].start << ", " << activities[i].finish << ") ";
            lastSelected = i;
        }
    }
}

int main() {
    vector<Activity> activities = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    activitySelection(activities);
    return 0;
}
