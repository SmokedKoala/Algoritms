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
	cout<<"������� �������� ���������\n��� ���������� ����� �������� '�����'\n";
	string nameData, line;
	ifstream out("binary_file.bin", ios::binary); 
	out.read((char*)&line, sizeof(line));
	out.close();
	cin>> nameData;
	while (nameData!="�����"){
	int pos = line.find(nameData);
	if (pos == -1)
        cout << "������ ������ �� �������: "<<nameData << endl;
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
				cout<<"������� �������������� ��������� ����� � �������� ����\n��� ��������� ����� �������� �������� -1\n";
				convert_to_binary();
				break;
			case(2):
				cout << "������� ����������� ������� ��������� �����\n"; 
				show_binary();
				break;
			case(3):
				cout << "������� ������������ ���������� ����� �� ������� �� �� �����\n"; 
				create_txt();
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

