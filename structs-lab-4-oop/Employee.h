#pragma once
#include <iostream>
#include <string>

template <typename T>
T get_valid_input(const std::string& prompt);

class Employee {
public:
    std::string full_name;
    int birth_year;
    int department_code;
    std::string position;
    int experience;
    Employee() {};
    Employee(const std::string& name, int year, int dept_code, const std::string& pos, int exp)
        : full_name(name), birth_year(year), department_code(dept_code), position(pos), experience(exp) {}

    
   
    friend std::istream& operator>>(std::istream& is, Employee& emp) {
        std::cout << "������� ������ ����������:\n";
        emp.full_name = get_valid_input<std::string>("���: ");
        emp.birth_year = get_valid_input<int>("��� ��������: ");
        emp.department_code = get_valid_input<int>("��� ������: ");
        emp.position = get_valid_input<std::string>("��������� :");
        emp.experience = get_valid_input<int>("���� ������: ");
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Employee& emp) {
        os << "���: " << emp.full_name << "\n";
        os << "��� ��������: " << emp.birth_year << "\n";
        os << "��� ������: " << emp.department_code << "\n";
        os << "���������: " << emp.position << "\n";
        os << "���� ������: " << emp.experience << " ���\n";
        return os;
    }
};

template <typename T>
T get_valid_input(const std::string& prompt) {
    T value;
    while (true) {
        std::cout << prompt;

        if constexpr (std::is_same<T, std::string>::value) {
            if (std::cin.peek() == '\n') std::cin.ignore(); 
            std::getline(std::cin, value);
        }
        else {
            std::cin >> value;
        }

        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "������ �����. ����������, ���������� ��� ���.\n";
        }
        else {
            if constexpr (!std::is_same<T, std::string>::value) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            return value;
        }
    }
}

