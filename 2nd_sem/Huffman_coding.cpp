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
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) { 
	struct MinHeap* minHeap = createMinHeap(size); 
	for (int i = 0; i < size; ++i) 
		minHeap->array[i] = newNode(data[i], freq[i]); 
	minHeap->size = size; 
	buildMinHeap(minHeap); 
	return minHeap; 
} 

// �������� ������� ��� ���������� ������ ��������
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) { 
	struct MinHeapNode *left, *right, *top; 
	// ��� 1: �������� ����������� ���� �������, ������ �������. ���������� ���������� ����, ������ �� �������.
	struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size); 
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
		Element temp;
		temp.data = root->data;
		cout<< root->data <<": "; 
		temp.num=printArr(arr, top); 
		elements_array.push_back(temp);
	} 
} 

// �������� �������, ������� ������ ������ �������� � �������� ����, ������� �� ������������ ������ ��������
void HuffmanCodes(char data[], int freq[], int size) { 
	// ����������� ������ ��������
	struct MinHeapNode* root = buildHuffmanTree(data, freq, size); 
	// ������� ���� ��������, ��������� ������ ��������
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
	cout<<"������������ ������ �10. ��� ��������. ������ ����������, ����-02-19"<<endl;
	string ch;
	string first_str;
	arr_vec.push_back(' ');	
	freq_vec.push_back(2);
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

