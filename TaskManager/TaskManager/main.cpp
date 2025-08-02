#include <iostream>
#include "task_manager.h"

int main() {
    TaskManager taskManager;                                 // ������� ������ ������ TaskManager
    taskManager.loadTasksFromFile("tasks.txt");              // ��������� ������ �� ����� ��� ������� ���������

    int choice;                                          // ���������� ��� �������� ������ ������������
    do {
        std::cout << "\nTask Manager\n";                  // ������� ��������� ���������
        std::cout << "1. Add task\n";                    // ������� ����� ���� "�������� ������"
        std::cout << "2. Remove task\n";                 // ������� ����� ���� "������� ������"
        std::cout << "3. Mark task as completed\n";    // ������� ����� ���� "�������� ������ ��� �����������"
        std::cout << "4. Display tasks\n";              // ������� ����� ���� "����������� ������ �����"
        std::cout << "5. Save tasks\n";                 // ������� ����� ���� "��������� ������ �����"
        std::cout << "6. Load tasks\n";                 // ������� ����� ���� "��������� ������ �����"
        std::cout << "7. Exit\n";                      // ������� ����� ���� "�����"
        std::cout << "Choose an action: ";             // ����������� ����� ������������
        std::cin >> choice;                                 // ������ ����� ������������

        std::cin.ignore();                                  // ������� ������ ����� ����� cin >> int (����� ��� ����������� ������ ����� �����)

        switch (choice) {
        case 1: {
            std::string description;                   // ���������� ��� �������� �������� ������
            std::cout << "Enter task description: "; // ����������� �������� ������
            std::getline(std::cin, description);        // ������ ������ � ��������� (���������� getline)
            taskManager.addTask(description);           // ��������� ������ � ������
            break;
        }
        case 2: {
            int index;                               // ���������� ��� �������� ������� ������
            std::cout << "Enter task number to remove: "; // ����������� ����� ������ ��� ��������
            std::cin >> index;                              // ������ ����� ������
            taskManager.removeTask(index - 1);          // ������� ������ �� ������ (���������, ��� ������������ ������ �����, � �� ������)
            break;
        }
        case 3: {
            int index;                               // ���������� ��� �������� ������� ������
            std::cout << "Enter task number to mark as completed: "; // ����������� ����� ������ ��� ������� ��� �����������
            std::cin >> index;                              // ������ ����� ������
            taskManager.markTaskAsCompleted(index - 1);    // �������� ������ ��� ����������� (���������, ��� ������������ ������ �����, � �� ������)
            break;
        }
        case 4:
            taskManager.displayTasks();                   // ������� ������ �����
            break;
        case 5:
            taskManager.saveTasksToFile("tasks.txt");    // ��������� ������ ����� � ����
            break;
        case 6:
            taskManager.loadTasksFromFile("tasks.txt");    // ��������� ������ ����� �� �����
            break;
        case 7:
            std::cout << "Saving tasks...\n";            // ������� ��������� � ���������� �����
            taskManager.saveTasksToFile("tasks.txt");    // ��������� ������ ����� ����� �������
            std::cout << "Program completed.\n";           // ������� ��������� � ���������� ���������
            break;
        default:
            std::cout << "Error: Invalid choice.\n";      // ������� ��������� �� ������ ��� ������������ ������
        }
    } while (choice != 7);                                   // ��������� ����, ���� ������������ �� ������� ����� "�����"

    return 0;                                              // ���������� 0 (�������� ���������� ���������)
}