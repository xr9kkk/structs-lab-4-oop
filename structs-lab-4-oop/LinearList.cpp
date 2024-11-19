#include "LinearList.h"

void LinearList::add_to_start(const Employee& employee) {
    list.insert(list.begin(), employee);
}

void LinearList::add_to_end(const Employee& employee) {
    list.push_back(employee);
}

void LinearList::add_after(int index, const Employee& employee) {
    if (index >= 0 && index < list.size()) {
        list.insert(list.begin() + index + 1, employee);
    }
}
void LinearList::remove_from_start() {
    if (!list.empty()) {
        list.erase(list.begin());
    }
}
void LinearList::remove_from_end() {
    if (!list.empty()) {
        list.pop_back();
    }
}
void LinearList::remove_by_index(int index) {
    if (index >= 0 && index < list.size()) {
        list.erase(list.begin() + index);
    }
}

Employee* LinearList::find_by_index(int index) {
    if (index >= 0 && index < list.size()) {
        return &list[index];
    }
    return nullptr;
}

void LinearList::clear() {
    list.clear();
}

const std::vector<Employee>& LinearList::get_all() const {
    return list;
}

std::vector<Employee>& LinearList::get_all() {
    return list;
}

size_t LinearList::size() const {
    return list.size();
}