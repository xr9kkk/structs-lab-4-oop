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
            "Выберите пункт меню:\n"
            "1. Проверить методы списка\n"
            "2. Проверить методы контейнера\n"
            "3. Выйти\n");

        switch (choice) {
        case 1: {
            while (true) {
                const int list_choice = menu(
                    "\nМетоды списка:\n"
                    "1. Добавить в начало\n"
                    "2. Добавить в конец\n"
                    "3. Добавить за индексом\n"
                    "4. Удалить из начала\n"
                    "5. Удалить из конца\n"
                    "6. Удалить по индексу\n"
                    "7. Найти по индексу\n"
                    "8. Очистить список\n"
                    "9. Вернуться в главное меню\n");

                switch (list_choice) {
                case 1: {
                    Employee emp;
                    std::cin >> emp;
                    container.add_to_start(emp);
                    std::cout << "Сотрудник добавлен в начало списка.\n";
                    break;
                }
                case 2: {
                    Employee emp;
                    std::cin >> emp;
                    container.add_to_end(emp);
                    std::cout << "Сотрудник добавлен в конец списка.\n";
                    break;
                }
                case 3: {
                    const int index = get_valid_input<int>("Введите индекс: ");
                    if (!(index >= 0 && index < container.get_list_size()))
                        std::cout << "Элемента с таким индексом не существует" << std::endl;
                    else
                    {
                        Employee emp;
                        std::cin >> emp;
                        container.add_at_position(emp, index);
                        std::cout << "Сотрудник добавлен за индексом " << index << ".\n";
                    }
                    break;
                }
                case 4:
                    if (container.is_empty())
                        std::cout << "Список пуст, удалять нечего" << std::endl;
                    else
                    {
                        container.remove_from_start();
                        std::cout << "Сотрудник удалён из начала списка.\n";
                    }
                    break;
                case 5:
                    if (container.is_empty())
                        std::cout << "Список пуст, удалять нечего" << std::endl;
                    else
                    {
                        container.remove_from_end();
                        std::cout << "Сотрудник удалён из конца списка.\n";
                    }
                    break;
                case 6: {
                    if (container.is_empty())
                        std::cout << "Список пуст, сначала добавьте сотрудников" << std::endl;
                    else
                    {
                        const int index = get_valid_input<int>("Введите индекс: ");
                        if (!(index >= 0 && index < container.get_list_size()))
                            std::cout << "Элемента с таким индексом не существует" << std::endl;

                        else
                        {
                            container.remove_at_position(index);
                            std::cout << "Сотрудник удалён по индексу " << index << ".\n";
                        }
                    }
                    break;
                }
                case 7: {
                    if (container.is_empty())
                        std::cout << "Список пуст, сначала добавьте сотрудников" << std::endl;
                    else
                    {
                        const int index = get_valid_input<int>("Введите индекс: ");
                        const Employee* emp = container.find_by_index(index);
                        if (emp) {
                            std::cout << *emp;
                        }
                        else {
                            std::cout << "Сотрудник с таким индексом не найден.\n";
                        }
                    }
                    break;
                }
                case 8:
                    if (container.is_empty())
                        std::cout << "Список пуст, чистить нечего" << std::endl;
                    else
                    {
                        container.clear();
                        std::cout << "Список очищен.\n";
                    }
                    break;
                case 9:
                    goto end_list_menu;
                default:
                    std::cout << "Некорректный выбор.\n";
                }
            }
        end_list_menu:
            break;
        }
        case 2: {
            while (true) {
                const int container_choice = menu(
                    "\nМетоды контейнера:\n"
                    "1. Добавить сотрудника\n"
                    "2. Показать сотрудников моложе года со стажем > 5 лет\n"
                    "3. Удалить сотрудников из отдела\n"
                    "4. Отсортировать сотрудников\n"
                    "5. Показать всех сотрудников\n"
                    "6. Вернуться в главное меню\n");

                switch (container_choice) {
                case 1: {
                    Employee emp;
                    std::cin >> emp;
                    container.add_to_end(emp);
                    std::cout << "Сотрудник добавлен в контейнер.\n";
                    break;
                }
                case 2: {
                    if (container.is_empty())
                        std::cout << "Список пуст, сначала добавьте сотрудников" << std::endl;
                    else
                    {
                        const int year = get_valid_input<int>("Введите год: ");
                        std::cout << "Сотрудники моложе " << year << " со стажем > 5 лет:\n";
                        container.get_employees_younger_than(year, 5);
                    }
                    break;
                }
                case 3: {
                    if (container.is_empty())
                        std::cout << "Список пуст, сначала добавьте сотрудников" << std::endl;
                    else
                    {
                        const int dept_code = get_valid_input<int>("Введите код отдела: ");
                        std::cout << "Удаление сотрудников из отдела " << dept_code << ":\n";
                        container.get_by_department_and_remove(dept_code);
                    }
                    break;
                }
                case 4:
                    if (container.is_empty())
                        std::cout << "Список пуст, сначала добавьте сотрудников" << std::endl;
                    else
                    {
                        container.sort_employees();
                        std::cout << "Сотрудники отсортированы.\n";
                    }
                    break;
                case 5:
                    std::cout << container;
                    break;
                case 6:
                    goto end_container_menu;
                default:
                    std::cout << "Некорректный выбор.\n";
                }
            }
        end_container_menu:
            break;
        }
        case 3:
            std::cout << "Выход из программы.\n";
            return 0;
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}

int menu(const std::string& text) {
    std::cout << text;
    return get_valid_input<int>("Ваш выбор: ");
}
