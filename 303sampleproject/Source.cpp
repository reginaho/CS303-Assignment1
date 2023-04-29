#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// Course class
class Course {
public:
    string code;
    string name;
    vector<string> prereqs;
    vector<string> schedule;
};

// Schedule class
class Schedule {
private:
    unordered_map<string, Course> courses;
public:
    void addCourse(Course c) {
        courses[c.code] = c;
    }

    void printSchedule() {
        for (auto const& [code, course] : courses) {
            cout << course.code << ": " << course.name << endl;
            cout << "Schedule: ";
            for (auto const& time : course.schedule) {
                cout << time << " ";
            }
            cout << endl;
        }
    }

    Course getCourse(string code) {
        return courses[code];
    }
};

// Student class
class Student {
public:
    string name;
    int id;
    vector<string> courses;
};

// Course Prerequisites class
class CoursePrerequisites {
private:
    unordered_map<string, vector<string>> graph;
public:
    void addCourse(string code, vector<string> prereqs) {
        graph[code] = prereqs;
    }

    bool hasPrerequisitesMet(string code, vector<string> takenCourses) {
        vector<string> prerequisites = graph[code];
        for (auto const& prereq : prerequisites) {
            if (find(takenCourses.begin(), takenCourses.end(), prereq) == takenCourses.end()) {
                return false;
            }
        }
        return true;
    }

    vector<string> getCourseOrder() {
        vector<string> courseOrder;
        unordered_map<string, int> inDegree;
        queue<string> q;

        // initialize in-degree for each course
        for (auto const& [code, prereqs] : graph) {
            inDegree[code] = 0;
        }

        // calculate in-degree for each course
        for (auto const& [code, prereqs] : graph) {
            for (auto const& prereq : prereqs) {
                inDegree[code]++;
            }
        }

        // add courses with in-degree of 0 to the queue
        for (auto const& [code, degree] : inDegree) {
            if (degree == 0) {
                q.push(code);
            }
        }

        // process courses in the queue
        while (!q.empty()) {
            string code = q.front();
            q.pop();
            courseOrder.push_back(code);
            for (auto const& prereq : graph[code]) {
                inDegree[prereq]--;
                if (inDegree[prereq] == 0) {
                    q.push(prereq);
                }
            }
        }

        return courseOrder;
    }
};

int main() {
    Schedule schedule;
    CoursePrerequisites prereqs;
    Student student;
    string input;

    // add courses to the schedule
    Course c1 = { "CSCI101", "Introduction to Computer Science", {}, {"MWF 9:00am-10:00am", "TH 10:00am-11:00am"} };
    Course c2 = { "CSCI201", "Data Structures and Algorithms", {"CSCI101"}, {"MWF 10:00am-11:00am", "TH 11:00am-12:00pm"} };
    Course c3 = { "CSCI310", "Operating Systems", {"CSCI201"}, {"MWF 11:00am-12:00pm", "TH 1:00pm-2:00pm"} };
    Course c4 = { "CSCI350", "Computer Networks", {"CSCI201"}, {"MWF 1:00pm-2:00pm", "TH 2:00pm-3:00pm"} };
    Course c5 = { "CSCI404", "Database Systems", {"CSCI201"}, {"MWF 3:00pm-4:00pm", "TH 3:00pm-4:00pm"} };
    schedule.addCourse(c1);
    schedule.addCourse(c2);
    schedule.addCourse(c3);
    schedule.addCourse(c4);
    schedule.addCourse(c5);

    // add course prerequisites
    prereqs.addCourse("CSCI101", {});
    prereqs.addCourse("CSCI201", { "CSCI101" });
    prereqs.addCourse("CSCI310", { "CSCI201" });
    prereqs.addCourse("CSCI350", { "CSCI201" });
    prereqs.addCourse("CSCI404", { "CSCI201" });

    // get student information
    cout << "Enter your name: ";
    getline(cin, student.name);
    cout << "Enter your student ID: ";
    cin >> student.id;

    // display available courses and let the student register
    cout << "Available courses:" << endl;
    vector<string> courseOrder = prereqs.getCourseOrder();
    for (auto const& code : courseOrder) {
        Course course = schedule.getCourse(code);
        cout << course.code << ": " << course.name << endl;
        cout << "Schedule: ";
        for (auto const& time : course.schedule) {
            cout << time << " ";
        }
        cout << endl;

        cout << "Would you like to register for " << course.name << "? (Y/N) ";
        cin >> input;
        if (input == "Y") {
            if (prereqs.hasPrerequisitesMet(course.code, student.courses)) {
                student.courses.push_back(course.code);
                cout << "Registered for " << course.name << endl;
            }
            else {
                cout << "You haven't met the prerequisites for " << course.name << endl;
            }
        }
    }

    // display student schedule
    cout << "Your schedule:" << endl;
    for (auto const& courseCode : student.courses) {
        Course course = schedule.getCourse(courseCode);
        cout << course.name << endl;
        for (auto const& time : course.schedule) {
            cout << time << endl;
        }
    }

    return 0;
