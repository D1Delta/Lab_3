//
// Created by student on 13.11.2026.
//

#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <vector>
#include <string>

class Department;

class Employee {
public:
    Employee(std::string name, Department* department);

    std::string getName();
    Department* getDepartment();
    // Задание 3.4
    std::vector<Employee*> getDepartmentEmployees();
    void print();
    ~Employee();
private:
    std::string name;
    Department* department;
};
#endif //EMPLOYE_H
