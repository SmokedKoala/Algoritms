#include <bits/stdc++.h>
#include <limits.h> 
#include <stdio.h> 
#include <Windows.h>

using namespace std;

// Количество  вершин в графе
int V=0;

// Служебная функция для поиска вершины с минимальным значением расстояния из множества вершин, еще не включенных в дерево кратчайших путей 
int minDistance(int dist[], bool sptSet[]) 
{ 
	// Initialize min value 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 

// Служебная функция для печати построенного массива расстояний
void printSolution(int dist[]) 
{ 
	printf("Вершина \t Расстояние от источника\n"); 
	for (int i = 0; i < V; i++) 
		printf("%d \t\t %d\n", i+1, dist[i]); 
} 

// Функция, реализующая алгоритм кратчайшего пути Дейкстры для графа, представленного с использованием представления матрицы смежности
void dijkstra(int **graph, int src) 
{ 
	int dist[V]; // Выходной массив. dist[i] будет содержать кратчайшее расстояние от src до i
	bool sptSet[V]; // sptSet[i] будет истинным, если вершина i включена в дерево кратчайших путей или кратчайшее расстояние от src до i завершено 
	// Инициализируйте все расстояния как бесконечные, а stpSet[] как false
	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, sptSet[i] = false; 
	// Расстояние исходной вершины от себя всегда равно 0
	dist[src] = 0; 
	// Найти кратчайший путь для всех вершин
	for (int count = 0; count < V - 1; count++) { 
		// Выберите минимальную удаленную вершину из набора еще не обработанных вершин. u всегда равно src в первой итерации.
		int u = minDistance(dist, sptSet); 
		// Отметьте выбранную вершину как обработанную
		sptSet[u] = true; 
		// Обновите значение расстояния соседних вершин выбранной вершины.
		for (int v = 0; v < V; v++) 
			// Обновление dist[v] только в том случае, если его нет в наборе spt, есть ребро от u до v, а общий вес пути от src до v через u равен
			// меньше текущего значения dist[v]
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v]; 
	} 

	// выведите построенный массив расстояний
	printSolution(dist); 
} 

int main() 
{ 
	setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int source=0;
    string choice="да";
	cout<<"Практическая работа №12. алгоритм Дейкстры поиска кратчайшего пути в графе. Азаров Константин, ИКБО-02-19"<<endl; 
	while (choice!="нет"){
		cout<<"Введите количество вершин графа: ";
		cin>>V;
		int **graph = new int*[V];
		for(int i =0; i<V;i++){
			graph[i] = new int[V];
		}
		cout << "Создайте граф(введите матрицу весов граней между вершинами), при отсутсвии грани, напишите 0"<<endl<<"\t";
		for (int i = 0; i< V; i++)
			cout<< i+1<<" ";
		cout<<endl<<endl;
		for (int i = 0; i< V; i++){
			cout<< i+1<<"\t";
			for (int j =0; j<V; j++){
				cin>>graph[i][j];
			}
		}
		cout<<endl<<"от какой точки найти расстояние?"<<endl;
		cin>>source;
		dijkstra(graph, source-1);
		cout<<"Ввети новый граф?(да/нет)"<<endl;
		cin>>choice;	
	}
	return 0; 
} 

/*
8

0 23 12 0 0 0 0 0
23 0 25 0 22 0 0 35
12 25 0 18 0 0 0 0
0 0 18 0 0 20 0 0
0 22 0 0 0 23 14 0
0 0 0 0 23 0 24 0
0 0 0 0 14 24 0 16
0 35 0 0 0 0 16 0
*/
