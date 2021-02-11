#include <cstdio>
#include <iostream>
#include <ctime>
//#include <bits/stdc++.h>
#include <Windows.h>

using namespace std;

//��������������� ������� swap ��� ������ � �����������
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//������� ���������� ������� �������� ������
long long int exchangeSort(int *arr, int n) {
    long long int M = 0, C = 0; //�������� ����������� � ���������
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
        // ���������� ������� ���������: ���� �� �������� ��� ����� �� ���������� �������, ��������� ����
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

//            for (int i = 0; i < N; i++)
//                printf("%d ", arr[i]);
//            cout<<endl;

                cout << "N = " << N << endl;
                cout << "������� ������: " << exchangeSort(arr, N) << endl;
                
//            for (int i = 0; i < N; i++)
//                printf("%d ", arr[i]);
//            cout<<endl;

                cout << "��������� ������: " << exchangeSort(arr, N) << endl;


                for (int i = 0; i < N / 2; i++)
                    swap(arr[i], arr[N - i - 1]); //"��������" ������� ��� ����, ����� ������� ��������� ������

//            for (int i = 0; i < N; i++)
//                printf("%d ", arr[i]);
//            cout<<endl;

                cout << "��������� ������: " << exchangeSort(arr, N) << endl;
                cout <<"--------------------------"<< endl;

//            for (int i = 0; i < N; i++)
//                printf("%d ", arr[i]);
            }
            break;
        }
        case 2: {
            int N = 10;
            int arr[N];
            cout << "������� 10 �����: ";
            for (int i = 0; i < N; i++)
                cin >> arr[i]; //���������� ������� � ����������

            cout << exchangeSort(arr, N) << endl;
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

