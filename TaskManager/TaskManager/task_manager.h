#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <string>
#include "task.h"

class TaskManager {
public:
    TaskManager();                                         // Конструктор по умолчанию
    void addTask(const std::string& description);          // Добавляет новую задачу в список
    void removeTask(int index);                            // Удаляет задачу из списка по индексу
    void markTaskAsCompleted(int index);                  // Отмечает задачу как выполненную по индексу
    void displayTasks() const;                             // Выводит список задач в консоль
    void saveTasksToFile(const std::string& filename) const; // Сохраняет список задач в файл
    void loadTasksFromFile(const std::string& filename);  // Загружает список задач из файла

private:
    std::vector<Task> tasks_;     // Список задач (хранит объекты класса Task)
    std::string filename_; // Имя файла для сохранения и загрузки задач
};

#endif // TASK_MANAGER_H