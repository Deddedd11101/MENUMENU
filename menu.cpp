// menu.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); 
constexpr auto ESC = 27;;
constexpr auto UP = 72;;
constexpr auto DOWN = 80;;
constexpr auto ENTER = 13;;
HWND hWnd = GetConsoleWindow();
RECT rc;


void GoToXY(short x, short y)
{
    SetConsoleCursorPosition(hStdOut, { x, y });
}
void ConsoleCursorVisible(bool show, short size)
{
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = show; 
        structCursorInfo.dwSize = size; 
        SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}
int main()
{
   




    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    SetConsoleTitle(L"Menu");
    
    HWND hWnd = GetConsoleWindow();
    RECT rc;
    GetClientRect(hWnd, &rc);
    

    setlocale(0, "Rus"); 
    ConsoleCursorVisible(false, 100);
    string Menu[] = { "Лабораторная №1", "Лабораторная №2", "Лабораторная №3", "Выход" };
    int active_menu = 0;

    
    char ch;
    while (true)
    {
        int x = 50;
        int  y = 13;
        GoToXY(x, y);
        for (int i = 0; i < size(Menu); i++)
        {
            if (i == active_menu) SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            else SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
            GoToXY(x, y++);
            cout << Menu[i] << endl;
        }

        std::ifstream  file;
        static char  buff[1024][1024];
        int i = 0;


        ch = _getch();
        if (ch == -32) ch = _getch(); // Отлавливаем стрелочки
        switch (ch)
        {
        case ESC :
            exit(0);
        case UP: 
            if (active_menu>0)
            --active_menu;
            break;
        case DOWN:
            if (active_menu < size(Menu)-1)
            ++active_menu;
            break;
        case ENTER:
            switch(active_menu)
            {
            case 0:
                system("CLS");
                GoToXY(x, y);
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
               
                file.open("C:\\Users/Пользователь/Desktop/lol.txt");
                while (!file.is_open()) {
                    std::cerr << "File error!\n";
                    std::cin.ignore();
                }


                while (!file.eof()) {  
                    file.getline(buff[i], sizeof(buff)); 
                    std::cout << buff[i]<< "\n";
                    ++i;
                }
                file.close();
                std::cin.ignore();
                _getch();
                system("CLS");
                break;
            case 1:
                system("CLS");
                GoToXY(x, y);
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

                file.open("C:\\Users/Пользователь/Desktop/lol2.txt");
                while (!file.is_open()) {
                    std::cerr << "File error!\n";
                    std::cin.ignore();
                }


                while (!file.eof()) {
                    file.getline(buff[i], sizeof(buff));
                    std::cout << buff[i] << "\n";
                    ++i;
                }
                file.close();
                std::cin.ignore();
                _getch();
                system("CLS");
                break;
            case 2:
                system("CLS");
                GoToXY(x, y);
                SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

                file.open("C:\\Users/Пользователь/Desktop/lol3.txt");
                while (!file.is_open()) {
                    std::cerr << "File error!\n";
                    std::cin.ignore();
                }


                while (!file.eof()) {
                    file.getline(buff[i], sizeof(buff));
                    std::cout << buff[i] << "\n";
                    ++i;
                }
                file.close();
                std::cin.ignore();
                _getch();
                system("CLS");
                break;
            case 3:
                exit(0);
            }
        default: 
            cout << "Kod" << (int)ch << endl;
        }
    }
    _getch();
}


