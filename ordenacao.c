#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selection_sort (long int v[], int size) {
	int i, j, posMenor = 0;
	long int temp;
		
	for (i = 0; i < size - 1; i++) {
		posMenor = i;
		for (j = i + 1; j < size; j++) {
			if (v[j] < v[posMenor]) posMenor = j;
		}
		
		temp = v[i];
		v[i] = v[posMenor];
		v[posMenor] = temp;		
	}
}

int main () {
	
	FILE* fp;
	fp = freopen("input1.txt", "r", stdin);
	
	char buf[10005];	
	memset(buf, 0, 10005);
	
	if (fp != NULL) {
		fgets(buf, 10005, fp);
		long int n = strtol(buf, NULL, 10);
		
		long int numeros[n];
		memset(numeros, 0, n);
		
		int i;
		char *pEnd = NULL;
		fgets(buf, 10005, fp);
		for (i = 0; i < n; i++) {
			numeros[i] = strtol(buf, &pEnd, 0);		
			memcpy(buf, &pEnd[1], strlen(pEnd));
		}
		
		selection_sort(numeros, n);
		
		for (i = 0; i < n; i++) {
			printf("%d ", numeros[i]);
		}
		
	}
	
	return (0);
}
