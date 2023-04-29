// CourseQueue.cpp
#include <iostream>
#include "CourseQueue.h"

void CourseQueue::addCourse(const Course& course) {
    courses.push(course);
}

void CourseQueue::deleteCourse() {
    if (!isEmpty()) {
        courses.pop();
    }
}

void CourseQueue::printCourses() {
    // Iterate through the queue and print the information of all courses
    int i = 1;
    for (const Course& course : courses) {
        std::cout << "Course " << i << ":" << std::endl;
        course.printInfo();
        std::cout << "----------------------" << std::endl;
        i++;
    }
}

bool CourseQueue::isEmpty() const {
    return courses.empty();
}
