# To-Do-List
This project allows you to add, remove, and mark tasks as completed.

How It Works:
Task Management:

The user can add tasks, remove tasks, or view the list of tasks.
Each task is stored in a 2D character array (tasks[MAX_TASKS][MAX_LENGTH]).
A task count (taskCount) keeps track of how many tasks have been added.
Menu Options:

The user can select from a menu to:
Add a task: The task description is entered, and it is added to the list.
Remove a task: The user specifies which task to remove by its number.
View tasks: The program displays all the tasks currently in the list.
Exit: The program ends.
Memory Management:

The program checks if there is space to add more tasks (it can hold up to MAX_TASKS tasks).
When a task is removed, the remaining tasks are shifted to fill the gap, ensuring the list stays compact.

![image](https://github.com/user-attachments/assets/29f6df42-7061-4281-a0b9-0b8f6acbc91b)

