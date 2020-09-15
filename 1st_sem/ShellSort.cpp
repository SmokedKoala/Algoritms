#include <cstdio>
#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#include <Windows.h>

using namespace std;

//������� ���������� �����
long long int shellSort(int array[], int n, bool worst) {
    long long int C = 0, M = 0;// ������������� ���������
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

//������� ������
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

    cout << "����������, �������: [1] - ��� ���������� ������� ���������� �������, "
            "[2] - ��� ���������� ������� ������� (���� � ����������): ";
    cin >> num;
    cout << endl;
    cout
            << "������������ ������ �2. ������������� ��������� ���������� ���������� ��������. ������ ����������, ����-08-19"
            << endl;
    cout
            << "------------------------------------------------------------------------------------------------------------"
            << endl;


    switch (num) {
        case 1: {
            for (int N = 6000; N <= 10000; N += 1000) {

                int arr[N];
                srand(time(NULL)); //������� ��������� ��������������� �����
                for (int i = 0; i < N; i++)
                    arr[i] = rand(); //��������� ������ ���������� �������

                cout << "N = " << N << endl;
                clock_t begin = clock();
                cout << "������� ������: " << shellSort(arr, N, false) << endl;
                clock_t end = clock();
                double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                cout << "����������� ����� (�): " << elapsed_secs << endl;

                begin = clock();
                cout << "��������� ������: " << shellSort(arr, N, false) << endl;
                end = clock();
                elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                cout << "����������� ����� (�): " << elapsed_secs << endl;


                for (int i = 0; i < N / 2; i++)
                    swap(arr[i], arr[N - i - 1]); //"��������" ������� ��� ����, ����� ������� ��������� ������

                begin = clock();
                cout << "��������� ������: " << shellSort(arr, N, true) << endl;
                end = clock();
                elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                cout << "����������� ����� (�): " << elapsed_secs << endl;
                cout << "--------------------------" << endl;
            }

            break;
        }
        case 2: {
            int N = 10;
            int arr[N];
            cout << "������� 10 ����� ����� ����� ������: ";
            for (int i = 0; i < N; i++)
                cin >> arr[i]; //���������� ������� � ����������

            cout << "C+M = " << shellSort(arr, N, false) << endl;
            cout << "��������������� ������: " << endl;
            printArray(arr, N);

            break;
        }
        default:
            cout << "����������, ������� ���������� �����";
    }

    return 0;
}

