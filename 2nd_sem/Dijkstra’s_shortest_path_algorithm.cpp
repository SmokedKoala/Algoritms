#include <bits/stdc++.h>
#include <limits.h> 
#include <stdio.h> 
#include <Windows.h>

using namespace std;

// ����������  ������ � �����
int V=0;

// ��������� �������� ��� ������ ������� � ����������� ��������� ���������� �� ��������� ������, ��� �� ���������� � ������ ���������� ����� 
int minDistance(int dist[], bool sptSet[]) 
{ 
	// Initialize min value 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 

// ��������� ������� ��� ������ ������������ ������� ����������
void printSolution(int dist[]) 
{ 
	printf("������� \t ���������� �� ���������\n"); 
	for (int i = 0; i < V; i++) 
		printf("%d \t\t %d\n", i, dist[i]); 
} 

// �������, ����������� �������� ����������� ���� �������� ��� �����, ��������������� � �������������� ������������� ������� ���������
void dijkstra(int **graph, int src) 
{ 
	int dist[V]; // �������� ������. dist[i] ����� ��������� ���������� ���������� �� src �� i

	bool sptSet[V]; // sptSet[i] ����� ��������, ���� ������� i �������� � ������ ���������� ����� ��� ���������� ���������� �� src �� i ��������� 

	// ��������������� ��� ���������� ��� �����������, � stpSet[] ��� false
	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, sptSet[i] = false; 

	// ���������� �������� ������� �� ���� ������ ����� 0
	dist[src] = 0; 

	// ����� ���������� ���� ��� ���� ������
	for (int count = 0; count < V - 1; count++) { 
		// �������� ����������� ��������� ������� �� ������ ��� �� ������������ ������. u ������ ����� src � ������ ��������.
		int u = minDistance(dist, sptSet); 

		// �������� ��������� ������� ��� ������������
		sptSet[u] = true; 

		// �������� �������� ���������� �������� ������ ��������� �������.
		for (int v = 0; v < V; v++) 

			// ���������� dist[v] ������ � ��� ������, ���� ��� ��� � ������ spt, ���� ����� �� u �� v, � ����� ��� ���� �� src �� v ����� u �����
			// ������ �������� �������� dist[v]
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
				&& dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v]; 
	} 

	// �������� ����������� ������ ����������
	printSolution(dist); 
} 

int main() 
{ 
	setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int source=0;
    string choice="��";
	cout<<"������������ ������ �12. �������� �������� ������ ����������� ���� � �����. ������ ����������, ����-02-19"<<endl; 
	while (choice!="���"){
		cout<<"������� ���������� ������ �����: ";
		cin>>V;
		int **graph = new int*[V];
		for(int i =0; i<V;i++){
			graph[i] = new int[V];
		}
		cout << "�������� ����(������� ������� ����� ������ ����� ���������), ��� ��������� �����, �������� 0"<<endl<<"\t";
		for (int i = 0; i< V; i++)
			cout<< i<<" ";
		cout<<endl<<endl;
		for (int i = 0; i< V; i++){
			cout<< i<<"\t";
			for (int j =0; j<V; j++){
				cin>>graph[i][j];
			}
		}
		cout<<endl<<"�� ����� ����� ����� ����������?"<<endl;
		cin>>source;
		dijkstra(graph, source);
		cout<<"����� ����� ����?(��/���)"<<endl;
		cin>>choice;	
	}
	return 0; 
} 

/*
9

0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
*/
