# C++ Expense Tracker – Extended Version

[![C++ Standard](https://img.shields.io/badge/C%2B%2B-11%2F14%2F17-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B)
[![Course](https://img.shields.io/badge/Course-OOPs%20Lab-orange.svg)]()
[![Institution](https://img.shields.io/badge/ADYPU-AI%20%26%20Data%20Science-red.svg)]()

> A console-based personal expense and savings tracking application written in C++ demonstrating key Object-Oriented Programming (OOP) concepts.

---

## 1. Project Overview

The **Expense Tracker (Extended Version)** is a console application developed for the Object-Oriented Programming Lab curriculum at **Ajeenkya DY Patil University (ADYPU)** for B.Tech in Artificial Intelligence & Data Science.

The application allows users to record daily expenses across multiple categories while maintaining a strict distinction between **spending** (Food, Travel, Clothing, Accommodation) and **savings**.

---

## 2. Core Business Rule

> **Important**: Savings are stored as a separate type of record and are **NOT included in total expenses**.
>
> - `totalExpense()` calculates the sum of all expenditure categories (Food, Travel, Clothing, Accommodation).
> - `totalSavings()` calculates the sum of savings records only.

---

## 3. Expense Categories

| Category | What It Records |
| :--- | :--- |
| **Food** | Meals, groceries, snacks |
| **Travel** | Bus, train, fuel, taxi |
| **Clothing** | Clothes, footwear, accessories |
| **Accommodation** | Rent, hostel fees, hotel stays |
| **Savings** | Money set aside for future use |

---

## 4. OOP Architecture & Class Descriptions

The program is implemented in [`expence_tracker.cpp`](expence_tracker.cpp) using the following class hierarchy:

### 1. `Expense` (Abstract Base Class)
- **Data Members**:
  - `protected: string name;` — Name of the record (e.g., `Lunch`, `Hostel`).
  - `protected: float amount;` — Monetary value.
- **Member Functions**:
  - `Expense()`: Default constructor (initializes `name = "Unknown"`, `amount = 0`).
  - `Expense(string n, float a)`: Parameterized constructor.
  - `Expense(const Expense &e)`: Copy constructor demonstrating OOP copy semantics.
  - `virtual ~Expense()`: Virtual destructor ensuring safe polymorphic deletion.
  - `float getAmount() const`: Returns the record amount.
  - `virtual bool isSaving() const`: Virtual function returning `false` by default.
  - `virtual void display() const = 0`: **Pure virtual function** (makes `Expense` an abstract class).
  - `void show() const`: Overloaded display function.
  - `void show(string message) const`: Overloaded display function with prefix message.
  - `friend void showDetails(const Expense &e)`: Friend function accessing protected members.

### 2. Derived Category Classes
All category classes inherit publicly from `Expense`:
- **`Food`**: Inherits from `Expense`, overrides `display()` to print `Food - <name> : Rs. <amount>`.
- **`Travel`**: Inherits from `Expense`, overrides `display()` to print `Travel - <name> : Rs. <amount>`.
- **`Clothing`**: Inherits from `Expense`, overrides `display()` to print `Clothing - <name> : Rs. <amount>`.
- **`Accommodation`**: Inherits from `Expense`, overrides `display()` to print `Accommodation - <name> : Rs. <amount>`.
- **`Savings`**: Inherits from `Expense`, overrides `isSaving()` to return `true`, and overrides `display()` to print `Savings - <name> : Rs. <amount>`.

### 3. `Stack` (Record Management Class)
- **Data Members**:
  - `Expense *records[20]`: Fixed-size array storing up to 20 `Expense` pointers.
  - `int top`: Tracks the top index of the stack (initialized to `-1`).
- **Member Functions**:
  - `Stack()`: Constructor initializes `top = -1`.
  - `~Stack()`: Destructor loops while `top >= 0`, deleting allocated records to prevent memory leaks.
  - `void push(Expense *e)`: Checks for overflow (`top == 19`). Deletes object if full, otherwise adds to stack.
  - `void pop()`: Checks for underflow (`top == -1`). Deletes topmost record and decrements `top`.
  - `void displayAll() const`: Demonstrates **runtime polymorphism** by calling `records[i]->display()` through base-class pointers.
  - `friend void totalExpense(const Stack &s)`: Friend function calculating total spending (skipping savings).
  - `friend void totalSavings(const Stack &s)`: Friend function calculating total savings.

---

## 5. OOP Concepts Demonstrated

| Concept | Location in Code | Purpose |
| :--- | :--- | :--- |
| **Class and Object** | `Expense`, `Food`, `Travel`, `Clothing`, `Accommodation`, `Savings`, `Stack` | Object-oriented modeling of real-world financial records. |
| **Encapsulation** | `protected: name, amount;`, `private: records[20], top;` | Information hiding and controlled data access. |
| **Abstraction** | `class Expense` | Abstract base class hiding implementation details. |
| **Pure Virtual Function** | `virtual void display() const = 0;` | Enforces implementation in all derived classes. |
| **Inheritance** | Derived classes inheriting from `Expense` | Code reuse and hierarchical organization. |
| **Runtime Polymorphism** | `records[i]->display();` in `Stack::displayAll()` | Dynamic method binding at runtime via base-class pointers. |
| **Virtual Destructor** | `virtual ~Expense()` | Prevents memory leaks and undefined behavior during polymorphic `delete`. |
| **Constructor Overloading** | Default and Parameterized constructors across classes | Multiple ways to initialize objects. |
| **Copy Constructor** | `Expense(const Expense &e)` | Demonstrates copy semantics in C++. |
| **Function Overloading** | `show()` and `show(string message)` in `Expense` | Compile-time polymorphism with matching function names. |
| **Friend Functions** | `showDetails()`, `totalExpense()`, `totalSavings()` | Allows external functions direct access to private/protected data. |
| **Dynamic Memory Allocation** | `new Food(...)`, `delete records[top]` | Dynamic heap memory management using `new` and `delete`. |
| **Stack Data Structure** | `class Stack` with `push()`, `pop()`, `displayAll()` | LIFO memory buffer with capacity of 20 records. |

---

## 6. Application Menu

When executed, the program presents an interactive menu:

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

### Menu Operations:
- **Options 1 to 5**: Prompts for a one-word record name and monetary amount. Rejects zero or negative amounts (`amount <= 0`). Dynamically allocates the chosen category object and pushes it onto the stack.
- **Option 6 (Remove Last Record)**: Pops and deletes the most recently added record.
- **Option 7 (Display All Records)**: Iterates from bottom to top, invoking `display()` polymorphically.
- **Option 8 (Show Total Expenses)**: Computes and displays the sum of all non-savings records.
- **Option 9 (Show Total Savings)**: Computes and displays the sum of savings records.
- **Option 0 (Exit)**: Exits the loop and triggers the stack destructor to clean up memory.

---

## 7. How to Compile and Run

### Compilation:
Navigate to the `Mini_Project/Expense_Tracker/` directory and compile with `g++`:

```bash
g++ expence_tracker.cpp -o expence_tracker
```

### Execution:
On Linux / macOS / Git Bash:
```bash
./expence_tracker
```

On Windows Command Prompt / PowerShell:
```cmd
expence_tracker.exe
```

---

## 8. Sample Program Walkthrough

The program supports the following verification workflow:

1. **Add Food Expense** (Option 1):
   - Record name: `Lunch`
   - Amount: `150`
2. **Add Travel Expense** (Option 2):
   - Record name: `Bus`
   - Amount: `50`
3. **Add Clothing Expense** (Option 3):
   - Record name: `Shoes`
   - Amount: `1200`
4. **Add Accommodation Expense** (Option 4):
   - Record name: `Hostel`
   - Amount: `3000`
5. **Add Savings** (Option 5):
   - Record name: `EmergencyFund`
   - Amount: `500`

### Display All Records (Option 7):
```text
--- All Records ---
Food - Lunch : Rs. 150
Travel - Bus : Rs. 50
Clothing - Shoes : Rs. 1200
Accommodation - Hostel : Rs. 3000
Savings - EmergencyFund : Rs. 500
```

### Show Total Expenses (Option 8):
```text
Total expenses: Rs. 4400
```
*(Calculation: 150 + 50 + 1200 + 3000 = Rs. 4400. Savings of Rs. 500 is excluded)*

### Show Total Savings (Option 9):
```text
Total savings: Rs. 500
```

### Remove Last Record (Option 6):
```text
Last record removed.
```
*(Removes `EmergencyFund`)*

### Verify Updated Totals:
- Option 8: `Total expenses: Rs. 4400`
- Option 9: `Total savings: Rs. 0`

---

## 9. Notes and Limitations

- **In-Memory Storage**: Records are kept only while the program is running. As specified in the course reference, persistent file/database storage is not used.
- **Fixed Capacity**: The stack capacity is strictly capped at **20 records**. Attempting to add beyond 20 displays `"Record list is full!"` and safely deletes the unpushed record.
- **Single-Word Record Names**: Record names are read using `cin >> name`. Use underscores for multi-word descriptions (e.g., `Bus_Ticket`).
- **Copy Constructor**: Included to demonstrate C++ copy semantics as an academic OOP requirement; the interactive menu does not need to call it directly.
