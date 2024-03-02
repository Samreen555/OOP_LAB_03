//// task 1:
////Create a program to manage student grades using vectors, demonstrating dynamic resizing and element access.
//#include <iostream>
//#include <vector>
//using namespace std;
//int main() {
//    vector<int> grades; // Vector to store student grades
//    int choice;
//    cout << "1. Add a grade\n";
//    cout << "2. Display all grades\n";
//    cout << "3. Calculate average grade\n";
//    cout << "4. Exit\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//        switch (choice) 
//        {
//             case 1:
//            {
//            int grade;
//            cout << "Enter the grade: ";
//            cin >> grade;
//            grades.push_back(grade); // Add grade to the vector
//            cout << "Grade added successfully.\n";
//            break;
//            }
//            case 2:
//           {
//            if (grades.empty()) {
//                cout << "No grades added yet.\n";
//            }
//            else
//            {
//                cout << "Grades:\n";
//                for (int i = 0; i < grades.size(); ++i) {
//                    cout << grades[i] << endl; // Display all grades
//                }
//            }
//            break;
//            }
//        case 3: {
//            if (grades.empty()) {
//                cout << "No grades added yet.\n";
//            }
//            else {
//                int total = 0;
//                for (int grade : grades) {
//                    total += grade; // Calculate total of all grades
//                }
//                double average = static_cast<double>(total) / grades.size(); // Calculate average grade
//                cout << "Average grade: " << average << endl;
//            }
//            break;
//        }
//        case 4:
//        {
//            cout << "Exiting program.\n";
//            break;
//        }
//        default:
//            cout << "Invalid choice. Please enter a valid option.\n";
//        }
//    return 0;
//}

// task 2
//Develop a contact management system using maps to store and search for contact details based on names.
//#include <iostream>
//#include <map>
//#include <string>
//using namespace std;
//int main() {
//    map<string, string> contacts; // Map to store contacts with names as keys and details as values
//    cout << "1. Add a contact\n";
//    cout << "2. Search for a contact\n";
//    cout << "3. Exit\n";
//    int choice;
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            string name, details;
//            cout << "Enter the name: ";
//            cin.ignore(); // Clear the input buffer
//            getline(cin, name); // Read the entire line including spaces
//            cout << "Enter the details: ";
//            getline(cin, details);
//            contacts[name] = details; // Add contact to the map
//            cout << "Contact added successfully.\n";
//            break;
//        }
//        case 2: {
//            string searchName;
//            cout << "Enter the name to search: ";
//            cin.ignore(); // Clear the input buffer
//            getline(cin, searchName); // Read the entire line including spaces
//            auto it = contacts.find(searchName);
//            if (it != contacts.end()) {
//                cout << "Contact details: " << it->second << endl; // Display contact details
//            }
//            else {
//                cout << "Contact not found.\n";
//            }
//            break;
//        }
//        case 3: {
//            cout << "Exiting program.\n";
//            break;
//        }
//        default:
//            cout << "Invalid choice. Please enter a valid option.\n";
//
//        }
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//struct Student {
//    int id;
//    string name;
//    float grade;
//    Student(int i, string n, float g) : id(i), name(n), grade(g) {}
//};
//
//class StudentManager {
//private:
//    vector<Student*> records;
//public:
//    void addStudent(int id, string name, float grade)  // 2.	Implement a function to add a new student record to the system.
//    {
//        Student* newStudent = new Student(id, name, grade);   //1. Creating a vector of Student* (pointers to Student) to manage student records dynamically.
//        records.push_back(newStudent);
//    }
//
//    void updateGrade(int id, float newGrade)  // 3.	Implement a function to update the grade of a student by ID.
//    {
//        for (Student* student : records) {
//            if (student->id == id) {
//                student->grade = newGrade;
//                return;
//            }
//        }
//        cout << "Student ID not found." << endl;
//    }
//
//    void displayRecords()   // 4.  Implement a function to display all student records stored in the system.
//    {
//        for (Student* student : records) {
//            cout << "ID: " << student->id << ", Name: " << student->name << ", Grade: " << student->grade << endl;
//        }
//    }
//
//    ~StudentManager() {
//        for (Student* student : records) {
//            delete student;
//        }
//    }
//};
//
//int main() {
//    StudentManager sm;
//    sm.addStudent(1, "Samreen Farhat", 92.5);
//    sm.addStudent(2, "Zain Javed", 88.0);
//    sm.displayRecords();
//    sm.updateGrade(1, 95.0);
//    cout << "After grade update:" << endl;
//    sm.displayRecords();
//    system("pause");
//    return 0;
//}
#include <iostream>
#include <vector>
using namespace std;
class Task {
public:
    string description;
    bool completed;
    Task(string desc) : description(desc), completed(false) {}
};
class ToDoList {
    vector<Task*> tasks;
public:
    void addTask(const string& desc) { tasks.push_back(new Task(desc)); }

    void listTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i]->description;
            if (tasks[i]->completed)
                cout << " [Completed]";
            cout << endl;
        }
    }
    void markTaskAsCompleted(int index) {
        if (index < 0 || index >= tasks.size()) {
            cout << "Invalid task index." << endl;
            return;
        }
        tasks[index]->completed = true;
        cout << "Task \"" << tasks[index]->description << "\" marked as completed." << endl;
    }
    ~ToDoList() {
        for (auto& task : tasks)
            delete task;
    }
};
int main() {
    ToDoList myList;
    myList.addTask("Finish Lab 3");
    myList.addTask("Study for exam");

    myList.listTasks();

    myList.markTaskAsCompleted(0);

    myList.listTasks();
    system("pause");
    return 0;
}



