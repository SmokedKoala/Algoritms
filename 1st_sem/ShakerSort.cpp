#include <cstdio>
#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#include <Windows.h>

using namespace std;

// функция шейкерной (челночной) сортировки
long long int shakerSort(int a[], int n) {
    long long int M = 0, C = 0;
    bool swapped = true;
    int start = 0; //координата начала неотсортированного массива
    int end = n - 1; //координата конца неотсортированного массива

    while (swapped) {
        swapped = false;

        // проход по массиву слева направо, как в алгоритме сортировки методом простого обмена
        for (int i = start; i < end; ++i) {
            C++;
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                M++;
                swapped = true;
            }
        }

        // условие Айверсона:
        // если перемещений нет, то массив отсортирован - выход из функции
        if (!swapped)
            break;

        swapped = false;

        // смещение координаты конца неотсортированного массива
        --end;

        //аналогичный проход по массиву, но справа налево
        for (int i = end - 1; i >= start; --i) {
            C++;
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                M++;
                swapped = true;
            }
        }

        // смещение координаты начала неотсортированного массива
        ++start;
    }
    return C + M;
}

//выводит массив
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int num;
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Пожалуйста, введите: [1] - для заполнения массива случайными числами, "
            "[2] - для заполнения массива вручную (ввод с клавиатуры): ";
    cin >> num;
    cout << endl;
    cout
            << "Практическая работа №2. Нетривиальные алгоритмы внутренней сортировки массивов. Азаров Константин, ИКБО-08-19"
            << endl;
    cout << "---------------------------------------------------------------------------------------------------------"
         << endl;


    switch (num) {
        case 1: {
            for (int N = 6000; N <= 10000; N += 1000) {

                int arr[N];
                srand(time(NULL)); //создаем генератор псевдослучайных чисел
                for (int i = 0; i < N; i++)
                    arr[i] = rand(); //заполняем массив случайными числами

                cout << "N = " << N << endl;
                clock_t begin = clock();
                cout << "Средний случай: " << shakerSort(arr, N) << endl;
                clock_t end = clock();
                double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                cout << "Затраченное время (с): " << elapsed_secs <<endl;

                begin = clock();
                cout << "Наилучший случай: " << shakerSort(arr, N) << endl;
                end = clock();
                elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                cout << "Затраченное время (с): " << elapsed_secs <<endl;


                for (int i = 0; i < N / 2; i++)
                    swap(arr[i], arr[N - i - 1]); //"разворот" массива для того, чтобы создать наихудший случай

                begin = clock();
                cout << "Наихудший случай: " << shakerSort(arr, N) << endl;
                end = clock();
                elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                cout << "Затраченное время (с): " << elapsed_secs <<endl;
                cout << "--------------------------" << endl;

            }

            break;
        }
        case 2: {
            int N = 10;
            int arr[N];
            cout << "Введите 10 целых чисел через пробел: ";
            for (int i = 0; i < N; i++)
                cin >> arr[i]; //заполнение массива с клавиатуры

            cout << "C+M = " << shakerSort(arr, N) << endl;
            cout << "Отсортированный массив: " << endl;
            printArray(arr, N);

            break;
        }
        default:
            cout << "Пожалуйста, введите корректное число";
    }

    return 0;
}

