#include <bits/stdc++.h>
using namespace std;

struct GPA_Node {  
    float gpa;  
    GPA_Node* next;  
    GPA_Node(float g) : gpa(g), next(NULL) {}
};

struct Student {
    int rollNo;
    string name;
    float gpa;
    GPA_Node* history;  

    Student() {
        history = NULL;
    }

    void addSemesterGPA(float g) {
        GPA_Node* node = new GPA_Node(g);
        node->next = history;
        history = node;
    }
};

// GLOBAL ARRAY
Student students[100];
int studentCount = 0;

// --------- SEARCH FUNCTIONS ---------
int searchByRoll(int roll) {
    for (int i = 0; i < studentCount; i++)
        if (students[i].rollNo == roll)
            return i;
    return -1;
}

// --------- SORTING (Bubble Sort) ---------
void sortByGPA() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (students[j].gpa < students[j+1].gpa)
                swap(students[j], students[j+1]);
        }
    }
}

// --------- DECISION TREE PREDICTION ---------
string predict(float gpa) {
    if (gpa > 3.5)
        return "Excellent Performance";
    else if (gpa > 3.0)
        return "Good Performance";
    else if (gpa > 2.0)
        return "Average Performance";
    else
        return "At Risk";
}

// --------- ADD STUDENT ---------
void addStudent() {
    Student s;

    cout << "Enter name: ";
    cin >> s.name;

    cout << "Enter roll no: ";
    cin >> s.rollNo;

    cout << "Enter current GPA: ";
    cin >> s.gpa;

    s.addSemesterGPA(s.gpa);

    students[studentCount++] = s;

    cout << "Student added!\n";
}

// --------- DISPLAY ALL ---------
void showAll() {
    for (int i = 0; i < studentCount; i++) {
        cout << "\nRoll No: " << students[i].rollNo;
        cout << "\nName: " << students[i].name;
        cout << "\nGPA: " << students[i].gpa;
        cout << "\nPrediction: " << predict(students[i].gpa);
        cout << "\n------------------------\n";
    }
}

// --------- MAIN MENU ---------
int main() {
    int choice;

    while (true) {
        cout << "\n===== Student Academic Tracker =====\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student by Roll No\n";
        cout << "3. Show All Students\n";
        cout << "4. Sort by GPA (Ranking)\n";
        cout << "5. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) addStudent();
        else if (choice == 2) {
            int r; cout << "Enter roll no: "; cin >> r;
            int index = searchByRoll(r);
            if (index != -1) {
                cout << "Name: " << students[index].name << "\n";
                cout << "GPA: " << students[index].gpa << "\n";
                cout << "Prediction: " << predict(students[index].gpa) << "\n";
            } else cout << "Student not found!\n";
        }
        else if (choice == 3) showAll();
        else if (choice == 4) {
            sortByGPA();
            cout << "Sorted by GPA!\n";
        }
        else if (choice == 5) break;
        else cout << "Invalid choice!\n";
    }

    return 0;
}
