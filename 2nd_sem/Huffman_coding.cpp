#include <iostream> 
#include <cstdlib> 
#include <vector>
#include <Windows.h>
#include <string>
using namespace std; 


struct Element {
	char data;
	string num;
	int freq;
};
vector <Element> elements_array;


// Этой константы можно избежать, явно рассчитав высоту дерева Хаффмана
#define MAX_TREE_HT 100 

// узел дерева Хаффмана
struct MinHeapNode { 
	// один из вводимых символов
	char data; 
	// Частота появления этого символа
	unsigned freq; 
	// Левый и правыый наследники узла
	struct MinHeapNode *left, *right; 
}; 

// A Min Heap: набор узлов минимальной кучи (или дерева Хаффмана)
struct MinHeap { 
	// текущий размер минимальной кучи 
	unsigned size; 
	//  объём min heap 
	unsigned capacity; 
	// Массив указателей узлов минимальной кучи 
	struct MinHeapNode** array; 
}; 

// Служебная функция выделяет новый узел минимальной кучи с заданным символом и частотой этого символа
struct MinHeapNode* newNode(char data, unsigned freq) 
{ 
	struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode)); 
	temp->left = temp->right = NULL; 
	temp->data = data; 
	temp->freq = freq; 
	return temp; 
} 

// Служебная функция для создания минимальной кучи заданного объёма 
struct MinHeap* createMinHeap(unsigned capacity) { 
	struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap)); 
	// текущий размер 0 
	minHeap->size = 0; 
	minHeap->capacity = capacity; 
	minHeap->array 	= (struct MinHeapNode**)malloc(minHeap-> capacity * sizeof(struct MinHeapNode*)); 
	return minHeap; 
} 

// Служебная функция для замены двух узлов минимальных куч
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) { 
	struct MinHeapNode* t = *a; 
	*a = *b; 
	*b = t; 
} 

// Стандартная функция minHeapify
void minHeapify(struct MinHeap* minHeap, int idx) { 
	int smallest = idx; 
	int left = 2 * idx + 1; 
	int right = 2 * idx + 2; 
	if (left < minHeap->size && minHeap->array[left]-> freq < minHeap->array[smallest]->freq) 
		smallest = left; 
	if (right < minHeap->size && minHeap->array[right]-> freq < minHeap->array[smallest]->freq) 
		smallest = right; 
	if (smallest != idx) { 
		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]); 
		minHeapify(minHeap, smallest); 
	} 
} 

// Служебная функция для проверки того, равен ли размер кучи 1 или нет
int isSizeOne(struct MinHeap* minHeap) { 

	return (minHeap->size == 1); 
} 

// Стандартная функция для извлечения узла минимального значения из кучи
struct MinHeapNode* extractMin(struct MinHeap* minHeap) 
{ 
	struct MinHeapNode* temp = minHeap->array[0]; 
	minHeap->array[0] 	= minHeap->array[minHeap->size - 1]; 
	--minHeap->size; 
	minHeapify(minHeap, 0); 
	return temp; 
} 

// Служебная функция для вставки нового узла в минимальную кучу
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) { 
	++minHeap->size; 
	int i = minHeap->size - 1; 
	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) { 
		minHeap->array[i] = minHeap->array[(i - 1) / 2]; 
		i = (i - 1) / 2; 
	} 
	minHeap->array[i] = minHeapNode; 
} 

// Стандартная функция для построения минимальной кучи
void buildMinHeap(struct MinHeap* minHeap) { 
	int n = minHeap->size - 1; 
	int i; 
	for (i = (n - 1) / 2; i >= 0; --i) 
		minHeapify(minHeap, i); 
} 

// Служебная функция для печати массива размера n
string printArr(int arr[], int n) { 
	string code; 
	for (int i = 0; i < n; ++i) 
//		cout<< ; 
		code+=to_string(arr[i]);
	cout<<code<<"\n"; 
	return code;
} 

// Служебная функция для проверки того, является ли этот узел листовым
int isLeaf(struct MinHeapNode* root) { 
	return !(root->left) && !(root->right); 
} 

// Создает минимальную кучу емкости, равную размеру, и вставляет все символы из data[] в минимальную кучу. Изначально размер минимальной кучи равен емкости
struct MinHeap* createAndBuildMinHeap(vector <Element> elements_array, int size) { 
	struct MinHeap* minHeap = createMinHeap(size); 
	for (int i = 0; i < size; ++i) 
		minHeap->array[i] = newNode(elements_array[i].data, elements_array[i].freq); 
	minHeap->size = size; 
	buildMinHeap(minHeap); 
	return minHeap; 
} 

