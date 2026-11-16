# C++ Expense Tracker – Extended Version

[![C++ Standard](https://img.shields.io/badge/C%2B%2B-14%2F17-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B17)
[![Course](https://img.shields.io/badge/Course-OOPs%20Lab-orange.svg)]()
[![Institution](https://img.shields.io/badge/ADYPU-AI%20%26%20Data%20Science-red.svg)]()

> A modular, console-based personal finance and expense management application written in standard C++ showcasing core **Object-Oriented Programming (OOP)** paradigms.

---

## 1. Project Introduction

The **Expense Tracker (Extended Version)** is an academic mini project designed for the second-year B.Tech in Artificial Intelligence & Data Science curriculum at **Ajeenkya DY Patil University (ADYPU)**.

The software enables users to track daily financial outflows across essential living categories while isolating future-focused savings reserves from general operational expenditures.

---

## 2. Problem Statement

Students and young professionals frequently face difficulties tracking categorized daily expenditures and distinguishing between **active consumption expenses** (food, travel, clothing, lodging) and **savings reserves**. Traditional monolithic budgeting programs often mingle savings with regular spending or suffer from memory leaks and rigid architecture.

This project addresses these challenges by delivering:
- Strict mathematical segregation between **spending** and **savings**.
- Clean **modular class hierarchy** adhering to the Single Responsibility Principle.
- Safe in-memory **LIFO stack management** preventing dangling pointers and dynamic memory leaks.

---

## 3. Objectives

1. Implement an **Abstract Base Class (`Expense`)** with pure virtual functions.
2. Model real-world spending using **five derived category classes** (`Food`, `Travel`, `Clothing`, `Accommodation`, `Savings`).
3. Enforce business rules where **Savings are stored as a distinct record type and excluded from total expenses**.
4. Manage records dynamically in memory via a custom **Stack** (maximum capacity: 20 records).
5. Demonstrate runtime polymorphism through base-class pointers (`Expense*`).
6. Apply **encapsulation**, **constructors**, **copy constructors**, **virtual destructors**, **function overloading**, and **friend functions**.

---

## 4. Key Features

- **Five Tailored Record Categories**:
  1. **Food**: Meals, groceries, snacks.
  2. **Travel**: Bus, train, fuel, taxi.
  3. **Clothing**: Clothes, footwear, accessories.
  4. **Accommodation**: Rent, hostel fees, hotel stays.
  5. **Savings**: Emergency reserves and future funds.
- **Segregated Totals Calculation**:
  - `totalExpense()` calculates the sum of categories 1 through 4.
  - `totalSavings()` calculates the sum of category 5 only.
- **In-Memory Stack History**:
  - Capacity strictly capped at **20 records**.
  - Last-in, First-out (LIFO) record removal via `pop()`.
  - Overflow detection (`top == 19`) and underflow prevention (`top == -1`).
- **Safe Dynamic Memory Management**:
  - Automatically deallocates popped records.
  - Destructor iterates through remaining records on application exit, ensuring zero memory leaks.

---

## 5. Application Menu Structure

Upon execution, the application presents the following interactive menu:

```text
===== EXPENSE TRACKER =====
1. Add Food Expense
2. Add Travel Expense
3. Add Clothing Expense
4. Add Accommodation Expense
5. Add Savings
6. Remove Last Record
7. Display All Records
8. Show Total Expenses
9. Show Total Savings
0. Exit
Enter your choice: 
```

### Menu Options Explanation:
- **Options 1 to 5**: Prompts for a single-word record name and a positive monetary amount (`amount > 0`). Instantiates a heap-allocated derived object and pushes it to the stack.
- **Option 6 (`Remove Last Record`)**: Deletes the most recently added item from the stack and reclaims memory.
- **Option 7 (`Display All Records`)**: Iterates from bottom to top, invoking each record's polymorphic `display()` method.
- **Option 8 (`Show Total Expenses`)**: Invokes friend function `totalExpense(s)` to sum only non-savings records.
- **Option 9 (`Show Total Savings`)**: Invokes friend function `totalSavings(s)` to sum savings records.
- **Option 0 (`Exit`)**: Exits the program and triggers the `Stack` destructor to clean up memory.

---

## 6. OOP Concepts Demonstrated

| Concept | Location in Code | Purpose / Academic Significance |
| :--- | :--- | :--- |
| **Class & Object** | `Expense`, `Food`, `Travel`, `Clothing`, `Accommodation`, `Savings`, `Stack` | Object modeling of real-world entities. |
| **Encapsulation** | `protected: name, amount;`, `private: records[20], top;` | Information hiding and controlled access. |
| **Abstraction** | `class Expense` | High-level interface hiding concrete implementations. |
| **Pure Virtual Function** | `virtual void display() const = 0;` | Defines mandatory contract for derived subclasses. |
| **Inheritance** | `Food : public Expense`, etc. | Code reusability and hierarchical categorization. |
| **Runtime Polymorphism** | `records[i]->display();` | Dynamic binding resolved at runtime via VTABLE. |
| **Virtual Destructor** | `virtual ~Expense()` | Prevents undefined behavior during polymorphic `delete`. |
| **Constructor Overloading** | Default & Parameterized constructors across classes | Flexible object initialization. |
| **Copy Constructor** | `Expense(const Expense &e)` | Demonstrates deep copy semantics in base class. |
| **Function Overloading** | `show()` and `show(string message)` | Compile-time polymorphism with matching names. |
| **Friend Functions** | `showDetails()`, `totalExpense()`, `totalSavings()` | Allows controlled external access to private data. |
| **Dynamic Memory Allocation** | `new Food(...)`, `delete records[top]` | Heap memory management with RAII principles. |
| **Data Structure (Stack)** | Array-based fixed capacity LIFO buffer | Real-world application of stack operations. |

---

## 7. Class Architecture

```
                  ┌───────────────────────────────┐
                  │    <<abstract>> Expense       │
                  ├───────────────────────────────┤
                  │ # name : string               │
                  │ # amount : float              │
                  ├───────────────────────────────┤
                  │ + Expense()                   │
                  │ + Expense(n, a)               │
                  │ + Expense(e: const Expense&)  │
                  │ + virtual ~Expense()          │
                  │ + getAmount() : float         │
                  │ + virtual isSaving() : bool   │
                  │ + virtual display() = 0       │
                  │ + show() : void               │
                  │ + show(msg: string) : void    │
                  └───────────────▲───────────────┘
                                  │
      ┌───────────┬───────────────┼───────────────┬────────────┐
      │           │               │               │            │
┌─────┴────┐ ┌────┴─────┐ ┌───────┴──────┐ ┌──────┴──────┐ ┌───┴─────┐
│   Food   │ │  Travel  │ │   Clothing   │ │Accommodation│ │ Savings │
└──────────┘ └──────────┘ └──────────────┘ └─────────────┘ └─────────┘
```

A high-resolution visual UML diagram is available in [docs/UML_Diagram.png](docs/UML_Diagram.png).

---

## 8. Compilation and Execution

### Prerequisites:
- Any standard C++ compiler (`g++`, `clang++`, or MSVC) supporting C++14 or C++17.

### Compilation Command:
From the `Mini_Project/Expense_Tracker/` directory:

```bash
g++ -std=c++14 -Wall -Wextra -Iinclude src/*.cpp -o expense_tracker
```

Or from the root `OOPs Lab/` directory:

```bash
g++ -std=c++14 -Wall -Wextra -IMini_Project/Expense_Tracker/include Mini_Project/Expense_Tracker/src/*.cpp -o expense_tracker
```

### Execution:
```bash
./expense_tracker
```
*(On Windows: `expense_tracker.exe`)*

---

## 9. Sample Program Walkthrough

The following sequence replicates the exact test scenario specified in the curriculum reference:

1. **Add Food Expense**:
   - Choice: `1`
   - Record Name: `Lunch`
   - Amount: `150`
2. **Add Travel Expense**:
   - Choice: `2`
   - Record Name: `Bus`
   - Amount: `50`
3. **Add Clothing Expense**:
   - Choice: `3`
   - Record Name: `Shoes`
   - Amount: `1200`
4. **Add Accommodation Expense**:
   - Choice: `4`
   - Record Name: `Hostel`
   - Amount: `3000`
5. **Add Savings**:
   - Choice: `5`
   - Record Name: `EmergencyFund`
   - Amount: `500`

### Display All Records (Choice 7):
```text
--- All Records ---
Food - Lunch : Rs. 150
Travel - Bus : Rs. 50
Clothing - Shoes : Rs. 1200
Accommodation - Hostel : Rs. 3000
Savings - EmergencyFund : Rs. 500
```

### Show Total Expenses (Choice 8):
```text
Total expenses: Rs. 4400
```
*(Calculation: 150 + 50 + 1200 + 3000 = Rs. 4400. Savings of Rs. 500 is correctly excluded)*

### Show Total Savings (Choice 9):
```text
Total savings: Rs. 500
```

### Remove Last Record (Choice 6):
```text
Last record removed.
```
*(Removes EmergencyFund; stack top updates to 3)*

### Verify Updated Totals:
- Choice 8 (Expenses): `Total expenses: Rs. 4400`
- Choice 9 (Savings): `Total savings: Rs. 0`

---

## 10. Memory Management & Limitations

- **Volatile Storage**: As specified in the reference documentation, records exist solely in memory while the application runs.
- **Fixed Capacity**: Maximum capacity is fixed at 20 entries. Pushing beyond 20 issues a friendly overflow notice and cleanly deletes the unpushed object to avoid memory leaks.
- **Single-Word Names**: Inputs are captured via standard stream extraction (`cin >> name`). Multi-word names should use underscores (e.g., `Train_Ticket`).
