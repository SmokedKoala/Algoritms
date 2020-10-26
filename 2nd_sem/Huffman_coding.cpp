#include <iostream> 
#include <cstdlib> 
#include <vector>
#include <Windows.h>
#include <string>
using namespace std; 

vector <char> arr_vec;
vector<int> freq_vec;

struct Element {
	char data;
	string num;
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
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) { 
	struct MinHeap* minHeap = createMinHeap(size); 
	for (int i = 0; i < size; ++i) 
		minHeap->array[i] = newNode(data[i], freq[i]); 
	minHeap->size = size; 
	buildMinHeap(minHeap); 
	return minHeap; 
} 

// основная функция для построения дерева Хаффмана
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) { 
	struct MinHeapNode *left, *right, *top; 
	// Шаг 1: Создайте минимальную кучу емкости, равную размеру. Изначально существуют узлы, равные по размеру.
	struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size); 
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
		Element temp;
		temp.data = root->data;
		cout<< root->data <<": "; 
		temp.num=printArr(arr, top); 
		elements_array.push_back(temp);
	} 
} 

// Основная функция, которая строит дерево Хаффмана и печатает коды, проходя по построенному дереву Хаффмана
void HuffmanCodes(char data[], int freq[], int size) { 
	// Конструктор дерева Хаффмана
	struct MinHeapNode* root = buildHuffmanTree(data, freq, size); 
	// вывести коды Хаффмана, используя дерево Хаффмана
	int arr[MAX_TREE_HT], top = 0; 
	printCodes(root, arr, top); 
} 

void calc_char_number(char value){
	for (int i=0;i<arr_vec.size();i++){
		if(arr_vec[i]==value){
			freq_vec[i]=freq_vec[i]+1;
			return;
		}
	}
	arr_vec.push_back(value);
	freq_vec.push_back(1);		
}
	
 
int main() 
{ 
	setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	cout<<"Практическая работа №10. код Хаффмана. Азаров Константин, ИКБО-02-19"<<endl;
	string ch;
	string first_str;
	arr_vec.push_back(' ');	
	freq_vec.push_back(2);
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
		} 
	char arr[arr_vec.size()];
	int freq[freq_vec.size()];
	for (int i =0;i<arr_vec.size();i++){
		arr[i]=arr_vec[i];
		freq[i]=freq_vec[i];
	}
//	cout<<first_str<<endl;

	HuffmanCodes(arr, freq, arr_vec.size()); 
//	for (int i=0; i<elements_array.size();i++){
//		cout<<elements_array[i].data<<" "<< elements_array[i].num<<endl;
//	}

	return 0; 
} 

