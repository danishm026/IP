#include<stdio.h>
#include<limits.h>
#define MAX_V 250
#define MAX 99999999

int M[MAX_V][MAX_V], S[MAX_V][MAX_V];

int min(int a, int b) {
	return a < b ? a : b;
}

int fw(int numberOfVerteces) {
	for (int k = 1; k <= numberOfVerteces; k++) {
		for (int i = 1; i <= numberOfVerteces; i++) {
			for (int j = 1; j <= numberOfVerteces; j++) {
				if (i != j) {
					S[i][j] = min(S[i][j], S[i][k] + S[k][j]);
				}
			}
		}
	}
	int maxDistance = 0;
	for (int i = 1; i <= numberOfVerteces; i++) {
		for (int j = 1; j <= numberOfVerteces; j++) {
			if (S[i][j] > maxDistance && i != j) {
				maxDistance = S[i][j];
			}
		}
	}
	return maxDistance;
}

int main() {
	int V, E, s, e, c;
	scanf("%d%d", &V, &E);
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			S[i][j] = MAX;
		}
	}
	for (int i=0; i<E; i++) {
		scanf("%d%d%d", &s, &e, &c);
		M[s][e] = S[s][e] = c;
		M[e][s] = S[e][s] = c;
	}
	printf("%d\n",fw(V));
}
