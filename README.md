# ADYPU B.Tech AI & DS – Object-Oriented Programming (OOPs Lab) & Mini Project

[![C++ Standard](https://img.shields.io/badge/C%2B%2B-14%2F17-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B17)
[![University](https://img.shields.io/badge/University-Ajeenkya%20DY%20Patil%20University-purple.svg)]()
[![Department](https://img.shields.io/badge/Department-Artificial%20Intelligence%20%26%20Data%20Science-red.svg)]()
[![Status](https://img.shields.io/badge/Status-Lab%20Submission%20Ready-success.svg)]()

This repository contains the complete laboratory practical assignments (Experiments 01 to 10) and the capstone **Expense Tracker (Extended Version)** mini project for the **Object-Oriented Programming with C++** course, Department of Artificial Intelligence and Data Science at **Ajeenkya DY Patil University (ADYPU)**.

---

## Table of Contents

1. [Repository Overview](#repository-overview)
2. [Project Folder Structure](#project-folder-structure)
3. [Summary of 10 Lab Experiments](#summary-of-10-lab-experiments)
4. [Mini Project – Expense Tracker (Extended Version)](#mini-project--expense-tracker-extended-version)
5. [Prerequisites & Compiler Requirements](#prerequisites--compiler-requirements)
6. [Compilation and Execution Guide](#compilation-and-execution-guide)
7. [Git Version Control & Suggested Commit Workflow](#git-version-control--suggested-commit-workflow)
8. [Viva Voce Preparation & Key OOPs Q&A](#viva-voce-preparation--key-oops-qa)

---

## 1. Repository Overview

Each experiment is written in standard modern C++ (C++14/C++17), following clean coding standards, extensive comments explaining underlying compiler mechanics, safe dynamic memory allocation, and robust input validation.

| Exp No. | File Name | Experiment Title | Core OOPs Concept |
| :---: | :--- | :--- | :--- |
| **01** | `exp_01.cpp` | C++ Fundamentals | Data types, constants, operators, console I/O |
| **02** | `exp_02.cpp` | Classes and Objects | Encapsulation, access specifiers (`private`, `protected`, `public`) |
| **03** | `exp_03.cpp` | Constructors & Rule of Five | Deep copy, move semantics, RAII, zero memory leaks |
| **04** | `exp_04.cpp` | Inheritance Hierarchies | Single & Multilevel inheritance, constructor/destructor ordering |
| **05** | `exp_05.cpp` | Runtime Polymorphism | Abstract base class, pure virtual functions, dynamic dispatch (`VTABLE`) |
| **06** | `exp_06.cpp` | Compile-Time Polymorphism | Function overloading, operator overloading (`+`, `-`, `*`, `<<`, `>>`) |
| **07** | `exp_07.cpp` | Generic Stack Templates | Template classes, type genericity (`int`, `float`, `string`), exceptions |
| **08** | `exp_08.cpp` | STL Containers & Algorithms | `std::vector`, `map`, `unordered_map`, `sort`, `find_if`, `transform` |
| **09** | `exp_09.cpp` | Custom Exception Hierarchy | Custom exceptions inheriting from `std::exception`, polymorphic catch |
| **10** | `exp_10.cpp` | CSV File Reader & Writer | File I/O (`fstream`), stream pointers (`seekg`, `seekp`, `tellg`, `tellp`) |
| **Capstone**| `Mini_Project/` | Expense Tracker Mini Project | End-to-end OOP system: ABC, inheritance, stack, friend functions |

---

## 2. Project Folder Structure

```text
OOPs Lab/
│
├── exp_01.cpp                  # Experiment 01: C++ Fundamentals
├── exp_02.cpp                  # Experiment 02: Classes and Objects
├── exp_03.cpp                  # Experiment 03: Constructors & Rule of Five
├── exp_04.cpp                  # Experiment 04: Inheritance
├── exp_05.cpp                  # Experiment 05: Runtime Polymorphism
├── exp_06.cpp                  # Experiment 06: Compile-Time Polymorphism
├── exp_07.cpp                  # Experiment 07: Generic Stack using Templates
├── exp_08.cpp                  # Experiment 08: STL Containers & Algorithms
├── exp_09.cpp                  # Experiment 09: Custom Exception Hierarchy
├── exp_10.cpp                  # Experiment 10: CSV File Reader/Writer
│
├── Mini_Project/
│   └── Expense_Tracker/
│       ├── include/            # Header interface files (.h)
│       │   ├── Expense.h       # Abstract base class
│       │   ├── Food.h          # Derived category: Food
│       │   ├── Travel.h        # Derived category: Travel
│       │   ├── Clothing.h      # Derived category: Clothing
│       │   ├── Accommodation.h # Derived category: Accommodation
│       │   ├── Savings.h       # Derived category: Savings (isSaving = true)
│       │   └── Stack.h         # LIFO stack (capacity 20) with friend functions
│       │
│       ├── src/                # Implementation source files (.cpp)
│       │   ├── Expense.cpp
│       │   ├── Food.cpp
│       │   ├── Travel.cpp
│       │   ├── Clothing.cpp
│       │   ├── Accommodation.cpp
│       │   ├── Savings.cpp
│       │   ├── Stack.cpp
│       │   └── main.cpp        # Application entry point & interactive menu
│       │
│       ├── docs/               # Architecture diagrams and documentation
│       │   └── UML_Diagram.png # High-resolution UML Class Diagram
│       │
│       ├── README.md           # Dedicated Mini Project documentation
│       └── .gitignore          # Mini project ignore rules
│
├── README.md                   # Root documentation and lab manual
└── .gitignore                  # Root Git ignore rules (binaries, build artifacts)
```

---

## 3. Summary of 10 Lab Experiments

### Experiment 01 – C++ Fundamentals (`exp_01.cpp`)
- Demonstrates primitive types (`int`, `float`, `double`, `char`, `bool`), string objects, and storage sizes using `sizeof`.
- Illustrates constant variables (`const double PI`, `const int MAX_SCORE`) preventing inadvertent mutation.
- Demonstrates arithmetic, relational, and logical operators with formatted output (`iomanip`).
- Implements interactive console I/O using `cin` and `cout`.

### Experiment 02 – Classes and Objects (`exp_02.cpp`)
- Models a `BankAccount` system demonstrating the three access specifiers:
  - `private`: Hides critical state variables (`accountNumber`, `balance`, `transactionCount`).
  - `protected`: Exposes holder details (`ownerName`, `contactNumber`) to derived entities.
  - `public`: Exposes validated business methods (`deposit`, `withdraw`, `displayAccountSummary`).
- Strictly enforces encapsulation through validation guards.

### Experiment 03 – Constructors and Rule of Five (`exp_03.cpp`)
- Demonstrates the canonical **Rule of Five** for dynamic resource management:
  1. Default constructor (initializes empty state).
  2. Parameterized constructor (allocates heap buffer).
  3. Copy constructor (performs deep copy to prevent pointer aliasing).
  4. Move constructor (steals buffer pointer from rvalue reference `&&`).
  5. Copy assignment operator (guards self-assignment `this == &other` & performs deep copy).
  6. Move assignment operator (transfers ownership cleanly).
  7. Destructor (safely deallocates array memory using `delete[]`).

### Experiment 04 – Inheritance Hierarchies (`exp_04.cpp`)
- Implements an academic university management hierarchy:
  $$\text{Person} \longrightarrow \text{Student} \longrightarrow \text{GraduateStudent}$$
- Demonstrates **Single Inheritance** (`Person` to `Student`) and **Multilevel Inheritance** (`Person` to `Student` to `GraduateStudent`).
- Logs constructor execution order (Base $\rightarrow$ Intermediate $\rightarrow$ Derived) and destructor reverse destruction order.
- Demonstrates member function reuse via explicit scope resolution (`Person::displayInfo()`).

### Experiment 05 – Runtime Polymorphism (`exp_05.cpp`)
- Builds an abstract `Shape` class containing pure virtual functions:
  $$\text{virtual double area() const = 0;}$$
- Derives concrete shapes: `Circle`, `Rectangle`, and `Triangle`.
- Demonstrates dynamic binding at runtime via base class pointers and references through the Virtual Table (`VTABLE`).
- Employs a `virtual ~Shape()` destructor to prevent undefined behavior during polymorphic deletions.

### Experiment 06 – Compile-Time Polymorphism (`exp_06.cpp`)
- Implements static polymorphism using a `Complex` number class.
- Demonstrates **Function Overloading**: Multiple `display()` methods with differing signatures.
- Demonstrates **Operator Overloading**: Overloads binary operators `+`, `-`, `*`, `==`.
- Overloads stream insertion `operator<<` and extraction `operator>>` for natural stream syntax.
- Replicates lab syllabus prompt: First number ($2 + 3i$) + Second number ($4 + 5i$) = Sum ($6 + 8i$).

### Experiment 07 – Generic Stack using Templates (`exp_07.cpp`)
- Implements a generic `Stack<T>` class template parameterized over arbitrary types.
- Provides essential operations: `push()`, `pop()`, `peek()`, `display()`, `isEmpty()`, `isFull()`.
- Incorporates robust boundary checks throwing `std::underflow_error` and handling overflow.
- Instantiated and verified with `int`, `float`, and `std::string`.

### Experiment 08 – STL Containers and Algorithms (`exp_08.cpp`)
- Processes a realistic student marks dataset using the C++ Standard Template Library.
- Utilizes containers:
  - `std::vector` for sequential student records.
  - `std::map` for ordered roll number search.
  - `std::unordered_map` for $O(1)$ grade frequency distribution counting.
- Employs STL algorithms:
  - `std::sort()` with lambda comparator for descending marks ranking.
  - `std::transform()` for percentage calculation and grade assignment.
  - `std::find_if()` to locate distinction scorers ($\ge 85\%$).

### Experiment 09 – Custom Exception Hierarchy (`exp_09.cpp`)
- Implements custom exception classes derived from `std::exception`:
  - Base: `BankException`
  - Derived: `InsufficientBalanceException` (tracks balance deficit)
  - Derived: `InvalidAmountException` (flags negative or zero amounts)
- Implements `try`, `throw`, and `catch` blocks with polymorphic base reference catching (`catch (const BankException& e)`).

### Experiment 10 – CSV File Reader/Writer (`exp_10.cpp`)
- Implements persistent student record storage using C++ file streams (`std::fstream`, `ifstream`, `ofstream`).
- Automatically creates `student_records.csv` if absent.
- Appends and reads comma-separated records.
- Directly demonstrates file stream pointers:
  - `seekp()` & `tellp()` for write position navigation.
  - `seekg()` & `tellg()` for read position seeking and byte size calculation.

---

## 4. Mini Project – Expense Tracker (Extended Version)

The **Expense Tracker Mini Project** is located in `Mini_Project/Expense_Tracker/`. It complies with all architectural, functional, and academic specifications outlined in the curriculum reference PDF.

### Key Architecture:
- **`Expense`**: Abstract Base Class (`name`, `amount`, pure virtual `display()`, virtual destructor, overloaded `show()`, friend `showDetails()`).
- **Category Subclasses**: `Food`, `Travel`, `Clothing`, `Accommodation`, and `Savings`.
- **Business Rule**: `Savings::isSaving()` returns `true`. The friend function `totalExpense()` filters out savings records, guaranteeing that **savings are never added into total expenses**.
- **`Stack`**: Fixed-capacity array storing up to 20 `Expense*` pointers with runtime polymorphic dispatch and memory leak protection.
- **UML Diagram**: Located at `Mini_Project/Expense_Tracker/docs/UML_Diagram.png`.

---

## 5. Prerequisites & Compiler Requirements

- **C++ Compiler**: GCC (`g++`) version 6.0+ or Clang or MSVC.
- **Standard**: C++14 or C++17 (`-std=c++14` or `-std=c++17`).
- **Operating System**: Windows, Linux, or macOS.

> **Windows Security Note**: On Windows 11 with *Smart App Control* enabled, newly compiled local `.exe` files created without a digital certificate may trigger a security notification when executed from untrusted directories. To test executables smoothly, use VS Code's integrated runner or add your project workspace folder to Windows Defender's Exclusion list.

> **Memory Verification (Valgrind)**: Valgrind is a Linux-native tool. On Windows systems without WSL, memory correctness is verified through rigorous RAII compliance, virtual destructors, and explicit delete sweeps in destructors. On Linux/WSL, execute `valgrind --leak-check=full ./<executable>`.

---

## 6. Compilation and Execution Guide

### Compiling Individual Experiments:

```bash
# Experiment 01: C++ Fundamentals
g++ -std=c++14 -Wall -Wextra exp_01.cpp -o exp_01
./exp_01

# Experiment 02: Classes and Objects
g++ -std=c++14 -Wall -Wextra exp_02.cpp -o exp_02
./exp_02

# Experiment 03: Constructors & Rule of Five
g++ -std=c++14 -Wall -Wextra exp_03.cpp -o exp_03
./exp_03

# Experiment 04: Inheritance
g++ -std=c++14 -Wall -Wextra exp_04.cpp -o exp_04
./exp_04

# Experiment 05: Runtime Polymorphism
g++ -std=c++14 -Wall -Wextra exp_05.cpp -o exp_05
./exp_05

# Experiment 06: Compile-Time Polymorphism
g++ -std=c++14 -Wall -Wextra exp_06.cpp -o exp_06
./exp_06

# Experiment 07: Generic Stack Templates
g++ -std=c++14 -Wall -Wextra exp_07.cpp -o exp_07
./exp_07

# Experiment 08: STL Containers & Algorithms
g++ -std=c++14 -Wall -Wextra exp_08.cpp -o exp_08
./exp_08

# Experiment 09: Custom Exception Hierarchy
g++ -std=c++14 -Wall -Wextra exp_09.cpp -o exp_09
./exp_09

# Experiment 10: CSV File Reader/Writer
g++ -std=c++14 -Wall -Wextra exp_10.cpp -o exp_10
./exp_10
```

### Compiling and Running the Expense Tracker Mini Project:

From the `Mini_Project/Expense_Tracker/` directory:

```bash
cd Mini_Project/Expense_Tracker
g++ -std=c++14 -Wall -Wextra -Iinclude src/*.cpp -o expense_tracker
./expense_tracker
```

---

## 7. Git Version Control & Suggested Commit Workflow

To push this repository to your personal GitHub profile, run the following commands in your terminal:

```bash
# Initialize local Git repository
git init

# Configure user identity
git config user.name "Your Name"
git config user.email "your.email@adypu.edu.in"

# Commit Experiment 01
git add exp_01.cpp
git commit -m "Add experiment 01 - C++ fundamentals"

# Commit Experiment 02
git add exp_02.cpp
git commit -m "Add experiment 02 - Classes and objects"

# Commit Experiment 03
git add exp_03.cpp
git commit -m "Add experiment 03 - Rule of Five"

# Commit Experiment 04
git add exp_04.cpp
git commit -m "Add experiment 04 - Inheritance"

# Commit Experiment 05
git add exp_05.cpp
git commit -m "Add experiment 05 - Runtime polymorphism"

# Commit Experiment 06
git add exp_06.cpp
git commit -m "Add experiment 06 - Operator overloading"

# Commit Experiment 07
git add exp_07.cpp
git commit -m "Add experiment 07 - Templates"

# Commit Experiment 08
git add exp_08.cpp
git commit -m "Add experiment 08 - STL containers and algorithms"

# Commit Experiment 09
git add exp_09.cpp
git commit -m "Add experiment 09 - Custom exception handling"

# Commit Experiment 10
git add exp_10.cpp
git commit -m "Add experiment 10 - CSV file handling"

# Commit Mini Project & Documentation
git add Mini_Project/ README.md .gitignore
git commit -m "Add Expense Tracker mini project"

# Link to GitHub remote and push (replace with your repo URL)
git branch -M main
git remote add origin https://github.com/<your-username>/oops-lab-adypu.git
git push -u origin main
```

---

## 8. Viva Voce Preparation & Key OOPs Q&A

1. **Q: Why must a base class destructor be declared `virtual`?**
   - **A**: If a derived class object is deleted through a base class pointer (`delete basePtr;`), declaring the base destructor `virtual` ensures the derived class destructor executes first, followed by the base class destructor. Without `virtual`, only the base destructor runs, causing resource leaks.

2. **Q: What is the difference between shallow copy and deep copy?**
   - **A**: Shallow copy copies pointer values directly, causing both objects to point to the exact same heap memory block (leading to double-free corruption). Deep copy allocates new memory and duplicates the underlying data.

3. **Q: What is the Rule of Five in modern C++?**
   - **A**: If a class manages dynamic resources and implements any one of: Destructor, Copy Constructor, Copy Assignment, Move Constructor, or Move Assignment Operator, it should explicitly implement all five.

4. **Q: How does dynamic dispatch work internally?**
   - **A**: Classes containing virtual functions have an internal **Virtual Table (`VTABLE`)** containing pointers to their virtual functions. Each object contains a hidden pointer (**`VPTR`**) pointing to this table, resolved at runtime.

5. **Q: In the Expense Tracker, how are savings kept separate from expenses?**
   - **A**: The base class `Expense` defines `virtual bool isSaving() const { return false; }`. The derived class `Savings` overrides it to return `true`. When calculating expenses, `totalExpense()` skips any record where `isSaving()` is `true`.

---

*Author: B.Tech Artificial Intelligence and Data Science Student, ADYPU*  
*Academic Year: 2024–2026*
