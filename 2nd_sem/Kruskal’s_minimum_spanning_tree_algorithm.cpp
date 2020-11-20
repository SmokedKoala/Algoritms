#include <bits/stdc++.h>
#include <Windows.h>
#include <vector>
#include <string>
using namespace std;

//��������� ��� ������������� ����������� ����� � �����
class Edge {
public:
	int src, dest, weight;
};

// ��������� ��� ������������� ��������, ������������������ � ����������� �����
class Graph {
public:
	
	// V-> ����� ������, E-> ���������� �����
	int V, E;

	// ���� ����������� � ���� ������� �����.
	// ��������� ���� �����������������, ����� �� src � dest ����� ����� �� dest � src. ��� ��� ��������� ����� 1 ������.
	Edge* edge;
};

// ������� ���� � V ��������� � E �������
Graph* createGraph(int V, int E)
{
	Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;

	graph->edge = new Edge[E];

	return graph;
}

// ��������� ��� ������������� ������������ ��� ��������� �����
class subset {
public:
	int parent;
	int rank;
};

// ��������� ������� ��� ������ ��������� �������� i (���������� ����� ������ ����)
int find(subset subsets[], int i)
{
	// ����� ������ � ������� ������ ��������� i (������ ���� )
	if (subsets[i].parent != i)
		subsets[i].parent= find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

// �������, ������� ��������� ����������� ���� ������� x � y (���������� ����������� �� �����)
void Union(subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	// ���������� ������� �������� ������ ��� ������ ������ �������� ����� (����������� �� �����)
	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;

	// ���� ����� ���������, �� �������� ���� ������ � ��������� ��� ���� �� �������
	else {
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}


// �������� ������� ���������� ����������� ��������� ������ � �������������� ��������� ��������
void KruskalMST(Graph* graph)
{
	int V = graph->V;
	Edge result[V]; // ��� �������� ��������� ���������� ���
	int e = 0; // ��������� ����������, ������������ ��� ��������� ����������[]
	int i = 0; // ��������� ����������, ������������ ��� ������������� �����

	// ��� 1: ������������ ��� ����� � ����������� ������� �� ����. ���� ��� ����� �� ��������
	// ������� ������ ����, �� ����� ������� ����� ������� �����
	
	for (int i = 0; i <graph->E-1; i++){
		for (int j =0; j<graph->E-1-i; j++){
			if (graph->edge[j].weight>graph->edge[j+1].weight){
				Edge temp = graph->edge[j];
				graph->edge[j]=graph->edge[j+1];
				graph->edge[j+1]=temp;
			}
		}
	}

	// �������� ������ ��� �������� ����������� V
	subset* subsets = new subset[(V * sizeof(subset))];

	// ������� V ��������� � ���������� ����������
	for (int v = 0; v < V; ++v) 
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	// ���������� �����, ������� ����� �����, ����� V-1
	while (e < V - 1 && i < graph->E) 
	{
		// ��� 2: �������� ����� ��������� �����. � ��������� ������ ��� ��������� ��������
		Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);

		// ���� ��������� ����� ����� �� �������� �����, �������� ��� � ��������� � ��������� ������
		// ���������� ��� ���������� �����
		if (x != y) {
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
		// � ��������� ������ ��������� next_edge
	}

	//�������� ���������� result[] ��� ����������� ������������ ���
	cout << "���� ��������� ����� � ����������� ���\n";
	int minimumCost = 0;
	for (i = 0; i < e; ++i) 
	{
		cout << result[i].src << " -- " << result[i].dest
			<< " � ����� " << result[i].weight << endl;
		minimumCost = minimumCost + result[i].weight;
	}
	cout << "��� ������������ ��������� ������: " << minimumCost
		<< endl;
	cout<< "���������� ����:"<<endl<<
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
	cout<<"������������ ������ �11. �������� �������� ���������� ��������� ������ �����. ������ ����������, ����-02-19"<<endl;
	
	int V=0 ; // ���������� ������ � �����
	int E=0 ; // ���������� ����� � �����
	int first_V;
	int second_V;
	int weight;
	string choice="��";
	vector <Element> edges_vector;
	while(choice!="���"){
		cout<<"������� ���������� ������ � ����� "<<endl;
		cin>>V;
		cout<<"������� ����� ����� � �������: ������ �������, ������ �������, ��� �����"<<endl<<"��� ���������� ����� ������� -1"<<endl;
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
		cout<<"��������� ������ ���������? (��/���)"<<endl;
		cin>>choice;
	}
	

	return 0;
}


