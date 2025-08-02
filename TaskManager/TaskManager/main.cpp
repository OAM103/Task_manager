#include <iostream>
#include "task_manager.h"

int main() {
    TaskManager taskManager;                                 // Создаем объект класса TaskManager
    taskManager.loadTasksFromFile("tasks.txt");              // Загружаем задачи из файла при запуске программы

    int choice;                                          // Переменная для хранения выбора пользователя
    do {
        std::cout << "\nTask Manager\n";                  // Выводим заголовок программы
        std::cout << "1. Add task\n";                    // Выводим пункт меню "Добавить задачу"
        std::cout << "2. Remove task\n";                 // Выводим пункт меню "Удалить задачу"
        std::cout << "3. Mark task as completed\n";    // Выводим пункт меню "Отметить задачу как выполненную"
        std::cout << "4. Display tasks\n";              // Выводим пункт меню "Просмотреть список задач"
        std::cout << "5. Save tasks\n";                 // Выводим пункт меню "Сохранить список задач"
        std::cout << "6. Load tasks\n";                 // Выводим пункт меню "Загрузить список задач"
        std::cout << "7. Exit\n";                      // Выводим пункт меню "Выйти"
        std::cout << "Choose an action: ";             // Запрашиваем выбор пользователя
        std::cin >> choice;                                 // Читаем выбор пользователя

        std::cin.ignore();                                  // Очистка буфера ввода после cin >> int (важно для корректного чтения строк далее)

        switch (choice) {
        case 1: {
            std::string description;                   // Переменная для хранения описания задачи
            std::cout << "Enter task description: "; // Запрашиваем описание задачи
            std::getline(std::cin, description);        // Читаем строку с пробелами (используем getline)
            taskManager.addTask(description);           // Добавляем задачу в список
            break;
        }
        case 2: {
            int index;                               // Переменная для хранения индекса задачи
            std::cout << "Enter task number to remove: "; // Запрашиваем номер задачи для удаления
            std::cin >> index;                              // Читаем номер задачи
            taskManager.removeTask(index - 1);          // Удаляем задачу из списка (учитываем, что пользователь вводит номер, а не индекс)
            break;
        }
        case 3: {
            int index;                               // Переменная для хранения индекса задачи
            std::cout << "Enter task number to mark as completed: "; // Запрашиваем номер задачи для отметки как выполненной
            std::cin >> index;                              // Читаем номер задачи
            taskManager.markTaskAsCompleted(index - 1);    // Отмечаем задачу как выполненную (учитываем, что пользователь вводит номер, а не индекс)
            break;
        }
        case 4:
            taskManager.displayTasks();                   // Выводим список задач
            break;
        case 5:
            taskManager.saveTasksToFile("tasks.txt");    // Сохраняем список задач в файл
            break;
        case 6:
            taskManager.loadTasksFromFile("tasks.txt");    // Загружаем список задач из файла
            break;
        case 7:
            std::cout << "Saving tasks...\n";            // Выводим сообщение о сохранении задач
            taskManager.saveTasksToFile("tasks.txt");    // Сохраняем список задач перед выходом
            std::cout << "Program completed.\n";           // Выводим сообщение о завершении программы
            break;
        default:
            std::cout << "Error: Invalid choice.\n";      // Выводим сообщение об ошибке при некорректном выборе
        }
    } while (choice != 7);                                   // Повторяем цикл, пока пользователь не выберет пункт "Выйти"

    return 0;                                              // Возвращаем 0 (успешное завершение программы)
}