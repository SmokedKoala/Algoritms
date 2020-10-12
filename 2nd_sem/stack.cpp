// выражение записывается посимвольно в стек, в нём считается баланс скобок "(" и "["
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
	cout<<"Практическая работа №4. Стек. Азаров Константин, ИКБО-02-19"<<endl;
	string ch, choice;
	while (true){
		cout<<"Введите строку для анализа: ";
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
    	cout<<"Найденные скобки\n";
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
    	cout<<"\nБаланс круглых скобок: ";
		if(balance_counter1==0)
			cout<<"равное количество";
		if(balance_counter1>0)
			cout<<"открывающих больше на "<<balance_counter1;
		if(balance_counter1<0)
			cout<<"закрывающих больше на "<<-1*balance_counter1;
		cout<<endl;	    
		cout<<"Баланс квадратных скобок: ";
		if(balance_counter2==0)
			cout<<"равное количество";
		if(balance_counter2>0)
			cout<<"открывающих больше на "<<balance_counter2;
		if(balance_counter2<0)
			cout<<"закрывающих больше на "<<-1*balance_counter2;
		cout<<"\nПовторить ввод?(да/нет): ";
		cin>>choice;
		if(choice=="нет")
			return 0;
		
	}
}
