#include <iomanip>
#include <list>
#include <iostream>
#include <Windows.h>
using namespace std;

const int HASH_TABLE_LENGTH = 10;

// Структура элемента
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

// Класс Хеш-таблицы
class Hash
{
    int BUCKET_NUM;    // Число "корзин" (указателей на списки в хеш-таблице)
    list<Node*>* table; // Указатель на массив с корзинами (хеш-таблицу)
public:
	
   	// Конструктор
    Hash(int b)
	{
    	this->BUCKET_NUM = b;
    	table = new list<Node*>[BUCKET_NUM];
	}; 
	
	// Функция вставки элемента 
    int insert(int num, string name, string adress)
	{
    	int index = hashFunction(num);
    	Node* new_f = new Node(num, name, adress);
    	table[index].push_back(new_f);
    	return index;
	}; 
	
    // Функция удаления элемента
    void erase(int num)
	{
    	int index = hashFunction(num);
    	for (Node* f : table[index]) {
    	    if (f->number == num) {
    	    	cout<<"Элемент "<<f->name<<" удалён"<<endl;
    	        table[index].remove(f);
   	         return;
    	    }
    	}
    	cout<<"Элемент не найден";
	}; 
	
    // Функция поиска элемента
    void find(int num){
    	int index = hashFunction(num);
    	for (Node* f : table[index]) {
        	if (f->number == num) {
        	    cout<<"номер "<<f->number<<" Имя "<<f->name<<" по адресу "<<f->adress<<endl;
        	    return;
        	}
    	}
    	cout<<"не существует элемента"<<endl;
	}; 
	
    // Хеш-функция
    int hashFunction(int x) {
    	return (x % BUCKET_NUM);
	}; 
	
	// Функция вывода содержимого хеш-таблицы
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
    cout << "Практическая работа №3 Хеширование – прямой доступ к данным. Азаров Константин, ИКБО-02-19"
         << endl;
    int typeNum;
    int commandNum=0, newNodeNum=0;
    string newNodeName="", newNodeAdress;
    string menuChoice="\n1)Вставка элемента\n2)Удаление Элемента\n3)Поиск элемента\n4)Вывод значений\n5)Выход\n";
    
	while(true){
    	commandNum=0;
    	while(commandNum !=6){
    		cout<<menuChoice;
			cin>>commandNum;
			switch(commandNum){
			case(1):
				cout<<"Выбрана вставка элемента\nВведите данные элемента: ";
				cin>>newNodeNum>>newNodeName>>newNodeAdress;
				hash.insert(newNodeNum,newNodeName,newNodeAdress);
				break;
			case(2):
				cout<<"Выбрано удаление элемента\nВведите номер элемента: "; 
				cin>>newNodeNum;
				hash.erase(newNodeNum);
				break;
			case(3):
				cout<<"Выбран поиск элемента\nВведите номер элемента: "; 
				cin>>newNodeNum;
				cout<<"Найденный элемент: "<<endl;
				hash.find(newNodeNum);
				break;
			case(4):
				cout<<"Выбран вывод всех значений"<<endl; 
				hash.display();
				break;
			case(5):
				return 0;	
				break;
			default:
				cout<<"Некорректные данные";
				break;
			}
		}
	}
}
