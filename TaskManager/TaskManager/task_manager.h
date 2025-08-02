#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <string>
#include "task.h"

class TaskManager {
public:
    TaskManager();                                         // ����������� �� ���������
    void addTask(const std::string& description);          // ��������� ����� ������ � ������
    void removeTask(int index);                            // ������� ������ �� ������ �� �������
    void markTaskAsCompleted(int index);                  // �������� ������ ��� ����������� �� �������
    void displayTasks() const;                             // ������� ������ ����� � �������
    void saveTasksToFile(const std::string& filename) const; // ��������� ������ ����� � ����
    void loadTasksFromFile(const std::string& filename);  // ��������� ������ ����� �� �����

private:
    std::vector<Task> tasks_;     // ������ ����� (������ ������� ������ Task)
    std::string filename_; // ��� ����� ��� ���������� � �������� �����
};

#endif // TASK_MANAGER_H