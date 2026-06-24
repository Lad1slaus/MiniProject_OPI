#include <iostream>    
#include <cstdlib>     
#include <ctime>       
#include <windows.h>    
#include "game.h"       

using namespace std;    

// ОПРЕДЕЛЕНИЕ ГЛОБАЛЬНЫХ ПЕРЕМЕННЫХ
int board[9];           // Игровое поле: 9 клеток
bool gameActive;        // Активна ли игра?
int playerSymbol;       // 1 = X, 2 = O
int botSymbol;          // 1 = X, 2 = O

//  ФУНКЦИЯ НАСТРОЙКИ КОНСОЛИ 
void setupConsole() {
    SetConsoleCP(65001);        // Устанавливаем кодовую страницу ввода на UTF-8
    SetConsoleOutputCP(65001);  // Устанавливаем кодовую страницу вывода на UTF-8
    setlocale(LC_ALL, "ru");    // Устанавливаем русскую локаль
}

// ФУНКЦИЯ ОТОБРАЖЕНИЯ ПОЛЯ
void displayBoard() {
    cout << "\n";              
    cout << " +---+---+---+\n";  // Верхняя граница поля

    for (int i = 0; i < 3; i++) {          // 3 строки, цикл поля
        cout << " |";                     

        for (int j = 0; j < 3; j++) {      
            int index = i * 3 + j;         // Преобразуем координаты в индекс (0-8)

            if (board[index] == 0) {       // Если клетка пустая
                setConsoleColor(COLOR_GREEN);  // Зеленый цвет
                cout << " " << index << " ";   // Показываем номер клетки
                setConsoleColor(COLOR_WHITE);  
                cout << "|";                   
            }
            else if (board[index] == 1) {  // Если в клетке X
                setConsoleColor(COLOR_RED);    // Красный цвет
                cout << " X ";                 // Показываем X
                setConsoleColor(COLOR_WHITE);  
                cout << "|";                  
            }
            else {                          // Если в клетке O
                setConsoleColor(COLOR_BLUE);   // Синий цвет
                cout << " O ";                 // Показываем O
                setConsoleColor(COLOR_WHITE);  
                cout << "|";                   
            }
        }

        cout << "\n";                      // Переход на новую строку
        if (i < 2) cout << " +---+---+---+\n"; // Средняя граница 
    }

    cout << " +---+---+---+\n\n";         // Нижняя граница поля
}

//  ФУНКЦИЯ ВЫБОРА СИМВОЛА 
void chooseSymbol() {
    char choice;              // Выбор пользователя
    bool validChoice = false; // Флаг корректного выбора

    setConsoleColor(COLOR_RED);
    cout << "Крестики (X) - красные\n";
    setConsoleColor(COLOR_BLUE);
    cout << "Нолики (O) - синие\n";
    setConsoleColor(COLOR_WHITE);

    // Цикл продолжается, пока пользователь не сделает правильный выбор
    while (!validChoice) {
        cout << "\nВыберите символ (";
        setConsoleColor(COLOR_RED);
        cout << "X";
        setConsoleColor(COLOR_WHITE);
        cout << "/";
        setConsoleColor(COLOR_BLUE);
        cout << "O";
        setConsoleColor(COLOR_WHITE);
        cout << "): ";

        cin >> choice;  // Считываем выбор пользователя

        // Обработка выбора X 
        if (choice == 'X' || choice == 'x' || choice == 'Х' || choice == 'х') {
            playerSymbol = 1;  // Игрок будет X 
            botSymbol = 2;     // Компьютер будет O 
            validChoice = true; 

      
            cout << "\nВы играете за ";
            setConsoleColor(COLOR_RED);
            cout << "КРЕСТИКИ";
            setConsoleColor(COLOR_WHITE);
            cout << " (красные)\n";
        }
        // Обработка выбора O 
        else if (choice == 'O' || choice == 'o' || choice == 'О' || choice == 'о' || choice == '0') {
            playerSymbol = 2;  // Игрок будет O 
            botSymbol = 1;     // Компьютер будет X 
            validChoice = true; 

            cout << "\nВы играете за ";
            setConsoleColor(COLOR_BLUE);
            cout << "НОЛИКИ";
            setConsoleColor(COLOR_WHITE);
            cout << " (синие)\n";
        }
        // Если введен неправильный символ
        else {
            setConsoleColor(COLOR_YELLOW); 
            cout << "Ошибка! Введите X или O\n";
            setConsoleColor(COLOR_WHITE);   
        }
    }
}