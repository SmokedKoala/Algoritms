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
	string line, main_line;
	ifstream in("in.txt");
	ofstream out("out.bin", ios::binary); 
	if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
            main_line+='\n'+line;
        }
    out.write((char*)&main_line, sizeof(line));    
    }
    in.close(); 
    out.close();

}

void show_binary()
{
	string line;
	ifstream in("out.bin", ios::binary);
	
		in.read((char*)&line, sizeof(line));
		cout<<line;
	
	in.close();
	
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

