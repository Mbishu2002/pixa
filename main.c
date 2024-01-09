#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <num_tasks> <num_processes>\n", argv[0]);
        return 1;
    }

    int numTasks = atoi(argv[1]);
    int numProcesses = atoi(argv[2]);

    if (numTasks <= 0 || numProcesses <= 0) {
        printf("Number of tasks and processes should be greater than 0.\n");
        return 1;
    }

    int remainder = numTasks % numProcesses;
    int defaultTasksPerProcess = floor(numTasks / numProcesses);
    int end = 0;
    int i;
    for ( i = 1; i <= numProcesses; ++i) {
        int tasksPerProcess = (i <= remainder) ? defaultTasksPerProcess + 1 : defaultTasksPerProcess;
        int start = end + 1;
        end = start + tasksPerProcess - 1;
        printf("Process %d: Tasks %d-%d (%d tasks)\n", i, start, end, tasksPerProcess);
    }

    return 0;
}
