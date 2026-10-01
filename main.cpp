// Was easy to set up since i already had them spread out, void functions were already on top of main
// void prototypes were in the bottom
#include "todo.h"

using namespace std;

int main() {

    int choice;
    int taskCount = 0;
    int capacity = INITIAL_CAPACITY;
    Task* tasks = new Task[capacity];
    loadTasks(tasks, taskCount, capacity);

    while (true) {

        cout << endl;
        cout << "                       Welcome to the Main Menu" << endl;
        cout << "Please press the following associated number to the task you wish to do:" << endl;
        cout << "Press 1 to Add a New Task" << endl;
        cout << "Press 2 to Complete a Task" << endl;
        cout << "Press 3 to Display All Tasks" << endl;
        cout << "Press 4 to Remove a Task" << endl;
        cout << "Press 5 to Modify a Task" << endl;
        cout << "Press 0 to Exit Program" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "You Picked: Add a New Task" << endl;
            addTask(tasks, taskCount, capacity);
            break;

        case 2:
            cout << "You Picked: Complete a Task" << endl;
            completeTask(tasks, taskCount);
            break;

        case 3:
            cout << "You Picked: Display All Tasks" << endl;
            displayTasks(tasks, taskCount);
            break;

        case 4:
            cout << "You Picked: Remove a Task" << endl;
            removeTask(tasks, taskCount);
            break;

        case 5:
            cout << "You Picked: Modify a Task" << endl;
            modifyTask(tasks, taskCount);
            break;

        case 0:
            saveTasks(tasks, taskCount);

            delete[] tasks;
            tasks = nullptr;

            cout << "Tasks have been saved. Goodbye!" << endl;

            return 0;

        default:
            cout << "Invalid choice. Please use a number from 0 to 5." << endl;
        }
    }

    return 0;
}
