#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void dfs(int** VertMatrix, int CountOfVertex, int Vertex, int* visited, int mode) {
	printf("%d ", Vertex);
	int stack[2000];
	int CountInStack = 0, WasInStack = 0, LastVertOfStack = Vertex;
	stack[0] = Vertex;
	visited[Vertex] = 1;
	int check = 1;
	CountInStack++; WasInStack++;
	while (WasInStack != CountOfVertex) {
		if (CountInStack == 0) break;
		else
			if (check == 0) {
				CountInStack--;
				LastVertOfStack = stack[CountInStack];
			}
		check = 0;
		for (int j = 0; j < CountOfVertex; j++) {
			if (VertMatrix[LastVertOfStack][j] && visited[j] != 1) {
				stack[CountInStack] = j;
				printf("%d ", j);
				CountInStack++;
				WasInStack++;
				visited[j] = 1;
				LastVertOfStack = j;
				check = 1;
				break;
			}
		}
	}

	if (WasInStack != CountOfVertex) {
		printf("\n");
		if (mode == 1) {
			for (int i = 0; i < CountOfVertex; i++) {
				if (visited[i] == 0) {
					dfs(VertMatrix, CountOfVertex, i, visited, 1);
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
	dfs(VertMatrix, CountOfVertex, Vertex, visited, 1);
	for (int i = 0; i < CountOfVertex; i++) {
		free(VertMatrix[i]);
	}
	free(VertMatrix);
	free(visited);
	return 0;
}