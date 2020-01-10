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

long int compare (const void *a, const void *b) {
	if (*(long int*)a > *(long int*)b) {
		return 1;
	} else if (*(long int*)a < *(long int*)b) {
		return -1;
	} else {
		return 0;
	}
}

int main () {
	
	FILE* fp;
	fp = freopen("input3.txt", "r", stdin);
	
	char buf[1000009];	
	memset(buf, 0, 1000009);
	
	if (fp != NULL) {
		fgets(buf, 1000009, fp);
		long int n = strtol(buf, NULL, 10);
		
		long int numeros[n];
		memset(numeros, 0, n);
		
		long int i;
		char *pEnd = NULL;
		fgets(buf, 1000009, fp);
		for (i = 0; i < n; i++) {
			numeros[i] = strtol(buf, &pEnd, 10);
			memcpy(buf, &pEnd[1], strlen(pEnd));
			fgets(buf, 1000009, fp);
		}
		
		//selection_sort(numeros, n);
		qsort(numeros, n, sizeof(long int), compare);
		
		for (i = 0; i < n; i++) {
			printf("%d ", numeros[i]);
		}		
	}
	
	return (0);
}
