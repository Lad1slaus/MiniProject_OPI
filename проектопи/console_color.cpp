#include <iostream>     
#include <windows.h>    
#include "game.h"      

using namespace std;  

// Функция установки цвета консоли
void setConsoleColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hConsole, colorCode);      
}

// Функция для печати цветного текста 
void printColored(char symbol, int color) {
    setConsoleColor(color);  
    cout << symbol;          
    setConsoleColor(COLOR_WHITE); 
}

// Функция для печати цветного текста (строки)
void printColoredString(const string& text, int color) {
    setConsoleColor(color);  
    cout << text;            
    setConsoleColor(COLOR_WHITE); 
}
