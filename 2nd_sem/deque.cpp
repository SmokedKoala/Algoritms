#include <iostream>
#include <bits/stdc++.h>
#include <Windows.h>
#include <string>

using namespace std;

//структура ЛДС - дек
struct Node {
public:
	int number;
	string firstName;
	string lastName;
	struct Node *next; // указатель на следующий элемент в ЛДС
	struct Node *prev; // указатель на предыдущий элемент в ЛДС
	Node(){}
};

//добавить элемент в начало дека (слева)
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

//добавить элемент в конец дека (справа)
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

//удаление заданного элемента
void deleteNode(struct Node **head_ref, struct Node *del) {
	//если список пустой
	if (*head_ref == NULL || del == NULL)
		return;

	//сметсить указатель на первый элемент списка, если его требуется удалить
	if (*head_ref == del)
		*head_ref = del->next;

	if (del->next != NULL)
		del->next->prev = del->prev;

	if (del->prev != NULL)
		del->prev->next = del->next;

	//удаление
	free(del);
}

//удаление одного или всех вхождений заданного элемента
void deleteByNumber(struct Node **head_ref, int x, bool all) {
	//если список пустой
	if ((*head_ref) == NULL)
		return;

	struct Node *current = *head_ref;
	struct Node *next;

	//проход по списку
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

//вывод на экран текущего ЛДС слева направо
void printList(struct Node *head) {
	if (head == NULL)
		cout << "ЛДС пуст";

	while (head != NULL) {
		cout << head->number << " " << head->firstName << " " << head->lastName << endl;
		head = head->next;
	}
}

//вывод на экран текущего ЛДС справа налево
void reversePrint(struct Node **head_ref) {
	struct Node *tail = *head_ref;

	//поиск конца ЛДС
	while (tail->next != NULL) {
		tail = tail->next;
	}

	// проход по списку с конца и вывод информации на каждой итерации
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

	cout<< "Практическая работа №5. Дек. Азаров Константин, ИКБО-02-19"<< endl;

	const int amountOfNodes = 10;
	string userLN, userFN;
	int numToDelete, userNum;

	struct Node *head = NULL;

	cout << "Введите 10 элементов дека: " << endl;

	for(int i = 0; i<amountOfNodes; i++) {
		cin >> userNum >> userFN >> userLN;
		append(&head, userNum, userFN, userLN);
	}

	cout<< endl;
	cout << "Список команд:\n" << "1) добавить элемент" << endl << "2) удалить элемент" << endl
		 << "3)вывести дек" << endl << "0)выход из программы" << endl;
	cout << endl << "Выбранная команда: ";

	int num, subNum, subSubNum;
	cin >> num;
	do {
		cout << endl;
		switch (num) {
			case 1:
				cout << "Добавить элемент: 1)в начало дека (слева), 2)в конец дека (справа)\n";
				cout << endl << "Выбранная команда: ";
				cin >> subNum;
				cout<< endl;
				switch (subNum) {
					case 1:
						cout << "Введите элемент, который нужно добавить в начало списка:" << endl;
						cin >> userNum >> userFN >> userLN;
						push(&head, userNum, userFN, userLN);
						break;
						case 2:
						cout << "Введите элемент, который нужно добавить в конец списка:" << endl;
						cin >> userNum >> userFN >> userLN;
						append(&head, userNum, userFN, userLN);
						break;
					default:
						cout << "Пожалуйста, введите корректное число";
						break;
				}
				break;
			case 2:
				cout << "Удалить элемент: 1)заданный\n";
				cout << endl << "Выбранная команда: ";
				cin >> subNum;
				cout<< endl;
				switch (subNum) {
					case 1:
						cout << "Заданный элемент: 1)первое вхождение, 2)все вхождения\n";
						cout << endl << "Выбранная команда: ";
						cin >> subSubNum;
						cout<< endl << "Введите номер элемента, который надо удалить:" << endl;
						cin >> numToDelete;
						switch (subSubNum) {
							case 1:
								deleteByNumber(&head, numToDelete, false);
								break;
							case 2:
								deleteByNumber(&head, numToDelete, true);
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
				cout << "Вывести дек: 1)проход слева направо, 2)проход справа налево\n";
				cout << endl << "Выбранная команда: ";
				cin >> subNum;
				cout << endl << "Дек:" << endl;
				switch (subNum) {
					case 1:
						printList(head);
						break;
					case 2:
						reversePrint(&head);
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
		cout<< endl;
		cout << "Список команд:\n" << "1) добавить элемент" << endl << "2) удалить элемент" << endl
		 << "3)вывести дек" << endl << "0)выход из программы" << endl;
		cout << endl << "Новая команда: ";
		cin >> num;
	} while (num != 0);

	return 0;
}

/*
1 Казимир Малевич
2 Валентин Серов
3 Карл Брюллов
4 Архип Куинджи
5 Иван Айвазовский
6 Иван Шишкин
7 Исаак Левитан
8 Эдуард Мане
9 Илья Репин
10 Михаил Врубель

66 Джексон Поллок
33 Поль Гоген
8 Клод Моне
*/
