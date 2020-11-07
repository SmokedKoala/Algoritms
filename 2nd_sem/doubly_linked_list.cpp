#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct Node {                //��������� ����� ������ 
	int value;          //������������ ��������
	Node* next, * prev;      //��������� �� ��������� � ���������� ��������
};

struct LDS {
	Node* head = nullptr;     //������������� ������ � ����� ������, ������� ��� 
	Node* tail = nullptr;
	int count = 0;

	int push()
	{
		Node* search = new Node;
		cout << "������� �������, ����� �������� ���������� �������� �����: ";
		cin >> search->value;

		Node* el = new Node;
		cout << "������� ����� �������: ";
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
				cout << "������� ������� ��������\n";
				return i;
			}
			else
				fl = fl->next;
		}

		cout << "������� � ������� " << search->value << " �� ������\n";
		return -1;
	}

	void push_back(bool flag) {

		Node* element = new Node; //��������� ������ ��� ����� ������� ���������
		if (flag) cout << "������� �������, ������� ���������� �������� � ����� ���: ";
		cin >> element->value;  //��������� �������� � ���������
		count++;
		if (!head) {          //���� ������ ����
			head = element;       //�.� ������� ������������, 
			tail = head;      //�� �������� � ������� � �������
		}
		else {
			element->prev = tail; //���������� ������� ������ ������������ ������������, ����� ���������(�������)
			tail->next = element; //��������� ������� �� ������� ��� ����������� ������� ������
			tail = element;       //������������ �������� ������� ������
		}
		if (flag) cout << "������� ������� �������� � ����� ���" << endl;
	}

	void push_front() {

		Node* element = new Node;
		cout << "������� �������, ������� ���������� �������� � ������ ���: ";
		cin >> element->value;
		count++;
		if (!head)
		{
			head = element;
			tail = head;
		}
		else
		{
			element->next = head;      //��������� ������� �� ����������� ��������� �������� �����
			head->prev = element;      //����� ������� ��������� ����������� �������
			head = element;           //������������ �������� ������� ������
		}
		cout << "������� ������� �������� � ������ ���" << endl;
	}

	void pop_back() {
		if (count != 0) {               //���� ��� �� ������
			cout << tail->value << endl;
			if (count > 1) {         //���� � ��� ��������� ������ ������ ��������
				Node* element = tail;     //��������� �� ��, ��� ����� �������������� �����
				tail = tail->prev; //����������� ������ ������ ����������� ��������
				tail->next = nullptr;     //��������� �� ��, ��� �� ��������� �����
				delete element;     //������� ������ �����
				count--;        //��������� ������ ���
			}
			else {               //���� � ��� ��������� ����� ���� �������
				head = tail = 0;        //����������� ��� �������� ����
				count--;        //��������� ������ ���
			}
			cout << "��������� ������� ��� �����\n";
		}
		else cout << "��� ����, ������� ������" << endl;
	}

	void pop_front() {
		if (count != 0) {
			cout << head->value << endl;
			if (head->next) {          //���� � ��� ������ ������ �������� 
				Node* element = head; //��������� �� ��, ��� ����� ������������ ������
				head = head->next;	//����������� ������ ������ ���������� �� ������ ������� �������� 
				head->prev = nullptr;  //��������� �� ��, ��� ����� ������� �����
				delete element;     //������� ������ ������
				count--;			//��������� ������ ���
			}
			else if (head == tail) {    //���� ������� ���� � ���
				head->next = nullptr;  //���������, ��� �� ������� �����
				head = nullptr;       //��������� �� ��, ��� ������ ���� �����
				delete head;        //������� ������������ �������
				count = 0;        //����������� ���� ������� ���
			}
			cout << "������ ������� ��� �����\n";
		}
		else cout << "��� ����, ������� ������" << endl;
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

		cout << "�������� ������ �������\n";
	}
};

void menu(LDS* l)
{
	cout << "������������ ������ �4 �������� ���������� ������. ������ ����������, ����-02-19"<< endl;
	cout << "������� 10 ��������� ��� ���������� � �����:\n";
	for (int i = 0; i < 10; i++)
		l->push_back(false);
	cout << "\n";

	int n = 0;
	cout << "������ ������:\n";
	string menu_bar =  "1) ���������� ��������  2) �������� �������� 3) ����� ��� �� ����� 0) ����� �� ���������\n\n";
	while (true)
	{
		Node* search = new Node;
		cout<<menu_bar;
		cout << "����� �������: ";
		cin >> n;
		string value;
		switch (n)
		{
		case 0:
			exit(0);
		case 1:
			cout << "\t1) � ������ ���\n";
			cout << "\t2) � ����� ���\n";
			cout << "\t3) ����� ��������� ��������\n";
			cout << "��� �����: ";
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
			cout << "\t1) ������ �������\n";
			cout << "\t2) ��������� �������\n";
			cout << "��� �����: ";
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
			cout << "\t1) �� �������\n";
			cout << "\t2) � �������� �������\n";
			cout << "��� �����: ";
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
