#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void Dijsktra(int** VertMatrix, int* WeightsToVertexes, int CountOfVertex, int Vertex) {
	int wasvisited = 0; int visited[1000];
	for (int i = 0; i < CountOfVertex; i++)	visited[i] = 0;
	int next = Vertex;
	visited[0] = 1;
	WeightsToVertexes[0] = 0;
	while(wasvisited != CountOfVertex){
		Vertex = next;
		for (int i = 0; i < CountOfVertex; i++) {
			if (VertMatrix[Vertex][i] != -1) {
				if (WeightsToVertexes[i] == -1 || ((WeightsToVertexes[i] > WeightsToVertexes[Vertex] + VertMatrix[Vertex][i]) && (WeightsToVertexes[i] != -1))) {
					WeightsToVertexes[i] = WeightsToVertexes[Vertex] + VertMatrix[Vertex][i];
				}
			}
		}
		visited[Vertex] = 1;
		wasvisited++;
		int min = -1;
		for (int i = 0; i < CountOfVertex; i++) {
			if (visited[i] == 0)
				if (min == -1 || (WeightsToVertexes[i] < min && (WeightsToVertexes[i] != -1))) {
					min = WeightsToVertexes[i];
					next = i;
				}
		}
	}
}

int main() {
	int CountOfVertex;
	scanf("%d", &CountOfVertex);
	int** VertMatrix = (int**)malloc(CountOfVertex * sizeof(int*));
	int* WeightsToVertexes = (int*)malloc(CountOfVertex * sizeof(int));
	for (int i = 0; i < CountOfVertex; i++) VertMatrix[i] = (int*)malloc(CountOfVertex * sizeof(int));
	for (int i = 0; i < CountOfVertex; i++) WeightsToVertexes[i] = -1;
	for (int i = 0; i < CountOfVertex; i++)
		for (int j = 0; j < CountOfVertex; j++)
			scanf("%d", &VertMatrix[i][j]);
	int Vertex;
	scanf("%d", &Vertex);
	Dijsktra(VertMatrix,WeightsToVertexes, CountOfVertex, Vertex);
	for (int i = 0; i < CountOfVertex; i++) printf("%d ", WeightsToVertexes[i]);
	for (int i = 0; i < CountOfVertex; i++)	free(VertMatrix[i]);
	free(VertMatrix);
	free(WeightsToVertexes);
	return 0;
}