#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

class Node
{
	float data;
	Node *left, *right;
	public:
	int sum=0;
	int num;
	Node(): data(0), left(NULL), right(NULL){};
	Node(float value)
	{
	data = value;
	left = right = NULL;
	};
	Node* Insert(Node *root, float value)
	{
		if(!root)
		{
			num++;
			return new Node(value);
		}
		if(value > root->data)
		{
			root->right = Insert(root->right, value);
		}
		else
		{
			root->left = Insert(root->left, value);
		}
		return root;
	};
	
	// Inorder traversal.
	void Inorder(Node *root)
	{
		if(!root)
		{
			return;
		}
		Inorder(root->left);
		cout << root->data << " ";
		Inorder(root->right);
	};
	
	void averageSumOfNodes(Node *root){
		if(!root)
		{
			return;
		}
		averageSumOfNodes(root->left);
		sum+=root->data ;
		averageSumOfNodes(root->right);
	};
	
	void findLevel(Node *root,int value, int level){
		if(!root)
		{
			return;
		}
		if (root->data==value){
			cout<<"Длина пути от корня до "<<value<<" равна: "<<level<<endl;
			return;
		}
		findLevel(root->left,value,level+1 );
		findLevel(root->right,value,level+1 );	
	};
};

int main()
{
	setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float data;
    cout << "Практическая работа №6 Бинарное дерево поиска. Азаров Константин, ИКБО-02-19"<< endl;
    Node tree,*root = NULL;
    string menuChoice="\n1)Вставка элемента\n2)Симметричный обход\n3)Среднее арифметическое узлов\n4)Длина пути от корня до заданного значения\n5)Выход\n";
    cout<<"Введите 10 элементов: ";
    cin>>data;
    root = tree.Insert(root, data);
    for (int i=0; i<9;i++){
    	cin>>data;
		tree.Insert(root,data);
	}
    int commandNum=0;
    while(commandNum !=5){
    	cout<<menuChoice;
		cin>>commandNum;
		switch(commandNum){
		case(1):
			cout<<"Выбрана вставка элемента\nВведите элемент: ";
			cin>>data;
			tree.Insert(root,data);
			break;
		case(2):
			 cout << "Выбран симметричный обход\n"; 
    		tree.Inorder(root); 
    		cout<<endl;
			break;
		case(3):
			cout << "\nВыбран вывод среднего арифметического суммы узлов\n"; 
   			tree.averageSumOfNodes(root);
			cout<<"Среднее арифметическое значений "<<tree.num<<" элементов: "<<tree.sum/tree.num<<endl;
			tree.sum=0;
			break;
		case(4):
			cout << "\nВыбран вывод длины пути от корня до заданного значения\nВведите элемент: ";
			cin>>data;
			tree.findLevel(root,data,1);
			break;
		}
	}
	return 0;
}
