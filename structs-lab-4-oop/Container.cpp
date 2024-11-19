#include "Container.h"

// Конструктор и деструктор
Container::Container() {
    list = new LinearList();
}

Container::~Container() {
    delete list;
}

// Методы добавления
void Container::add_to_start(const Employee& employee) {
    list->add_to_start(employee);
}

void Container::add_to_end(const Employee& employee) {
    list->add_to_end(employee);
}

void Container::add_at_position(const Employee& employee, size_t position) {
    list->add_after(position, employee);
}

// Методы удаления
void Container::remove_from_start() {
    list->remove_from_start();
}

void Container::remove_from_end() {
    list->remove_from_end();
}

void Container::remove_at_position(size_t position) {
    list->remove_by_index(position);
}

// Очистка
void Container::clear() {
    list->clear();
}

// Методы обработки сотрудников
void Container::get_employees_younger_than(int year, int min_experience) {
    auto& employees = list->get_all();
    for (const auto& employee : employees) {
        if (employee.birth_year > year && employee.experience > min_experience) {
            std::cout << employee << "\n";
        }
    }
}

void Container::get_by_department_and_remove(int department_code) {
    auto& employees = list->get_all();
    auto it = employees.begin();
    while (it != employees.end()) {
        if (it->department_code == department_code) {
            std::cout << *it << "\n";
            it = employees.erase(it);
        }
        else {
            ++it;
        }
    }
}

void Container::sort_employees() {
    auto& employees = list->get_all();
    std::sort(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
        if (a.department_code != b.department_code)
            return a.department_code < b.department_code;
        if (a.position != b.position)
            return a.position < b.position;
        return a.full_name < b.full_name;
        });
}

std::ostream& operator<<(std::ostream& os, const Container& container) {
    const auto& employees = container.list->get_all(); 
    if (employees.empty()) {
        os << "Список сотрудников пуст.\n";
    }
    else {
        for (const auto& employee : employees) {
            os << employee << "\n"; 
        }
    }
    return os;
}