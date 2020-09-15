#include <cstdio>
#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#include <Windows.h>

using namespace std;

//функция сортировки методом простого выбора
long long int selectionSort(int arr[], int n) {
    int i, j, min_idx;
    long int C = 0, M = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			C++;
			if (arr[j] < arr[min])
			{
				min = j;
				M++;
			}
		}
		if(min!=i){
		swap(arr[i], arr[min]);
		M++;	
		}
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
                srand(time(NULL)); //создаем генератор случайных чисел
                for (int i = 0; i < N; i++)
                    arr[i] = rand(); //заполняем массив случайными числами


                cout << "N = " << N << endl;
                cout << "Средний случай: " << selectionSort(arr, N) << endl;


                cout << "Наилучший случай: " << selectionSort(arr, N) << endl;


                for (int i = 0; i < N / 2; i++)
                    swap(arr[i], arr[N - i - 1]); //"разворот" массива для наихудшего случая


                cout << "Наихудший случай: " << selectionSort(arr, N) << endl;
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

            cout << "C+M = " << selectionSort(arr, N) << endl;
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
