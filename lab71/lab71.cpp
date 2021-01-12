// lab71.cpp
// Шевченко Тарас
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 12
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** P, const int rowCount, const int colCount, int High, int Low) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            P[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** P, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << P[i][j];
        }
        cout << endl;
    }
}

void Change(int** P, const int col1, const int col2, const int rowCount) {
    int tmp;
    for (int i = 0; i < rowCount; i++) {
        tmp = P[i][col1];
        P[i][col1] = P[i][col2];
        P[i][col2] = tmp;
    }
}

void Sort(int** P, const int rowCount, const int colCount)
{
    for (int j0 = 0; j0 < colCount - 1; j0++)
        for (int j1 = 0; j1 < colCount - j0 - 1; j1++)
            if ((P[0][j1] < P[0][j1 + 1])
                ||
                (P[0][j1] == P[0][j1 + 1] &&
                    P[1][j1] < P[1][j1 + 1])
                ||
                (P[0][j1] == P[0][j1 + 1] &&
                    P[1][j1] == P[1][j1 + 1] &&
                    P[2][j1] > P[2][j1 + 1]))
                Change(P, j1, j1 + 1, rowCount);
}

void Sum(int** P, const int rowCount, const int colCount, int& S, int& n) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++) {
            if (P[i][j] % 3 == 0 && P[i][j] > 0) {
                S += P[i][j];
                n++;
                P[i][j] = 0;
            }
        }
}


int main()
{
    int Low = -21;
    int High = 24;

    int rowCount = 9;
    int colCount = 6;

    int** P = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        P[i] = new int[colCount];

    Create(P, rowCount, colCount, High, Low);
    Print(P, rowCount, colCount);
    Sort(P, rowCount, colCount);
    Print(P, rowCount, colCount);

    int S = 0;
    int n = 0;

    Sum(P, rowCount, colCount, S, n);
    cout << "S = " << S << endl;
    cout << "n = " << n << endl;
    Print(P, rowCount, colCount);


    system("pause");
    cin.get();
    return 0;
}