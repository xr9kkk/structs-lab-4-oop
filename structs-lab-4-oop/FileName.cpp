#include "Employee.h"
#include "LinearList.h"
#include "Container.h"
#include <iostream>
#include <string>

int menu(const std::string& text);

int main() {
    setlocale(LC_ALL, "ru");

    Container container;

    while (true) {
        const int choice = menu(
            "�������� ����� ����:\n"
            "1. ��������� ������ ������\n"
            "2. ��������� ������ ����������\n"
            "3. �����\n");

        switch (choice) {
        case 1: {
            while (true) {
                const int list_choice = menu(
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
                    container.add_to_start(emp);
                    std::cout << "��������� �������� � ������ ������.\n";
                    break;
                }
                case 2: {
                    Employee emp;
                    std::cin >> emp;
                    container.add_to_end(emp);
                    std::cout << "��������� �������� � ����� ������.\n";
                    break;
                }
                case 3: {
                    const int index = get_valid_input<int>("������� ������: ");
                    if (!(index >= 0 && index < container.get_list_size()))
                        std::cout << "�������� � ����� �������� �� ����������" << std::endl;
                    else
                    {
                        Employee emp;
                        std::cin >> emp;
                        container.add_at_position(emp, index);
                        std::cout << "��������� �������� �� �������� " << index << ".\n";
                    }
                    break;
                }
                case 4:
                    if (container.is_empty())
                        std::cout << "������ ����, ������� ������" << std::endl;
                    else
                    {
                        container.remove_from_start();
                        std::cout << "��������� ����� �� ������ ������.\n";
                    }
                    break;
                case 5:
                    if (container.is_empty())
                        std::cout << "������ ����, ������� ������" << std::endl;
                    else
                    {
                        container.remove_from_end();
                        std::cout << "��������� ����� �� ����� ������.\n";
                    }
                    break;
                case 6: {
                    if (container.is_empty())
                        std::cout << "������ ����, ������� �������� �����������" << std::endl;
                    else
                    {
                        const int index = get_valid_input<int>("������� ������: ");
                        if (!(index >= 0 && index < container.get_list_size()))
                            std::cout << "�������� � ����� �������� �� ����������" << std::endl;

                        else
                        {
                            container.remove_at_position(index);
                            std::cout << "��������� ����� �� ������� " << index << ".\n";
                        }
                    }
                    break;
                }
                case 7: {
                    if (container.is_empty())
                        std::cout << "������ ����, ������� �������� �����������" << std::endl;
                    else
                    {
                        const int index = get_valid_input<int>("������� ������: ");
                        const Employee* emp = container.find_by_index(index);
                        if (emp) {
                            std::cout << *emp;
                        }
                        else {
                            std::cout << "��������� � ����� �������� �� ������.\n";
                        }
                    }
                    break;
                }
                case 8:
                    if (container.is_empty())
                        std::cout << "������ ����, ������� ������" << std::endl;
                    else
                    {
                        container.clear();
                        std::cout << "������ ������.\n";
                    }
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
                const int container_choice = menu(
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
                    if (container.is_empty())
                        std::cout << "������ ����, ������� �������� �����������" << std::endl;
                    else
                    {
                        const int year = get_valid_input<int>("������� ���: ");
                        std::cout << "���������� ������ " << year << " �� ������ > 5 ���:\n";
                        container.get_employees_younger_than(year, 5);
                    }
                    break;
                }
                case 3: {
                    if (container.is_empty())
                        std::cout << "������ ����, ������� �������� �����������" << std::endl;
                    else
                    {
                        const int dept_code = get_valid_input<int>("������� ��� ������: ");
                        std::cout << "�������� ����������� �� ������ " << dept_code << ":\n";
                        container.get_by_department_and_remove(dept_code);
                    }
                    break;
                }
                case 4:
                    if (container.is_empty())
                        std::cout << "������ ����, ������� �������� �����������" << std::endl;
                    else
                    {
                        container.sort_employees();
                        std::cout << "���������� �������������.\n";
                    }
                    break;
                case 5:
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

int menu(const std::string& text) {
    std::cout << text;
    return get_valid_input<int>("��� �����: ");
}
