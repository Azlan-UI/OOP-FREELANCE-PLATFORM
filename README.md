# OOP-FREELANCE-PLATFORM
# Freelance Platform (OOP-Based)

A console-based Freelance Platform built using Object-Oriented Programming (OOP) principles in C++ with Java-based GUI components.

## Project Overview
**Course:** Object Oriented Programming  
**Instructor:** Maam Hareem Kibriya  
**Developer:** Azlan Zafar (241820)  
**Department:** Computer Science  
**Institution:** Air University Islamabad  
**Submission Date:** June 1, 2025  

## Key Features
- Dual implementation: C++ backend + Java GUI frontend
- Role-based access (Clients/Freelancers)
- Complete gig lifecycle management
- Persistent data storage using text files and SQLite
- OOP principles implementation:
  - Inheritance
  - Polymorphism
  - Abstraction
  - Encapsulation

## System Architecture
### C++ Backend Components
```plaintext
Auth/               # Authentication system
├── User            # Abstract base class
├── Client          # Client-specific operations
├── Freelancer      # Freelancer-specific operations
Core/               # Business logic
├── Gig             # Gig management
├── Review          # Review system
├── Payment         # Payment processing
├── Chat            # Communication system
Data/               # Persistent storage
├── *.txt           # All data files
