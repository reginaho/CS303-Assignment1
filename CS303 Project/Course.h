

// Course.h
#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course {
public:
    Course();
    Course(const std::string& name, const std::string& school, const std::string& schoolYear, const std::string& id);
    std::string getName() const;
    std::string getSchool() const;
    std::string getSchoolYear() const;
    std::string getId() const;

private:
    std::string name_;
    std::string school_;
    std::string schoolYear_;
    std::string id_;
};

#endif // COURSE_H

