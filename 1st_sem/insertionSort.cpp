#include <iostream>
#include <cstdio>
#include <ctime>
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

//функция сортировки методом простых вставок
long long int insertionSort(int *a, int n) {
    long long int M = 0, C = 0;
    for (int j = 1; j < n; j++) {
        int key = a[j];
        int i = j - 1;
        C++;
        while (i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i--;
            C++;
            M++;
        }
        a[i + 1] = key;
    }
        return C + M;
}

int main() {
    int num;
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Практическая работа №1. Сравнение простых алгоритмов сортировки массивов. Азаров Константин, ИКБО-08-19"
         << endl;
    cout << "---------------------------------------------------------------------------------------------------------"
         << endl;
    cout << "Пожалуйста, введите: [1] - для заполнения массива случайными числами, "
            "[2] - для заполнения массива вручную (ввод с клавиатуры): ";
    cin >> num;
    cout << endl;

    switch (num) {
        case 1: {
            for (int N = 6000; N <= 10000; N += 1000) {
                int arr[N];
                srand(time(NULL)); //создаем генератор случайных (не повторяющихся с каждым запуском) чисел
                for (int i = 0; i < N; i++)
                    arr[i] = rand(); //заполняем массив случайными числами


                cout << "N = " << N << endl;
                cout << "Средний случай: " << insertionSort(arr, N) << endl;


                cout << "Наилучший случай: " << insertionSort(arr, N) << endl;


                for (int i = 0; i < N / 2; i++)
                    swap(arr[i], arr[N - i - 1]); //"разворот" массива для того, чтобы создать наихудший случай


                cout << "Наихудший случай: " << insertionSort(arr, N) << endl;
                cout << "--------------------------" << endl;

            }
            break;
        }
        case 2: {
            int N = 10;
            int arr[N];
            cout << "Введите 10 чисел: ";
            for (int i = 0; i < N; i++)
                cin >> arr[i]; //заполнение массива с клавиатуры

            cout << "C+M = " <<  insertionSort(arr, N) << endl;
            cout << "Отсортированный массив: " << endl;
            for (int i = 0; i < N; i++)
                printf("%d ", arr[i]);

            break;
        }
        default:
            cout << "Пожалуйста, введите корректное число";
    }

    return 0;
}
