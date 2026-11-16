
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

int main() {

    // Student marks dataset using vector
    vector<pair<string, int>> students = {
        {"Atharav", 95},
        {"Rahul", 85},
        {"Aarti", 90},
        {"Meenakshi", 76},
        {"Rohan", 70}
    };

    // Display original data
    cout << "===== STUDENT MARKS =====" << endl;

    for (auto s : students) {
        cout << s.first << " : " << s.second << endl;
    }

    // Sort students by marks (descending)
    sort(students.begin(), students.end(),
         [](auto a, auto b) {
             return a.second > b.second;
         });

    cout << "\n===== SORTED MARKS =====" << endl;

    for (auto s : students) {
        cout << s.first << " : " << s.second << endl;
    }

    // Find student with marks greater than 85
    auto it = find_if(students.begin(), students.end(),
                      [](auto s) {
                          return s.second > 85;
                      });

    cout << "\n===== FIND STUDENT =====" << endl;

    if (it != students.end()) {
        cout << "Student: " << it->first
             << ", Marks: " << it->second << endl;
    }

    // Transform marks into percentage
    vector<float> percentages(students.size());

    transform(students.begin(), students.end(),
              percentages.begin(),
              [](auto s) {
                  return s.second / 5.0f;
              });

    cout << "\n===== PERCENTAGES =====" << endl;

    for (int i = 0; i < students.size(); i++) {
        cout << students[i].first << " : "
             << percentages[i] << "%" << endl;
    }

    // Map: Store student grades
    map<string, string> grades;

    for (auto s : students) {
        if (s.second >= 90)
            grades[s.first] = "A+";
        else if (s.second >= 80)
            grades[s.first] = "A";
        else if (s.second >= 70)
            grades[s.first] = "B";
        else
            grades[s.first] = "C";
    }

    cout << "\n===== STUDENT GRADES (MAP) =====" << endl;

    for (auto g : grades) {
        cout << g.first << " : " << g.second << endl;
    }

    // Unordered_map: Store student roll numbers
    unordered_map<int, string> rollNumbers;

    rollNumbers[101] = "Atharav";
    rollNumbers[102] = "Rahul";
    rollNumbers[103] = "Aarti";
    rollNumbers[104] = "Meenakshi";
    rollNumbers[105] = "Rohan";

    cout << "\n===== ROLL NUMBER DATA =====" << endl;

    for (auto r : rollNumbers) {
        cout << r.first << " : " << r.second << endl;
    }

    return 0;
}
