// CourseQueue.h
#ifndef COURSEQUEUE_H
#define COURSEQUEUE_H

#include <queue>
#include "Course.h"

class CourseQueue {
public:
    void addCourse(const Course & (const Course& course); // Add a course to the queue
    void deleteCourse(); // Delete the front course from the queue
    void printCourses(); // Print the information of all courses in the queue
    bool isEmpty() const; // Check if the queue is empty
private:
    std::queue<Course> courses; // Queue to store courses
};

#endif /* COURSEQUEUE_H */

