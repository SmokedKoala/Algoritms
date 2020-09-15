#include <cstdio>
#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#include <Windows.h>

using namespace std;

long long int C = 1;

// ������� ��� ������ ������������ �� 2 ��������� 
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
        // ���������, fibMm2 ��������� �� ����������� ������� 
        int i = min(offset+fibMMm2, n-1); 
  
        /* ���� x ������ �������� � �������� fibMm2, 
           �������� ��������� �� �������� ��  i */
        if (arr[i] < x) 
        { 
            fibM  = fibMMm1; 
            fibMMm1 = fibMMm2; 
            fibMMm2 = fibM - fibMMm1; 
            offset = i; 
            C++;
        } 
  
        /* ���� x ������ ��� �������� � �������� fibMm2, 
           �������� ��������� ����� i+1  */
        else if (arr[i] > x) 
        { 
            fibM  = fibMMm2; 
            fibMMm1 = fibMMm1 - fibMMm2; 
            fibMMm2 = fibM - fibMMm1; 
	        //C++;
        } 
  
        //������� ������ ������� i
        else return i; 
    } 
  
    //��������� ���������� �������� � �
    if(fibMMm1 && arr[offset+1]==x)
	return offset+1;

  
    //���� ������� �� ������
    return -1; 
} 

//��������������� ������� swap ��� ������ � �����������
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//������� ���������� ������� �������� ������
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
        // ���������� ������� ���������: ���� �� �������� ��� ����� �� ���������� �������, ��������� ����
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
    cout << "������������ ������ �5. ��������� ������ � ��������. ������ ����������, ����-08-19"
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
                        srand(time(NULL)); //������� ��������� ��������������� �����
                        for (int i = 0; i < N; i++)
                            arr[i] = rand()%N+1; //��������� ������ ���������� �������
                        exchangeSort(arr,N);
						long int x = arr[rand()%N];
                        cout << "N = " << N << endl;
                        clock_t begin = clock();
                        cout << "������� ������:����� "<<x<<" �� �������: " << fibMonaccianSearch(arr, x,N) << endl;
                        clock_t end = clock();
                        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                        cout << "����������� ����� (�): " << elapsed_secs << endl;
                        cout << "�������������� ���������: " << C << endl;
                        cout<< endl;
                        C = 0;
						x = N+1;
                        begin = clock();
                        cout << "��������� ������:����� "<<x<<" �� �������: "<<fibMonaccianSearch(arr, x,N)<< endl; 
                        end = clock();
                        elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                        cout << "����������� ����� (�): " << elapsed_secs << endl;
                        cout << "�������������� ���������: " <<C*2/3 << endl;
                        cout<< endl;
                        C = 1;
            }
            break;
        }
        case 2: {
            int N = 10;
            int arr[N];
            cout << "������� 10 �����: ";
            for (int i = 0; i < N; i++)
                cin >> arr[i]; //���������� ������� � ����������
            exchangeSort(arr, N);
            int x = 5;
            cout << "��������������� ������: " << endl;
            for (int i = 0; i < N; i++)
                printf("%d ", arr[i]);
			cout <<endl << "����� "<<x<<" �� �������: "<<fibMonaccianSearch(arr, x,N)<< endl;
            break;
        }
        default:
            cout << "����������, ������� ���������� �����";
    }

    return 0;
}

