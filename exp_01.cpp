
#include <iostream>
#include <string>
using namespace std;

int main() {

    // 1. Demonstration of variables and data types
    int age;
    float marks;
    double percentage;
    char grade;
    bool isStudent;
    string name;

    // 2. Demonstration of constants
    const int MAX_MARKS = 100;
    const float PI = 3.14;

    // 3. Input operations
    cout << "===== C++ FUNDAMENTALS =====" << endl;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter your marks: ";
    cin >> marks;

    // 4. Arithmetic operators
    percentage = (marks / MAX_MARKS) * 100;

    // 5. Relational operators
    isStudent = (age >= 18);

    // 6. Conditional operator
    grade = (percentage >= 75) ? 'A' : 'B';

    // 7. Logical operator
    bool passed = (marks >= 40 && marks <= MAX_MARKS);

    // 8. Output operations
    cout << "\n===== STUDENT DETAILS =====" << endl;

    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Marks: " << marks << endl;
    cout << "Percentage: " << percentage << "%" << endl;
    cout << "Grade: " << grade << endl;

    cout << "\n===== OPERATOR DEMONSTRATION =====" << endl;

    cout << "Addition (10 + 5): " << 10 + 5 << endl;
    cout << "Subtraction (10 - 5): " << 10 - 5 << endl;
    cout << "Multiplication (10 * 5): " << 10 * 5 << endl;
    cout << "Division (10 / 5): " << 10 / 5 << endl;
    cout << "Remainder (10 % 3): " << 10 % 3 << endl;

    cout << "Is age >= 18? " << isStudent << endl;
    cout << "Is student passed? " << passed << endl;

    cout << "\nConstant PI: " << PI << endl;
    cout << "Maximum Marks: " << MAX_MARKS << endl;

    return 0;
}
