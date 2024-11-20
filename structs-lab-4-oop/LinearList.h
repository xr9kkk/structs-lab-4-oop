#pragma once
#include "Employee.h"
#include <vector>

class LinearList {
private:
    std::vector<Employee> list;

public:
    bool is_empty() { return list.empty(); };
    void add_to_start(const Employee& employee);
    void add_to_end(const Employee& employee);
    void add_after(int index, const Employee& employee);
    void remove_from_start();
    void remove_from_end();
    void remove_by_index(int index);
    Employee* find_by_index(int index);
    void clear();
    const std::vector<Employee>& get_all() const;
    std::vector<Employee>& get_all();
    size_t size() const;
};