# Airport Management System

## Overview
Academic project: airport management system in C using linked lists to handle aircraft takeoff and landing queues.

## Features
- Add aircraft to takeoff/landing queues
- Priority system (low fuel < 45%)
- Remove aircraft by ID
- Company blacklist management
- Display aircraft lists

## Data Structure
```c
typedef struct avion {
    char identifiant[20];
    int carburant;        // fuel percentage
    char compagnie[20];   // airline company
} avion;

typedef struct Liste_avion {
    struct avion donnee;
    int priorite;         // 1 = priority, 0 = normal
    struct Liste_avion *next;
} Liste_avion;
```

## Usage
```bash
gcc -o airport main.c paste.c
./airport
```

## Menu Options
1. Add takeoff aircraft
2. Add landing aircraft  
3. Remove takeoff aircraft
4. Remove landing aircraft
5. Set landing priority
6. Blacklist company
7. Display company aircraft
8. Display takeoff queue
9. Display landing queue
10. Show airport log

Academic project demonstrating linked lists and basic data structures in C.

---- 
**Author**: Inès D
