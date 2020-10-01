#include <bits/stdc++.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include <exception>
#include <stdlib.h>
using namespace std; 

class Hash 
{ 
	int BUCKET; // No. корзины 

	// Указатель на список с корзинами 
	list<int> *table; 
public: 

	// конструктор 
	Hash(int b) 
	{ 
		this->BUCKET = b; 
		table = new list<int>[BUCKET]; 
	}  

	// добавление ключа в хеш таблицу 
	void insertItem(int key) 
	{ 
		int index = hashFunction(key); 
		table[index].push_back(key); 
	}  

	// удаление ключа из хеш таблицы 
	void deleteItem(int key) 
	{ 
		// получение хеш индекса ключа 
		int index = hashFunction(key); 
		// найти ключ в i-том списке 
		list <int> :: iterator i; 
		for (i = table[index].begin(); i != table[index].end(); i++) { 
			if (*i == key) 
				break; 
		} 
		// если ключ найден в хеш таблице, удалить его
		if (i != table[index].end()) 
		table[index].erase(i); 
	}  

	// хеш функция для определения ключа для данных
	int hashFunction(int x) { 
		return (x % BUCKET); 
	} 
	
	// функция для отображения хеш таблицы 
	void displayHash() { 
		for (int i = 0; i < BUCKET; i++) { 
			cout << i; 
			for (auto x : table[i]) 
			cout << " --> " << x; 
			cout << endl; 
		}		 
	} 
}; 


int main() 
{ 
	setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    cout << "Практическая работа №3 Хеширование - прямой доступ к данным. Азаров Константин, ИКБО-02-19"
         << endl;
    string menuChoice="\n1)Вставка элемента\n2)Удаление элемента\n3)Поиск элемента\n4)Вывод данных\n5)Выход\n";
    int newNodeData = 0, commandNum=0;
	// array that contains keys to be mapped 
	int a[] = {15, 11, 27, 8, 12}; 
	int n = sizeof(a)/sizeof(a[0]); 

// insert the keys into the hash table 
	Hash h(7); // 7 is count of buckets in 
			// hash table 
//for (int i = 0; i < n; i++) 
//	h.insertItem(a[i]); 

	while(true){
    	commandNum=0;
    	while(commandNum !=6){
    		cout<<menuChoice;
			cin>>commandNum;
			switch(commandNum){
			case(1):
				cout<<"Выбрана вставка элемента\nВведите элемент: ";
				cin>>newNodeData;
				h.insertItem(newNodeData);
				break;
			case(2):
				cout << "Выбрано удаление элемента\nВведите элемент: "; 
				cin>>newNodeData;
				h.deleteItem(newNodeData);
				break;
			case(3):
				cout << "\nВыбран поиск элемента\n"; 

				break;
			case(4):
				cout << "\nВыбран вывод данных\n"; 
				h.displayHash(); 
				break;
			case(5):
				return 0;	
				break;
			default:
				cout<<"Некорректные данные";
				break;
			}
		}
	}
} 

