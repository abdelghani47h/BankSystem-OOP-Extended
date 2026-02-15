# 🏦 BankSystem-OOP-Extended

> A Complete Object-Oriented Redesign of the Original Bank System  
> Built with Clean Architecture, Layered Design, and Real-World Banking Features

---

## 🔄 Project Evolution & Refactoring

This project represents the evolution of the original procedural Bank System.

The previous versions were implemented using procedural programming techniques.
In this release, the entire system has been completely refactored into a full
Object-Oriented Programming (OOP) architecture.

This transformation included:

- Converting all logic into structured classes
- Introducing layered architecture (Presentation, Business Logic, Data)
- Applying encapsulation, inheritance, abstraction, and polymorphism
- Separating UI screens from core business logic
- Improving maintainability and scalability

In addition to the architectural refactoring, several new features were added:

- Login Register (Audit Trail System)
- Currency Exchange Module
- Transfer Logging System
- Enhanced Role-Based Access Control
- System Lock after failed login attempts
- Improved console UI formatting and navigation

This version is not just an update — it is a complete architectural redesign
that preserves the original banking logic while upgrading the system to a
professional OOP-based software structure.

---

## 📖 About The Project

> ⚡ This project is a **fully refactored and enhanced version** of the original Bank System.  
> It has been transformed from procedural code to a full Object-Oriented design with new modules, features, and a modern console UI.


**BankSystem-OOP-Extended** is a fully refactored and upgraded version of the original procedural Bank System project.

This version transforms the entire system into a structured **Object-Oriented Programming (OOP)** architecture while introducing new advanced features such as:

- Login Register (Audit Trail)
- Currency Exchange System
- Enhanced Security & Permissions
- Modular Screen-Based Architecture
- Improved UI/UX Console Formatting

This release represents a complete architectural evolution — not just a feature update.

---

## 🎯 Project Goals

- Refactor the full system from procedural programming to OOP
- Apply the four pillars of Object-Oriented Programming:
  - Encapsulation
  - Abstraction
  - Inheritance
  - Polymorphism
- Implement layered architecture
- Improve maintainability and scalability
- Simulate real-world banking logic in a console application

---

## 📂 Project Structure

The project is organized using a clean layered Object-Oriented architecture:

```
BankSystem-OOP-Extended
│
├── Core/                                # Business Logic Layer
│   ├── clsPerson.h                      # Base class (Inheritance foundation)
│   ├── clsUser.h                        # User entity & permission handling
│   ├── clsBankClient.h                  # Client entity & account operations
│   ├── clsCurrency.h                    # Currency entity & exchange logic
│   ├── clsLoginRegister.h               # Login audit record handling
│   └── clsTransferLog.h                 # Transfer logging management
│
├── Screens/                             # Presentation Layer (UI Screens)
│   ├── clsScreen.h                      # Base screen class (Date & Logged User display)
│   ├── clsMainScreen.h                  # Main Menu
│   ├── clsLoginScreen.h                 # Authentication Screen
│   ├── clsUsersScreen.h                 # Manage Users Screen
│   ├── clsClientsScreen.h               # Manage Clients Screen
│   ├── clsTransactionsScreen.h          # Transactions Menu
│   ├── clsDepositScreen.h               # Deposit Operation
│   ├── clsWithdrawScreen.h              # Withdraw Operation
│   ├── clsTransferScreen.h              # Transfer Between Clients
│   ├── clsCurrencyExchangeScreen.h      # Currency Exchange Menu
│   ├── clsLoginRegisterScreen.h         # Login Register Viewer
│   └── ...                              # Additional feature screens
│
├── Libraries/                           # Utility & Helper Classes
│   ├── clsInputValidate.h               # Static validation utilities
│   ├── clsDate.h                        # Date & time handling
│   ├── clsString.h                      # String manipulation helpers
│   ├── clsUtil.h                        # Encryption & general utilities
│   └── clsPermissions.h                 # Bitwise permission flags
│
├── Data/                                # Flat File Storage (Persistence Layer)
│   ├── Clients.txt                      # Client records
│   ├── Users.txt                        # User accounts & permissions
│   ├── LoginRegister.txt                # Login audit trail
│   ├── TransferLog.txt                  # Transfer history records
│   ├── Currencies.txt                   # Currency exchange rates
│   └── ...
│
└── main.cpp                             # Application Entry Point
```

