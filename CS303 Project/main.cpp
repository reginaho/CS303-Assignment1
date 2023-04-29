// main.cpp
#include <iostream>
#include "Course.h"
#include "CourseQueue.h"

int main() {
    CourseQueue courseQueue;

    char choice;
    do {
        std::cout << "Please choose an option:" << std::endl;
        std::cout << "A - Add a course" << std::endl;
        std::cout << "B - Delete a course" << std::endl;
        std::cout << "P - Print courses" << std::endl;
        std::cout << "I - Enter user information" << std::endl;
        std::cout << "Q - Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (toupper(choice)) {
        case 'A': {
            std::string name, school, schoolYear, id;
            std::cout << "Enter course name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter school: ";
            std::getline(std::cin, school);
            std::cout << "Enter school year: ";
            std::getline(std::cin, schoolYear);
            std::cout << "Enter ID: ";
            std::getline(std::cin, id);
            Course course(name, school, schoolYear, id);
            courseQueue.addCourse(course);
            std::cout << "Course added successfully." << std::endl;
            break;
        }
        case 'B': {
            if (!courseQueue.isEmpty()) {
                courseQueue.deleteCourse();
                std::cout << "Course deleted successfully." << std::endl;
            }
            else {
                std::cout << "No courses in the queue." << std::endl;
            }
            break;
        }
        case 'P': {
            if (!courseQueue.isEmpty()) {
                std::cout << "Courses in the queue:" << std::endl;
                courseQueue.printCourses();  // Display courses in the queue
            }
            else {
                std::cout << "No courses in the queue." << std::endl;
            }
            break;
        }
        case 'I': {
            std::string name, school, schoolYear, id;
            std::cout << "Enter your name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter your school: ";
            std::getline(std::cin, school);
            std::cout << "Enter your school year: ";
            std::getline(std::cin, schoolYear);
            std::cout << "Enter your ID: ";
            std::getline(std::cin, id);
            Course course(name, school, schoolYear, id);
            courseQueue.addCourse(course);
            std::cout << "User information added successfully." << std::endl;
            break;
        }
        case 'Q': {
            std::cout << "Exiting..." << std::endl;
            break;
        }
        default: {
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
        }

    } while (toupper(choice) != 'Q');

    return 0;
}
