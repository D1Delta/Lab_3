#ifndef LAB_3_HEADER_H
#define LAB_3_HEADER_H

#include <string>
#include <vector>
// Класс "Время" — время суток в 24-часовом формате (секунды с начала суток).
class Time {
public:
    Time(int seconds);
    void setSeconds(int seconds);
    void print();
    ~Time();
private:
    int seconds;
};
// Класс "Дом" — количество этажей.
class Home {
public:
    Home(int floor);
    void print();
private:
    int floor;
};
// Класс "Пистолет" — количество патронов, может стрелять.
class Gun {
public:
    Gun(int amm);
    Gun();
    void print();
    ~Gun();
private:
    int ammunition;
};
class Employee;
// Класс "Отдел" — название, начальник и список сотрудников.
class Department {
public:
    Department(std::string name);
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
// Класс "Сотрудник" — имя и отдел, в котором он работает.
class Employee {
public:
    Employee(std::string name, Department* department);
    std::string getName();
    Department* getDepartment();
    // Задание 3.4: по сотруднику узнаём всех сотрудников его отдела.
    std::vector<Employee*> getDepartmentEmployees();
    void print();
    ~Employee();
private:
    std::string name;
    Department* department;
};
#endif //LAB_3_HEADER_H