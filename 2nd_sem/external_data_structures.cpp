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
    cout << "������������ ������ �6 ������� ��������� ������ - ����� � ��������� �� ���������. ������ ����������, ����-02-19"<< endl;
    int typeNum;
    int commandNum=0, newNodeData;
    string menuChoice="\n1)������������� ��������� ������ � �������� ����\n2)���������� ��� ������ ��������� �����\n3)������������ ��������� ���� �� ������� �� �� ��������� ��������\n4)���������� ���������� �������� ������ �� �����\n5)�����\n";
	while(true){
    	commandNum=0;
    	while(commandNum !=6){
    		cout<<menuChoice;
			cin>>commandNum;
			switch(commandNum){
			case(1):
				cout<<"������� �������������� ���������� ����� � ��������\n";
				convert_to_binary();
				break;
			case(2):
				 cout << "������� ����������� ������� ��������� �����\n"; 
				 show_binary();
				break;
			case(3):
				cout << "������� ������������ ���������� ����� �� ������� �� �� �����\n"; 
				break;
			case(4):
				cout << "������ ����� ����������� �������� �� �����\n";
				break;
			case(5):
				cout<<"���������� ������\n";
				return 0;	
				break;
			default:
				cout<<"������������ ������";
				break;
			}
		}
	}
}

