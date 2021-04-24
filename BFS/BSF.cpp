#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void bfs(int** VertMatrix, int CountOfVertex, int Vertex, int* visited, int mode) {
	printf("%d ", Vertex);
	int queue[2000];
	int CountInQueue = 1, WasInQueue = 1, LastVertOfQueue = Vertex;
	queue[0] = Vertex;
	visited[Vertex] = 1;
	while (CountInQueue != 0) {
		LastVertOfQueue = queue[0];
		CountInQueue--;
		for (int i = 0; i < CountInQueue; i++) queue[i] = queue[i + 1];
		for (int j = 0; j < CountOfVertex; j++) {
			if (VertMatrix[LastVertOfQueue][j] && visited[j] != 1) {
				queue[CountInQueue] = j;
				printf("%d ", j);
				CountInQueue++;
				WasInQueue++;
				visited[j] = 1;
			}
		}
	}
	if (WasInQueue != CountOfVertex) {
		printf("\n");
		if (mode == 1) {
			for (int i = 0; i < CountOfVertex; i++) {
				if (visited[i] == 0) {
					bfs(VertMatrix, CountOfVertex, i, visited, 1);
					break;
				}
			}
		}
	}
}
int main() {
	int CountOfVertex;
	scanf("%d", &CountOfVertex);
	int** VertMatrix = (int**)malloc(CountOfVertex * sizeof(int*));
	for (int i = 0; i < CountOfVertex; i++) {
		VertMatrix[i] = (int*)malloc(CountOfVertex * sizeof(int));
	}
	for (int i = 0; i < CountOfVertex; i++)
		for (int j = 0; j < CountOfVertex; j++) {
			scanf("%d", &VertMatrix[i][j]);
		}
	int Vertex;
	scanf("%d", &Vertex);
	int* visited = (int*)malloc(CountOfVertex * sizeof(int));
	for (int i = 0; i < CountOfVertex; i++) visited[i] = 0;
	bfs(VertMatrix, CountOfVertex, Vertex, visited, 1);
	for (int i = 0; i < CountOfVertex; i++) {
		free(VertMatrix[i]);
	}
	free(VertMatrix);
	free(visited);
	return 0;
}