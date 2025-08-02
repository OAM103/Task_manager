#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
public:
    Task(const std::string& description); // �����������, ����������� �������� ������
    std::string getDescription() const;    // ���������� �������� ������
    bool isCompleted() const;              // ���������� true, ���� ������ ���������, ����� false
    void markAsCompleted();                // �������� ������ ��� �����������
    std::string toString() const;          // ����������� ������ � ������ ��� ���������� � ����

private:
    std::string description_; // �������� ������
    bool completed_;     // ������ ������ (��������� ��� ���)
};

#endif // TASK_H
