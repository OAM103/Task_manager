#include "task.h"

// Конструктор класса Task.  Инициализирует описание задачи и устанавливает статус "не выполнена".
Task::Task(const std::string& description) : description_(description), completed_(false) {}

// Возвращает описание задачи.
std::string Task::getDescription() const {
    return description_;
}

// Возвращает true, если задача выполнена, иначе false.
bool Task::isCompleted() const {
    return completed_;
}

// Отмечает задачу как выполненную.  Устанавливает флаг completed_ в true.
void Task::markAsCompleted() {
    completed_ = true;
}

// Преобразует задачу в строку для сохранения в файл.
// Формат строки: "description|completed" (например, "Купить хлеб|0")
std::string Task::toString() const {
    return description_ + "|" + (completed_ ? "1" : "0"); // Используем тернарный оператор для записи статуса
}