
#include <iostream>
#include <string>
using namespace std;

// Base Class
class Person {
protected:
    string name;
    int age;

public:
    // Constructor
    Person(string n, int a) {
        name = n;
        age = a;
        cout << "Person Constructor Called" << endl;
    }

    // Display person details
    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived Class - Single Inheritance
class Student : public Person {
protected:
    int rollNo;
    string course;

public:
    // Constructor
    Student(string n, int a, int r, string c)
        : Person(n, a) {
        rollNo = r;
        course = c;
        cout << "Student Constructor Called" << endl;
    }

    // Display student details
    void displayStudent() {
        displayPerson();
        cout << "Roll Number: " << rollNo << endl;
        cout << "Course: " << course << endl;
    }
};

// Derived Class - Multilevel Inheritance
class GraduateStudent : public Student {
private:
    string researchTopic;
    string guideName;

public:
    // Constructor
    GraduateStudent(string n, int a, int r, string c,
                    string topic, string guide)
        : Student(n, a, r, c) {
        researchTopic = topic;
        guideName = guide;
        cout << "GraduateStudent Constructor Called" << endl;
    }

    // Display graduate student details
    void displayGraduate() {
        displayStudent();
        cout << "Research Topic: " << researchTopic << endl;
        cout << "Research Guide: " << guideName << endl;
    }
};

int main() {

    cout << "===== UNIVERSITY MANAGEMENT SYSTEM =====" << endl;

    // Create GraduateStudent object
    GraduateStudent gs(
        "Atharav",
        20,
        101,
        "B.Tech AI & DS",
        "Artificial Intelligence",
        "Dr. Sharma"
    );

    cout << "\n===== GRADUATE STUDENT DETAILS =====" << endl;

    gs.displayGraduate();

    return 0;
}
