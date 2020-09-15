#include <cstdio>
#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#include <Windows.h>

using namespace std;

// ������� ���������� ���������
long long int countingSort(int a[], int n, int sortedArr[]) {
    long long int M = 0; //��������� � ������� �� ���������� ���������, �� ������� � �����������
    int k;
    for (int i = 0; i < n; i++) {
        k = 0;
        for (int j = 0; j < n; j++) {
            if (a[i] > a[j]) {
                k++;
            }
        }
        sortedArr[k] = a[i];
        M++;
    }

    cout << "M = " << M << endl;
    return M;
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
    cout << "---------------------------------------------------------------------------------------------------------"
         << endl;


    switch (num) {
        case 1: {
            for (int N = 6000; N <= 10000; N += 1000) {

                int arr[N];
                int sorted[N];
                srand(time(NULL)); //������� ��������� ��������������� �����
                for (int i = 0; i < N; i++)
                    arr[i] = rand(); //��������� ������ ���������� �������

                cout << "N = " << N << endl;
                clock_t begin = clock();
                cout << "������� ������: " << countingSort(arr, N, sorted) << endl;
                clock_t end = clock();
                double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                cout << "����������� ����� (�): " << elapsed_secs << endl;

                begin = clock();
                cout << "��������� ������: " << countingSort(arr, N, sorted) << endl;
                end = clock();
                elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                cout << "����������� ����� (�): " << elapsed_secs << endl;


                for (int i = 0; i < N / 2; i++)
                    swap(arr[i], arr[N - i - 1]); //"��������" ������� ��� ����, ����� ������� ��������� ������

                begin = clock();
                cout << "��������� ������: " << countingSort(arr, N, sorted) << endl;
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
            int sorted[N];
            cout << "������� 10 ����� ����� ����� ������: ";
            for (int i = 0; i < N; i++)
                cin >> arr[i]; //���������� ������� � ����������

            cout << "C+M = " << countingSort(arr, N, sorted) << endl;
            cout << "��������������� ������: " << endl;
            printArray(sorted, N);

            break;
        }
        default:
            cout << "����������, ������� ���������� �����";
    }

    return 0;
}

