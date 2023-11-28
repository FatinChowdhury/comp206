#include <stdio.h>
#include <string.h>
#include <stdlib.h>

# define maxSize 10
# define nameSize 50
# define birthSize 12
# define phoneSize 15


typedef struct {
	char name[nameSize];
	char birthdate[birthSize];
	char phone[phoneSize];
}PHONE_RECORD;

PHONE_RECORD *phonebook = NULL;
int phonebook_length = 0;
int phonebookMaxSize = 0;

int initPhonebook(int size){
	phonebook = (PHONE_RECORD *)malloc(size * sizeof(PHONE_RECORD));

	if (!phonebook){
		return 1;
	}

	phonebookMaxSize = size;
	phonebook_length = 0;
	return 0;
}

int addRecord(char name[], char birth[], char phone[]) {
	
	if (phonebook_length >= phonebookMaxSize) {
		int newSize = phonebookMaxSize * 2;
		PHONE_RECORD *newPhonebook = realloc(phonebook, newSize * sizeof(PHONE_RECORD));
		if (!newPhonebook){
			return 1;
		}

		phonebook = newPhonebook;
		phonebookMaxSize = newSize;

	}

	strncpy(phonebook[phonebook_length].name, name, nameSize - 1);
	phonebook[phonebook_length].name[nameSize-1] = '\0';

	strncpy(phonebook[phonebook_length].birthdate, birth, birthSize - 1);
	phonebook[phonebook_length].birthdate[birthSize-1] = '\0';

	strncpy(phonebook[phonebook_length].phone, phone, phoneSize - 1);
        phonebook[phonebook_length].phone[phoneSize-1] = '\0';

	phonebook_length++;

	return 0;
}


int listRecords(void){
	if (phonebook_length == 0){
		return 1;
	}
	printf("---- NAME ----    ---- BIRTH DATE ----    ---- PHONE ----\n");

	for (int i = 0; i < phonebook_length; i++){
		printf("%-14s %-20s %-10s\n", phonebook[i].name, phonebook[i].birthdate, phonebook[i].phone);
	}
	
	return 0;
}

int findRecord(char name[]){
	for (int i = 0; i < phonebook_length; i++){
		if (strcmp(phonebook[i].name, name) == 0) {
			printf("---- NAME ----    ---- BIRTH DATE ----    ---- PHONE ----\n");
			printf("%-14s %-20s %-10s\n", phonebook[i].name, phonebook[i].birthdate, phonebook[i].phone);
			return i;
		}
	}
	printf("Phone record not found\n");
	return -1;
}

int loadCSV(char *filename){
	FILE *file = fopen(filename, "r");
	if (!file){
		return 1;
	}

	phonebook_length = 0;
	char buff[256];

	while(fgets(buff, 100, file)){
		
		char *t;
                t = strtok(buff, ",");
		if (t!=NULL) strncpy(phonebook[phonebook_length].name, t, nameSize-1);

		t = strtok(NULL, ",");
                if (t!=NULL) strncpy(phonebook[phonebook_length].birthdate, t, birthSize-1);

		t = strtok(NULL, ",");
                if (t!=NULL) strncpy(phonebook[phonebook_length].phone, t, phoneSize-1);
		if (phonebook_length >= maxSize) break;
	}

	fclose(file);
	return 0;
}

int saveCSV(char *filename){
	FILE *file = fopen(filename, "w");
	if (!file){
		return 1;
	}

	if (phonebook_length == 0){
		return 2;
	}

	fprintf(file, "name,birthdate,phone\n");
	for (int i = 0; i < phonebook_length; i++){
		phonebook[i].phone[strcspn(phonebook[i].phone, "\n")] = '\0';
		fprintf(file, "%s,%s,%s\n", phonebook[i].name, phonebook[i].birthdate, phonebook[i].phone);
	}
	fclose(file);
	return 0;
}

void fPhonebook(){
	free(phonebook);
}
