// lab71.cpp
// Шевченко Тарас
// Лабораторна робота № 7.1
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 11
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** Q, const int rowCount, const int colCount, int High, int Low) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            Q[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** Q, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << Q[i][j];
        }
        cout << endl;
    }
}

void Change(int** Q, const int col1, const int col2, const int rowCount) {
    int tmp;
    for (int i = 0; i < rowCount; i++) {
        tmp = Q[i][col1];
        Q[i][col1] = Q[i][col2];
        Q[i][col2] = tmp;
    }
}

void Sort(int** Q, const int rowCount, const int colCount)
{
    for (int j0 = 0; j0 < colCount - 1; j0++)
        for (int j1 = 0; j1 < colCount - j0 - 1; j1++)
            if ((Q[0][j1] < Q[0][j1 + 1])
                ||
                (Q[0][j1] == Q[0][j1 + 1] &&
                    Q[1][j1] > Q[1][j1 + 1])
                ||
                (Q[0][j1] == Q[0][j1 + 1] &&
                    Q[1][j1] == Q[1][j1 + 1] &&
                    Q[2][j1] > Q[2][j1 + 1]))
                Change(Q, j1, j1 + 1, rowCount);
}

void Sum(int** Q, const int rowCount, const int colCount, int& S, int& n) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++) {
            if ( Q[i][j] % 2== 0 && Q[i][j] % 8 != 0) {
                S += Q[i][j];
                n++;
                Q[i][j] = 0;
            }
        }
}


int main()
{
    int Low = 7;
    int High = 62;

    int rowCount = 7;
    int colCount = 6;

    int** Q = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        Q[i] = new int[colCount];

    Create(Q, rowCount, colCount, High, Low);
    Print(Q, rowCount, colCount);
    Sort(Q, rowCount, colCount);
    Print(Q, rowCount, colCount);

    int S = 0;
    int n = 0;

    Sum(Q, rowCount, colCount, S, n);
    cout << "S = " << S << endl;
    cout << "n = " << n << endl;
    Print(Q, rowCount, colCount);


    system("pause");
    cin.get();
    return 0;
}