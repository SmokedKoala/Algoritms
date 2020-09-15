#include <bits/stdc++.h> 
#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
#include <Windows.h>
#include <string>

using namespace std;

class Node { 
public: 
    string dataFN; 
    string dataLN;
    int dataNum;
    Node* next; 
    
    Node(){};
    
    Node(int dataNum, const string &dataFN, const string &dataLN, Node *next) {
		this->dataNum = dataNum;
		this->dataFN = dataFN;
		this->dataNum = dataNum;
		this->next = next;
	}
}; 
  
// Функция для вывода всех элеменнтов списка начиная с указанного 
void listPrint(Node* n) 
{ 
    while (n != NULL) { 
        cout << n->dataNum << " "<< n->dataLN << " "<< n->dataFN<<" "<< endl; 
        n = n->next; 
    } 
}

//удаление текущего ЛОС
void listDelete(Node **head_ref) {
	Node *current = *head_ref;
	Node *next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	*head_ref = NULL;
}


//добавляет новый элемент в начало списка. 
void addFirst(Node** head_ref, int new_dataNum, string new_dataLN, string new_dataFN )  
{  
    Node* new_node = new Node();  
  
    new_node->dataNum = new_dataNum;  
    new_node->dataLN = new_dataLN; 
    new_node->dataFN = new_dataFN; 
  
    new_node->next = (*head_ref);  
  
    (*head_ref) = new_node;  
}

