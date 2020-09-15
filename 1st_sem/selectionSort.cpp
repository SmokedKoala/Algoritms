#include <cstdio>
#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#include <Windows.h>

using namespace std;

//������� ���������� ������� �������� ������
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
                srand(time(NULL)); //������� ��������� ��������� �����
                for (int i = 0; i < N; i++)
                    arr[i] = rand(); //��������� ������ ���������� �������


                cout << "N = " << N << endl;
                cout << "������� ������: " << selectionSort(arr, N) << endl;


                cout << "��������� ������: " << selectionSort(arr, N) << endl;


                for (int i = 0; i < N / 2; i++)
                    swap(arr[i], arr[N - i - 1]); //"��������" ������� ��� ���������� ������


                cout << "��������� ������: " << selectionSort(arr, N) << endl;
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

            cout << "C+M = " << selectionSort(arr, N) << endl;
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
