// Laboratory_work_s2_number_6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

void DrawTask1() {
    HWND hwnd = GetConsoleWindow(); 
    HDC dc = GetDC(hwnd); 
    RECT window = {}; 
    HBRUSH brush; 

    brush = CreateSolidBrush(RGB(100, 255, 100));
    SelectObject(dc, brush); 
    Rectangle(dc, 900, 250, 500, 450);
    DeleteObject(brush);

    brush = CreateSolidBrush(RGB(255, 0, 100));
    SelectObject(dc, brush);
    Ellipse(dc, 800, 250, 600, 450);
    DeleteObject(brush);

    LPCTSTR a = L"Мотренко П.В.";
    TextOut(dc, 650, 345, a, 13);

    ReleaseDC(hwnd, dc); 
    std::cin.get();
}

void DrawTask2() {
    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);
    int x = 0;
    for (float i = 0; i < 3.14 * 15; i += float(0.05))
    {
        SetPixel(hdc, x, 250 + 25 * cos(i/2), RGB(13, 255, 0));
        x += 1;
    }
    ReleaseDC(hwnd, hdc);
    std::cin.ignore();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool alive = true;
    int num;
    
    while (alive) {
        cout << "Задание 1 , нажмите 1" << endl;
        cout << "Задание 2 , нажмите 2" << endl;
        cout << "Очистить консоль, нажмите 3" << endl;
        cout << "Выйти из программы, нажмите 4" << endl;
        cin >> num;

        switch (num) {
            case 1: 
                DrawTask1();
                break;
            case 2:
                DrawTask2();         
                break;
            case 3:
                system("cls");
                break;
            case 4:
                alive = false;
                break;
            default:
                cout << "Что-то пошло не так, пожалуйста попробуйте снова" << endl;
                break;
        
        }

    }

    return 0;
}
