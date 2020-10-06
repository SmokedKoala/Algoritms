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
    Facility(int number, string name, string adress) {
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
    	table = new list<Facility*>[BUCKET_NUM];
	};  
	// Функция вставки элемента
    int insert(int num, string name, string adress); 
     // Функция удаления элемента
    bool erase(int num);
    // Функция поиска элемента
    Node* find(int num); 
    int hashFunction(int x); // Хеш-функция
    void display(); // Функция вывода содержимого хеш-таблицы
};


int Hash::hashFunction(int x) {
    return (x % BUCKET_NUM);
}

int Hash::insert(int num, string name, string fou)
{
    int index = hashFunction(num);
    Facility* new_f = new Facility(num, name, fou);
    table[index].push_back(new_f);
    return index;
}

bool Hash::erase(int num)
{
    int index = hashFunction(num);

    for (Facility* f : table[index]) {
        if (f->number == num) {
            table[index].remove(f);
            return true;
        }
    }
    return false;
}

Facility* Hash::find(int num){
    int index = hashFunction(num);

    for (Facility* f : table[index]) {
        if (f->number == num) {
            return f;
        }
    }
    return NULL;
}
 
void Hash::display() {
    for (int i = 0; i < BUCKET_NUM; i++) {
        cout << i;
        for (Facility* x : table[i])
            cout << " --> " << x->number;
        cout << endl;
    }
}




int main() 
{ 
	setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    cout << "Практическая работа №3 Хеширование - прямой доступ к данным. Азаров Константин, ИКБО-02-19"
         << endl;
    string menuChoice="\n1)Вставка элемента\n2)Удаление элемента\n3)Поиск элемента\n4)Вывод данных\n5)Выход\n";
    int commandNum=0;
    string newNodeData = "";
	// array that contains keys to be mapped 
//	int a[] = {15, 11, 27, 8, 12}; 
//	int n = sizeof(a)/sizeof(a[0]); 

// insert the keys into the hash table 
	Hash h(0); // 7 is count of buckets in 
			// hash table 
//for (int i = 0; i < n; i++) 
//	h.insertItem(a[i]); 

	while(true){
    	commandNum=0;
    	while(commandNum !=6){
    		cout<<menuChoice;
			cin>>commandNum;
			switch(commandNum){
			case(1):
				cout<<"Выбрана вставка элемента\nВведите элемент: ";
				cin>>newNodeData;
				h.insertItem(newNodeData);
				break;
			case(2):
				cout << "Выбрано удаление элемента\nВведите элемент: "; 
				cin>>newNodeData;
				h.deleteItem(newNodeData);
				break;
			case(3):
				cout << "\nВыбран поиск элемента\n"; 

				break;
			case(4):
				cout << "\nВыбран вывод данных\n"; 
				h.displayHash(); 
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

