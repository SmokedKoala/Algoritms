#include <bits/stdc++.h> 
#include <cstdio>
#include <iostream>
#include <Windows.h>
#include <string>
#include <exception>
#include <vector> 

using namespace std;

class Node { 
public: 
    int dataNum;
    Node* next; 
    
    Node(){};
    Node(int dataNum, Node *next) {
		this->dataNum = dataNum;
		this->next = next;
	}
};

void listPrint(Node* n) 
{ 
	cout<<"������� ������: ";
    while (n != NULL) { 
        cout << n->dataNum << " "; 
        n = n->next; 
    } 
} 
  
//���������� �������� � ����� ������
void addLast(Node **head_ref, int dataNum) {
	Node *new_node = new Node();
	
	new_node->dataNum = dataNum;  
    new_node->next=NULL;

	Node *last = *head_ref;

	if (*head_ref == NULL) {
		*head_ref = new_node;
		return;
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
}

//�������� �������
void deleteNode(struct Node **head_ref, int position) 
{ 
   if (*head_ref == NULL){
   		cout<<"\n������,� ������� ��� ���������\n";
	   return;
   } 
   		
       
   
   struct Node* temp = *head_ref; 
   
    if (position == 0) 
    { 
        *head_ref = temp->next;
		cout<<"����� "<<temp->dataNum<<endl;   
        free(temp);               
        return; 
    } 
   
} 

void findNode(struct Node *head, int position){
	if (head==NULL){
		cout<<"\n������� �����, ��������� ���� �������\n";
		return;
	}
	try{
		int count = 0;
	Node *current = head;
	while(count != position){
		count++;
		current = current->next;
	}
	cout<<"\n������ ������� ����� "<< current->dataNum<<endl;
	}
	catch(exception& e){
		cout<<"������������ ������"<<endl;
	}
	
}

//���������� ����� ���
int getLength(Node *head) {
	int count = 0;
	Node *current = head;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}










// ����� �������� ������� ��������
void firstEl(vector<int> vec_arr){
	if(vec_arr.size()!=0)
		cout<<"\n�������� ������� ��������: "<< vec_arr[0]<<endl;
	else
		cout<<"\n����������� ������ �������"<<endl;;
}

// ����� ���������� ��������� � ������������ �������
int arrLen(vector<int> vec_arr){
	return vec_arr.size();
}

// ����� �������
void printArr(vector<int> vec_arr){
	cout<<"\n������: ";
	for (int i = 0; i != vec_arr.size(); ++i) 
        cout << vec_arr[i] << " ";
}

// ���������� � ����� ������� �������
void addLastEl(vector<int> vec_arr, int new_dataNum){
	vec_arr.push_back(new_dataNum);
}

// �������� ������� �������� �������
void delFirstEl(vector<int> vec_arr){
	if (vec_arr.size()!=0){
	cout<<"\n��� ����� ������ ������� �� ��������� "<<vec_arr[0]<<endl;
	vec_arr.erase(vec_arr.begin());	
	}
	else
	cout<<"�� ���������� ������� ��������\n";
}







int main(){
	setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Node* head = NULL;
    
    cout << "������������ ������ �1 �������� ������. �������. ������ ����������, ����-02-19"
         << endl;
    int typeNum;
    int commandNum=0;
    int new_dataNum,mas_size;
    string menuChoice="\n1)���������� ��������\n2)�������� ��������\n3)��������� �������� ������� ��������\n4)������ �� �������?\n5)������ �� �������?\n6)��������� � ������ ����������\n";
    
	while(true){
    	cout<<"\n�������� ������ ���������� �������\n1)�� ����������� ������������ ������\n2)�� ������������ �������\n3)������� 5(���������� �����������)\n4)�����\n";
    	cin>>typeNum;
    	commandNum=0;
    	switch(typeNum){
    		case(3):
//    			char nextSymb=' ';
//    			vector<int> calc_vec;
//    			while(nextSymb!="\n"){
//    				cin>>nextSymb;
//    				calc_vec.push_back(nextSymb)
				}
    			
				break;
			case(4):
				return 0;
				break;
    		case(1):
    			while(commandNum !=6){
    				cout<<menuChoice;
					cin>>commandNum;
						switch(commandNum){
							case(1):
								cout<<"\n������� ���������� ��������\n������� ����� ";
								cin>> new_dataNum;
								addLast(&head, new_dataNum);
								listPrint(head); 
    							cout<<endl;
								break;
							case(2):
								cout<<"\n������� �������� ��������\n";
								deleteNode(&head, 0);
								listPrint(head); 
								break;
							case(3):
								cout<<"\n������� ��������� �������� ������� ��������";
								findNode(head, 0);
								break;
							case(4):
								cout<<"\n������� �������, �� ������ �� �������";
								if (getLength(head)==0){
									cout<<"\n������� ������\n";}
								else 
									cout<<"\n� �������� ��������� "<<getLength(head)<<" ���������\n";
								break;
							case(5):
								cout<<"\n������� �������, �� ������ �� �������";
								cout<<"\n������� ����������� �� ������������ ���, ������� ��� ������\n� �������� ��������� "<<getLength(head)<<" ���������\n";
								break;
							case(6):
								while(head!=NULL){
									deleteNode(&head, 0);
								}
								cout<<"������� �������\n";
								break;
							default:
								break;
					}
				}
				break;
			case(2):
				vector<int> vec_arr;
    			while(commandNum !=6){
    				cout<<menuChoice;
					cin>>commandNum;
						switch(commandNum){
							case(1):
								cout<<"\n������� ���������� ��������\n������� ����� ";
								cin>> new_dataNum;
//								addLastEl(vec_arr, new_dataNum);
								vec_arr.push_back(new_dataNum);
								printArr(vec_arr);
								cout<<endl;
								break;
							case(2):
								cout<<"\n������� �������� ��������\n";
//								delFirstEl(vec_arr);
								if (vec_arr.size()!=0){
									cout<<"\n��� ����� ������ ������� �� ��������� "<<vec_arr[0]<<endl;
									vec_arr.erase(vec_arr.begin());	
								}
								else
								cout<<"�� ���������� ������� ��������\n";
								printArr(vec_arr);
								cout<<endl;
								break;
							case(3):
								cout<<"\n������� ��������� �������� ������� ��������";
								firstEl(vec_arr);
								break;
							case(4):
								cout<<"\n������� �������, �� ������ �� �������";
								if (arrLen(vec_arr)==0){
									cout<<"\n������� ������\n";}
								else 
									cout<<"\n� �������� ��������� "<<arrLen(vec_arr)<<" ���������\n";
								break;
							case(5):
								cout<<"\n������� �������, �� ������ �� �������";
								cout<<"\n������� ����������� �� ������������ �������, ������� ��� ������\n� �������� ��������� "<<arrLen(vec_arr)<<" ���������\n";
								break;
							case(6):
								vec_arr.clear();
								cout<<"������� �������\n";
								break;
							default:
								break;
					}
				}
				break;
		}
	}
}
