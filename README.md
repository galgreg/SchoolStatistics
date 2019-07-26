# School Statistics
Application is responsible for keeping documentation and doing statistics about student class.  
Student class can have up to 20 students.  
Each student data consists of:
- unique ID
- first name
- last name
- gender
- partial grades for tests written in the semester
- grades average

Application has the following functional requirements:
1. Add student
2. Edit student's personal data
3. Delete student
4. Display student's personal data
5. Add grade
6. Edit grade
7. Delete grade
8. Display student's grades
9. Compute and display grades average for each student and the whole class
10. Write all data into text file
11. Read all data from text file

## Implementation details
Application has been written in C++14 and Qt framework (5.12 version).

## How to build & run the project
### 1. Install Qt (version 5.0 or higher) + Qt Creator
  Check [*official documentation*](https://doc.qt.io/qt-5/gettingstarted.html) for more details.

### 2. Clone Git repo
```
git clone https://gitlab.com/galgreg/schoolstatistics.git
```
### 3. Configure build options
1. Open project in Qt Creator
2. Switch to Projects mode (```Ctrl + 5```)
3. Select ```Debug``` build configuration
4. Clone selected and type ```Test``` as new configuration name
5. Add ```CONFIG+=test``` to qmake's ```Additional arguments```.

### 4. Choose build configuration
Choose ```Test``` to run test suites or others to run application.

### 5. Build application
```Ctrl + Shift + B```

### 6. Run application
```Ctrl + R```

## Why such project
The project was created mainly for educational purposes.
Author wanted to better understand programming in Qt framework.

Additionally, author put a lot of effort to follow the best practices of software engineering,  
especially TDD and SOLID principles.
Almost every piece of "production" code has been created after writing corresponding test.

## What could still be done
Author is aware, that a lot of features could be still added to project.  
One of them is certainly open file dialog for student data files.  
However, because of limited time, such features will probably never be implemented.

## Terms of use
Author takes no responsibility for any damage or loss caused by improper use of above application.
