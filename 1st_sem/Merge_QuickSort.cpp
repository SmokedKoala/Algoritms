#include <cstdio>
#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#include <Windows.h>

using namespace std;

long long int C = 0;
long long int recursion_depth = 0;



// Объединяет два подмассива массива arr[].
// Первый подмассив arr[l..m]
// Второй подмассив arr[m+1..r]
long long int merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        C++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    return C;
}

// функция сортировки двухпутевого двухфазного слияния
long long int mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        recursion_depth++;
        mergeSort(arr, m + 1, r);
        recursion_depth++;

        return merge(arr, l, m, r);
    }
}

long long int res = 0;

int partition(int arr[], int low, int high, bool worst_case) {
    int pivot;
    if (worst_case)
        pivot = arr[low]; // опорный элемент
    else
        pivot = arr[(low + high) / 2]; // опорный элемент
    int i = (low - 1); // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            res++;
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high, bool worst_case) {
    if (low < high) {
        //pi - индекс разбиения
        int pi = partition(arr, low, high, worst_case);

        // Отдельная сортировка элементов
        // Перед и после разбиения
        quickSort(arr, low, pi - 1, worst_case);
        recursion_depth++;
        quickSort(arr, pi + 1, high, worst_case);
        recursion_depth++;
    }
}


//выводит массив
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int num, sortNum;
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    cout << "Пожалуйста, выберите сортировку: [1] - двухпутевого однофазногохфазного слияния, "
            "[2] - сортировка Хоара: ";
    cin >> sortNum;
    cout << endl;

    cout << "Пожалуйста, введите: [1] - для заполнения массива случайными числами, "
            "[2] - для заполнения массива вручную (ввод с клавиатуры): ";
    cin >> num;
    cout << endl;

    cout
            << "Практическая работа №3. Рекурсивные алгоритмы. Азаров Константин, ИКБО-08-19"
            << endl;
    cout << "---------------------------------------------------------------------------------------------------------"
         << endl;

    switch (sortNum) {
        case 1: {
            switch (num) {
                case 1: {
                    for (int N = 10000; N <= 50000; N += 10000) {

                        int arr[N];
                        srand(time(NULL)); //создаем генератор псевдослучайных чисел
                        for (int i = 0; i < N; i++)
                            arr[i] = rand(); //заполняем массив случайными числами

                        cout << "N = " << N << endl;
                        clock_t begin = clock();
                        cout << "Средний случай: " << mergeSort(arr, 0, N - 1) << endl;
                        clock_t end = clock();
                        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                        cout << "Затраченное время (с): " << elapsed_secs << endl;
                        cout << "Глубина рекурсии: " << recursion_depth << endl;
                        cout<< endl;

                        C = 0;
                        recursion_depth = 0;

                        begin = clock();
                        cout << "Наилучший случай: " << mergeSort(arr, 0, N - 1) << endl;
                        end = clock();
                        elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                        cout << "Затраченное время (с): " << elapsed_secs << endl;
                        cout << "Глубина рекурсии: " << recursion_depth << endl;
                        cout<< endl;


                        for (int i = 0; i < N / 2; i++)
                            swap(arr[i], arr[N - i - 1]); //"разворот" массива для того, чтобы создать наихудший случай


                        C = 0;
                        recursion_depth = 0;

                        begin = clock();
                        cout << "Наихудший случай: " << mergeSort(arr, 0, N - 1) << endl;
                        end = clock();
                        elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                        cout << "Затраченное время (с): " << elapsed_secs << endl;

                        cout << "Глубина рекурсии: " << recursion_depth << endl;
                        cout << "----------------------------" << endl;

                        C = 0;
                        recursion_depth = 0;
                    }

                    break;
                }
                case 2: {
                    int N = 8;
                    int arr[N];
                    cout << "Введите " << N << " целых чисел через пробел: ";
                    for (int i = 0; i < N; i++)
                        cin >> arr[i]; //заполнение массива с клавиатуры

                    long long int useless = mergeSort(arr, 0, N - 1);
                    cout << "Отсортированный массив: " << endl;
                    printArray(arr, N);

                    break;
                }
                default:
                    cout << "Пожалуйста, введите корректное число";
            }
            break;
        }

        case 2: {
            switch (num) {

                case 1: {
                    for (int N = 10000; N <= 50000; N += 10000) {
                        int *arr = new int[N];

                        srand(time(NULL)); //создаем генератор псевдослучайных чисел
                        for (int i = 0; i < N; i++)
                            arr[i] = rand(); //заполняем массив случайными числами

                        cout << "N = " << N << endl;
                        cout<< endl;
                        clock_t begin = clock();
                        quickSort(arr, 0, N - 1, false);
                        clock_t end = clock();
                        cout << "Средний случай: " << res << endl;
                        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                        cout << "Затраченное время (с): " << elapsed_secs << endl;
                        cout << "Глубина рекурсии: " << recursion_depth << endl;
                        cout<< endl;

                        res = 0;
                        recursion_depth = 0;

                        begin = clock();
                        quickSort(arr, 0, N - 1, false);
                        end = clock();
                        cout << "Наилучший случай: " << res << endl;
                        elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                        cout << "Затраченное время (с): " << elapsed_secs << endl;
                        cout << "Глубина рекурсии: " << recursion_depth << endl;
                        cout<< endl;


                        for (int i = 0; i < N / 2; i++)
                            swap(arr[i], arr[N - i - 1]); //"разворот" массива для того, чтобы создать наихудший случай

                        res = 0;
                        recursion_depth = 0;

                        begin = clock();
                        quickSort(arr, 0, N - 1, true);
                        end = clock();
                        cout << "Наихудший случай: " << res << endl;
                        elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                        cout << "Затраченное время (с): " << elapsed_secs << endl;
                        cout << "Глубина рекурсии: " << recursion_depth << endl;
                        cout << "----------------------------" << endl;

                        recursion_depth = 0;
                        res = 0;
                        delete[] arr;
                    }

                    break;
                }

                case 2: {
                    int N = 8;
                    int arr[N];
                    cout << "Введите " << N << " целых чисел через пробел: ";
                    for (int i = 0; i < N; i++)
                        cin >> arr[i]; //заполнение массива с клавиатуры

                    quickSort(arr, 0, N - 1, false);
                    cout << "Отсортированный массив: " << endl;
                    printArray(arr, N);

                    break;
                }
                default:
                    cout << "Пожалуйста, введите корректное число";
            }
            break;
        }

        default:
            cout << "Пожалуйста, введите корректное число";

    }
    return 0;
}
