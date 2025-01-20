#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Task {
public:
    string title;
    string description;
    string priority;
    string dueDate;
    bool isComplete;

    Task(string t, string d, string p, string dd) : title(t), description(d), priority(p), dueDate(dd), isComplete(false) {}
};

vector<Task> tasks;

void addTask() {
    string title, description, priority, dueDate;
    cout << "Enter title: ";
    cin >> title;
    cout << "Enter description: ";
    cin >> description;
    cout << "Enter priority: ";
    cin >> priority;
    cout << "Enter due date: ";
    cin >> dueDate;
    Task newTask(title, description, priority, dueDate);
    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

void editTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        cout << "Enter new title: ";
        cin >> tasks[index].title;
        cout << "Enter new description: ";
        cin >> tasks[index].description;
        cout << "Enter new priority: ";
        cin >> tasks[index].priority;
        cout << "Enter new due date: ";
        cin >> tasks[index].dueDate;
        cout << "Task edited successfully!" << endl;
    } else {
        cout << "Invalid task index!" << endl;
    }
}

void deleteTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        cout << "Task deleted successfully!" << endl;
    } else {
        cout << "Invalid task index!" << endl;
    }
}

void markTaskComplete(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].isComplete = true;
        cout << "Task marked as complete!" << endl;
    } else {
        cout << "Invalid task index!" << endl;
    }
}

void displayTasks() {
    for (int i = 0; i < tasks.size(); ++i) {
        cout << i << ". [" << (tasks[i].isComplete ? "X" : " ") << "] " << tasks[i].title << " - " << tasks[i].description
             << " - " << tasks[i].priority << " - " << tasks[i].dueDate << endl;
    }
}

void filterTasks(string priority) {
    for (int i = 0; i < tasks.size(); ++i) {
        if (tasks[i].priority == priority) {
            cout << i << ". [" << (tasks[i].isComplete ? "X" : " ") << "] " << tasks[i].title << " - " << tasks[i].description
                 << " - " << tasks[i].priority << " - " << tasks[i].dueDate << endl;
        }
    }
}

int main() {
    int choice, index;
    string priority;
    while (true) {
        cout << "\n1. Add Task\n2. Edit Task\n3. Delete Task\n4. Mark Task Complete\n5. Display Tasks\n6. Filter Tasks\n7. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addTask(); break;
            case 2: cout << "Enter task index to edit: "; cin >> index; editTask(index); break;
            case 3: cout << "Enter task index to delete: "; cin >> index; deleteTask(index); break;
            case 4: cout << "Enter task index to mark as complete: "; cin >> index; markTaskComplete(index); break;
            case 5: displayTasks(); break;
            case 6: cout << "Enter priority to filter by: "; cin >> priority; filterTasks(priority); break;
            case 7: exit(0);
            default: cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

