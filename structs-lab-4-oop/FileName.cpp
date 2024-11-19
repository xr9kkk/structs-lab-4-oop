#include "Employee.h"
#include "LinearList.h"
#include "Container.h"
#include <iostream>
#include <string>

// �������� ������� ����
int menu(const std::string& text);

// ������� �������
int main() {
    setlocale(LC_ALL, "ru");

    Container container;
    LinearList list;

    while (true) {
        int choice = menu(
            "�������� ����� ����:\n"
            "1. ��������� ������ ������\n"
            "2. ��������� ������ ����������\n"
            "3. �����\n");

        switch (choice) {
        case 1: {
            while (true) {
                int list_choice = menu(
                    "\n������ ������:\n"
                    "1. �������� � ������\n"
                    "2. �������� � �����\n"
                    "3. �������� �� ��������\n"
                    "4. ������� �� ������\n"
                    "5. ������� �� �����\n"
                    "6. ������� �� �������\n"
                    "7. ����� �� �������\n"
                    "8. �������� ������\n"
                    "9. ��������� � ������� ����\n");

                switch (list_choice) {
                case 1: {
                    Employee emp;
                    std::cin >> emp;
                    list.add_to_start(emp);
                    std::cout << "��������� �������� � ������ ������.\n";
                    break;
                }
                case 2: {
                    Employee emp;
                    std::cin >> emp;
                    list.add_to_end(emp);
                    std::cout << "��������� �������� � ����� ������.\n";
                    break;
                }
                case 3: {
                    int index = get_valid_input<int>("������� ������: ");
                    Employee emp;
                    std::cin >> emp;
                    list.add_after(index, emp);
                    std::cout << "��������� �������� �� �������� " << index << ".\n";
                    break;
                }
                case 4:
                    list.remove_from_start();
                    std::cout << "��������� ����� �� ������ ������.\n";
                    break;
                case 5:
                    list.remove_from_end();
                    std::cout << "��������� ����� �� ����� ������.\n";
                    break;
                case 6: {
                    int index = get_valid_input<int>("������� ������: ");
                    list.remove_by_index(index);
                    std::cout << "��������� ����� �� ������� " << index << ".\n";
                    break;
                }
                case 7: {
                    int index = get_valid_input<int>("������� ������: ");
                    Employee* emp = list.find_by_index(index);
                    if (emp) {
                        std::cout << *emp;
                    }
                    else {
                        std::cout << "��������� � ����� �������� �� ������.\n";
                    }
                    break;
                }
                case 8:
                    list.clear();
                    std::cout << "������ ������.\n";
                    break;
                case 9:
                    goto end_list_menu;
                default:
                    std::cout << "������������ �����.\n";
                }
            }
        end_list_menu:
            break;
        }
        case 2: {
            while (true) {
                int container_choice = menu(
                    "\n������ ����������:\n"
                    "1. �������� ����������\n"
                    "2. �������� ����������� ������ ���� �� ������ > 5 ���\n"
                    "3. ������� ����������� �� ������\n"
                    "4. ������������� �����������\n"
                    "5. �������� ���� �����������\n"
                    "6. ��������� � ������� ����\n");

                switch (container_choice) {
                case 1: {
                    Employee emp;
                    std::cin >> emp;
                    container.add_to_end(emp);
                    std::cout << "��������� �������� � ���������.\n";
                    break;
                }
                case 2: {
                    int year = get_valid_input<int>("������� ���: ");
                    std::cout << "���������� ������ " << year << " �� ������ > 5 ���:\n";
                    container.get_employees_younger_than(year, 5);
                    break;
                }
                case 3: {
                    int dept_code = get_valid_input<int>("������� ��� ������: ");
                    std::cout << "�������� ����������� �� ������ " << dept_code << ":\n";
                    container.get_by_department_and_remove(dept_code);
                    break;
                }
                case 4:
                    container.sort_employees();
                    std::cout << "���������� �������������.\n";
                    break;
                case 5:
                    std::cout << "��� ����������:\n";
                    std::cout << container;
                    break;
                case 6:
                    goto end_container_menu;
                default:
                    std::cout << "������������ �����.\n";
                }
            }
        end_container_menu:
            break;
        }
        case 3:
            std::cout << "����� �� ���������.\n";
            return 0;
        default:
            std::cout << "������������ �����. ���������� �����.\n";
        }
    }

    return 0;
}

// ������� ��� ����������� ���� � ��������� �����
int menu(const std::string& text) {
    std::cout << text;
    return get_valid_input<int>("��� �����: ");
}
