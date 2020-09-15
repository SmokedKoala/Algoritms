#include <cstdio>
#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#include <Windows.h>
#include <string>
#include <chrono>

using namespace std;

long long int C = 0, Moving = 0;
const string &link = "./file.txt";

//������� �������� ���������������� �������
void computeLPSArray(char *pat, int M, int *lps);

int KMP( char* str,  char* obr, int str_len, int obr_len) {
	int i, j;
	int* pi = new int[obr_len];
	pi[0] = 0;
	for (i = 1, j = 0; i < obr_len; i++) {
		while (j > 0 && obr[j] != obr[i])
		j = pi[j - 1];
		if (obr[j] == obr[i])
		j++;
		pi[i] = j;
	}
	for (i = 0; i < str_len; ++i) {
		C++;
		while ((j > 0) && (str[i] != obr[j])) {
			j = pi[j - 1];
		}
		if (str[i] == obr[j]){
		++j;
		C++;
		Moving++;
	}
	if (j == obr_len) {
		return i - j + 1;
	}
	}
	return -1;
}
			

// ������� ������ �����-�������-������
void KMPSearch(char *pat, char *txt) {
    int M = strlen(pat);
    int N = strlen(txt);
    bool found = false;

    // ������������� lps[], ������� ����� ������� ���������� ���������
    int lps[M];

    // �������� ������� lps[]
    computeLPSArray(pat, M, lps);

    int i = 0; // ������ ��� txt[]
    int j = 0; // ������ ��� pat[]
    while (i < N) {
        
        if (pat[j] == txt[i]) {
            j++;
            i++;
            C++;
            Moving++;
            
        }

        if (j == M) {
            printf("%d ", i - j);
            j = lps[j - 1];
            C++;
            Moving++;
            found = true;
        }

            // ������������� ����� ���������� j
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0){
			
                j = lps[j - 1];
                C++;
            }
            else
                i = i + 1;
        }
    }
    if (!found)
        cout << "�� �������";
}

// ������� �������� ���������������� �������
void computeLPSArray(char *pat, int M, int *lps) {
    // ����� ����������� ������ �������� ��������
    int len = 0;

    lps[0] = 0; // lps[0] ������ ����� 0


    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
            C++;
        } else // (pat[i] != pat[len])
        {
            if (len != 0) {
                len = lps[len - 1];
            } else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

//��������� � ������� ��� �������� �������
double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter() {
    LARGE_INTEGER li;
    if (!QueryPerformanceFrequency(&li))
        cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart);

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double GetCounter() {
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart - CounterStart) / PCFreq;
}

int main() {
    srand(time(nullptr));
    int num;
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "����������, �������: [1] - ��� ���������� ������� �������������, "
            "[2] - ��� ���������� ������� ������� (���� � ����������): ";
    cin >> num;
    cout << endl;
    cout
            << "������������ ������ �6. ��������� ������ ������ � ������. ������ ����������, ����-08-19"
            << endl;
    cout << "-----------------------------------------------------------------------------------------------"
         << endl;


    switch (num) {
        case 1: {
            for (int N = 100000; N <= 500000; N += 100000) {

                cout << "N = " << N << endl;

                char arr[N];
                srand(time(NULL)); //������� ��������� ��������������� �����

                // �������� �����
                ofstream fout(link);
                if (fout.is_open()) {
                    //���������� ����� c��������� ��������� (��������� ������� + �����)
                    for (int i = 0; i < N;) {
                        char ch = rand() % 125;
                        if (isalnum(ch)) {
                            fout << ch;
                            ++i;
                        }
                    }
                }
                fout.close();

                //���������� ������� ��������� �� �����
                ifstream fin(link);
                if (fin.is_open()) {
                    char my_character;
                    for (int i = 0; i < N; i++) {
                        fin.get(my_character);
                        arr[i] = my_character;
                    }
                }
                fin.close();

                int first = rand() % (N - 10)+60000;
                char pat[50];
                int j = 0;
                for (int i = first; i < first + 50; i++) {
                    pat[j] = arr[i];
                    j++;
                }

                cout << "������� ������\n";
                cout << " ������ ��� ������: ";
                for (char i : pat)
                    cout << i;
                cout << endl;
                cout << " ������� ������ �� �������: ";
                StartCounter();
                cout<<KMP(arr, pat, N,10);
                cout << "\n���������� ���������: " << N-(C + Moving) << endl;
                C = 0;
                Moving = 0;
                cout << "����������� ����� (�): " << GetCounter() << endl;

                cout << endl;
                char wrongStr[] = "@!";

                cout << "��������� ������\n";
                cout << " ������ ��� ������: ";
                for (char i : wrongStr)
                    cout << i;
                cout << endl;
                cout << " ������� ������ �� �������: ";
                StartCounter();
                cout<<KMP(arr, wrongStr,N,2);
                cout << "\n���������� ���������: " << C + Moving+2 << endl;
                C = 0;
                Moving = 0;
                cout << "����������� ����� (�): " << GetCounter() << endl;

                int status = remove("file.txt"); //�������� �����

                cout << "-------------------------------------------------------" << endl;
            }

            break;
        }
        case 2: {
            int N = 10;
            char arr[N];
            char str[] = "find";
            char wrongStr[] = "!?&";

            cout << "������� " << N << " ��������: ";
            for (int i = 0; i < N; i++)
                cin >> arr[i]; //���������� ������� � ����������

            cout << "������� ������\n";
            cout << " ������ ��� ������: find\n";
            cout << " ������� ������ �� �������: ";
            KMPSearch(str, arr);
            cout << endl;

            cout << "��������� ������\n";
            cout << " ������ ��� ������: !?&\n";
            cout << " ������� ������ �� �������: ";
            KMPSearch(wrongStr, arr);
            cout << endl;

            break;
        }
        default:
            cout << "����������, ������� ���������� �����";
    }

    return 0;
}
