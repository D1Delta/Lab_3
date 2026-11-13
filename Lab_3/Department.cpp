
#include "Department.h"

#include <cstddef>
#include <iostream>
#include <vector>

#include "Employe.h"
// ============================ Department ============================

Department::Department(std::string& name) {
    this->name = name;
    this->head = nullptr;
}
std::string Department::getName() {
    return name;
}
Employee* Department::getHead() {
    return head;
}
std::vector<Employee*> Department::getEmployees() {
    return employees;
}
// Вызывается из конструктора Employee, когда сотрудник приходит в отдел.
void Department::addEmployee(Employee* employee) {
    employees.push_back(employee);
}
void Department::setHead(Employee* head) {
    // Начальником может стать только сотрудник этого же отдела.
    if (head == nullptr || head->getDepartment() != this) {
        std::cout << "Начальником отдела " << name << " может быть только его сотрудник" << std::endl;
        return;
    }
    this->head = head;
}
void Department::print() {
    std::cout << "Отдел " << name << ", начальник: ";
    if (head != nullptr) {
        std::cout << head->getName();
    } else {
        std::cout << "не назначен";
    }
    std::cout << ", сотрудники: ";
    if (employees.empty()) {
        std::cout << "нет";
    }
    for (size_t i = 0; i < employees.size(); i++) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << employees[i]->getName();
    }
    std::cout << std::endl;
}
Department::~Department() {}