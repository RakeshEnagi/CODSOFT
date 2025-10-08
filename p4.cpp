#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void addTask(vector<Task> &tasks) {
    string desc;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, desc);
    tasks.push_back({desc, false});
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description 
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

void markTaskCompleted(vector<Task> &tasks) {
    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;
    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void removeTask(vector<Task> &tasks) {
    int index;
    cout << "Enter task number to remove: ";
    cin >> index;
    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

