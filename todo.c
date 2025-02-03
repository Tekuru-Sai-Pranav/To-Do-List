// Online C compiler to run C program online
#include <stdio.h>

#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100

// Function prototypes
void addTask(char tasks[][MAX_LENGTH], int *taskCount);
void removeTask(char tasks[][MAX_LENGTH], int *taskCount);
void displayTasks(char tasks[][MAX_LENGTH], int taskCount);

int main() {
    char tasks[MAX_TASKS][MAX_LENGTH];
    int taskCount = 0;
    int choice;

    while (1) {
        printf("\nTo-Do List Menu\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. View Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                removeTask(tasks, &taskCount);
                break;
            case 3:
                displayTasks(tasks, taskCount);
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to add a task
void addTask(char tasks[][MAX_LENGTH], int *taskCount) {
    if (*taskCount >= MAX_TASKS) {
        printf("Task list is full! Cannot add more tasks.\n");
        return;
    }

    printf("Enter the task description: ");
    fgets(tasks[*taskCount], MAX_LENGTH, stdin);
    tasks[*taskCount][strcspn(tasks[*taskCount], "\n")] = '\0';  // Remove the newline character
    (*taskCount)++;
    printf("Task added successfully!\n");
}

// Function to remove a task
void removeTask(char tasks[][MAX_LENGTH], int *taskCount) {
    int taskNumber;

    if (*taskCount == 0) {
        printf("No tasks to remove!\n");
        return;
    }

    displayTasks(tasks, *taskCount);
    printf("Enter the task number to remove: ");
    scanf("%d", &taskNumber);
    getchar();  // Consume the newline character

    if (taskNumber < 1 || taskNumber > *taskCount) {
        printf("Invalid task number!\n");
        return;
    }

    // Shift remaining tasks
    for (int i = taskNumber - 1; i < *taskCount - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
    }

    (*taskCount)--;
    printf("Task removed successfully!\n");
}

// Function to display tasks
void displayTasks(char tasks[][MAX_LENGTH], int taskCount) {
    if (taskCount == 0) {
        printf("No tasks available!\n");
        return;
    }

    printf("\nCurrent Tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
}
