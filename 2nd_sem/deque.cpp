#include <iostream>
#include <bits/stdc++.h>
#include <Windows.h>
#include <string>

using namespace std;

//��������� ��� - ���
struct Node {
public:
	int number;
	string firstName;
	string lastName;
	struct Node *next; // ��������� �� ��������� ������� � ���
	struct Node *prev; // ��������� �� ���������� ������� � ���
	Node(){}
};

//�������� ������� � ������ ���� (�����)
void push(struct Node **head_ref, int new_num, string fN, string lN) {
	struct Node* new_node = new Node();

	new_node->number = new_num;
	new_node->firstName = fN;
	new_node->lastName = lN;

	new_node->prev = NULL;

	new_node->next = (*head_ref);

	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	(*head_ref) = new_node;
}

//�������� ������� � ����� ���� (������)
void append(struct Node** head_ref, int new_num, string fN, string lN)
{
	struct Node* new_node = new Node();

	struct Node* last = *head_ref;

	new_node->number = new_num;
	new_node->firstName = fN;
	new_node->lastName = lN;

	new_node->next = NULL;

	if (*head_ref == NULL) {
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new_node;

	new_node->prev = last;
}

//�������� ��������� ��������
void deleteNode(struct Node **head_ref, struct Node *del) {
	//���� ������ ������
	if (*head_ref == NULL || del == NULL)
		return;

	//�������� ��������� �� ������ ������� ������, ���� ��� ��������� �������
	if (*head_ref == del)
		*head_ref = del->next;

	if (del->next != NULL)
		del->next->prev = del->prev;

	if (del->prev != NULL)
		del->prev->next = del->next;

	//��������
	free(del);
}

//�������� ������ ��� ���� ��������� ��������� ��������
void deleteByNumber(struct Node **head_ref, int x, bool all) {
	//���� ������ ������
	if ((*head_ref) == NULL)
		return;

	struct Node *current = *head_ref;
	struct Node *next;

	//������ �� ������
	while (current != NULL) {

		if (current->number == x) {
			next = current->next;
			deleteNode(head_ref, current);
			if (!all)
				return;
			current = next;
		} else
			current = current->next;
	}
}

//����� �� ����� �������� ��� ����� �������
void printList(struct Node *head) {
	if (head == NULL)
		cout << "��� ����";

	while (head != NULL) {
		cout << head->number << " " << head->firstName << " " << head->lastName << endl;
		head = head->next;
	}
}

//����� �� ����� �������� ��� ������ ������
void reversePrint(struct Node **head_ref) {
	struct Node *tail = *head_ref;

	//����� ����� ���
	while (tail->next != NULL) {
		tail = tail->next;
	}

	// ������ �� ������ � ����� � ����� ���������� �� ������ ��������
	while (tail != *head_ref) {
		cout << tail->number << " " << tail->firstName << " " << tail->lastName << endl;
		tail = tail->prev;
	}
	cout << tail->number << " " << tail->firstName << " " << tail->lastName << endl;
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout<< "������������ ������ �5. ���. ������ ����������, ����-02-19"<< endl;

	const int amountOfNodes = 10;
	string userLN, userFN;
	int numToDelete, userNum;

	struct Node *head = NULL;

	cout << "������� 10 ��������� ����: " << endl;

	for(int i = 0; i<amountOfNodes; i++) {
		cin >> userNum >> userFN >> userLN;
		append(&head, userNum, userFN, userLN);
	}

	cout<< endl;
	cout << "������ ������:\n" << "1) �������� �������" << endl << "2) ������� �������" << endl
		 << "3)������� ���" << endl << "0)����� �� ���������" << endl;
	cout << endl << "��������� �������: ";

	int num, subNum, subSubNum;
	cin >> num;
	do {
		cout << endl;
		switch (num) {
			case 1:
				cout << "�������� �������: 1)� ������ ���� (�����), 2)� ����� ���� (������)\n";
				cout << endl << "��������� �������: ";
				cin >> subNum;
				cout<< endl;
				switch (subNum) {
					case 1:
						cout << "������� �������, ������� ����� �������� � ������ ������:" << endl;
						cin >> userNum >> userFN >> userLN;
						push(&head, userNum, userFN, userLN);
						break;
						case 2:
						cout << "������� �������, ������� ����� �������� � ����� ������:" << endl;
						cin >> userNum >> userFN >> userLN;
						append(&head, userNum, userFN, userLN);
						break;
					default:
						cout << "����������, ������� ���������� �����";
						break;
				}
				break;
			case 2:
				cout << "������� �������: 1)��������\n";
				cout << endl << "��������� �������: ";
				cin >> subNum;
				cout<< endl;
				switch (subNum) {
					case 1:
						cout << "�������� �������: 1)������ ���������, 2)��� ���������\n";
						cout << endl << "��������� �������: ";
						cin >> subSubNum;
						cout<< endl << "������� ����� ��������, ������� ���� �������:" << endl;
						cin >> numToDelete;
						switch (subSubNum) {
							case 1:
								deleteByNumber(&head, numToDelete, false);
								break;
							case 2:
								deleteByNumber(&head, numToDelete, true);
								break;
							default:
								cout << "����������, ������� ���������� �����";
								break;
						}
						break;
					default:
						cout << "����������, ������� ���������� �����";
						break;
				}
				break;
			case 3:
				cout << "������� ���: 1)������ ����� �������, 2)������ ������ ������\n";
				cout << endl << "��������� �������: ";
				cin >> subNum;
				cout << endl << "���:" << endl;
				switch (subNum) {
					case 1:
						printList(head);
						break;
					case 2:
						reversePrint(&head);
						break;
					default:
						cout << "����������, ������� ���������� �����";
						break;
				}
				break;
			default:
				cout << "����������, ������� ���������� �����";
				break;
		}
		cout<< endl;
		cout << "������ ������:\n" << "1) �������� �������" << endl << "2) ������� �������" << endl
		 << "3)������� ���" << endl << "0)����� �� ���������" << endl;
		cout << endl << "����� �������: ";
		cin >> num;
	} while (num != 0);

	return 0;
}

/*
1 ������� �������
2 �������� �����
3 ���� �������
4 ����� �������
5 ���� �����������
6 ���� ������
7 ����� �������
8 ������ ����
9 ���� �����
10 ������ �������

66 ������� ������
33 ���� �����
8 ���� ����
*/