//добавление элемента в конец списка
void addLast(Node **head_ref, int dataNum, string dataFN, string dataLN) {
	Node *new_node = new Node();
	
	new_node->dataNum = dataNum;  
    new_node->dataLN = dataLN; 
    new_node->dataFN = dataFN; 
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


/* даёт ссылку (указатель на указатель) на первый элемент списка и позицию 
   , удаляет элемент на выбранной позиции */
void deleteNode(struct Node **head_ref, int position) 
{ 
   if (*head_ref == NULL) 
      return; 
   
   struct Node* temp = *head_ref; 
   
    if (position == 0) 
    { 
        *head_ref = temp->next;   
        free(temp);               
        return; 
    } 
   
    for (int i=0; temp!=NULL && i<position-1; i++) 
         temp = temp->next; 
   
    if (temp == NULL || temp->next == NULL) 
         return; 
   
    struct Node *next = temp->next->next; 
   
    free(temp->next);  
  
    temp->next = next;
} 

//добавление элемента после заданного элемента
void insertAfter(Node *prev_node, int new_num, string lN, string fN) {
	if (prev_node == NULL) {
		printf("Такого элемента не существует");
		return;
	}
	
	Node *new_node = new Node();
	new_node->dataNum = new_num;  
    new_node->dataLN = lN; 
    new_node->dataFN = fN;
    new_node->next = prev_node->next;
	prev_node->next = new_node;
}

void insertBefore(Node *next_node, Node *prev_node, int new_num, string lN, string fN) {
	if (next_node == NULL) {
		printf("Такого элемента не существует");
		return;
	}

	Node *new_node = new Node();
	new_node->dataNum = new_num;  
    new_node->dataLN = lN; 
    new_node->dataFN = fN;
    new_node->next = next_node;
	prev_node->next = new_node;
}



//удаление элемента по заданному номеру (первое вхождение)
void deleteNodeByNumber(Node **head_ref, int key) {

	Node *temp = *head_ref, *prev;

	// Если первый элемент - тот, который надо удалить
	if (temp != NULL && temp->dataNum == key) {
		*head_ref = temp->next;
		return;
	}


	// Поиск элемента для удаления
	while (temp != NULL && temp->dataNum != key) {
		prev = temp;
		temp = temp->next;
	}

	// если элемент не был найден
	if (temp == NULL) return;

	prev->next = temp->next;

	free(temp);
}

//удаление элемента по заданному номеру (все вхождения)
void deleteByNumberAll(Node **head_ref, int key) {
	Node *temp = *head_ref, *prev;

	//если требуется удалить первый элемент
	while (temp != NULL && temp->dataNum == key) {
		*head_ref = temp->next;
		free(temp);
		temp = *head_ref;
	}

	while (temp != NULL) {
		while (temp != NULL && temp->dataNum != key) {
			prev = temp;
			temp = temp->next;
		}

		if (temp == NULL) return;

		prev->next = temp->next;

		free(temp);

		temp = prev->next;
	}
}

//поиск элемента, после/перед которым надо будет вставить другой элемент
Node *searchToInsert(Node *head, int x) {
	Node *current = head;
	while (current != NULL) {
		if (current->dataNum == x) {
			return current;
		}
		current = current->next;
	}
}

//поиск элемента по заданному номеру (первое вхождение)
void search(Node *head, int x) {
	cout << "Элемент с номером " << x << ":";
	Node *current = head;
	while (current != NULL) {
		if (current->dataNum == x) {
			cout << "\n " << current->dataFN << " " << current->dataLN << endl;
			return;
		}
		current = current->next;
	}
	cout << " не найден";
}

//поиск элемента по заданному номеру (все вхождения)
void searchAll(Node *head, int x) {
	cout << "Элементы с номером " << x << ":\n";
	bool found = false;
	Node *current = head;
	while (current != NULL) {
		if (current->dataNum == x) {
			cout << " " << current->dataFN << " " << current->dataLN << endl;
			found = true;
		}
		current = current->next;
	}
	if (!found)
		cout << " не найдены";
}

//изменение элемента по значению его номера (первое вхождение)
void ChangeByNumber(Node *head, int num, string lN, string fN) {
	Node *current = head;

	while (current != NULL) {
		if (current->dataNum == num) {
			current->dataFN = fN;
			current->dataLN = lN;
			return;
		}
		current = current->next;
	}

	cout << "Элемента не существует";
}

//изменение элемента по значению его номера (все вхождения)
void ChangeByNumberAll(Node *head, int num, string lN, string fN) {
	Node *current = head;
	bool changed = false;

	while (current != NULL) {
		if (current->dataNum == num) {
			current->dataFN = fN;
			current->dataLN = lN;
			changed=true;
		}
		current = current->next;
	}
	if (changed = false)
		cout << "Элемента не существует";
}

//изменение элемента по порядковому номеру
void ChangeNth(Node *head, int index, int new_num, string lN, string fN) {

	Node *current = head;

	int count = 0;
	while (current != NULL) {
		if (count == index) {
			current->dataNum = new_num;
			current->dataFN = fN;
			current->dataLN = lN;
			return;
		}
		count++;
		current = current->next;
	}

	cout << "Элемента не существует";
}

//поменять два элемента ЛОС местами
void swapElemets(Node **head_ref, int x, int y) {
	if (x == y) return;
	Node *prevX = NULL, *currX = *head_ref;
	while (currX && currX->dataNum != x) {
		prevX = currX;
		currX = currX->next;
	}
	Node *prevY = NULL, *currY = *head_ref;
	while (currY && currY->dataNum != y) {
		prevY = currY;
		currY = currY->next;
	}
	if (currX == NULL || currY == NULL)
		return;
	if (prevX != NULL)
		prevX->next = currY;
	else 
		*head_ref = currY;
	if (prevY != NULL)
		prevY->next = currX;
	else 
		*head_ref = currX;

	Node *temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
}

//вычисление длины ЛОС
int getLength(Node *head) {
	int count = 0;
	Node *current = head;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}


int main() {
    int ch,nextCh, lastCh, numToSearch, numToDelete, numToChange, numToSwap1, numToSwap2;
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Практическая работа №7. Линейные связные списки. Азаров Константин, ИКБО-08-19"
         << endl;
    string new_dataLN, new_dataFN;
    int new_dataNum;
    
	Node* head = NULL; 
    Node* second = NULL; 
    Node* third = NULL; 
    Node* forth = NULL;
    Node* fifth = NULL;
    Node* sixth = NULL;
    Node* seventh = NULL;
    Node* eighth = NULL;
    Node* nineth = NULL;
    Node* tenth = NULL;
    
	head = new Node();
    second = new Node();
    third = new Node();
    forth = new Node();
    fifth = new Node();
    sixth = new Node();
    seventh = new Node();
    eighth = new Node();
    nineth = new Node();
    tenth = new Node(); 
    
    cout << "Введите 10 элементов списка: "<< endl;
    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
	sixth->next = seventh; 
    seventh->next = eighth;
    eighth->next = nineth;
    nineth->next = tenth;
	tenth->next = NULL; 
	      
	Node *n = head;
	while(n!=NULL){
		cin>>n->dataNum>>n->dataLN>>n->dataFN;
		n=n->next;
	}
	
	cout << endl<<"Список команд:\n" << "1)добавить элемент" << endl << "2)удалить элемент" << endl
		 << "3)найти элемент" << endl << "4)изменить элемент" << endl
		 << "5)поменять два элемента местами" << endl << "6)вычислить длину" << endl
		 << "7)вывести список" << endl
		 << "8)удалить список" << endl << "0)выход" << endl;
	cout << endl << "Выбранная команда: ";

	cin >> ch;
	do {
		switch (ch) {
			case 1:
				cout<< endl<< "Добавить элемент:"<<endl<<"1.1)в начало списка"<<endl<<"1.2)в конец списка"<<endl<<"1.3)в середину списка\n";
				cout << endl << "Выбранная команда: ";
				cin >> nextCh;
				switch (nextCh) {
					case 1:
						cout
								<< endl << "Введите элемент:" << endl;
						cin >> new_dataNum >> new_dataFN >> new_dataLN;
						addFirst(&head, new_dataNum, new_dataFN, new_dataLN);
						cout<< endl;
						break;
					case 2:
						cout<< endl << "Введите элемент: " << endl;
						cin >> new_dataNum >> new_dataLN >> new_dataFN;
						addLast(&head, new_dataNum, new_dataFN, new_dataLN);
						cout<< endl;
						break;
					case 3:
						cout<< endl
								<< "Добавить элемент в середину списка:"<<endl<<"1.3.1)после заданного элемента"<<endl<<"1.3.2)перед заданным элементом\n";
						cout << endl << "Выбранная команда: ";
						cin >> lastCh;
						switch (lastCh) {
							case 1:
								cout
									
										<< endl << "Введите номер элемента: "
										<< endl;

								cin >> numToSearch;
								cout << "Введите новые данные: " << endl;
								cin >> new_dataNum >> new_dataFN >> new_dataLN;
								insertAfter(searchToInsert(head, numToSearch), new_dataNum, new_dataFN, new_dataLN);
								cout<< endl;
								break;
							case 2:
								cout<< endl << "Введите номер элемента:"
										<< endl;

								cin >> numToSearch;
								cout << "Введите новые данные: " << endl;
								cin >> new_dataNum >> new_dataFN >> new_dataLN;
								insertBefore(searchToInsert(head, numToSearch), searchToInsert(head, 5), new_dataNum,
											 new_dataFN, new_dataLN);
								cout<< endl;
								break;
							default:
								cout << "Пожалуйста, введите корректное число";
								break;
						}
						break;
					default:
						cout << "Пожалуйста, введите корректное число";
						break;
				}
				break;
			case 2:
				cout<< endl
						<< "Удалить элемент:"<<endl<<"2.1)первый"<<endl<<"2.2)последний"<<endl<<"2.3)заданный\n";
				cout << endl << "Выбранная команда: ";
				cin >> nextCh;
				switch (nextCh) {
					case 1:
						cout<< endl << "Первый элемент удален" << endl;
						deleteNode(&head, 0);
						cout<< endl;
						break;
					case 2:
						cout<< endl << "Последний элемент удален" << endl;
						deleteNode(&head, getLength(head) - 1);
						cout<< endl;
						break;
					case 3:
						cout<< endl
								<< "Заданный элемент:"<<endl<<"2.3.1)первое вхождение"<<endl<<"2.3.2)все вхождения\n";
						cout << endl << "Выбранная команда: ";
						cin >> lastCh;
						switch (lastCh) {
							case 1:
								cout<< endl << "Введите номер элемента:" << endl;
								cin >> numToDelete;
								deleteNodeByNumber(&head, numToDelete);
								cout<< endl;
								break;
							case 2:
								cout<< endl << "Введите номер элемента:" << endl;
								cin >> numToDelete;
								deleteByNumberAll(&head, numToDelete);
								cout<< endl;
								break;
							default:
								cout << "Пожалуйста, введите корректное число";
								break;
						}
						break;
					default:
						cout << "Пожалуйста, введите корректное число";
						break;
				}
				break;
			case 3:
				cout<< endl
						<< "Найти элемент:"<<endl<<"3.1)первое вхождение"<<endl<<"3.2)все вхождения\n";
				cout << endl << "Выбранная команда: ";
				cin >> nextCh;
				switch (nextCh) {
					case 1:
						cout<< endl << "Введите номер элемента для поиска:" << endl;
						cin >> numToSearch;
						search(head, numToSearch);
						cout<< endl;
						break;
					case 2:
						cout<< endl << "Введите номер элемента для поиска:" << endl;
						cin >> numToSearch;
						searchAll(head, numToSearch);
						cout<< endl;
						break;
					default:
						cout << "Пожалуйста, введите корректное число";
						break;
				}
				break;
			case 4:
				cout<< endl
						<< "Изменить элемент:"<<endl<<"4.1)по значению"<<endl<<"4.2)по порядковому номеру\n";
				cout << endl << "Выбранная команда: ";
				cin >> nextCh;
				switch (nextCh) {
					case 1:
						cout<< endl
								<< "Изменить элемент по значению:"<<endl<<"4.1.1) первое вхождение"<<endl<<"4.1.2)все вхождения\n";
						cout << endl << "Выбранная команда: ";
						cin >> lastCh;
						switch (lastCh) {
							case 1:
								cout<< endl << "Введите номер элемента, значения которого надо изменить:"
										<< endl;

								cin >> numToChange;
								cout << "Введите новые данные: " << endl;
								cin >> new_dataFN >> new_dataLN;
								ChangeByNumber(head, numToChange, new_dataFN, new_dataLN);
								cout<< endl;
								break;
							case 2:
								cout<< endl << "Введите номер элемента, значения которого надо изменить:"
										<< endl;

								cin >> numToChange;
								cout << "Введите новые данные: " << endl;
								cin >> new_dataFN >> new_dataLN;
								ChangeByNumberAll(head, numToChange, new_dataFN, new_dataLN);
								cout<< endl;
								break;
							default:
								cout << "Пожалуйста, введите корректное число";
								break;
						}
						break;
					case 2:
						cout<< endl << "Введите порядковый номер элемента, значения которого надо изменить:"
								<< endl;

						cin >> numToChange;
						cout << "Введите новые данные: " << endl;
						cin >> new_dataNum >> new_dataFN >> new_dataLN;
						ChangeNth(head, numToChange - 1, new_dataNum, new_dataFN, new_dataLN);
						cout<< endl;
						break;
					default:
						cout << "Пожалуйста, введите корректное число";
						break;
				}
				break;
			case 5:
				cout<< endl << "Введите номера элементов, которые нужно поменять местами:" << endl;
				cin >> numToSwap1 >> numToSwap2;
				swapElemets(&head, numToSwap1, numToSwap2);
				break;
			case 6:
				cout<< endl << "Длина текущего списка: "
						<< getLength(head) << endl;
				cout<< endl;
				break;
			case 7:
				cout<< endl << "Список:" << endl;
				listPrint(head);
				cout<< endl;
				break;
			case 8:
				cout<< endl << "Текущий список был удалён"
						<< endl;
				listDelete(&head);
				cout<< endl;
				break;
			default:
				cout << "Пожалуйста, введите корректное число";
				break;
		}
		cout << endl << "Новая команда: ";
		cin >> ch;
	} while (ch != 0);
    return 0;
}
