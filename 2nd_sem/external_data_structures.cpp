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
	string nameData="", line="";
	char snum[5];
	int numData=0, priceData=0;
	ofstream in("binary_file.bin", ios::binary); 
	cin>> numData;
    while (numData!=-1)
    {
    	cin>>nameData>>priceData;
        line+=string(itoa(numData, snum,6))+" "+nameData+" "+string(itoa(priceData,snum,10))+"\n";
        cin>> numData;
    }
    in.write((char*)&line, sizeof(line));   
    in.close();

}

void show_binary()
{
	string line;
	ifstream out("binary_file.bin", ios::binary);
	out.read((char*)&line, sizeof(line));
	cout<<line;
	out.close();
	
}

void create_txt(){
	cout<<"Введите названия продуктов\nПри завершении ввода напишите 'Конец'\n";
	string nameData, line;
	ifstream out("binary_file.bin", ios::binary); 
	out.read((char*)&line, sizeof(line));
	out.close();
	cin>> nameData;
	while (nameData!="Конец"){
	int pos = line.find(nameData);
	if (pos == -1)
        cout << "данная запись не найдена: "<<nameData << endl;
    else
        cout << "ch " << line[pos]  << endl;	
    cin>> nameData;
	}
	ofstream in("txt_file.txt", ios::binary);
	
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
				cout<<"Выбрано преобразование текстовых данны в двоичный файл\nПри окончании ввода структур напишите -1\n";
				convert_to_binary();
				break;
			case(2):
				cout << "Выбрано отображение записей двоичного файла\n"; 
				show_binary();
				break;
			case(3):
				cout << "Выбрано формирование текстового файла из записей не по ключу\n"; 
				create_txt();
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

