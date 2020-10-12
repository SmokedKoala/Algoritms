#include <bits/stdc++.h>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;

struct Node {
	int num;
	string name;
	int price;
};

void convert_to_binary()
{
	string line;
	ifstream in("in.txt");
	if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
            for( char c : line )
    		{
        		bitset<8> bs(c);
        		cout << bs;
    		}
   		 cout << endl;
        }
    }
    in.close(); 
//   	string s= "Welcome to black list, bitch";
//    
//    for( char c : s )
//    {
//        bitset<8> bs(c);
//        cout << bs;
//    }
//    cout << endl;
}

void show_binary()
{
	
}



int main(){
	setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Практическая работа №6 Внешние структуры данных - файлы и алгоритмы их обработки. Азаров Константин, ИКБО-02-19"<< endl;
    int typeNum;
    int commandNum=0, newNodeData;
    string menuChoice="\n1)Преобразовать текстовые данные в двоичный файл\n2)Отобразить все записи двоичного файла\n3)сформировать текстовый файл из записей не по ключевому элементу\n4)Определить неключевой параметр записи по ключу\n5)Выход\n";
	while(true){
    	commandNum=0;
    	while(commandNum !=6){
    		cout<<menuChoice;
			cin>>commandNum;
			switch(commandNum){
			case(1):
				cout<<"Выбрано преобразование текстового файла в двоичный\n";
				convert_to_binary();
				break;
			case(2):
				 cout << "Выбрано отображение записей двоичного файла\n"; 
				 show_binary();
				break;
			case(3):
				cout << "Выбрано формирование текстового файла из записей не по ключу\n"; 
				break;
			case(4):
				cout << "Выбран вывод неключевого элемента по ключу\n";
				break;
			case(5):
				cout<<"Завершение работы\n";
				return 0;	
				break;
			default:
				cout<<"Некорректные данные";
				break;
			}
		}
	}
}

