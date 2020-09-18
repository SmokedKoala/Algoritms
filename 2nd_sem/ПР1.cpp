#include <bits/stdc++.h> 
#include <cstdio>
#include <iostream>
#include <Windows.h>
#include <string>
#include <exception>
#include <vector> 
#include <stdlib.h>

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
	cout<<"Текущий массив: ";
    while (n != NULL) { 
        cout << n->dataNum << " "; 
        n = n->next; 
    } 
} 
  
//добавление элемента в конец списка
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

//удаление первого
void deleteNode(struct Node **head_ref, int position) 
{ 
   if (*head_ref == NULL){
   		cout<<"\nОшибка,в очереди нет элементов\n";
	   return;
   } 
   		
       
   
   struct Node* temp = *head_ref; 
   
    if (position == 0) 
    { 
        *head_ref = temp->next;
		cout<<"Удалён "<<temp->dataNum<<endl;   
        free(temp);               
        return; 
    } 
   
} 

void findNode(struct Node *head, int position){
	if (head==NULL){
		cout<<"\nОчередь пуста, повторите ввод команды\n";
		return;
	}
	try{
		int count = 0;
	Node *current = head;
	while(count != position){
		count++;
		current = current->next;
	}
	cout<<"\nПервый элемент равен "<< current->dataNum<<endl;
	}
	catch(exception& e){
		cout<<"Некорректные данные"<<endl;
	}
	
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










// Вывод значения первого элемента
void firstEl(vector<int> vec_arr){
	if(vec_arr.size()!=0)
		cout<<"\nЗначение первого элемента: "<< vec_arr[0]<<endl;
	else
		cout<<"\nОтсутствует первый элемент"<<endl;;
}

// Вывод количества элементов в динамическом массиве
int arrLen(vector<int> vec_arr){
	return vec_arr.size();
}

// Вывод массива
void printArr(vector<int> vec_arr){
	cout<<"\nМассив: ";
	for (int i = 0; i != vec_arr.size(); ++i) 
        cout << vec_arr[i] << " ";
}

// Добавление в конец массива элемент
void addLastEl(vector<int> vec_arr, int new_dataNum){
	vec_arr.push_back(new_dataNum);
}

// Удаление первого элемента массива
void delFirstEl(vector<int> vec_arr){
	if (vec_arr.size()!=0){
	cout<<"\nБыл удалён первый элемент со значением "<<vec_arr[0]<<endl;
	vec_arr.erase(vec_arr.begin());	
	}
	else
	cout<<"Не существует первого элемента\n";
}

// Проверка, пустая ли очередь
void isEmpty(vector<int> vec_arr){
	if (arrLen(vec_arr)==0){
		cout<<"\nочередь пустая\n";}
	else 
		cout<<"\nв очередти находится "<<arrLen(vec_arr)<<" элементов\n";
}

//Проверка, полная ли очередь
void isFull(vector<int> vec_arr){
	if (arrLen(vec_arr)==10){
		cout<<"\nочередь полная\n";}
	else 
		cout<<"\nв очередти находится "<<arrLen(vec_arr)<<" из 10 элементов\n";
}





int main(){
	setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Node* head = NULL;
    
    cout << "Практическая работа №1 Линейный список. Очередь. Азаров Константин, ИКБО-02-19"
         << endl;
    int typeNum;
    int commandNum=0;
    int new_dataNum,mas_size;
    string menuChoice="\n1)Добавление элемента\n2)Удаление элемента\n3)Получение значения первого элемента\n4)Пустая ли очередь?\n5)Полная ли очередь?\n6)Вернуться к выбору реализации\n";
    
	while(true){
    	cout<<"\nВыберете способ реализации очереди\n1)на односвязном динамическом списке\n2)на динамическом массиве\n3)Задание 5(Префиксный калькулятор)\n4)Выход\n";
    	cin>>typeNum;
    	commandNum=0;
    	vector <string> str_for_calc;
    	string ch="";
    	int cur_res=0;
    	string major_sign ="";
		string minor_sign ="";
		string cur_A ="";
		string cur_B ="";
		string cur_C ="";
		int A =0;
		int B=0;
		int C =0;
    	vector<int> vec_arr;
    	switch(typeNum){
    		
    		case(1):
    			while(commandNum !=6){
    				cout<<menuChoice;
					cin>>commandNum;
						switch(commandNum){
							case(1):
								cout<<"\nВыбрано добавление элемента\nВведите число ";
								if(getLength(head)<10){
									cin>> new_dataNum;
									addLast(&head, new_dataNum);
									listPrint(head); 
    								cout<<endl;}
								else
									cout<<"В очереди предельное количество элементов(10)\n";
								break;
							case(2):
								cout<<"\nВыбрано удаление элемента\n";
								deleteNode(&head, 0);
								listPrint(head); 
								break;
							case(3):
								cout<<"\nВыбрано получение значения первого элемента";
								findNode(head, 0);
								break;
							case(4):
								cout<<"\nВыбрана поверка, не пустая ли очередь";
								if (getLength(head)==0){
									cout<<"\nочередь пустая\n";}
								else 
									cout<<"\nв очередти находится "<<getLength(head)<<" элементов\n";
								break;
							case(5):
								cout<<"\nВыбрана поверка, не полная ли очередь";
								cout<<"\nОчередь реализована на динамическом ЛОС, поэтому нет лимита\nв очередти находится "<<getLength(head)<<" элементов\n";
								break;
							case(6):
								while(head!=NULL){
									deleteNode(&head, 0);
								}
								cout<<"очередь очищена\n";
								break;
							default:
								break;
					}
				}
				break;
			case(2):
    			while(commandNum !=6){
    				cout<<menuChoice;
					cin>>commandNum;
						switch(commandNum){
							case(1):
								cout<<"\nВыбрано добавление элемента\nВведите число ";
								cin>> new_dataNum;
//								addLastEl(vec_arr, new_dataNum);
								vec_arr.push_back(new_dataNum);
								printArr(vec_arr);
								cout<<endl;
								break;
							case(2):
								cout<<"\nВыбрано удаление элемента\n";
//								delFirstEl(vec_arr);
								if (vec_arr.size()!=0){
									cout<<"\nБыл удалён первый элемент со значением "<<vec_arr[0]<<endl;
									vec_arr.erase(vec_arr.begin());	
								}
								else
								cout<<"Не существует первого элемента\n";
								printArr(vec_arr);
								cout<<endl;
								break;
							case(3):
								cout<<"\nВыбрано получение значения первого элемента";
								firstEl(vec_arr);
								break;
							case(4):
								cout<<"\nВыбрана поверка, не пустая ли очередь";
								isEmpty(vec_arr);
								break;
							case(5):
								cout<<"\nВыбрана поверка, не полная ли очередь";
								isFull(vec_arr);
								break;
							case(6):
								vec_arr.clear();
								cout<<"очередь очищена\n";
								break;
							default:
								break;
					}
				}
				break;
				case(3):
    				cout<<"\nВведите через пробел префиксное выражение для калькулятора\n";
    				while (cin>>ch){
						str_for_calc.push_back(ch);
						if (isspace(cin.peek()))
						{
							if (cin.get()=='\n')
								break;	
						}
						else
							break;
						}
						while (str_for_calc.size()>0){
							if (str_for_calc[0]=="+" or str_for_calc[0]=="-" or str_for_calc[0]=="*" or str_for_calc[0]=="/"){
								major_sign=minor_sign;
								minor_sign=str_for_calc[0];
								str_for_calc.erase(str_for_calc.begin());
							}
							else {
								if (str_for_calc.size()==2){
									cur_B=str_for_calc[0];
									str_for_calc.erase(str_for_calc.begin());
								}
								else{
									if (str_for_calc[1]=="+" or str_for_calc[1]=="-" or str_for_calc[1]=="*" or str_for_calc[1]=="/"){
										cur_C=str_for_calc[0];
										str_for_calc.erase(str_for_calc.begin());
									}
									else{
										cur_A=str_for_calc[0];
										str_for_calc.erase(str_for_calc.begin());
										cur_B=str_for_calc[0];
										str_for_calc.erase(str_for_calc.begin());
									}
										
								}
								
							}
							if (cur_B!=""){
								//Вынести в функцию
								if (major_sign==""){
									if (minor_sign=="+"){
										cur_res=+(A+B);
									}
									if (minor_sign=="-"){
										cur_res=+(A-B);
									}
									if (minor_sign=="*"){
										cur_res=+(A*B);
									}
									if (minor_sign=="/"){
										cur_res=+(A/B);
									}
								}
								if (major_sign=="+"){
									if (minor_sign=="+"){
										cur_res=+(A+B+C);
									}
									if (minor_sign=="-"){
										cur_res=+(A-B+C);
									}
									if (minor_sign=="*"){
										cur_res=+(A*B+C);
									}
									if (minor_sign=="/"){
										cur_res=+(A/B+C);
									}
								}
								if (major_sign=="-"){
									if (minor_sign=="+"){
										cur_res=+(A+B-C);
									}
									if (minor_sign=="-"){
										cur_res=+(A-B-C);
									}
									if (minor_sign=="*"){
										cur_res=+(A*B-C);
									}
									if (minor_sign=="/"){
										cur_res=+(A/B-C);
									}
								}
								if (major_sign=="*"){
									if (minor_sign=="+"){
										cur_res=+((A+B)*C);
									}
									if (minor_sign=="-"){
										cur_res=+((A-B)*C);
									}
									if (minor_sign=="*"){
										cur_res=+(A*B*C);
									}
									if (minor_sign=="/"){
										cur_res=+(A/B*C);
									}
								}
								if (major_sign=="/"){
									if (minor_sign=="+"){
										cur_res=+((A+B)/C);
									}
									if (minor_sign=="-"){
										cur_res=+((A-B)/C);
									}
									if (minor_sign=="*"){
										cur_res=+(A*B/C);
									}
									if (minor_sign=="/"){
										cur_res=+(A/B/C);
									}
								}
								minor_sign="";
								major_sign="";
								cur_A="";
								cur_B="";
								cur_C="";
							}
						}
						cout<<"minor_sign:"<<minor_sign<<"_"<<endl;
						cout<<"major_sign: "<<major_sign<<endl;
						cout<<"cur_A: "<<cur_A<<endl;
						cout<<"cur_B: "<<cur_B<<endl;
						cout<<"cur_C: "<<cur_C<<endl;
						cout<<"cur_res: "<<cur_res<<endl;
						
				break;
			case(4):
				return 0;
				break;
		}
	}
}
