#include <bits/stdc++.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include <exception>
#include <vector> 
#include <stdlib.h>

using namespace std;

 int max_level = INT_MIN; 
 int sum=0;
enum Color {RED, BLACK}; 
  //структура элемента
struct Node 
{ 
    int data; 
    bool color; 
    Node *left, *right, *parent; 
  
    // конструктор элемента
    Node(int data) 
    { 
       this->data = data; 
       left = right = parent = NULL; 
       this->color = RED; 
    } 
}; 
  
// класс для реализации красно-чёрного дерева
class RBTree 
{ 
private: 
    Node *root; 
protected: 
    void rotateLeft(Node *&, Node *&); 
    void rotateRight(Node *&, Node *&); 
    void fixViolation(Node *&, Node *&); 
public: 
    // конструктор дерева 
    RBTree() { root = NULL; } 
    void insert(const int &n); 
    void inorder(); 
    void levelOrder(); 
    int heightOfTree();
    void sumOfNodesAtMaxDepth();
}; 
  
// рекурсивная функция обхода дерева по ветвям(вывод элементов в порядке возрастания)
void inorderHelper(Node *root) 
{ 
    if (root == NULL) 
        return; 
  
    inorderHelper(root->left); 
    cout << root->data << "  "; 
    inorderHelper(root->right); 
} 

  
// добавление нового элемента в дерево
Node* BSTInsert(Node* root, Node *pt) 
{ 
    // если дерево пустое, возвращает введенный элемент
    if (root == NULL) 
       return pt; 
  
    // иначе, рекурсивно спускается вниз по дереву
    if (pt->data < root->data) 
    { 
        root->left  = BSTInsert(root->left, pt); 
        root->left->parent = root; 
    } 
    else if (pt->data > root->data) 
    { 
        root->right = BSTInsert(root->right, pt); 
        root->right->parent = root; 
    } 
  
    //возвращает неизмененную ссылку на root
    return root; 
} 
  
//  рекурсивная функция обхода дерева по уровням(вывод элементов сверху вниз)
void levelOrderHelper(Node *root) 
{ 
    if (root == NULL) 
        return; 
  
    std::queue<Node *> q; 
    q.push(root); 
  
    while (!q.empty()) 
    { 
        Node *temp = q.front(); 
        cout << temp->data << "  "; 
        q.pop(); 
  
        if (temp->left != NULL) 
            q.push(temp->left); 
  
        if (temp->right != NULL) 
            q.push(temp->right); 
    } 
} 

// функция вывода высоты древа
int heightOfTreeHelper(Node * node)
{
    if(node == NULL)
        return 0;
    int left, right;
    if (node->left != NULL) {
        left = heightOfTreeHelper(node->left);
    }else 
        left = -1;
    if (node->right != NULL) {
        right = heightOfTreeHelper(node->right);
    }else 
        right = -1;
    int max = left > right ? left : right;
    return max+1;
}
// функция подсчёта суммы элементов на листьях
void sumOfNodesAtMaxDepthHelper(Node *root,int level) 
{ 
    if(root == NULL) 
    return; 
    if(level > max_level) 
    { 
        sum = root->data; 
        max_level = level; 
    } 
    else if(level == max_level) 
    { 
        sum = sum + root->data; 
    } 
    sumOfNodesAtMaxDepthHelper(root ->left, level + 1); 
    sumOfNodesAtMaxDepthHelper(root ->right, level + 1);  
} 



//  функция сдвига всех элементов влево(левый - в корневой, корневой - в правую ветвь)
void RBTree::rotateLeft(Node *&root, Node *&pt) 
{ 
    Node *pt_right = pt->right; 
  
    pt->right = pt_right->left; 
  
    if (pt->right != NULL) 
        pt->right->parent = pt; 
  
    pt_right->parent = pt->parent; 
  
    if (pt->parent == NULL) 
        root = pt_right; 
  
    else if (pt == pt->parent->left) 
        pt->parent->left = pt_right; 
  
    else
        pt->parent->right = pt_right; 
  
    pt_right->left = pt; 
    pt->parent = pt_right; 
} 
//  функция сдвига вправо (правый - в корень, корневой - в левую ветвь)
void RBTree::rotateRight(Node *&root, Node *&pt) 
{ 
    Node *pt_left = pt->left; 
  
    pt->left = pt_left->right; 
  
    if (pt->left != NULL) 
        pt->left->parent = pt; 
  
    pt_left->parent = pt->parent; 
  
    if (pt->parent == NULL) 
        root = pt_left; 
  
    else if (pt == pt->parent->left) 
        pt->parent->left = pt_left; 
  
    else
        pt->parent->right = pt_left; 
  
    pt_left->right = pt; 
    pt->parent = pt_left; 
} 
  
