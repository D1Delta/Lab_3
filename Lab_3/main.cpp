#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <windows.h>
#include "header.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
static void resetInput() {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
// Чтение целого числа с проверкой ввода.
static int readInt(const string& prompt) {
    int value = 0;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        resetInput();
        cout << "  [!] Ошибка ввода: ожидается целое число." << endl;
    }
}
// Чтение неотрицательного целого числа.
static int readNonNegativeInt(const string& prompt) {
    while (true) {
        int value = readInt(prompt);
        if (value >= 0) {
            return value;
        }
        cout << "  [!] Число должно быть неотрицательным." << endl;
    }
}
// Чтение положительного целого числа.
static int readPositiveInt(const string& prompt) {
    while (true) {
        int value = readInt(prompt);
        if (value > 0) {
            return value;
        }
        cout << "  [!] Число должно быть положительным." << endl;
    }
}
// Чтение строки (непустой).
static string readString(const string& prompt) {
    string value;
    while (true) {
        cout << prompt;
        std::getline(cin, value);
        if (!value.empty()) {
            return value;
        }
        cout << "  [!] Строка не должна быть пустой." << endl;
    }
}
static void printHeader(const string& title) {
    cout << "\n============================================\n";
    cout << "   " << title << "\n";
    cout << "============================================\n";
}
// ======================= Демонстрация классов =======================
static void demoTime() {
    printHeader("Время (Time)");
    cout << "Создаём объект времени (секунды с начала суток).\n";
    int s = readNonNegativeInt("Секунды: ");
    Time t(s);
    cout << "Текстовая форма: ";
    t.print();
    while (true) {
        cout << "\n  1. Изменить секунды\n";
        cout << "  2. Показать время\n";
        cout << "  0. В главное меню\n";
        int c = readInt("Выбор: ");
        if (c == 0) {
            break;
        } else if (c == 1) {
            t.setSeconds(readNonNegativeInt("Новые секунды: "));
        } else if (c == 2) {
            cout << "Текстовая форма: ";
            t.print();
        } else {
            cout << "  [!] Неверный пункт." << endl;
        }
    }
}
static void demoHome() {
    printHeader("Дом (Home)");
    while (true) {
        cout << "\n  1. Создать дом и вывести его текстовую форму\n";
        cout << "  0. В главное меню\n";
        int c = readInt("Выбор: ");
        if (c == 0) {
            break;
        } else if (c == 1) {
            int f = readPositiveInt("Количество этажей: ");
            Home h(f);
            h.print();
        } else {
            cout << "  [!] Неверный пункт." << endl;
        }
    }
}
static void demoGun() {
    printHeader("Пистолет (Gun)");
    cout << "Как создать пистолет?\n";
    cout << "  1. С указанием количества патронов\n";
    cout << "  2. Без указания (по умолчанию 5 патронов)\n";
    int c = readInt("Выбор: ");
    Gun* gun = nullptr;
    if (c == 1) {
        gun = new Gun(readNonNegativeInt("Патроны: "));
    } else {
        gun = new Gun();
    }
    cout << "Пистолет создан.\n";
    while (true) {
        cout << "\n  1. Выстрелить\n";
        cout << "  0. В главное меню\n";
        int k = readInt("Выбор: ");
        if (k == 0) {
            break;
        } else if (k == 1) {
            gun->print();
        } else {
            cout << "  [!] Неверный пункт." << endl;
        }
    }
    delete gun;
}
static void demoDepartmentEmployee() {
    printHeader("Сотрудники и отделы (Department / Employee)");
    vector<Department*> departments;
    vector<Employee*> employees;
    while (true) {
        cout << "\n  1. Создать отдел\n";
        cout << "  2. Создать сотрудника\n";
        cout << "  3. Назначить начальника отдела\n";
        cout << "  4. Вывести отдел\n";
        cout << "  5. Вывести сотрудника\n";
        cout << "  6. Сотрудники отдела выбранного сотрудника (Задание 3.4)\n";
        cout << "  7. Показать все отделы и сотрудников\n";
        cout << "  0. В главное меню\n";
        int c = readInt("Выбор: ");
        if (c == 0) {
            break;
        }
        switch (c) {
        case 1: {
            string name = readString("Название отдела: ");
            departments.push_back(new Department(name));
            cout << "  Отдел \"" << name << "\" создан." << endl;
            break;
        }
        case 2: {
            if (departments.empty()) {
                cout << "  [!] Сначала создайте хотя бы один отдел." << endl;
                break;
            }
            string name = readString("Имя сотрудника: ");
            cout << "Выберите отдел:\n";
            for (size_t i = 0; i < departments.size(); i++) {
                cout << "  " << (i + 1) << ". " << departments[i]->getName() << endl;
            }
            int idx = readInt("Номер отдела (0 — без отдела): ");
            Department* dep = nullptr;
            if (idx >= 1 && idx <= static_cast<int>(departments.size())) {
                dep = departments[idx - 1];
            }
            employees.push_back(new Employee(name, dep));
            cout << "  Сотрудник \"" << name << "\" создан." << endl;
            break;
        }
        case 3: {
            if (departments.empty() || employees.empty()) {
                cout << "  [!] Нужны хотя бы один отдел и один сотрудник." << endl;
                break;
            }
            cout << "Выберите сотрудника:\n";
            for (size_t i = 0; i < employees.size(); i++) {
                cout << "  " << (i + 1) << ". " << employees[i]->getName() << endl;
            }
            int ei = readInt("Номер сотрудника: ");
            if (ei < 1 || ei > static_cast<int>(employees.size())) {
                cout << "  [!] Неверный номер сотрудника." << endl;
                break;
            }
            cout << "Выберите отдел:\n";
            for (size_t i = 0; i < departments.size(); i++) {
                cout << "  " << (i + 1) << ". " << departments[i]->getName() << endl;
            }
            int di = readInt("Номер отдела: ");
            if (di < 1 || di > static_cast<int>(departments.size())) {
                cout << "  [!] Неверный номер отдела." << endl;
                break;
            }
            departments[di - 1]->setHead(employees[ei - 1]);
            break;
        }
        case 4: {
            if (departments.empty()) {
                cout << "  [!] Отделов пока нет." << endl;
                break;
            }
            cout << "Выберите отдел:\n";
            for (size_t i = 0; i < departments.size(); i++) {
                cout << "  " << (i + 1) << ". " << departments[i]->getName() << endl;
            }
            int di = readInt("Номер отдела: ");
            if (di >= 1 && di <= static_cast<int>(departments.size())) {
                departments[di - 1]->print();
            } else {
                cout << "  [!] Неверный номер отдела." << endl;
            }
            break;
        }
        case 5: {
            if (employees.empty()) {
                cout << "  [!] Сотрудников пока нет." << endl;
                break;
            }
            cout << "Выберите сотрудника:\n";
            for (size_t i = 0; i < employees.size(); i++) {
                cout << "  " << (i + 1) << ". " << employees[i]->getName() << endl;
            }
            int ei = readInt("Номер сотрудника: ");
            if (ei >= 1 && ei <= static_cast<int>(employees.size())) {
                employees[ei - 1]->print();
            } else {
                cout << "  [!] Неверный номер сотрудника." << endl;
            }
            break;
        }
        case 6: {
            if (employees.empty()) {
                cout << "  [!] Сотрудников пока нет." << endl;
                break;
            }
            cout << "Выберите сотрудника:\n";
            for (size_t i = 0; i < employees.size(); i++) {
                cout << "  " << (i + 1) << ". " << employees[i]->getName() << endl;
            }
            int ei = readInt("Номер сотрудника: ");
            if (ei < 1 || ei > static_cast<int>(employees.size())) {
                cout << "  [!] Неверный номер сотрудника." << endl;
                break;
            }
            vector<Employee*> colleagues = employees[ei - 1]->getDepartmentEmployees();
            cout << "Сотрудники отдела сотрудника \"" << employees[ei - 1]->getName() << "\": ";
            if (colleagues.empty()) {
                cout << "нет" << endl;
            } else {
                for (size_t i = 0; i < colleagues.size(); i++) {
                    if (i > 0) {
                        cout << ", ";
                    }
                    cout << colleagues[i]->getName();
                }
                cout << endl;
            }
            break;
        }
        case 7: {
            cout << "\n--- Отделы ---\n";
            if (departments.empty()) {
                cout << "(нет отделов)" << endl;
            }
            for (size_t i = 0; i < departments.size(); i++) {
                departments[i]->print();
            }
            cout << "--- Сотрудники ---\n";
            if (employees.empty()) {
                cout << "(нет сотрудников)" << endl;
            }
            for (size_t i = 0; i < employees.size(); i++) {
                employees[i]->print();
            }
            break;
        }
        default:
            cout << "  [!] Неверный пункт." << endl;
        }
    }
    // Освобождаем память: сначала сотрудники, затем отделы.
    for (size_t i = 0; i < employees.size(); i++) {
        delete employees[i];
    }
    for (size_t i = 0; i < departments.size(); i++) {
        delete departments[i];
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    while (true) {
        std::cout << "\n============================================\n";
        std::cout << "   ЛАБОРАТОРНАЯ РАБОТА №3 — ООП\n";
        std::cout << "============================================\n";
        std::cout << "  1. Время (Time)\n";
        std::cout << "  2. Дом (Home)\n";
        std::cout << "  3. Пистолет (Gun)\n";
        std::cout << "  4. Сотрудники и отделы (Department / Employee)\n";
        std::cout << "  0. Выход\n";
        std::cout << "--------------------------------------------\n";
        int choice = readInt("Выбор: ");
        if (choice == 0) {
            break;
        }
        switch (choice) {
            case 1:
                demoTime();
                break;
            case 2:
                demoHome();
                break;
            case 3:
                demoGun();
                break;
            case 4:
                demoDepartmentEmployee();
                break;
            default:
                std::cout << "  [!] Неверный пункт." << std::endl;
        }
    }
    std::cout << "\nЗавершение работы. До свидания!\n";
    return 0;
}