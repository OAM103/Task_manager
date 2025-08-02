#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
public:
    Task(const std::string& description); // Конструктор, принимающий описание задачи
    std::string getDescription() const;    // Возвращает описание задачи
    bool isCompleted() const;              // Возвращает true, если задача выполнена, иначе false
    void markAsCompleted();                // Отмечает задачу как выполненную
    std::string toString() const;          // Преобразует задачу в строку для сохранения в файл

private:
    std::string description_; // Описание задачи
    bool completed_;     // Статус задачи (выполнена или нет)
};

#endif // TASK_H
