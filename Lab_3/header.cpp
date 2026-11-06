#include "header.h"
#include <iostream>
// ============================ Time ============================
Time::Time(int seconds) {
    this->seconds = seconds;
}
void Time::setSeconds(int seconds) {
    this->seconds = seconds;
}
void Time::print() {
    int total = seconds;
    // Если время превышает сутки, показываем только последние сутки.
    if (total > 86400) {
        total = total - 86400;
    }
    int hours = total / 3600;
    int minutes = (total % 3600) / 60;
    int secs = total % 60;
    std::cout << hours << ":" << minutes << ":" << secs << std::endl;
}
Time::~Time() {
    std::cout << "Delete class Time" << std::endl;
}
// ============================ Home ============================
Home::Home(int floor) {
    this->floor = floor;
}
void Home::print() {
    if (floor % 10 == 1 && floor % 100 != 11) {
        std::cout << "Дом с " << floor << " этажом" << std::endl;
    } else {
        std::cout << "Дом с " << floor << " этажами" << std::endl;
    }
}
// ============================ Gun ============================
Gun::Gun(int amm) {
    this->ammunition = amm;
}
Gun::Gun() {
    ammunition = 5;
}
void Gun::print() {
    if (ammunition != 0) {
        std::cout << "Бах!" << std::endl;
        ammunition = ammunition - 1;
    } else {
        std::cout << "клатс" << std::endl;
    }
}
Gun::~Gun() {
    std::cout << "Delete class Gun" << std::endl;
}
// ============================ Department ============================
Department::Department(std::string name) {
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
Department::~Department() {
    std::cout << "Delete class Department" << std::endl;
}
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
Employee::~Employee() {
    std::cout << "Delete class Employee" << std::endl;
}