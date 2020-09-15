#include <cstdio>
#include <iostream>
#include <ctime>
//#include <bits/stdc++.h>
//#include <Windows.h>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string &link = "./file.txt";

// �������� ����� - ������ ��������, ���������� � �������
void createFile(ofstream &file, int *array, long long size) {
    for (auto i = 0; i < size; i++)
        file << array[i]<<' ';
}

//����� ������ ����� � �����
bool searchDigit(ifstream &file, long digit, bool showtime) {
    clock_t begin = clock();
    long compare = 0, pos = -1;
    while (!file.eof()) {
        string str;
        getline(file, str);
        for (auto ch : str) {
            if (isdigit(ch)) {
                compare++;
                pos++;
                if (digit == atoi(&ch)) {
                    cout << "\n����� � �����. ����� \"" << digit << "\": ������� �����: " << pos
                         << "; ���������� ���������: "
                         << compare;
                    clock_t end = clock();
                    if (showtime) {
                        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                        cout << " ����� ������: " << elapsed_secs << " ������";
                    }
                    return true;
                }
            }
        }
    }
    cout << "\n����� � �����. ����� \"" << digit << "\" �� �������! ";
    if (showtime)
        cout << "����� ������: "
             << double(clock() - begin) / CLOCKS_PER_SEC
             << " ������" << endl;
    return false;
}

//����� ���������� ��������� � ������������ �������
void analyse(ifstream &f, const string &path, bool showtime) {
    searchDigit(f, 2, showtime);
    f.close();

    f.open(path);
    searchDigit(f, 3, showtime);
    f.close();
}

//���������� ������� - ��� ����� = 1, ����� ��������� �������
void fillArray(int *array, int size) {
    int position = rand() % (size - 4) + 4; //�������� ��������� ������� ��� ������� ��������
    for (int i = 0; i < size; i++)
        array[i] = 1;
    array[position] = 2;
}

//����� ������ ����� � �������
void searchInArray(int *array, int size, long digit, bool showtime) {
    int compare = 0;
    clock_t begin = clock();
    for (int i = 0; i < size; i++) {
        compare++;
        if (array[i] == digit) {
            cout << "\n����� � �������. ����� \"" << digit << "\": ������� �����: " << i
                 << "; ���������� ���������: "
                 << compare;
            clock_t end = clock();
            if (showtime) {
                double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
                cout << " ����� ������: " << elapsed_secs << setprecision(3)<< " ������";

            }
            return;
        }

    }
    cout << "\n����� � �������. ����� \"" << digit << "\" �� �������! ";
    if (showtime)
        cout << "����� ������: "
             << double(clock() - begin) / CLOCKS_PER_SEC
             << setprecision(3)<< " ������" << endl;

}


int main() {
    srand(time(nullptr));
    int num;
    setlocale(LC_ALL, "Russian");
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);

    cout << "����������, �������: [1] - ��� ���������� ������� �������������, "
            "[2] - ��� ���������� ������� ������� (���� � ����������): ";
    cin >> num;
    cout << endl;
    cout
            << "������������ ������ �4. �������� ��������� ������. ������ ����������, ����-08-19"
            << endl;
    cout << "----------------------------------------------------------------------------------------------------"
         << endl;


    switch (num) {
        case 1: {
            for (int N = 3000000; N <= 5000000; N += 1000000) {
                cout << "N = " << N << endl;

                ofstream fout(link);
                int arr[N];
                fillArray(arr, N); //���������� ������� ������� �������
                searchInArray(arr, N, 2, true);
                searchInArray(arr, N, 3, true);

                if (fout.is_open()) {
                    createFile(fout, arr, N); //�������� �����
                }
                fout.close();

                ifstream fin(link);
                if (fin.is_open()) {
                    analyse(fin, link, true); //����� � �����
                }
                fin.close();

                int status = remove("file.txt"); //�������� �����
//                if (status == 0) {
//                    cout << "file deleted successfully..!!\n";
//                } else
//                    cout << "Unable to delete file \n";

                cout << "--------------------------" << endl;
            }

            break;
        }
        case 2: {
            int N = 10;
            int arr[N];

            cout << "������� " << N << " ����� ����� ����� ������: ";
            for (int i = 0; i < N; i++)
                cin >> arr[i]; //���������� ������� � ����������

            searchInArray(arr, N, 2, false);
            searchInArray(arr, N, 3, false);

            ofstream fout(link);
            if (fout.is_open()) {
                createFile(fout, arr, N);
            }
            fout.close();

            ifstream fin(link);
            if (fin.is_open()) {
                analyse(fin, link, false);
            }

            break;
        }
        default:
            cout << "����������, ������� ���������� �����";
    }

    return 0;
}