// функция исправления дерева после вставки элемента по правилам красно-черного дерева 
void RBTree::fixViolation(Node *&root, Node *&pt) 
{ 
    Node *parent_pt = NULL; 
    Node *grand_parent_pt = NULL; 
  
    while ((pt != root) && (pt->color != BLACK) && 
           (pt->parent->color == RED)) 
    { 
  
        parent_pt = pt->parent; 
        grand_parent_pt = pt->parent->parent; 
  
        /*  Случай А
            корневой элемент расположен слева от дедушки-элемента */
        if (parent_pt == grand_parent_pt->left) 
        { 
  
            Node *uncle_pt = grand_parent_pt->right; 
  
            /* Вариант 1 
               дядя элемента тоже красный, тогда нужна просто произвести перекраску */
            if (uncle_pt != NULL && uncle_pt->color == RED) 
            { 
                grand_parent_pt->color = RED; 
                parent_pt->color = BLACK; 
                uncle_pt->color = BLACK; 
                pt = grand_parent_pt; 
            } 
  
            else
            { 
                /* Вариант 2
                   элемент справа от корневого 
                   сдвиг влево нужен */
                if (pt == parent_pt->right) 
                { 
                    rotateLeft(root, parent_pt); 
                    pt = parent_pt; 
                    parent_pt = pt->parent; 
                } 
  
                /* Вариант 3
                   элемент слева от корневого
				   нужен сдвиг вправо */
                rotateRight(root, grand_parent_pt); 
                swap(parent_pt->color, grand_parent_pt->color); 
                pt = parent_pt; 
            } 
        } 
  
        /* Случай Б 
           корневой элемент для вставленного находится справа от элемента-деда*/
        else
        { 
            Node *uncle_pt = grand_parent_pt->left; 
  
            /*  Вариант 1 
               дядя элемента тоже красный, тогда нужна просто произвести перекраску */
            if ((uncle_pt != NULL) && (uncle_pt->color == RED)) 
            { 
                grand_parent_pt->color = RED; 
                parent_pt->color = BLACK; 
                uncle_pt->color = BLACK; 
                pt = grand_parent_pt; 
            } 
            else
            { 
                /* Вариант 2
                   элемент слева от корневого 
                   сдвиг вправо нужен*/
                if (pt == parent_pt->left) 
                { 
                    rotateRight(root, parent_pt); 
                    pt = parent_pt; 
                    parent_pt = pt->parent; 
                } 
  
                /* Вариант 3
                   элемент справа от корневого 
                   сдвиг влево нужен */
                rotateLeft(root, grand_parent_pt); 
                swap(parent_pt->color, grand_parent_pt->color); 
                pt = parent_pt; 
            } 
        } 
    } 
  
    root->color = BLACK; 
} 
  
// добавление нового элемента
void RBTree::insert(const int &data) 
{ 
    Node *pt = new Node(data); 
  
    // просто вставка элемента
    root = BSTInsert(root, pt); 
  
    // выравнивание по правилам красно-черного дерева
    fixViolation(root, pt); 
} 
//  переопределение функционала для класса RBTree
void RBTree::inorder()     {  inorderHelper(root);} 
void RBTree::levelOrder()  {  levelOrderHelper(root); } 
int RBTree::heightOfTree(){  heightOfTreeHelper(root);}
void RBTree::sumOfNodesAtMaxDepth(){
	sumOfNodesAtMaxDepthHelper(root, 0);
}




int main(){
	setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    cout << "Практическая работа №2 Бинарное дерево поиска. AVL дерево. Азаров Константин, ИКБО-02-19"
         << endl;
    int typeNum;
    int commandNum=0, newNodeData;
    RBTree tree; 
    string menuChoice="\n1)Вставка элемента\n2)Симметричный обход\n3)Обход в ширину\n4)Найти сумму значений листьев\n5)Найти высоту дерева\n6)Выход\n";
    cout<<"Введите 10 элементов: ";
    for (int i=0; i<10;i++){
    	cin>>newNodeData;
		tree.insert(newNodeData);
	}
	cout<<endl;
	while(true){
		cout<<menuChoice;
    	commandNum=0;
    	cin>>commandNum;
    			while(commandNum !=6){
    				cout<<menuChoice;
					cin>>commandNum;
						switch(commandNum){
							case(1):
								cout<<"Выбрана вставка элемента\nВведите элемент: ";
								cin>>newNodeData;
								tree.insert(newNodeData);
								break;
							case(2):
								 cout << "Выбран симметричный обход\n"; 
    							tree.inorder(); 
								break;
							case(3):
								cout << "\nВыбран обход по ширине\n"; 
   								tree.levelOrder();
								break;
							case(4):
								sum = 0;
								tree.sumOfNodesAtMaxDepth();
								cout<<"Сумма элементов на листьях "<<sum<<endl;
								break;
							case(5):
								cout << "\nВыбран вывод высоты древа\n"; 
								cout<<"Высота древа: "<<tree.heightOfTree()+1<<endl;
								break;
							case(6):
							return 0;	
								break;
							default:
								cout<<"Некорректные данные";
								break;
					}
				}
				break;
	}
}

