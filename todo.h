#ifndef TODO_H
#define TODO_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Shared constant
const int INITIAL_CAPACITY = 20;

// Task struct
struct Task {
    string taskName;
    string priority;
    string deadline;
    bool isCompleted;
};

// Function prototypes
void expandArray(Task*& tasks, int& capacity);
void loadTasks(Task*& tasks, int& taskCount, int& capacity);
void saveTasks(Task* tasks, int taskCount);
void addTask(Task*& tasks, int& taskCount, int& capacity);
void completeTask(Task* tasks, int taskCount);
void displayTasks(Task* tasks, int taskCount);
void removeTask(Task* tasks, int& taskCount);
void modifyTask(Task* tasks, int taskCount);

#endif
