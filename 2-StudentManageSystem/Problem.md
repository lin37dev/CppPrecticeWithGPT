Design a student management system that covers topics such as polymorphism, STL containers, STL algorithms, exception handling, and implements the following features:

Create a base class called Person, which includes the following properties and methods:
- Properties: name, age, gender.
- Methods: constructor, destructor, getters for name, age, gender, display personal information.

Derive a Student class from Person and add the following properties and methods:
- Properties: student ID, major.
- Methods: constructor, destructor, getters for student ID and major, setter for major, display student information.

Derive two child classes from Student: Undergraduate and Graduate.
- The Undergraduate class has an additional property: classroom.
- The Graduate class has an additional property: advisor.
- Each subclass should have its own constructor, destructor, and override the method to display student information.

Create a Course class that includes the following properties and methods:
- Properties: course name, credits.
- Methods: constructor, destructor, getters for course name and credits, display course information.

Use an STL container (such as std::vector) to store collections of student and course objects.

Use STL algorithms (such as std::find_if) to implement the following operations:
- Add/delete a student
- Search a student by student ID
- Add/delete a course
- Search a course by course name
- Register/drop a course for a student

Exception handling:
- When attempting to add a duplicate student or course, throw a custom exception called ItemAlreadyExistsException.
- When attempting to delete or search for a non-existent student or course, throw a custom exception called ItemNotFoundException.
- When a student's course selection conflicts, throw a custom exception called CourseConflictException.

Use appropriate design patterns (such as the factory pattern or singleton pattern) to organize the code. Additionally, you may add other features such as grade management, student course selection statistics, etc. to make the project more challenging.
