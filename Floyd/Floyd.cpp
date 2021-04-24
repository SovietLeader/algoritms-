#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
const int INF = 2147483647;
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
void Floyd(int** VertMatrix, int** WeightsToVertexes2, int CountOfVertex) {
	int WeightsToVertexes[100][100];
	for (int i = 0; i < CountOfVertex; i++)
		for (int j = 0; j < CountOfVertex; j++) WeightsToVertexes[i][j] = VertMatrix[i][j];

	for (int i = 0; i < CountOfVertex; i++)
		for (int j = 0; j < CountOfVertex; j++)
			for (int k = 0; k < CountOfVertex; k++) {
				if(WeightsToVertexes[j][i] != INF && WeightsToVertexes[i][k] != INF)
					WeightsToVertexes[j][k] = min(WeightsToVertexes[j][k], WeightsToVertexes[j][i] + WeightsToVertexes[i][k]);
			}

	for (int i = 0; i < CountOfVertex; i++) {
		printf("\n");
		for (int j = 0; j < CountOfVertex; j++) {
			if (i != j)
				printf("%d ", WeightsToVertexes[i][j]);
			else printf("0 ");
		}
	}
}


int main() {
	int CountOfVertex;
	scanf("%d", &CountOfVertex);
	int** VertMatrix = (int**)malloc(CountOfVertex * sizeof(int*));
	int** WeightsToVertexes = (int**)malloc(CountOfVertex * sizeof(int*));
	for (int i = 0; i < CountOfVertex; i++) VertMatrix[i] = (int*)malloc(CountOfVertex * sizeof(int));
	for (int i = 0; i < CountOfVertex; i++) WeightsToVertexes[i] = (int*)malloc(CountOfVertex * sizeof(int));
	for (int i = 0; i < CountOfVertex; i++)
		for (int j = 0; j < CountOfVertex; j++)
			WeightsToVertexes[i][j] = INF;
	for (int i = 0; i < CountOfVertex; i++)
		for (int j = 0; j < CountOfVertex; j++)
			scanf("%d", &VertMatrix[i][j]);

	Floyd(VertMatrix,WeightsToVertexes, CountOfVertex);
	for (int i = 0; i < CountOfVertex; i++)	free(VertMatrix[i]);
	free(VertMatrix);
	free(WeightsToVertexes);
	return 0;
}