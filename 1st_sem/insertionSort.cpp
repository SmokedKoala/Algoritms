#include <iostream>
#include <cstdio>
#include <ctime>
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

//������� ���������� ������� ������� �������
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
    cout << "������������ ������ �1. ��������� ������� ���������� ���������� ��������. ������ ����������, ����-08-19"
         << endl;
    cout << "---------------------------------------------------------------------------------------------------------"
         << endl;
    cout << "����������, �������: [1] - ��� ���������� ������� ���������� �������, "
            "[2] - ��� ���������� ������� ������� (���� � ����������): ";
    cin >> num;
    cout << endl;

    switch (num) {
        case 1: {
            for (int N = 6000; N <= 10000; N += 1000) {
                int arr[N];
                srand(time(NULL)); //������� ��������� ��������� (�� ������������� � ������ ��������) �����
                for (int i = 0; i < N; i++)
                    arr[i] = rand(); //��������� ������ ���������� �������


                cout << "N = " << N << endl;
                cout << "������� ������: " << insertionSort(arr, N) << endl;


                cout << "��������� ������: " << insertionSort(arr, N) << endl;


                for (int i = 0; i < N / 2; i++)
                    swap(arr[i], arr[N - i - 1]); //"��������" ������� ��� ����, ����� ������� ��������� ������


                cout << "��������� ������: " << insertionSort(arr, N) << endl;
                cout << "--------------------------" << endl;

            }
            break;
        }
        case 2: {
            int N = 10;
            int arr[N];
            cout << "������� 10 �����: ";
            for (int i = 0; i < N; i++)
                cin >> arr[i]; //���������� ������� � ����������

            cout << "C+M = " <<  insertionSort(arr, N) << endl;
            cout << "��������������� ������: " << endl;
            for (int i = 0; i < N; i++)
                printf("%d ", arr[i]);

            break;
        }
        default:
            cout << "����������, ������� ���������� �����";
    }

    return 0;
}
