#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum deadline among all jobs
int findMaxDeadline(int deadlines[], int n) {
    int maxDeadline = deadlines[0];
    for (int i = 1; i < n; i++) {
        if (deadlines[i] > maxDeadline)
            maxDeadline = deadlines[i];
    }
    return maxDeadline;
}

// Function to solve job sequencing problem with deadlines
void jobSequencing(int profits[], int deadlines[], int n) {
    // Sort jobs based on profit in non-increasing order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (profits[i] < profits[j]) {
                // Swap profits
                int tempProfit = profits[i];
                profits[i] = profits[j];
                profits[j] = tempProfit;

                // Swap deadlines
                int tempDeadline = deadlines[i];
                deadlines[i] = deadlines[j];
                deadlines[j] = tempDeadline;
            }
        }
    }

    // Find the maximum deadline among all jobs
    int maxDeadline = findMaxDeadline(deadlines, n);

    // Initialize array to store job sequence
    int jobSequence[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
        jobSequence[i] = -1; // Marking as unassigned

    // Fill the job sequence array
    for (int i = 0; i < n; i++) {
        int j;
        for (j = deadlines[i] - 1; j >= 0; j--) {
            if (jobSequence[j] == -1) {
                jobSequence[j] = i; // Assign job i to time slot j
                break;
            }
        }
    }

    // Print the job sequence
    printf("Job sequence with deadlines:\n");
    for (int i = 0; i < maxDeadline; i++) {
        if (jobSequence[i] != -1) {
            printf("Job %d with profit %d\n", jobSequence[i] + 1, profits[jobSequence[i]]);
        }
    }
}

int main() {
    int profits[] = {20, 15, 10, 5, 1};
    int deadlines[] = {2, 2, 1, 3, 3};
    int n = sizeof(profits) / sizeof(profits[0]);

    jobSequencing(profits, deadlines, n);

    return 0;
}
