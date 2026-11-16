# ADYPU B.Tech AI & DS – OOPs Lab & Expense Tracker Mini Project

[![C++ Standard](https://img.shields.io/badge/C%2B%2B-11%2F14%2F17-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B)
[![University](https://img.shields.io/badge/University-Ajeenkya%20DY%20Patil%20University-purple.svg)]()
[![Department](https://img.shields.io/badge/Department-Artificial%20Intelligence%20%26%20Data%20Science-red.svg)]()
[![Status](https://img.shields.io/badge/Status-Complete-success.svg)]()

This repository contains the complete laboratory practical assignments (Experiments 01 to 10) and the capstone **Expense Tracker (Extended Version)** mini project for the **Object-Oriented Programming (OOPs Lab)** course, Department of Artificial Intelligence and Data Science at **Ajeenkya DY Patil University (ADYPU)**.

---

## Table of Contents

1. [Folder Structure](#1-folder-structure)
2. [Experiment Descriptions & Code Breakdown](#2-experiment-descriptions--code-breakdown)
3. [Mini Project: Expense Tracker (Extended Version)](#3-mini-project-expense-tracker-extended-version)
4. [Compilation & Execution Guide](#4-compilation--execution-guide)
5. [Git Version Control & Suggested Commits](#5-git-version-control--suggested-commits)
6. [Key OOPs Concepts & Viva Voce Q&A](#6-key-oops-concepts--viva-voce-qa)

---

## 1. Folder Structure

```text
OOPs Lab/
│
├── exp_01.cpp                      # Experiment 01: C++ Fundamentals
├── exp_02.cpp                      # Experiment 02: Classes and Objects (BankAccount & SavingsAccount)
├── exp_03.cpp                      # Experiment 03: Constructors & Rule of Five (Student Class)
├── exp_04.cpp                      # Experiment 04: Single & Multilevel Inheritance (University Management)
├── exp_05.cpp                      # Experiment 05: Runtime Polymorphism (Shape Hierarchy)
├── exp_06.cpp                      # Experiment 06: Compile-Time Polymorphism (Complex Numbers)
├── exp_07.cpp                      # Experiment 07: Generic Stack using Templates (int, float, string)
├── exp_08.cpp                      # Experiment 08: STL Containers & Algorithms (Student Marks Dataset)
├── exp_09.cpp                      # Experiment 09: Custom Banking Exception Hierarchy
├── exp_10.cpp                      # Experiment 10: CSV File Reader/Writer using File Pointers
│
├── Mini_Project/
│   └── Expense_Tracker/
│       ├── expence_tracker.cpp     # Complete C++ Expense Tracker (Extended Version)
│       └── README.md               # Mini Project Documentation & Walkthrough
│
└── README.md                       # Root Lab Documentation
```

---

## 2. Experiment Descriptions & Code Breakdown

### Experiment 01: C++ Fundamentals
- **File**: [`exp_01.cpp`](exp_01.cpp)
- **Concepts Demonstrated**:
  - Fundamental data types: `int`, `float`, `double`, `char`, `bool`, and `string`.
  - Constants: `const int MAX_MARKS = 100` and `const float PI = 3.14`.
  - Input operations: `getline(cin, name)` and stream extraction `cin >>`.
  - Arithmetic operators: `+`, `-`, `*`, `/`, `%` and percentage calculation `(marks / MAX_MARKS) * 100`.
  - Relational operators: `(age >= 18)`.
  - Conditional (ternary) operator: `grade = (percentage >= 75) ? 'A' : 'B'`.
  - Logical operators: `passed = (marks >= 40 && marks <= MAX_MARKS)`.
  - Formatted console output with `cout` and `endl`.

---

### Experiment 02: Classes and Objects
- **File**: [`exp_02.cpp`](exp_02.cpp)
- **Concepts Demonstrated**:
  - **Encapsulation**: Private data members (`accountNumber`, `balance`), protected member (`accountHolder`), and public member functions.
  - Base class **`BankAccount`**:
    - Constructor initializing account number, holder name, and balance.
    - Member function `deposit(double amount)` with validation (`amount > 0`).
    - Member function `displayDetails()` for account overview.
    - Public accessor `getBalance()` providing controlled access to private balance.
  - Derived class **`SavingsAccount`** (Single Inheritance):
    - Derived data member `interestRate`.
    - Constructor chaining to base class: `: BankAccount(accNo, name, bal)`.
    - Member function `calculateInterest()`: Computes interest using `getBalance() * interestRate / 100`.
    - Member function `displaySavings()` displaying full account details and interest rate.
  - Demonstrated with sample object: `SavingsAccount account(101, "Atharav", 10000, 5)`.

---

### Experiment 03: Constructors and the Rule of Five
- **File**: [`exp_03.cpp`](exp_03.cpp)
- **Concepts Demonstrated**:
  - Implementation of the **Rule of Five** for safe dynamic memory management:
    1. **Default Constructor**: `Student()` initializes `marks = nullptr`, `size = 0`.
    2. **Parameterized Constructor**: `Student(int n, int value)` dynamically allocates `marks = new int[size]` and populates elements.
    3. **Copy Constructor (Deep Copy)**: `Student(const Student& other)` allocates separate heap memory and copies elements to prevent pointer aliasing.
    4. **Move Constructor**: `Student(Student&& other) noexcept` steals pointer from rvalue object and sets source pointer to `nullptr`.
    5. **Copy Assignment Operator**: `Student& operator=(const Student& other)` with self-assignment check (`if (this != &other)`), frees old memory, and allocates deep copy.
    6. **Move Assignment Operator**: `Student& operator=(Student&& other) noexcept` frees existing buffer, transfers resource ownership, and resets source.
    7. **Destructor**: `~Student()` frees heap memory using `delete[] marks`.
  - Verified with `static_cast<Student&&>` to trigger move operations cleanly.

---

### Experiment 04: Single & Multilevel Inheritance
- **File**: [`exp_04.cpp`](exp_04.cpp)
- **Hierarchy**:
  $$\text{Person} \xrightarrow{\text{Single}} \text{Student} \xrightarrow{\text{Multilevel}} \text{GraduateStudent}$$
- **Concepts Demonstrated**:
  - **`Person` (Base Class)**: Protected attributes `name`, `age`; `displayPerson()`.
  - **`Student` (Single Inheritance)**: Inherits from `Person`, adds `rollNo`, `course`; calls `displayPerson()`, adds `displayStudent()`.
  - **`GraduateStudent` (Multilevel Inheritance)**: Inherits from `Student`, adds `researchTopic`, `guideName`; calls `displayStudent()`, adds `displayGraduate()`.
  - Observes constructor execution order: Base $\rightarrow$ Intermediate $\rightarrow$ Derived.
  - Tested with: `"Atharav"`, age 20, roll 101, course `"B.Tech AI & DS"`, topic `"Artificial Intelligence"`, guide `"Dr. Sharma"`.

---

### Experiment 05: Runtime Polymorphism
- **File**: [`exp_05.cpp`](exp_05.cpp)
- **Concepts Demonstrated**:
  - Abstract base class **`Shape`** with:
    - Pure virtual function: `virtual double area() = 0;`
    - Virtual function: `virtual void display()`
    - Virtual destructor: `virtual ~Shape() {}`
  - Derived classes overriding `area()` and `display()`:
    - **`Circle`**: `area() = 3.14 * radius * radius`
    - **`Rectangle`**: `area() = length * breadth`
    - **`Triangle`**: `area() = 0.5 * base * height`
  - Dynamic binding: Base class pointers (`Shape* s1, *s2, *s3`) bound to derived objects at runtime (`s1 = &c; s1->display();`).

---

### Experiment 06: Compile-Time Polymorphism
- **File**: [`exp_06.cpp`](exp_06.cpp)
- **Concepts Demonstrated**:
  - **`Complex`** class with private data members `float real, imag`.
  - **Function Overloading**:
    - `display()`: Prints `real + imag i`.
    - `display(string message)`: Prints a custom message prefix before the complex number.
  - **Operator Overloading**:
    - `Complex operator+(Complex c)`: Adds real and imaginary parts of two complex numbers.
    - `Complex operator-(Complex c)`: Subtracts real and imaginary parts of two complex numbers.
  - Tested with: $c_1(10, 5)$ and $c_2(4, 3) \implies c_1 + c_2 = 14 + 8i$, $c_1 - c_2 = 6 + 2i$.

---

### Experiment 07: Generic Stack using Templates
- **File**: [`exp_07.cpp`](exp_07.cpp)
- **Concepts Demonstrated**:
  - Template class: `template <class T> class Stack`.
  - Fixed-size array buffer `T arr[100]` and `int top`.
  - Member functions:
    - `push(T value)`: Pushes value, with stack overflow check (`top == 99`).
    - `pop()`: Pops value, with stack underflow check (`top == -1`).
    - `display()`: Displays all elements from top to bottom.
  - Type genericity tested with three distinct types:
    - `Stack<int>` (values: 10, 20, 30)
    - `Stack<float>` (values: 10.5, 20.5, 30.5)
    - `Stack<string>` (values: `"Hello"`, `"C++"`, `"Programming"`)

---

### Experiment 08: STL Containers & Algorithms
- **File**: [`exp_08.cpp`](exp_08.cpp)
- **Concepts Demonstrated**:
  - **`std::vector<pair<string, int>>`**: Dynamic list of student marks (`{"Atharav", 95}`, `{"Rahul", 85}`, `{"Aarti", 90}`, `{"Meenakshi", 76}`, `{"Rohan", 70}`).
  - **`std::sort`**: Sorts students in descending order of marks using a lambda comparator (`[](auto a, auto b) { return a.second > b.second; }`).
  - **`std::find_if`**: Searches for the first student scoring marks $> 85$.
  - **`std::transform`**: Computes percentages (`percentages[i] = s.second / 5.0f`).
  - **`std::map<string, string>`**: Stores student grades (`A+` for $\ge 90$, `A` for $\ge 80$, `B` for $\ge 70$, `C` otherwise).
  - **`std::unordered_map<int, string>`**: Hash table storing roll numbers to student names (Rolls 101 to 105).

---

### Experiment 09: Custom Exception Hierarchy
- **File**: [`exp_09.cpp`](exp_09.cpp)
- **Concepts Demonstrated**:
  - Custom exception inheritance from `std::exception`:
    - Base: `class BankException : public exception` with `const char* what() const noexcept override`.
    - Derived: `class InsufficientBalance : public BankException`.
    - Derived: `class InvalidAmount : public BankException`.
  - `BankAccount` class with balance validation:
    - `deposit(double amount)`: Throws `InvalidAmount` if `amount <= 0`.
    - `withdraw(double amount)`: Throws `InvalidAmount` if `amount <= 0`, throws `InsufficientBalance` if `amount > balance`.
  - `try`, `throw`, and `catch` blocks with polymorphic and specific exception catching.

---

### Experiment 10: CSV File Reader/Writer with File Pointers
- **File**: [`exp_10.cpp`](exp_10.cpp)
- **Concepts Demonstrated**:
  - File stream operations using `fstream file`.
  - Opens `"students.csv"` with mode `ios::in | ios::out | ios::trunc`.
  - Writes CSV header (`RollNo,Name,Marks`) and initial records (`101,Atharav,95`, `102,Rahul,85`, `103,Aarti,90`).
  - Direct stream pointer manipulation:
    - **`tellp()`**: Queries current write position.
    - **`seekp(0, ios::end)`**: Moves write pointer to end of file to append record (`104,Meenakshi,88`).
    - **`file.flush()`**: Flushes write buffer to disk.
    - **`seekg(0, ios::beg)`**: Rewinds read pointer to the beginning of the file.
    - **`tellg()`**: Queries current read position.
  - Reads and displays records row by row using `getline(file, line)`.

---

## 3. Mini Project: Expense Tracker (Extended Version)

- **File**: [`Mini_Project/Expense_Tracker/expence_tracker.cpp`](Mini_Project/Expense_Tracker/expence_tracker.cpp)
- **Documentation**: [`Mini_Project/Expense_Tracker/README.md`](Mini_Project/Expense_Tracker/README.md)

### Key Features:
1. **Abstract Base Class `Expense`**: Defines `# name`, `# amount`, default, parameterized, and copy constructors, virtual destructor, pure virtual `virtual void display() const = 0;`, overloaded `show()` functions, and friend function `showDetails()`.
2. **Derived Categories**: `Food`, `Travel`, `Clothing`, `Accommodation`, and `Savings`.
3. **Savings Isolation**: `Savings::isSaving()` returns `true`. The friend function `totalExpense()` skips savings records, ensuring **savings are never included in total expenses**.
4. **Stack Data Structure**: Array of 20 pointers (`Expense *records[20]`, `top`), with `push()`, `pop()`, and polymorphic `displayAll()`.
5. **Memory Safety**: `pop()` deletes removed records; the `~Stack()` destructor frees all remaining records on exit.
6. **10-Option Menu**: Add Food, Travel, Clothing, Accommodation, Savings, Remove Last Record, Display All Records, Show Total Expenses, Show Total Savings, and Exit.

---

## 4. Compilation & Execution Guide

### Compiling Experiments:
Each experiment compiles independently using standard `g++`:

```bash
# Experiment 01
g++ exp_01.cpp -o exp_01
./exp_01

# Experiment 02
g++ exp_02.cpp -o exp_02
./exp_02

# Experiment 03
g++ exp_03.cpp -o exp_03
./exp_03

# Experiment 04
g++ exp_04.cpp -o exp_04
./exp_04

# Experiment 05
g++ exp_05.cpp -o exp_05
./exp_05

# Experiment 06
g++ exp_06.cpp -o exp_06
./exp_06

# Experiment 07
g++ exp_07.cpp -o exp_07
./exp_07

# Experiment 08
g++ exp_08.cpp -o exp_08
./exp_08

# Experiment 09
g++ exp_09.cpp -o exp_09
./exp_09

# Experiment 10
g++ exp_10.cpp -o exp_10
./exp_10
```

### Compiling and Running the Mini Project:
```bash
cd Mini_Project/Expense_Tracker
g++ expence_tracker.cpp -o expence_tracker
./expence_tracker
```
*(On Windows Command Prompt / PowerShell, run `expence_tracker.exe`)*

---

## 5. Git Version Control & Suggested Commits

You can push this repository to your GitHub profile using the following clean commit sequence:

```bash
# Initialize git repository
git init

# Configure user details
git config user.name "Your Name"
git config user.email "your.email@adypu.edu.in"

# Sequential commits for experiments
git add exp_01.cpp && git commit -m "Add experiment 01 - C++ fundamentals"
git add exp_02.cpp && git commit -m "Add experiment 02 - Classes and objects"
git add exp_03.cpp && git commit -m "Add experiment 03 - Rule of Five"
git add exp_04.cpp && git commit -m "Add experiment 04 - Inheritance"
git add exp_05.cpp && git commit -m "Add experiment 05 - Runtime polymorphism"
git add exp_06.cpp && git commit -m "Add experiment 06 - Operator overloading"
git add exp_07.cpp && git commit -m "Add experiment 07 - Templates"
git add exp_08.cpp && git commit -m "Add experiment 08 - STL containers and algorithms"
git add exp_09.cpp && git commit -m "Add experiment 09 - Custom exception handling"
git add exp_10.cpp && git commit -m "Add experiment 10 - CSV file handling"

# Mini project commit
git add Mini_Project/ README.md
git commit -m "Add Expense Tracker mini project"

# Push to your GitHub repository
git branch -M main
git remote add origin https://github.com/<your-username>/oops-lab.git
git push -u origin main
```

---

## 6. Key OOPs Concepts & Viva Voce Q&A

1. **Q: What is the Rule of Five in C++?**
   - **A**: If a class manages dynamic resources, it should explicitly implement: Destructor, Copy Constructor, Copy Assignment Operator, Move Constructor, and Move Assignment Operator.

2. **Q: What is a pure virtual function?**
   - **A**: A virtual function declared with `= 0` in a base class (e.g., `virtual void display() const = 0;`). It has no implementation in the base class and makes the class abstract, forcing all derived classes to override it.

3. **Q: Why is a virtual destructor necessary?**
   - **A**: When deleting a derived object via a base-class pointer (`delete basePtr`), a virtual destructor ensures the derived class destructor is called first, preventing memory leaks and undefined behavior.

4. **Q: What is the difference between `tellp()` and `tellg()`?**
   - **A**: `tellp()` returns the current position of the **put/write** pointer in an output stream, while `tellg()` returns the current position of the **get/read** pointer in an input stream.

5. **Q: How does the Expense Tracker keep savings separate from expenses?**
   - **A**: The base class `Expense` defines `virtual bool isSaving() const { return false; }`, and `Savings` overrides it to return `true`. In `totalExpense()`, the condition `if (!s.records[i]->isSaving())` ensures savings are excluded from total expenses.

---

*Author: B.Tech Artificial Intelligence and Data Science Student, ADYPU*  
*Course: Object-Oriented Programming (OOPs Lab)*
