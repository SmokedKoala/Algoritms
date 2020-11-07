#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct Node {                //структура звена списка 
	int value;          //передаваемое значение
	Node* next, * prev;      //указатели на следующий и предыдущий элементы
};

struct LDS {
	Node* head = nullptr;     //инициализация начала и конца списка, размера ЛДС 
	Node* tail = nullptr;
	int count = 0;

	int push()
	{
		Node* search = new Node;
		cout << "Введите элемент, после которого необходимо добавить новый: ";
		cin >> search->value;

		Node* el = new Node;
		cout << "Введите новый элемент: ";
		cin >> el->value;

		Node* fl = head;
		for (int i = 0; i < count; i++)
		{
			if (fl->value == search->value)
			{
				Node* second = fl->next;
				fl->next = el;
				el->next = second;
				count++;
				cout << "Элемент успешно добавлен\n";
				return i;
			}
			else
				fl = fl->next;
		}

		cout << "Элемент с номером " << search->value << " не найден\n";
		return -1;
	}

	void push_back(bool flag) {

		Node* element = new Node; //выделение памяти под новый элемент структуры
		if (flag) cout << "Введите элемент, который необходимо добавить в конец ЛДС: ";
		cin >> element->value;  //добавляем значение в структуру
		count++;
		if (!head) {          //если список пуск
			head = element;       //т.к элемент единственный, 
			tail = head;      //он является и хвостом и головой
		}
		else {
			element->prev = tail; //предыдущий элемент списка относительно добавленного, будет последним(хвостом)
			tail->next = element; //следующий элемент за хвостом это добавляемый элемент списка
			tail = element;       //присваивание элементу статуса хвоста
		}
		if (flag) cout << "Элемент успешно добавлен в конец ЛДС" << endl;
	}

	void push_front() {

		Node* element = new Node;
		cout << "Введите элемент, который необходимо добавить в начало ЛДС: ";
		cin >> element->value;
		count++;
		if (!head)
		{
			head = element;
			tail = head;
		}
		else
		{
			element->next = head;      //следующий элемент за добавляемым элементом является хвост
			head->prev = element;      //перед головой находится добавляемый элемент
			head = element;           //присваивание элементу статуса головы
		}
		cout << "Элемент успешно добавлен в начало ЛДС" << endl;
	}

	void pop_back() {
		if (count != 0) {               //если ЛДС не пустой
			cout << tail->value << endl;
			if (count > 1) {         //если в ЛДС находится больше одного элемента
				Node* element = tail;     //указываем на то, что будет использоваться хвост
				tail = tail->prev; //присваиваем статус хвоста предыдущему элементу
				tail->next = nullptr;     //указываем на то, что за элементом пусто
				delete element;     //удаляем бывший хвост
				count--;        //уменьшаем размер ЛДС
			}
			else {               //если в ЛДС находится всего один элемент
				head = tail = 0;        //присваиваем ему значение ноль
				count--;        //уменьшаем размер ЛДС
			}
			cout << "Последний элемент ЛДС удалён\n";
		}
		else cout << "ЛДС пуст, удалять нечего" << endl;
	}

	void pop_front() {
		if (count != 0) {
			cout << head->value << endl;
			if (head->next) {          //если в ЛДС больше одного элемента 
				Node* element = head; //указываем на то, что будем использовать голову
				head = head->next;	//присваиваем статус головы следующему за бывшей головой элементу 
				head->prev = nullptr;  //указываем на то, что перед головой пусто
				delete element;     //удаляем бывшую голову
				count--;			//уменьшаем размер ЛДС
			}
			else if (head == tail) {    //если элемент один в ЛДС
				head->next = nullptr;  //указываем, что за головой пусто
				head = nullptr;       //указываем на то, что голова тоже пуста
				delete head;        //удаляем единственный элемент
				count = 0;        //присваиваем ноль размеру ЛДС
			}
			cout << "Первый элемент ЛДС удалён\n";
		}
		else cout << "ЛДС пуст, удалять нечего" << endl;
	}

	void print() {
		Node* first = this->head;
		for (int i = 0; i < count; i++)
		{
			cout << first->value << ' ';
			first = first->next;
		}
		cout << endl;
	}

	void print_back() {
		Node* first = this->tail;
		for (int i = count; i > 0; --i)
		{
			cout << first->value << ' ';
			first = first->prev;
		}
		cout << endl;
	}

	~LDS() {
		Node* first;
		for (int i = 0; i < count; i++)
		{
			first = head;
			head = head->next;
			delete first;
		}

		cout << "Удаление прошло успешно\n";
	}
};

void menu(LDS* l)
{
	cout << "Практическая работа №4 Линейный двусвязный список. Азаров Константин, ИКБО-02-19"<< endl;
	cout << "Введите 10 элементов для добавления в конец:\n";
	for (int i = 0; i < 10; i++)
		l->push_back(false);
	cout << "\n";

	int n = 0;
	cout << "Список команд:\n";
	string menu_bar =  "1) Добавление элемента  2) Удаление элемента 3) Вывод ЛДС на экран 0) Выход из программы\n\n";
	while (true)
	{
		Node* search = new Node;
		cout<<menu_bar;
		cout << "Новая команда: ";
		cin >> n;
		string value;
		switch (n)
		{
		case 0:
			exit(0);
		case 1:
			cout << "\t1) В начало ЛДС\n";
			cout << "\t2) В конец ЛДС\n";
			cout << "\t3) После заданного элемента\n";
			cout << "Ваш выбор: ";
			cin >> n;
			switch (n)
			{
			case 1:
				l->push_front();
				break;
			case 2:
				l->push_back(true);
				break;
			case 3:
				l->push();
				break;
			}
			break;
		case 2:
			cout << "\t1) Первый элемент\n";
			cout << "\t2) Последний элемент\n";
			cout << "Ваш выбор: ";
			cin >> n;
			switch (n)
			{
			case 1:
				l->pop_front();
				break;
			case 2:
				l->pop_back();
				break;
			}
			break;
		case 3:
			cout << "\t1) По порядку\n";
			cout << "\t2) В обрятном порядке\n";
			cout << "Ваш выбор: ";
			cin >> n;
			switch (n)
			{
			case 1:
				l->print();
				break;
			case 2:
				l->print_back();
				break;
			}
			break;
		}
		cout << "\n";

	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	LDS* l = new LDS;
	menu(l);
	return 0;
}
