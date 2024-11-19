#pragma once

#include "LinearList.h"
#include "Employee.h"
#include <vector>
#include <iostream>
#include <algorithm>

class Container {
private:
    LinearList* list;

public:
    // Конструктор и деструктор
    Container();
    ~Container();

    // Методы для работы с LinearList
    void add_to_start(const Employee& employee);
    void add_to_end(const Employee& employee);
    void add_at_position(const Employee& employee, size_t position);

    void remove_from_start();
    void remove_from_end();
    void remove_at_position(size_t position);

    void clear();

    // Контейнерные методы
    void get_employees_younger_than(int year, int min_experience);
    void get_by_department_and_remove(int department_code);
    void sort_employees();

    friend std::ostream& operator<<(std::ostream& os, const Container& container);
};
