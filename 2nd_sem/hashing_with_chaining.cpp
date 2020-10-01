#include <bits/stdc++.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include <exception>
#include <stdlib.h>
using namespace std; 

class Hash 
{ 
	int BUCKET; // No. ������� 

	// ��������� �� ������ � ��������� 
	list<int> *table; 
public: 

	// ����������� 
	Hash(int b) 
	{ 
		this->BUCKET = b; 
		table = new list<int>[BUCKET]; 
	}  

	// ���������� ����� � ��� ������� 
	void insertItem(int key) 
	{ 
		int index = hashFunction(key); 
		table[index].push_back(key); 
	}  

	// �������� ����� �� ��� ������� 
	void deleteItem(int key) 
	{ 
		// ��������� ��� ������� ����� 
		int index = hashFunction(key); 
		// ����� ���� � i-��� ������ 
		list <int> :: iterator i; 
		for (i = table[index].begin(); i != table[index].end(); i++) { 
			if (*i == key) 
				break; 
		} 
		// ���� ���� ������ � ��� �������, ������� ���
		if (i != table[index].end()) 
		table[index].erase(i); 
	}  

	// ��� ������� ��� ����������� ����� ��� ������
	int hashFunction(int x) { 
		return (x % BUCKET); 
	} 
	
	// ������� ��� ����������� ��� ������� 
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
    
    cout << "������������ ������ �3 ����������� - ������ ������ � ������. ������ ����������, ����-02-19"
         << endl;
    string menuChoice="\n1)������� ��������\n2)�������� ��������\n3)����� ��������\n4)����� ������\n5)�����\n";
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
				cout<<"������� ������� ��������\n������� �������: ";
				cin>>newNodeData;
				h.insertItem(newNodeData);
				break;
			case(2):
				cout << "������� �������� ��������\n������� �������: "; 
				cin>>newNodeData;
				h.deleteItem(newNodeData);
				break;
			case(3):
				cout << "\n������ ����� ��������\n"; 

				break;
			case(4):
				cout << "\n������ ����� ������\n"; 
				h.displayHash(); 
				break;
			case(5):
				return 0;	
				break;
			default:
				cout<<"������������ ������";
				break;
			}
		}
	}
} 

