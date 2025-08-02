#include "task.h"

// ����������� ������ Task.  �������������� �������� ������ � ������������� ������ "�� ���������".
Task::Task(const std::string& description) : description_(description), completed_(false) {}

// ���������� �������� ������.
std::string Task::getDescription() const {
    return description_;
}

// ���������� true, ���� ������ ���������, ����� false.
bool Task::isCompleted() const {
    return completed_;
}

// �������� ������ ��� �����������.  ������������� ���� completed_ � true.
void Task::markAsCompleted() {
    completed_ = true;
}

// ����������� ������ � ������ ��� ���������� � ����.
// ������ ������: "description|completed" (��������, "������ ����|0")
std::string Task::toString() const {
    return description_ + "|" + (completed_ ? "1" : "0"); // ���������� ��������� �������� ��� ������ �������
}