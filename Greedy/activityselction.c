#include <stdio.h>
#include <stdlib.h>

// Function to solve activity selection problem
void activitySelection(int start[], int finish[], int n) {
    // Sort activities based on finish times in non-decreasing order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (finish[i] > finish[j]) {
                // Swap start times
                int tempStart = start[i];
                start[i] = start[j];
                start[j] = tempStart;

                // Swap finish times
                int tempFinish = finish[i];
                finish[i] = finish[j];
                finish[j] = tempFinish;
            }
        }
    }
    
    printf("Selected activities:\n");

    // The first activity is always selected
    printf("(%d, %d) ", start[0], finish[0]);

    // Consider rest of the activities
    int prevFinish = finish[0];
    for (int i = 1; i < n; i++) {
        // If this activity has start time greater than or equal to the finish time of the previous one, then select it
        if (start[i] >= prevFinish) {
            printf("(%d, %d) ", start[i], finish[i]);
            prevFinish = finish[i];
        }
    }
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);

    activitySelection(start, finish, n);

    return 0;
}
