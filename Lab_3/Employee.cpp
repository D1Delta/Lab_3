#include "Employe.h"
#include <iostream>
#include <string>
#include <vector>
#include "Department.h"

// ============================ Employee ============================
Employee::Employee(std::string name, Department* department) {
    this->name = name;
    this->department = department;
    if (department != nullptr) {
        department->addEmployee(this);
    }
}
std::string Employee::getName() {
    return name;
}
Department* Employee::getDepartment() {
    return department;
}
// Задание 3.4: по сотруднику узнаём всех сотрудников его отдела.
std::vector<Employee*> Employee::getDepartmentEmployees() {
    if (department == nullptr) {
        return std::vector<Employee*>();
    }
    return department->getEmployees();
}
void Employee::print() {
    if (department == nullptr) {
        std::cout << name << " не работает ни в одном отделе" << std::endl;
    } else if (department->getHead() == this) {
        std::cout << name << " начальник отдела " << department->getName() << std::endl;
    } else if (department->getHead() == nullptr) {
        std::cout << name << " работает в отделе " << department->getName()
                  << ", начальник пока не назначен" << std::endl;
    } else {
        std::cout << name << " работает в отделе " << department->getName()
                  << ", начальник которого " << department->getHead()->getName() << std::endl;
    }
}
Employee::~Employee() {}