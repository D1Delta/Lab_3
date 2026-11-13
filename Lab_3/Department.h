//
// Created by student on 13.11.2026.
//

#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <vector>
#include <string>

class Employee;
// Класс "Отдел" — название, начальник и список сотрудников.
class Department {
public:

   explicit Department(std::string &name);

    std::string getName();
    Employee* getHead();
    std::vector<Employee*> getEmployees();
    void addEmployee(Employee* employee);
    void setHead(Employee* head);
    void print();
    ~Department();
private:
    std::string name;
    Employee* head;
    std::vector<Employee*> employees;
};
#endif //DEPARTMENT_H
