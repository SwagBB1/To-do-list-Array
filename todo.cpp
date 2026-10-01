#include "todo.h"

using namespace std;


// Loads tasks from task.txt
void loadTasks(Task*& tasks, int& taskCount, int& capacity) {

    ifstream inputFile("task.txt");

    if (!inputFile) {
        cout << "Could not open task.txt. Starting with an empty task list." << endl;
        return;
    }

    string taskName;
    string priority;
    string deadline;

    while (inputFile >> taskName >> priority >> deadline) {

        // Expand array if it is full
        if (taskCount >= capacity) {
            expandArray(tasks, capacity);
        }

        tasks[taskCount].taskName = taskName;
        tasks[taskCount].priority = priority;
        tasks[taskCount].deadline = deadline;

        // Loaded tasks start as incomplete
        tasks[taskCount].isCompleted = false;

        taskCount++;
    }

    inputFile.close();

    cout << taskCount << " task(s) loaded from task.txt." << endl;
}


// Saves tasks to task.txt
void saveTasks(Task* tasks, int taskCount) {

    ofstream outputFile("task.txt");

    if (!outputFile) {
        cout << "Error: Could not save tasks to task.txt." << endl;
        return;
    }

    for (int i = 0; i < taskCount; i++) {

        outputFile << tasks[i].taskName << " "
                   << tasks[i].priority << " "
                   << tasks[i].deadline
                   << endl;
    }

    outputFile.close();
}


// Expands the dynamic array
void expandArray(Task*& tasks, int& capacity) {

    int newCapacity = capacity * 2;

    Task* newTasks = new Task[newCapacity];

    for (int i = 0; i < capacity; i++) {
        newTasks[i] = tasks[i];
    }

    delete[] tasks;

    tasks = newTasks;
    capacity = newCapacity;

    cout << "Array expanded to "
         << capacity
         << " tasks." << endl;
}


// Adds a task
void addTask(Task*& tasks, int& taskCount, int& capacity) {

    if (taskCount >= capacity) {
        expandArray(tasks, capacity);
    }

    cout << "Please enter a task with _ as the space: ";
    cin >> tasks[taskCount].taskName;

    cout << "Please enter the priority (low, medium, high): ";
    cin >> tasks[taskCount].priority;

    cout << "Please enter the deadline (MM/DD/YYYY): ";
    cin >> tasks[taskCount].deadline;

    tasks[taskCount].isCompleted = false;

    taskCount++;

    saveTasks(tasks, taskCount);

    cout << "Task added successfully!" << endl;
}


// Completes a task
void completeTask(Task* tasks, int taskCount) {

    if (taskCount == 0) {
        cout << "There are no tasks to complete." << endl;
        return;
    }

    displayTasks(tasks, taskCount);

    int taskNumber;

    cout << "Enter the number of the task you want to complete: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > taskCount) {
        cout << "Invalid task number." << endl;
        return;
    }

    tasks[taskNumber - 1].isCompleted = true;

    saveTasks(tasks, taskCount);

    cout << "Task completed successfully!" << endl;
}


// Displays all tasks
void displayTasks(Task* tasks, int taskCount) {

    if (taskCount == 0) {
        cout << "There are no tasks." << endl;
        return;
    }

    cout << endl;
    cout << "                  All Tasks" << endl;

    for (int i = 0; i < taskCount; i++) {

        cout << i + 1 << ". "
             << tasks[i].taskName
             << " | Priority: "
             << tasks[i].priority
             << " | Deadline: "
             << tasks[i].deadline
             << " | Status: ";

        if (tasks[i].isCompleted) {
            cout << "Complete";
        }
        else {
            cout << "Incomplete";
        }

        cout << endl;
    }

    cout << endl;
}


// Removes a task
void removeTask(Task* tasks, int& taskCount) {

    if (taskCount == 0) {
        cout << "There are no tasks to remove." << endl;
        return;
    }

    displayTasks(tasks, taskCount);

    int taskNumber;

    cout << "Enter the number of the task you want to remove: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > taskCount) {
        cout << "Invalid task number." << endl;
        return;
    }

    // Shift tasks to the left
    for (int i = taskNumber - 1; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    taskCount--;

    saveTasks(tasks, taskCount);

    cout << "Task removed successfully!" << endl;
}


// Modifies a task
void modifyTask(Task* tasks, int taskCount) {

    if (taskCount == 0) {
        cout << "There are no tasks to modify." << endl;
        return;
    }

    displayTasks(tasks, taskCount);

    int taskNumber;

    cout << "Enter the number of the task you want to modify: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > taskCount) {
        cout << "Invalid task number." << endl;
        return;
    }

    cout << "Enter the new task with _ as the space: ";
    cin >> tasks[taskNumber - 1].taskName;

    cout << "Enter the new priority (low, medium, high): ";
    cin >> tasks[taskNumber - 1].priority;

    cout << "Enter the new deadline (MM/DD/YYYY): ";
    cin >> tasks[taskNumber - 1].deadline;

    saveTasks(tasks, taskCount);

    cout << "Task modified successfully!" << endl;
}
