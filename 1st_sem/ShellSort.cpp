#include <cstdio>
#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#include <Windows.h>

using namespace std;

//функция сортировки Шелла
long long int shellSort(int array[], int n, bool worst) {
    long long int C = 0, M = 0;// Инициализация счётчиков
    int s;
    if (worst) s = 1;
    else s = n / 2;
    for (int step = s; step > 0; step /= 2) {
        for (int i = step; i < n; i++) {

            int j = i - step;
            while ((j >= 0) && (C++ >= 0) && (array[j] > array[j + step])) {
                swap(array[j], array[j + step]);
                M++;
                j -= step;
            }

        }
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
    cout
            << "------------------------------------------------------------------------------------------------------------"
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
                cout << "Средний случай: " << shellSort(arr, N, false) << endl;
                clock_t end = clock();
                double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                cout << "Затраченное время (с): " << elapsed_secs << endl;

                begin = clock();
                cout << "Наилучший случай: " << shellSort(arr, N, false) << endl;
                end = clock();
                elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                cout << "Затраченное время (с): " << elapsed_secs << endl;


                for (int i = 0; i < N / 2; i++)
                    swap(arr[i], arr[N - i - 1]); //"разворот" массива для того, чтобы создать наихудший случай

                begin = clock();
                cout << "Наихудший случай: " << shellSort(arr, N, true) << endl;
                end = clock();
                elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                cout << "Затраченное время (с): " << elapsed_secs << endl;
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

            cout << "C+M = " << shellSort(arr, N, false) << endl;
            cout << "Отсортированный массив: " << endl;
            printArray(arr, N);

            break;
        }
        default:
            cout << "Пожалуйста, введите корректное число";
    }

    return 0;
}