// основная функция для построения дерева Хаффмана
struct MinHeapNode* buildHuffmanTree(vector <Element> elements_array, int size) { 
	struct MinHeapNode *left, *right, *top; 
	// Шаг 1: Создайте минимальную кучу емкости, равную размеру. Изначально существуют узлы, равные по размеру.
	struct MinHeap* minHeap = createAndBuildMinHeap(elements_array, size); 
	// Повторяйте, пока размер кучи не станет 1 
	while (!isSizeOne(minHeap)) { 
		// Шаг 2: извлеките два элемента с минимальной частотой появления из минимальной кучи 
		left = extractMin(minHeap); 
		right = extractMin(minHeap); 
		// Шаг 3: Создайте новый внутренний узел с частотой, равной сумме частот двух узлов.
		// Сделайте два извлеченных узла левыми и правыми дочерними элементами этого нового узла.
		// Добавьте этот узел в минимальную кучу ' $ ' - это специальное значение для внутренних узлов, которое не используется 
		top = newNode('$', left->freq + right->freq); 
		top->left = left; 
		top->right = right; 
		insertMinHeap(minHeap, top); 
	} 
	// Шаг 4: оставшийся узел является корневым узлом, и дерево завершено.
	return extractMin(minHeap); 
} 

// Выводит коды Хаффмана из корня дерева Хаффмана. Он использует arr[] для хранения кодов
void printCodes(struct MinHeapNode* root, int arr[], int top) { 
	// Присвоить 0 левому элементу и повторять 
	if (root->left) { 
		arr[top] = 0; 
		printCodes(root->left, arr, top + 1); 
	} 
	// Присвоить 1 правому элементу и повторять
	if (root->right) { 
		arr[top] = 1; 
		printCodes(root->right, arr, top + 1); 
	} 
	// Если это листовой узел, то он содержит один из входных символов, выведите символ и его код из arr[]
	if (isLeaf(root)) { 
//		Element temp;
//		temp.data = root->data;
		cout<<"'"<< root->data <<"': "; 
		for (int i =0; i< elements_array.size();i++)
			if (elements_array[i].data==root->data)
				elements_array[i].num =printArr(arr, top); 	
//		elements_array.push_back(temp);
	} 
} 

// Основная функция, которая строит дерево Хаффмана и печатает коды, проходя по построенному дереву Хаффмана
void HuffmanCodes(vector <Element> elements_array , int size) { 
	// Конструктор дерева Хаффмана
	struct MinHeapNode* root = buildHuffmanTree(elements_array, size); 
	// вывести коды Хаффмана, используя дерево Хаффмана
	int arr[MAX_TREE_HT], top = 0; 
	cout<<"Полученная кодировка символов: "<<endl;
	printCodes(root, arr, top); 
} 

void calc_char_number(char value){
	for (int i=0;i<elements_array.size();i++){
		if(elements_array[i].data==value){
			elements_array[i].freq=elements_array[i].freq+1;
			return;
		}
	}
	Element temp;
	temp.data=value;
	temp.freq=1;
	elements_array.push_back(temp);
}
	
 
void app(){
	string choice;
	
	string ch;
	string first_str;
	cout<<"Введите строку"<<endl;
	while (cin>>ch)
		{
			first_str+=ch+" ";
			for (int i =0; i< ch.size();i++)
				calc_char_number(ch[i]);
			if (isspace(cin.peek()))
			{
				if (cin.get()=='\n')
					break;
			}
			calc_char_number(' ');			
		} 
	cout<<"Частота появления символов: "<<endl;
	for(int i =0; i <elements_array.size();i++)
		cout<<"'"<<elements_array[i].data<<"': "<<elements_array[i].freq<<endl;
	HuffmanCodes(elements_array, elements_array.size()); 
	cout<<"Полученная строка: ";
	for (int i = 0; i< first_str.size();i++){
		for (int j=0;j<elements_array.size();j++){
			if (first_str[i]==elements_array[j].data)
				cout<<elements_array[j].num;
		}
	}	
	elements_array.clear();	
	cout<<endl<<"Повторить ввод? (да/нет): ";
	cin>>choice;
	if (choice == "да")
		app();
	if (choice =="нет"){
		cout<<"Вы уверены? (завершить/нет)";
		cin>>choice;
		if (choice == "нет")
			app();
		if (choice =="завершить")
			return;
	}
}
int main() 
{ 
	setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	cout<<"Практическая работа №10. код Хаффмана. Азаров Константин, ИКБО-02-19"<<endl;
	app();
	return 0; 
} 

