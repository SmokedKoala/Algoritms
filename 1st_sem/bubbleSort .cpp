#include <cstdio>
#include <iostream>
#include <ctime>
//#include <bits/stdc++.h>
#include <Windows.h>

using namespace std;

//переопределение функции swap для работы с указателями
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//функция сортировки методом простого обмена
long long int exchangeSort(int *arr, int n) {
    long long int M = 0, C = 0; //счетчики перемещений и сравнений
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            C++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                M++;
                swapped = true;
            }
        }
        // Выполнение условия Айверсона: если за итерацию два числа не поменялись местами, прерываем цикл
        if (swapped == false)
            return M + C;
    }
    return M + C;
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

//            for (int i = 0; i < N; i++)
//                printf("%d ", arr[i]);
//            cout<<endl;

                cout << "N = " << N << endl;
                cout << "Средний случай: " << exchangeSort(arr, N) << endl;
                
//            for (int i = 0; i < N; i++)
//                printf("%d ", arr[i]);
//            cout<<endl;

                cout << "Наилучший случай: " << exchangeSort(arr, N) << endl;


                for (int i = 0; i < N / 2; i++)
                    swap(arr[i], arr[N - i - 1]); //"разворот" массива для того, чтобы создать наихудший случай

//            for (int i = 0; i < N; i++)
//                printf("%d ", arr[i]);
//            cout<<endl;

                cout << "Наихудший случай: " << exchangeSort(arr, N) << endl;
                cout <<"--------------------------"<< endl;

//            for (int i = 0; i < N; i++)
//                printf("%d ", arr[i]);
            }
            break;
        }
        case 2: {
            int N = 10;
            int arr[N];
            cout << "Введите 10 чисел: ";
            for (int i = 0; i < N; i++)
                cin >> arr[i]; //заполнение массива с клавиатуры

            cout << exchangeSort(arr, N) << endl;
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

