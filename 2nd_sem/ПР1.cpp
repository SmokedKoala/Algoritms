#include <bits/stdc++.h> 
#include <cstdio>
#include <iostream>
#include <Windows.h>
#include <string>
#include <exception>

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

// ���������� � ����� ������� �������
void addLastEl(int *dim_arr, int new_dataNum){
	int i=0;
	while(dim_arr[i]!=NULL){
		i++;
	}	
	dim_arr[i]=new_dataNum;
	cout<<"\n�� ������� "<<i<<" ��� �������� ������� "<<new_dataNum<<endl;
}


// ����� �������� ������� ��������
int firstEl(int *dim_arr){
	return dim_arr[0];
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
    	cout<<"\n�������� ������ ���������� �������\n1)�� ����������� ������������ ������\n2)�� ������������ �������\n";
    	cin>>typeNum;
    	commandNum=0;
    	switch(typeNum){
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
				cout<<"������� ������ ������������� �������\n";
				cin>>mas_size;
				int *dim_arr = new int (mas_size);
    			while(commandNum !=6){
    				cout<<menuChoice;
					cin>>commandNum;
						switch(commandNum){
							case(1):
								cout<<"\n������� ���������� ��������\n������� ����� ";
								cin>> new_dataNum;
//								addLastEl(dim_arr, new_dataNum);
    							cout<<endl;
								break;
							case(2):
								cout<<"\n������� �������� ��������\n";
//								deleteNode(&head, 0);
//								listPrint(head); 
								break;
							case(3):
								cout<<"\n������� ��������� �������� ������� ��������";
								cout<<"\n�������� ������� ��������: "<<dim_arr[0]<<endl;
								break;
							case(4):
								cout<<"\n������� �������, �� ������ �� �������";
//								if (getLength(head)==0){
//									cout<<"\n������� ������\n";}
//								else 
//									cout<<"\n� �������� ��������� "<<getLength(head)<<" ���������\n";
								break;
							case(5):
								cout<<"\n������� �������, �� ������ �� �������";
								cout<<"\n������� ����������� �� ������������ �������, ������� ��� ������\n� �������� ���������  ���������\n";
								break;
							case(6):
								delete []dim_arr;
								cout<<"������� �������\n";
								break;
							default:
								break;
					}
				}
				break;	
		}
    	
	}
	return 0;
}
