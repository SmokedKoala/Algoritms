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


// ���� ��������� ����� ��������, ���� ��������� ������ ������ ��������
#define MAX_TREE_HT 100 

// ���� ������ ��������
struct MinHeapNode { 
	// ���� �� �������� ��������
	char data; 
	// ������� ��������� ����� �������
	unsigned freq; 
	// ����� � ������� ���������� ����
	struct MinHeapNode *left, *right; 
}; 

// A Min Heap: ����� ����� ����������� ���� (��� ������ ��������)
struct MinHeap { 
	// ������� ������ ����������� ���� 
	unsigned size; 
	//  ����� min heap 
	unsigned capacity; 
	// ������ ���������� ����� ����������� ���� 
	struct MinHeapNode** array; 
}; 

// ��������� ������� �������� ����� ���� ����������� ���� � �������� �������� � �������� ����� �������
struct MinHeapNode* newNode(char data, unsigned freq) 
{ 
	struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode)); 
	temp->left = temp->right = NULL; 
	temp->data = data; 
	temp->freq = freq; 
	return temp; 
} 

// ��������� ������� ��� �������� ����������� ���� ��������� ������ 
struct MinHeap* createMinHeap(unsigned capacity) { 
	struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap)); 
	// ������� ������ 0 
	minHeap->size = 0; 
	minHeap->capacity = capacity; 
	minHeap->array 	= (struct MinHeapNode**)malloc(minHeap-> capacity * sizeof(struct MinHeapNode*)); 
	return minHeap; 
} 

// ��������� ������� ��� ������ ���� ����� ����������� ���
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) { 
	struct MinHeapNode* t = *a; 
	*a = *b; 
	*b = t; 
} 

// ����������� ������� minHeapify
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

// ��������� ������� ��� �������� ����, ����� �� ������ ���� 1 ��� ���
int isSizeOne(struct MinHeap* minHeap) { 

	return (minHeap->size == 1); 
} 

// ����������� ������� ��� ���������� ���� ������������ �������� �� ����
struct MinHeapNode* extractMin(struct MinHeap* minHeap) 
{ 
	struct MinHeapNode* temp = minHeap->array[0]; 
	minHeap->array[0] 	= minHeap->array[minHeap->size - 1]; 
	--minHeap->size; 
	minHeapify(minHeap, 0); 
	return temp; 
} 

// ��������� ������� ��� ������� ������ ���� � ����������� ����
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) { 
	++minHeap->size; 
	int i = minHeap->size - 1; 
	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) { 
		minHeap->array[i] = minHeap->array[(i - 1) / 2]; 
		i = (i - 1) / 2; 
	} 
	minHeap->array[i] = minHeapNode; 
} 

// ����������� ������� ��� ���������� ����������� ����
void buildMinHeap(struct MinHeap* minHeap) { 
	int n = minHeap->size - 1; 
	int i; 
	for (i = (n - 1) / 2; i >= 0; --i) 
		minHeapify(minHeap, i); 
} 

// ��������� ������� ��� ������ ������� ������� n
string printArr(int arr[], int n) { 
	string code; 
	for (int i = 0; i < n; ++i) 
//		cout<< ; 
		code+=to_string(arr[i]);
	cout<<code<<"\n"; 
	return code;
} 

// ��������� ������� ��� �������� ����, �������� �� ���� ���� ��������
int isLeaf(struct MinHeapNode* root) { 
	return !(root->left) && !(root->right); 
} 

// ������� ����������� ���� �������, ������ �������, � ��������� ��� ������� �� data[] � ����������� ����. ���������� ������ ����������� ���� ����� �������
struct MinHeap* createAndBuildMinHeap(vector <Element> elements_array, int size) { 
	struct MinHeap* minHeap = createMinHeap(size); 
	for (int i = 0; i < size; ++i) 
		minHeap->array[i] = newNode(elements_array[i].data, elements_array[i].freq); 
	minHeap->size = size; 
	buildMinHeap(minHeap); 
	return minHeap; 
} 

// �������� ������� ��� ���������� ������ ��������
struct MinHeapNode* buildHuffmanTree(vector <Element> elements_array, int size) { 
	struct MinHeapNode *left, *right, *top; 
	// ��� 1: �������� ����������� ���� �������, ������ �������. ���������� ���������� ����, ������ �� �������.
	struct MinHeap* minHeap = createAndBuildMinHeap(elements_array, size); 
	// ����������, ���� ������ ���� �� ������ 1 
	while (!isSizeOne(minHeap)) { 
		// ��� 2: ��������� ��� �������� � ����������� �������� ��������� �� ����������� ���� 
		left = extractMin(minHeap); 
		right = extractMin(minHeap); 
		// ��� 3: �������� ����� ���������� ���� � ��������, ������ ����� ������ ���� �����.
		// �������� ��� ����������� ���� ������ � ������� ��������� ���������� ����� ������ ����.
		// �������� ���� ���� � ����������� ���� ' $ ' - ��� ����������� �������� ��� ���������� �����, ������� �� ������������ 
		top = newNode('$', left->freq + right->freq); 
		top->left = left; 
		top->right = right; 
		insertMinHeap(minHeap, top); 
	} 
	// ��� 4: ���������� ���� �������� �������� �����, � ������ ���������.
	return extractMin(minHeap); 
} 

// ������� ���� �������� �� ����� ������ ��������. �� ���������� arr[] ��� �������� �����
void printCodes(struct MinHeapNode* root, int arr[], int top) { 
	// ��������� 0 ������ �������� � ��������� 
	if (root->left) { 
		arr[top] = 0; 
		printCodes(root->left, arr, top + 1); 
	} 
	// ��������� 1 ������� �������� � ���������
	if (root->right) { 
		arr[top] = 1; 
		printCodes(root->right, arr, top + 1); 
	} 
	// ���� ��� �������� ����, �� �� �������� ���� �� ������� ��������, �������� ������ � ��� ��� �� arr[]
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

// �������� �������, ������� ������ ������ �������� � �������� ����, ������� �� ������������ ������ ��������
void HuffmanCodes(vector <Element> elements_array , int size) { 
	// ����������� ������ ��������
	struct MinHeapNode* root = buildHuffmanTree(elements_array, size); 
	// ������� ���� ��������, ��������� ������ ��������
	int arr[MAX_TREE_HT], top = 0; 
	cout<<"���������� ��������� ��������: "<<endl;
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
	cout<<"������� ������"<<endl;
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
	cout<<"������� ��������� ��������: "<<endl;
	for(int i =0; i <elements_array.size();i++)
		cout<<"'"<<elements_array[i].data<<"': "<<elements_array[i].freq<<endl;
	HuffmanCodes(elements_array, elements_array.size()); 
	cout<<"���������� ������: ";
	for (int i = 0; i< first_str.size();i++){
		for (int j=0;j<elements_array.size();j++){
			if (first_str[i]==elements_array[j].data)
				cout<<elements_array[j].num;
		}
	}	
	elements_array.clear();	
	cout<<endl<<"��������� ����? (��/���): ";
	cin>>choice;
	if (choice == "��")
		app();
	if (choice =="���"){
		cout<<"�� �������? (���������/���)";
		cin>>choice;
		if (choice == "���")
			app();
		if (choice =="���������")
			return;
	}
}
int main() 
{ 
	setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	cout<<"������������ ������ �10. ��� ��������. ������ ����������, ����-02-19"<<endl;
	app();
	return 0; 
} 

