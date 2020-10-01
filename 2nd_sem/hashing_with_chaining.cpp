// CPP program to implement hashing with chaining 
#include<bits/stdc++.h> 
using namespace std; 

class Hash 
{ 
	int BUCKET; // No. корзины 

	// Указатель на список с корзинами 
	list<int> *table; 
public: 
	Hash(int V); // конструктор 

	// добавление ключа в хеш таблицу 
	void insertItem(int x); 

	// удаление ключа из хеш таблицы 
	void deleteItem(int key); 

	// hash function to map values to key 
	int hashFunction(int x) { 
		return (x % BUCKET); 
	} 

	void displayHash(); 
}; 

Hash::Hash(int b) 
{ 
	this->BUCKET = b; 
	table = new list<int>[BUCKET]; 
} 

void Hash::insertItem(int key) 
{ 
	int index = hashFunction(key); 
	table[index].push_back(key); 
} 

void Hash::deleteItem(int key) 
{ 
// получение хеш индекса ключа 
int index = hashFunction(key); 

// найти ключ в i-том списке 
list <int> :: iterator i; 
for (i = table[index].begin(); 
		i != table[index].end(); i++) { 
	if (*i == key) 
	break; 
} 

// если ключ найден в хеш таблице, удалить его
if (i != table[index].end()) 
	table[index].erase(i); 
} 

// функция для отображения хеш таблицы 
void Hash::displayHash() { 
for (int i = 0; i < BUCKET; i++) { 
	cout << i; 
	for (auto x : table[i]) 
	cout << " --> " << x; 
	cout << endl; 
} 
} 


int main() 
{ 
// array that contains keys to be mapped 
int a[] = {15, 11, 27, 8, 12}; 
int n = sizeof(a)/sizeof(a[0]); 

// insert the keys into the hash table 
Hash h(7); // 7 is count of buckets in 
			// hash table 
for (int i = 0; i < n; i++) 
	h.insertItem(a[i]); 

// delete 12 from hash table 
h.deleteItem(12); 

// display the Hash table 
h.displayHash(); 

return 0; 
} 

