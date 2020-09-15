#include <cstdio>
#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#include <Windows.h>

using namespace std;

long long int C = 1;

// функция для поиска минимального из 2 элементов 
int min(int x, int y) { return (x<=y)? x : y; } 
  
int fibMonaccianSearch(int arr[], int x, int n) 
{ 
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;
    while (fibM < n) 
    { 
        fibMMm2 = fibMMm1; 
        fibMMm1 = fibM; 
        fibM  = fibMMm2 + fibMMm1; 
    } 
    int offset = -1; 
    while (fibM > 1) 
    { 
        // Проверить, fibMm2 находится на действующей позиции 
        int i = min(offset+fibMMm2, n-1); 
  
        /* Если x больше значения с индексом fibMm2, 
           обрезать подмассив от смещения до  i */
        if (arr[i] < x) 
        { 
            fibM  = fibMMm1; 
            fibMMm1 = fibMMm2; 
            fibMMm2 = fibM - fibMMm1; 
            offset = i; 
            C++;
        } 
  
        /* если x больше чем значение с индексом fibMm2, 
           обрезать подмассив после i+1  */
        else if (arr[i] > x) 
        { 
            fibM  = fibMMm2; 
            fibMMm1 = fibMMm1 - fibMMm2; 
            fibMMm2 = fibM - fibMMm1; 
	        //C++;
        } 
  
        //элемент найден возврат i
        else return i; 
    } 
  
    //сравнение последнего элемента и х
    if(fibMMm1 && arr[offset+1]==x)
	return offset+1;

  
    //если элемент не найден
    return -1; 
} 

//переопределение функции swap для работы с указателями
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//функция сортировки методом простого обмена
long long int exchangeSort(int *arr, int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        // Выполнение условия Айверсона: если за итерацию два числа не поменялись местами, прерываем цикл
        if (swapped == false)
            return *arr;
    }
    return *arr;
}

int main() {
    int num, x;
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Практическая работа №5. Алгоритмы поиска в массивах. Азаров Константин, ИКБО-08-19"
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
                        srand(time(NULL)); //создаем генератор псевдослучайных чисел
                        for (int i = 0; i < N; i++)
                            arr[i] = rand()%N+1; //заполняем массив случайными числами
                        exchangeSort(arr,N);
						long int x = arr[rand()%N];
                        cout << "N = " << N << endl;
                        clock_t begin = clock();
                        cout << "Средний случай:число "<<x<<" на позиции: " << fibMonaccianSearch(arr, x,N) << endl;
                        clock_t end = clock();
                        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                        cout << "Затраченное время (с): " << elapsed_secs << endl;
                        cout << "Вычислительная сложность: " << C << endl;
                        cout<< endl;
                        C = 0;
						x = N+1;
                        begin = clock();
                        cout << "Наихудший случай:число "<<x<<" на позиции: "<<fibMonaccianSearch(arr, x,N)<< endl; 
                        end = clock();
                        elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                        cout << "Затраченное время (с): " << elapsed_secs << endl;
                        cout << "Вычислительная сложность: " <<C*2/3 << endl;
                        cout<< endl;
                        C = 1;
            }
            break;
        }
        case 2: {
            int N = 10;
            int arr[N];
            cout << "Введите 10 чисел: ";
            for (int i = 0; i < N; i++)
                cin >> arr[i]; //заполнение массива с клавиатуры
            exchangeSort(arr, N);
            int x = 5;
            cout << "Отсортированный массив: " << endl;
            for (int i = 0; i < N; i++)
                printf("%d ", arr[i]);
			cout <<endl << "число "<<x<<" на позиции: "<<fibMonaccianSearch(arr, x,N)<< endl;
            break;
        }
        default:
            cout << "Пожалуйста, введите корректное число";
    }

    return 0;
}

