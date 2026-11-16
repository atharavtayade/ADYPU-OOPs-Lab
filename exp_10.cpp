#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    fstream file;
    string name;
    int rollNo, marks;

    // Create and open CSV file
    file.open("students.csv", ios::in | ios::out | ios::trunc);

    if (!file) {
        cout << "File opening failed!" << endl;
        return 1;
    }

    cout << "===== STUDENT RECORD MANAGEMENT =====" << endl;

    // Write CSV header
    file << "RollNo,Name,Marks\n";

    // Write student records
    file << "101,Atharav,95\n";
    file << "102,Rahul,85\n";
    file << "103,Aarti,90\n";

    // tellp(): Get current writing position
    cout << "\nWrite Position: " << file.tellp() << endl;

    // seekp(): Move writing pointer to end
    file.seekp(0, ios::end);
    cout << "After seekp(), Position: " << file.tellp() << endl;

    // Add another student record
    file << "104,Meenakshi,88\n";

    // Flush written data
    file.flush();

    // seekg(): Move reading pointer to beginning
    file.seekg(0, ios::beg);

    cout << "\n===== STUDENT RECORDS =====" << endl;

    // tellg(): Get current reading position
    cout << "Read Position: " << file.tellg() << endl;

    // Read and display CSV records
    string line;

    while (getline(file, line)) {
        cout << line << endl;
    }

    // Display final reading position
    cout << "\nFinal Read Position: " << file.tellg() << endl;

    // Close file
    file.close();

    cout << "\nFile operation completed successfully!" << endl;

    return 0;
}