### 🏗 Architecture Layers Explained

- **Core Layer** → Contains all entities and business rules.
- **Screens Layer** → Handles user interaction and console UI.
- **Libraries Layer** → Provides reusable helper utilities.
- **Data Layer** → Stores persistent data using structured flat files.
- **main.cpp** → Controls application startup and navigation flow.

This modular structure ensures:

- Separation of concerns  
- High maintainability  
- Easy scalability  
- Clean OOP implementation  
- Real-world software organization  

---

# 🚀 Core Features

## 👥 Client Management

- Add New Client
- Update Client Information
- Delete Client
- Find Client
- List All Clients
- Show Total Balances

All operations are file-persistent and validated.

---

## 💸 Transactions System

- Deposit
- Withdraw
- Transfer Between Clients
- Transfer Logs
- Automatic balance validation
- Immediate file synchronization

---

## 🔐 User Management & Security

- Secure Login System
- Role-Based Access Control
- Bitwise Permission Handling
- System Lock After 3 Failed Attempts
- Admin Full Access
- **Password Encryption:** All user passwords are encrypted before being stored in `Users.txt` using a custom encryption method.


### 🧾 Login Register (New Feature)

A new main menu option:

[8] Login Register



This feature:

- Records username
- Stores login date & time
- Logs user permissions
- Saves data in `LoginRegister.txt`
- Acts as a security audit trail

---

## 💱 Currency Exchange System (New Feature)

Added to main menu:

[9] Currency Exchange


Features:

- Convert between currencies via USD reference
- Update exchange rates
- Manage supported currencies
- File-based currency storage
- Real-time conversion calculations

Example conversion flow:

JOD → USD → EUR


---

# 🎨 Console UI Enhancements

- Fully centered screen output
- Structured screen separation
- Clear navigation flow
- Date & Logged-in User shown on all screens
- Color-coded interface:

| Color    | Usage |
|----------|--------|
| Cyan     | Titles & Headers |
| Green    | Tables |
| Yellow   | Success Messages |
| Red      | Errors & Warnings |
| Blue     | Prompts & Input Highlights |
| Magenta  | Special Messages / Alerts |


---

# 🧠 Technical Concepts Applied

- Object-Oriented Programming (OOP)
- Layered Architecture
- Inheritance-Based Screen System
- Bitwise Permission Flags
- File Handling & Structured Records
- Encapsulation of Data Access
- Modular Class Design
- Audit Logging System
- Input Validation Libraries

---

# 📂 Data Format Example

Records are stored using a custom delimiter:

Field1#//#Field2#//#Field3


Each entity manages its own file operations internally.

---

# 💻 Technologies Used

- C++
- STL (Standard Template Library)
- Object-Oriented Design
- File-Based Database (Flat Files)
- Bitwise Operations
- Modular Header Architecture

---

# 🏆 Why This Version Is Stronger

- Fully modular OOP design
- Scalable layered structure
- Advanced login auditing system
- Integrated currency exchange module
- Secure permission handling
- Professional console interface
- Clean separation between UI and business logic

---

# 📌 Final Note

This project demonstrates the transition from procedural coding to professional Object-Oriented architecture.

It reflects:

- Structured engineering thinking
- Clean code practices
- Security awareness
- Real-world system simulation
- Scalable software design principles

---

## 🚀 Future Improvements

- Database integration (SQL)
- GUI version
- REST API version
- Unit Testing Layer

---
**Version:** OOP Extended Edition  
**Language:** C++  

---

## ▶️ How To Run

1. Open the project in Visual Studio.
2. Build the solution (C++17 recommended).
3. Ensure all required `.txt` data files exist inside the `Data/` folder.
4. Run the application.

Default Admin Credentials:

Username: Admin  
Password: 1234




