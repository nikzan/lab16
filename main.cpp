#include "CircularList.h"
#include "CircularDoubleList.h"
#include "DoubleLinkedList.h"
#include "ChildrenCircle.h"
#include <iostream>
#include <string>
#include <fstream>

void Task1() {
    CircularList List;

    std::cout << "Введите количество элементов: ";
    int N;
    std::cin >> N;

    std::cout << "Введите " << N << " элементов:" << std::endl;
    for (int I = 0; I < N; ++I) {
        int Value;
        std::cin >> Value;
        List.Add(Value);
    }

    std::cout << "Содержимое списка: ";
    List.Print();

    std::cout << "Введите имя файла для записи результата: ";
    std::string Filename;
    std::cin >> Filename;

    List.WriteToFile(Filename);
    std::cout << "Успешно " << std::endl;
}

void Task2() {
    CircularDoubleList List;

    std::cout << "Введите количество элементов: ";
    int N;
    std::cin >> N;

    std::cout << "Введите " << N << " элементов:" << std::endl;
    for (int I = 0; I < N; ++I) {
        int Value;
        std::cin >> Value;
        List.Add(Value);
    }

    std::cout << "Исходный список: ";
    List.Print();

    DoubleNode* LastNode = List.RemoveSurrounded();

    std::cout << "Список после преобразования: ";
    List.Print();

    if (LastNode) {
        std::cout << "Последний элемент списка: " << LastNode->Data << std::endl;
    }
    else {
        std::cout << "Список пуст" << std::endl;
    }
}

void Task3() {
    DoubleLinkedList List;

    std::cout << "Введите количество элементов: ";
    int N;
    std::cin >> N;

    std::cout << "Введите " << N << " элементов:" << std::endl;
    for (int I = 0; I < N; ++I) {
        int Value;
        std::cin >> Value;
        List.Add(Value);
    }

    std::cout << "Исходный список: ";
    List.Print();

    DoubleNode* NewHead = List.ReorderOdd();

    std::cout << "Список после преобразования: ";
    List.Print();

    if (NewHead) {
        std::cout << "Первый элемент преобразованного списка: " << NewHead->Data << std::endl;
    }
    else {
        std::cout << "Список пуст" << std::endl;
    }
}

void Task4() {
    DoubleLinkedList List;

    std::cout << "Введите количество элементов (0 для пустого списка): ";
    int N;
    std::cin >> N;

    if (N > 0) {
        std::cout << "Введите " << N << " элементов:" << std::endl;
        for (int I = 0; I < N; ++I) {
            int Value;
            std::cin >> Value;
            List.Add(Value);
        }

        std::cout << "Исходный список: ";
        List.Print();
    }
    else {
        std::cout << "Исходный список пуст" << std::endl;
    }

    DoubleNode* Barrier = List.ConvertToCircular();

    std::cout << "Барьерный элемент: " << Barrier->Data << std::endl;

    if (Barrier->Next != Barrier) {
        std::cout << "Следующий элемент после барьера: " << Barrier->Next->Data << std::endl;
        std::cout << "Предыдущий элемент перед барьером: " << Barrier->Prev->Data << std::endl;
    }
    else {
        std::cout << "Барьерный элемент указывает сам на себя (список был пуст)" << std::endl;
    }
}

void Task5() {

    const std::string InputFilename = "../InputTask5.txt";
    const std::string OutputFilename = "../OutputTask5.txt";

    std::cout << "Используется входной файл: " << InputFilename << std::endl;
    std::cout << "Результат будет записан в: " << OutputFilename << std::endl;

    ChildrenCircle Circle;
    Circle.ProcessCounting(InputFilename, OutputFilename);

    std::cout << "Результат записан в файл " << OutputFilename << std::endl;
}

int main() {
    int Choice;
    bool Running = true;

    while (Running) {
        std::cout << "\nВыберите задачу (1-5, 0 для выхода): ";
        std::cin >> Choice;

        switch (Choice) {
        case 0: {
            Running = false;
            break;
        }
        case 1: {
            Task1();
            break;
        }
        case 2: {
            Task2();
            break;
        }
        case 3: {
            Task3();
            break;
        }
        case 4: {
            Task4();
            break;
        }
        case 5: {
            Task5();
            break;
        }
        default: {
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
        }
    }

    return 0;
}