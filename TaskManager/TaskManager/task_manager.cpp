#include "task_manager.h"
#include <iostream>
#include <fstream>
#include <sstream> 

// ����������� �� ���������.  �������������� ��� ����� ��� ����������/�������� �����.
// ������������ ������ ������������� ��� ��������� �������� filename_.
TaskManager::TaskManager() : filename_("tasks.txt") {}

// ��������� ����� ������ � ������.
void TaskManager::addTask(const std::string& description) {
    tasks_.emplace_back(description); // ������� ����� ������ Task � �������
    std::cout << "Task added.\n";
}

// ������� ������ �� ������ �� �������.
void TaskManager::removeTask(int index) {
    // ���������, ��� ������ ��������� � ���������� ���������.
    if (index >= 0 && index < tasks_.size()) {
        tasks_.erase(tasks_.begin() + index); // ������� ������� �� �������
        std::cout << "Task removed.\n";
    }
    else {
        std::cout << "Error: Invalid task index.\n";
    }
}

// �������� ������ ��� ����������� �� �������.
void TaskManager::markTaskAsCompleted(int index) {
    // ���������, ��� ������ ��������� � ���������� ���������.
    if (index >= 0 && index < tasks_.size()) {
        tasks_[index].markAsCompleted(); // �������� ����� markAsCompleted() ��� ���������� ������
        std::cout << "Task marked as completed.\n";
    }
    else {
        std::cout << "Error: Invalid task index.\n";
    }
}

// ������� ������ ����� � �������.
void TaskManager::displayTasks() const {
    // ���� ������ ����� ����, ������� ��������������� ���������.
    if (tasks_.empty()) {
        std::cout << "Task list is empty.\n";
        return;
    }

    std::cout << "Task list:\n";
    // ���������� ��� ������ � ������ � ������� �� � �������:
    // 1. [x] ������ ���� (��� x ��������, ��� ������ ���������)
    for (size_t i = 0; i < tasks_.size(); ++i) {
        std::cout << i + 1 << ". [" << (tasks_[i].isCompleted() ? "x" : " ") << "] " << tasks_[i].getDescription() << "\n";
    }
}

// ��������� ������ ����� � ����.
void TaskManager::saveTasksToFile(const std::string& filename) const {
    std::ofstream outputFile(filename); // ������� ������ ofstream ��� ������ � ����

    // ���������, ������� �� �������� ����.
    if (outputFile.is_open()) {
        // ���������� ��� ������ � ������ � ���������� �� � ����.
        for (const auto& task : tasks_) {
            outputFile << task.toString() << "\n"; // ���������� ������ � ����, ��������� ����� toString()
        }
        outputFile.close(); // ��������� ����
        std::cout << "Task list saved to file: " << filename << "\n";
    }
    else {
        std::cout << "Error: Unable to open file for saving.\n";
    }
}

// ��������� ������ ����� �� �����.
void TaskManager::loadTasksFromFile(const std::string& filename) {
    std::ifstream inputFile(filename); // ������� ������ ifstream ��� ������ �� �����
    std::string line;                  // ���������� ��� �������� ������, ����������� �� �����

    // ���������, ������� �� �������� ����.
    if (inputFile.is_open()) {
        tasks_.clear(); // ������� ������� ������ ����� ����� ��������� �� �����

        // ������ ���� ���������.
        while (std::getline(inputFile, line)) {
            // ��������� ������ �� �������� � ������, ��������� stringstream.
            std::stringstream ss(line); // ������� stringstream �� ������
            std::string description;     // ���������� ��� �������� �������� ������
            std::string completedStr;  // ���������� ��� �������� ������� ������ (� ���� ������)

            // ���������� getline ��� ���������� ������ �� ������� '|'.
            std::getline(ss, description, '|');   // ������ �������� ������ �� ������� '|'
            std::getline(ss, completedStr); // ������ ������ ������ ����� ������� '|'

            tasks_.emplace_back(description); // ������� ����� ������ Task � ���������
            // ���� ������ ������ ����� "1", �� �������� �� ��� �����������.
            if (completedStr == "1") {
                tasks_.back().markAsCompleted(); // �������� ������ �� ��������� ����������� ������ � �������� ����� markAsCompleted()
            }
        }
        inputFile.close(); // ��������� ����
        std::cout << "Task list loaded from file: " << filename << "\n";
    }
    else {
        std::cout << "Error: Unable to open file for loading.\n";
    }
}