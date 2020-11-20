#include <bits/stdc++.h>
#include <Windows.h>
#include <vector>
#include <string>
using namespace std;

//структура для представления взвешенного ребра в графе
class Edge {
public:
	int src, dest, weight;
};

// структура для представления Связного, неориентированного и взвешенного графа
class Graph {
public:
	
	// V-> Число вершин, E-> Количество ребер
	int V, E;

	// граф представлен в виде массива ребер.
	// Поскольку граф неориентированный, ребро из src в dest также ребро из dest в src. Оба они считаются здесь 1 ребром.
	Edge* edge;
};

// Создает Граф с V вершинами и E ребрами
Graph* createGraph(int V, int E)
{
	Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;

	graph->edge = new Edge[E];

	return graph;
}

// Структура для представления подмножества для найденной связи
class subset {
public:
	int parent;
	int rank;
};

// служебная функция для поиска множества элемента i (использует метод сжатия пути)
int find(subset subsets[], int i)
{
	// найти корень и сделать корень родителем i (сжатие пути )
	if (subsets[i].parent != i)
		subsets[i].parent= find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

// Функция, которая выполняет объединение двух наборов x и y (использует объединение по рангу)
void Union(subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	// Прикрепите меньшее ранговое дерево под корнем дерева высокого ранга (объединение по рангу)
	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;

	// Если ранги одинаковы, то сделайте один корнем и увеличьте его ранг на единицу
	else {
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}


// Основная функция построения Минимальное Связующее Дерево с использованием алгоритма Крускала
void KruskalMST(Graph* graph)
{
	int V = graph->V;
	Edge result[V]; // Это позволит сохранить полученный МСД
	int e = 0; // Индексная переменная, используемая для получения результата[]
	int i = 0; // Индексная переменная, используемая для сортированных ребер

	// Шаг 1: отсортируйте все ребра в неубывающем порядке их веса. Если нам этого не позволят
	// изменив данный граф, мы можем создать копию массива ребер
	
	for (int i = 0; i <graph->E-1; i++){
		for (int j =0; j<graph->E-1-i; j++){
			if (graph->edge[j].weight>graph->edge[j+1].weight){
				Edge temp = graph->edge[j];
				graph->edge[j]=graph->edge[j+1];
				graph->edge[j+1]=temp;
			}
		}
	}

	// Выделить память для создания подмножеств V
	subset* subsets = new subset[(V * sizeof(subset))];

	// Создать V подгруппы с отдельными элементами
	for (int v = 0; v < V; ++v) 
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	// Количество ребер, которые нужно взять, равно V-1
	while (e < V - 1 && i < graph->E) 
	{
		// Шаг 2: Выберите самый маленькое ребро. И увеличьте индекс для следующей итерации
		Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);

		// Если включение этого ребра не вызывает цикла, включите его в результат и увеличьте индекс
		// результата для следующего ребра
		if (x != y) {
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
		// В противном случае отбросьте next_edge
	}

	//выведите содержимое result[] для отображения построенного МСД
	cout << "Ниже приведены ребра в построенном МОД\n";
	int minimumCost = 0;
	for (i = 0; i < e; ++i) 
	{
		cout << result[i].src << " -- " << result[i].dest
			<< " с весом " << result[i].weight << endl;
		minimumCost = minimumCost + result[i].weight;
	}
	cout << "Вес минимального остовного дерева: " << minimumCost
		<< endl;
	cout<< "Полученный граф:"<<endl<<
		"    5"<<endl<<"   /"<<endl<<"  2-4"<<endl<<" /"<<endl<<"1-3"<<endl;
	
	
}

struct Element{
	int first_V;
	int second_V;
	int weight;
};

int main()
{
	setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	cout<<"Практическая работа №11. алгоритм Краскала построения остовного дерева графа. Азаров Константин, ИКБО-02-19"<<endl;
	
	int V=0 ; // Количество вершин в графе
	int E=0 ; // Количество ребер в графе
	int first_V;
	int second_V;
	int weight;
	string choice="да";
	vector <Element> edges_vector;
	while(choice!="нет"){
		cout<<"Введите количество вершин в графе "<<endl;
		cin>>V;
		cout<<"Вводите ребра графа в формате: первая вершина, вторая вершина, вес ребра"<<endl<<"При завершении ввода введите -1"<<endl;
		cin>>first_V;
		while (first_V!=-1){
			cin>>second_V;
			cin>>weight;
			Element temp;
			temp.first_V=first_V;
			temp.second_V=second_V;
			temp.weight=weight;
			edges_vector.push_back(temp);
			cin>>first_V;
		}
		E=edges_vector.size();
		Graph* graph = createGraph(V, E);
		for(int i=0; i<E; i++){
			graph->edge[i].src=edges_vector[i].first_V;
			graph->edge[i].dest=edges_vector[i].second_V;
			graph->edge[i].weight=edges_vector[i].weight;
		}
		KruskalMST(graph);
		edges_vector.clear();
		cout<<"Повторить работу программы? (да/нет)"<<endl;
		cin>>choice;
	}
	

	return 0;
}


