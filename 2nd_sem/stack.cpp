// ��������� ������������ ����������� � ����, � �� ��������� ������ ������ "(" � "["
#include <iostream>
#include <Windows.h>
using namespace std; 
  
/* Link list node */
struct Node { 
    char data; 
    struct Node* next; 
}; 
  
/* Function to remove the last node   
   of the linked list */
Node* pop(struct Node* head) { 
    if (head == NULL) 
        return NULL; 
  
    if (head->next == NULL) { 
        delete head; 
        return NULL; 
    } 
}
    
// Function to push node at head 
void push(struct Node** head_ref, char new_data){ 
    struct Node* new_node = new Node; 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 


int main(){
	setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	int balance_counter1=0,balance_counter2=0 ;
	Node* head = NULL;
	cout<<"������������ ������ �4. ����. ������ ����������, ����-02-19"<<endl;
	string ch, choice;
	while (true){
		cout<<"������� ������ ��� �������: ";
		while (cin>>ch)
		{
			for (int i =0; i< ch.size();i++)
				push(&head, ch[i]);
			if (isspace(cin.peek()))
			{
				if (cin.get()=='\n')
					break;
			}			
		} 
    	cout<<"��������� ������\n";
    	for (Node* temp = head; temp != NULL; temp = temp->next) {
    		if(temp->data=='('){
    			balance_counter1++;
	    		cout<<temp->data;
			}	
    		if(temp->data==')'){
    			balance_counter1--;
	    		cout<<temp->data;
			}	
    		if(temp->data=='['){
    			balance_counter2++;
	    		cout<<temp->data;
			}	
    		if(temp->data==']'){
    			balance_counter2--;
	    		cout<<temp->data;
			}	
    		head = pop(head);	
		}
    	cout<<"\n������ ������� ������: ";
		if(balance_counter1==0)
			cout<<"������ ����������";
		if(balance_counter1>0)
			cout<<"����������� ������ �� "<<balance_counter1;
		if(balance_counter1<0)
			cout<<"����������� ������ �� "<<-1*balance_counter1;
		cout<<endl;	    
		cout<<"������ ���������� ������: ";
		if(balance_counter2==0)
			cout<<"������ ����������";
		if(balance_counter2>0)
			cout<<"����������� ������ �� "<<balance_counter2;
		if(balance_counter2<0)
			cout<<"����������� ������ �� "<<-1*balance_counter2;
		cout<<"\n��������� ����?(��/���): ";
		cin>>choice;
		if(choice=="���")
			return 0;
		
	}
}
