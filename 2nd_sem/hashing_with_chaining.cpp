#include <iomanip>
#include <list>
#include <iostream>
#include <Windows.h>
using namespace std;

const int HASH_TABLE_LENGTH = 10;

// ��������� ��������
struct Node {
public:
    int number;
    string name;
    string adress;
    Node(int number, string name, string adress) {
        this->number = number;
        this->name = name;
        this->adress = adress;
    }
};

// ����� ���-�������
class Hash
{
    int BUCKET_NUM;    // ����� "������" (���������� �� ������ � ���-�������)
    list<Node*>* table; // ��������� �� ������ � ��������� (���-�������)
public:
	
   	// �����������
    Hash(int b)
	{
    	this->BUCKET_NUM = b;
    	table = new list<Node*>[BUCKET_NUM];
	}; 
	
	// ������� ������� �������� 
    int insert(int num, string name, string adress)
	{
    	int index = hashFunction(num);
    	Node* new_f = new Node(num, name, adress);
    	table[index].push_back(new_f);
    	return index;
	}; 
	
    // ������� �������� ��������
    void erase(int num)
	{
    	int index = hashFunction(num);
    	for (Node* f : table[index]) {
    	    if (f->number == num) {
    	    	cout<<"������� "<<f->name<<" �����"<<endl;
    	        table[index].remove(f);
   	         return;
    	    }
    	}
    	cout<<"������� �� ������";
	}; 
	
    // ������� ������ ��������
    void find(int num){
    	int index = hashFunction(num);
    	for (Node* f : table[index]) {
        	if (f->number == num) {
        	    cout<<"����� "<<f->number<<" ��� "<<f->name<<" �� ������ "<<f->adress<<endl;
        	    return;
        	}
    	}
    	cout<<"�� ���������� ��������"<<endl;
	}; 
	
    // ���-�������
    int hashFunction(int x) {
    	return (x % BUCKET_NUM);
	}; 
	
	// ������� ������ ����������� ���-�������
    void display() {
    	for (int i = 0; i < BUCKET_NUM; i++) {
        	cout << i;
    	    for (Node* x : table[i])
        	    cout << " --> " << x->number<<" "<<x->name<<" "<<x->adress;
    	    cout << endl;
    	}
	}; 
};



 

int main(){
	setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Hash hash(HASH_TABLE_LENGTH);
    cout << "������������ ������ �3 ����������� � ������ ������ � ������. ������ ����������, ����-02-19"
         << endl;
    int typeNum;
    int commandNum=0, newNodeNum=0;
    string newNodeName="", newNodeAdress;
    string menuChoice="\n1)������� ��������\n2)�������� ��������\n3)����� ��������\n4)����� ��������\n5)�����\n";
    
	while(true){
    	commandNum=0;
    	while(commandNum !=6){
    		cout<<menuChoice;
			cin>>commandNum;
			switch(commandNum){
			case(1):
				cout<<"������� ������� ��������\n������� ������ ��������: ";
				cin>>newNodeNum>>newNodeName>>newNodeAdress;
				hash.insert(newNodeNum,newNodeName,newNodeAdress);
				break;
			case(2):
				cout<<"������� �������� ��������\n������� ����� ��������: "; 
				cin>>newNodeNum;
				hash.erase(newNodeNum);
				break;
			case(3):
				cout<<"������ ����� ��������\n������� ����� ��������: "; 
				cin>>newNodeNum;
				cout<<"��������� �������: "<<endl;
				hash.find(newNodeNum);
				break;
			case(4):
				cout<<"������ ����� ���� ��������"<<endl; 
				hash.display();
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
