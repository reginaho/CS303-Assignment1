// Course.cpp
#include "Course.h"

Course::Course() {}

Course::Course(const std::string& name, const std::string& school, const std::string& schoolYear, const std::string& id)
    : name_(name), school_(school), schoolYear_(schoolYear), id_(id) {}

std::string Course::getName() const {
    return name_;
}

std::string Course::getSchool() const {
    return school_;
}

std::string Course::getSchoolYear() const {
    return schoolYear_;
}

std::string Course::getId() const {
    return id_;
}

