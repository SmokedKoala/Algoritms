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

//функция создания вспомогательного массива
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
			

// функция поиска Кнута-Морриса-Пратта
void KMPSearch(char *pat, char *txt) {
    int M = strlen(pat);
    int N = strlen(txt);
    bool found = false;

    // инициализация lps[], который будет хранить количество префиксов
    int lps[M];

    // создание массива lps[]
    computeLPSArray(pat, M, lps);

    int i = 0; // индекс для txt[]
    int j = 0; // индекс для pat[]
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

            // несоотвествие после совпадения j
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
        cout << "не найдено";
}

// функция создания вспомогательного массива
void computeLPSArray(char *pat, int M, int *lps) {
    // длина предыдущего самого длинного префикса
    int len = 0;

    lps[0] = 0; // lps[0] всегда равен 0


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

//константы и функции для подсчёта времени
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

    cout << "Пожалуйста, введите: [1] - для заполнения массива автоматически, "
            "[2] - для заполнения массива вручную (ввод с клавиатуры): ";
    cin >> num;
    cout << endl;
    cout
            << "Практическая работа №6. Алгоритмы поиска строки в тексте. Азаров Константин, ИКБО-08-19"
            << endl;
    cout << "-----------------------------------------------------------------------------------------------"
         << endl;


    switch (num) {
        case 1: {
            for (int N = 100000; N <= 500000; N += 100000) {

                cout << "N = " << N << endl;

                char arr[N];
                srand(time(NULL)); //создаем генератор псевдослучайных чисел

                // создание файла
                ofstream fout(link);
                if (fout.is_open()) {
                    //заполнение файла cлучайными символами (латинский алфавит + цифры)
                    for (int i = 0; i < N;) {
                        char ch = rand() % 125;
                        if (isalnum(ch)) {
                            fout << ch;
                            ++i;
                        }
                    }
                }
                fout.close();

                //заполнение массива символами из файла
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

                cout << "Средний случай\n";
                cout << " Строка для поиска: ";
                for (char i : pat)
                    cout << i;
                cout << endl;
                cout << " Образец найден на позиции: ";
                StartCounter();
                cout<<KMP(arr, pat, N,10);
                cout << "\nКоличество сравнений: " << N-(C + Moving) << endl;
                C = 0;
                Moving = 0;
                cout << "Затраченное время (с): " << GetCounter() << endl;

                cout << endl;
                char wrongStr[] = "@!";

                cout << "Наихудший случай\n";
                cout << " Строка для поиска: ";
                for (char i : wrongStr)
                    cout << i;
                cout << endl;
                cout << " Образец найден на позиции: ";
                StartCounter();
                cout<<KMP(arr, wrongStr,N,2);
                cout << "\nКоличество сравнений: " << C + Moving+2 << endl;
                C = 0;
                Moving = 0;
                cout << "Затраченное время (с): " << GetCounter() << endl;

                int status = remove("file.txt"); //удаление файла

                cout << "-------------------------------------------------------" << endl;
            }

            break;
        }
        case 2: {
            int N = 10;
            char arr[N];
            char str[] = "find";
            char wrongStr[] = "!?&";

            cout << "Введите " << N << " символов: ";
            for (int i = 0; i < N; i++)
                cin >> arr[i]; //заполнение массива с клавиатуры

            cout << "Средний случай\n";
            cout << " Строка для поиска: find\n";
            cout << " Образец найден на позиции: ";
            KMPSearch(str, arr);
            cout << endl;

            cout << "Наихудший случай\n";
            cout << " Строка для поиска: !?&\n";
            cout << " Образец найден на позиции: ";
            KMPSearch(wrongStr, arr);
            cout << endl;

            break;
        }
        default:
            cout << "Пожалуйста, введите корректное число";
    }

    return 0;
}
