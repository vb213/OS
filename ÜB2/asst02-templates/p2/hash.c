#include "hash.h"
#include <stdio.h>

int getStringLength();
uint64_t hashString(char *c);

int maind() {
	char* c = "asdf";

	

	printf("%ld\n", hashString(c));

	return 0;
}

int getStringLength(char* s) {
	int l = 0;
	while(*s != '\0') {
		s++;
		l++;
	}

	return l;
}

/*
 * Returns a hash value for the given string.
 */
uint64_t hashString(char *c)
{
	int lengthC = getStringLength(c);
	if(lengthC == 0){
		return 5381;
	}

	char cNew[lengthC];
	cNew[lengthC - 1] = '\0';
	for(int i = 0; i < lengthC - 1; i++) {
		 cNew[i] = c[i];
		 //printf("%c", cNew[i]);
	}
	//printf("\n");



	return *(c + lengthC - 1) + 33 * hashString(cNew);
}

/*
 * Inserts a key-value pair into the hash table.
 */
int insert(hashtable *table, char *key, int value)
{
	(void) table; (void) key; (void) value;
	return 0;
}

/*
 * Retrieves the value for a given key.
 */
int find(hashtable *table, char *key, int *value)
{
	(void) table; (void) key; (void) value;
	return 0;
}

