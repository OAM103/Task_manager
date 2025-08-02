#include "task_manager.h"
#include <iostream>
#include <fstream>
#include <sstream> 

// Конструктор по умолчанию.  Инициализирует имя файла для сохранения/загрузки задач.
// Используется список инициализации для установки значения filename_.
TaskManager::TaskManager() : filename_("tasks.txt") {}

// Добавляет новую задачу в список.
void TaskManager::addTask(const std::string& description) {
    tasks_.emplace_back(description); // Создаем новый объект Task в векторе
    std::cout << "Task added.\n";
}

// Удаляет задачу из списка по индексу.
void TaskManager::removeTask(int index) {
    // Проверяем, что индекс находится в допустимом диапазоне.
    if (index >= 0 && index < tasks_.size()) {
        tasks_.erase(tasks_.begin() + index); // Удаляем элемент из вектора
        std::cout << "Task removed.\n";
    }
    else {
        std::cout << "Error: Invalid task index.\n";
    }
}

// Отмечает задачу как выполненную по индексу.
void TaskManager::markTaskAsCompleted(int index) {
    // Проверяем, что индекс находится в допустимом диапазоне.
    if (index >= 0 && index < tasks_.size()) {
        tasks_[index].markAsCompleted(); // Вызываем метод markAsCompleted() для конкретной задачи
        std::cout << "Task marked as completed.\n";
    }
    else {
        std::cout << "Error: Invalid task index.\n";
    }
}

// Выводит список задач в консоль.
void TaskManager::displayTasks() const {
    // Если список задач пуст, выводим соответствующее сообщение.
    if (tasks_.empty()) {
        std::cout << "Task list is empty.\n";
        return;
    }

    std::cout << "Task list:\n";
    // Перебираем все задачи в списке и выводим их в формате:
    // 1. [x] Купить хлеб (где x означает, что задача выполнена)
    for (size_t i = 0; i < tasks_.size(); ++i) {
        std::cout << i + 1 << ". [" << (tasks_[i].isCompleted() ? "x" : " ") << "] " << tasks_[i].getDescription() << "\n";
    }
}

// Сохраняет список задач в файл.
void TaskManager::saveTasksToFile(const std::string& filename) const {
    std::ofstream outputFile(filename); // Создаем объект ofstream для записи в файл

    // Проверяем, успешно ли открылся файл.
    if (outputFile.is_open()) {
        // Перебираем все задачи в списке и записываем их в файл.
        for (const auto& task : tasks_) {
            outputFile << task.toString() << "\n"; // Записываем задачу в файл, используя метод toString()
        }
        outputFile.close(); // Закрываем файл
        std::cout << "Task list saved to file: " << filename << "\n";
    }
    else {
        std::cout << "Error: Unable to open file for saving.\n";
    }
}

// Загружает список задач из файла.
void TaskManager::loadTasksFromFile(const std::string& filename) {
    std::ifstream inputFile(filename); // Создаем объект ifstream для чтения из файла
    std::string line;                  // Переменная для хранения строки, прочитанной из файла

    // Проверяем, успешно ли открылся файл.
    if (inputFile.is_open()) {
        tasks_.clear(); // Очищаем текущий список задач перед загрузкой из файла

        // Читаем файл построчно.
        while (std::getline(inputFile, line)) {
            // Разделяем строку на описание и статус, используя stringstream.
            std::stringstream ss(line); // Создаем stringstream из строки
            std::string description;     // Переменная для хранения описания задачи
            std::string completedStr;  // Переменная для хранения статуса задачи (в виде строки)

            // Используем getline для разделения строки по символу '|'.
            std::getline(ss, description, '|');   // Читаем описание задачи до символа '|'
            std::getline(ss, completedStr); // Читаем статус задачи после символа '|'

            tasks_.emplace_back(description); // Создаем новый объект Task с описанием
            // Если статус задачи равен "1", то отмечаем ее как выполненную.
            if (completedStr == "1") {
                tasks_.back().markAsCompleted(); // Получаем ссылку на последнюю добавленную задачу и вызываем метод markAsCompleted()
            }
        }
        inputFile.close(); // Закрываем файл
        std::cout << "Task list loaded from file: " << filename << "\n";
    }
    else {
        std::cout << "Error: Unable to open file for loading.\n";
    }
}