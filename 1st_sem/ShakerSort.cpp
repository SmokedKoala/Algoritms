#include <cstdio>
#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#include <Windows.h>

using namespace std;

// ������� ��������� (���������) ����������
long long int shakerSort(int a[], int n) {
    long long int M = 0, C = 0;
    bool swapped = true;
    int start = 0; //���������� ������ ������������������ �������
    int end = n - 1; //���������� ����� ������������������ �������

    while (swapped) {
        swapped = false;

        // ������ �� ������� ����� �������, ��� � ��������� ���������� ������� �������� ������
        for (int i = start; i < end; ++i) {
            C++;
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                M++;
                swapped = true;
            }
        }

        // ������� ���������:
        // ���� ����������� ���, �� ������ ������������ - ����� �� �������
        if (!swapped)
            break;

        swapped = false;

        // �������� ���������� ����� ������������������ �������
        --end;

        //����������� ������ �� �������, �� ������ ������
        for (int i = end - 1; i >= start; --i) {
            C++;
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                M++;
                swapped = true;
            }
        }

        // �������� ���������� ������ ������������������ �������
        ++start;
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
    cout << "---------------------------------------------------------------------------------------------------------"
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
                cout << "������� ������: " << shakerSort(arr, N) << endl;
                clock_t end = clock();
                double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                cout << "����������� ����� (�): " << elapsed_secs <<endl;

                begin = clock();
                cout << "��������� ������: " << shakerSort(arr, N) << endl;
                end = clock();
                elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                cout << "����������� ����� (�): " << elapsed_secs <<endl;


                for (int i = 0; i < N / 2; i++)
                    swap(arr[i], arr[N - i - 1]); //"��������" ������� ��� ����, ����� ������� ��������� ������

                begin = clock();
                cout << "��������� ������: " << shakerSort(arr, N) << endl;
                end = clock();
                elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                cout << "����������� ����� (�): " << elapsed_secs <<endl;
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

            cout << "C+M = " << shakerSort(arr, N) << endl;
            cout << "��������������� ������: " << endl;
            printArray(arr, N);

            break;
        }
        default:
            cout << "����������, ������� ���������� �����";
    }

    return 0;
}

