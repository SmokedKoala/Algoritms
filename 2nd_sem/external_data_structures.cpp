#include <bits/stdc++.h>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;

int size;

struct Node {
	int num;
	char name[32];
	int price;
};

<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
void convert_to_binary()
{
	string nameData="", line="";
	char snum[5];
	int numData=0, priceData=0;
	ofstream in("binary_file.bin", ios::binary); 
	cin>> numData;
    while (numData!=-1)
    {
//    	line="";
    	cin>>nameData>>priceData;
//        line+=string(itoa(numData, snum,10))+" "+nameData+" "+string(itoa(priceData,snum,10))+"\n";
//        in.write((char*)&line, sizeof(line)); 
		in << numData<<" "<< nameData<<" "<<priceData<<endl;
        cin>> numData;
    }
    in.close();
>>>>>>> Stashed changes

=======
//������� �������� ��������� ����� � ��������� ������ � ����
>>>>>>> Stashed changes
void convert_to_binary(){
	cout<<"������� ���������� ��������� ��� ������ ";
	cin>>size;
	Node node_container[size];
	for(int i =0;i<size;i++){
		cin>>node_container[i].num>>node_container[i].name>>node_container[i].price;
	}
	ofstream input("binary_file.txt", ios::binary);
	input.write((char*)node_container, sizeof(node_container));
	input.close();
}

//������� ����������� ������ �� ��������� �����
void show_binary(){
	Node node_reader[size];
	ifstream output("binary_file.txt", ios::binary);
	output.read((char*)node_reader, sizeof(node_reader));
	output.close();
	
	for (int i =0; i<size; i++){
		cout<<node_reader[i].num<<" "<<node_reader[i].name<<" "<<node_reader[i].price<<endl;
	}
	
}
//������� �������� ���������� ����� � ��������� � ���� ��������� ��������
void create_txt(){
<<<<<<< Updated upstream
	string line;
	char name[32];
	cout<< "������� �������� ���������, ��� ���������� ����� ������� '�����'"<<endl;
	cin>>name;
	Node node_reader[size];
	ifstream output("binary_file.txt", ios::binary);
	output.read((char*)node_reader, sizeof(node_reader));
	output.close();
	while(strcmp(name,"�����" )!=0){
		for (int i =0; i<size; i++){
			if (strcmp(name, node_reader[i].name)==0  )
				line+=to_string(node_reader[i].num)+" "+node_reader[i].name+" "+to_string(node_reader[i].price)+"\n";
		}
		cin>>name;
	}
	ofstream out("txt_file.txt", std::ios::app);
	if (out.is_open()){
		out << line;
	}
	out.close();
	cout<<"���������� � ���� ������: "<<endl;
	ifstream in ("txt_file.txt");
	if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
        }
    }
    in.close();
}
//������� ������ ��������� � �������� �����
void find_node(int key){
	Node node_reader[size];
	ifstream output("binary_file.txt", ios::binary);
	output.read((char*)node_reader, sizeof(node_reader));
	output.close();
=======
	cout<<"������� �������� ���������\n��� ���������� ����� �������� '�����'\n";
	string nameData, line;
	cin>> nameData;
	while (nameData!="�����"){
		ifstream out("binary_file.bin", ios::binary); 
		if (out.is_open())
    	{
        	while (out.read((char*)&line, sizeof(line)))
        	{
            	int pos = line.find(nameData);
            	if (pos == -1)
        			cout << "������ ������ �� �������: "<<nameData << endl;
    			else{
    				cout << line << endl;
    				break;
				}
        			
			}
		}
		out.close();
    	cin>> nameData;
	}
	
//	ofstream in("txt_file.txt", ios::binary);
//	
//	in.close();
>>>>>>> Stashed changes
	
	for (int i =0; i<size; i++){
		if (key==node_reader[i].num){
			cout<<endl<<node_reader[i].num<<" "<<node_reader[i].name<<" "<<node_reader[i].price<<endl;
			return;
		}	
	}
	cout<<"�� ������� ������ � ����� �������"<<endl;
}



int main(){
	setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "������������ ������ �6 ������� ��������� ������ - ����� � ��������� �� ���������. ������ ����������, ����-02-19"<< endl;
    int commandNum=0, newNodeData;
    string menuChoice="\n1)������������� ��������� ������ � �������� ����\n2)���������� ��� ������ ��������� �����\n3)������������ ��������� ���� �� ������� �� �� ��������� ��������\n4)���������� ���������� �������� ������ �� �����\n5)�����\n";
    commandNum=0;
    while(true){
    	cout<<menuChoice;
		cin>>commandNum;
		switch(commandNum){
		case(1):
			cout<<"������� �������������� ��������� ����� � �������� ����\n";
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
			cout << "������ ����� ����������� �������� �� �����\n������� ����: ";
			cin>>newNodeData;
			find_node(newNodeData);
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

