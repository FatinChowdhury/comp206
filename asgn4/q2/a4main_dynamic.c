#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "a4phonebook_dynamic.c"

int menu(void){
	printf("Phonebook Menu: (1)Add, (2)Find, (3)List, (4)Quit >");
	int input;
	scanf("%d", &input);
	while (getchar()!='\n');
	return input;
}

int main(){

	int sizeInput;
	printf("Enter the size of phonebook: ");
	scanf("%d", &sizeInput);

	if (initPhonebook(sizeInput) != 0){
		printf("Phonebook of this size cannot store more info, ending program..\n");
		return 1;
	}

	char name[nameSize], birth[birthSize], phone[phoneSize];
	int menu_input, result;
	
	loadCSV("phonebook.csv");

	while(1){
		menu_input = menu();
		
		switch(menu_input){
			// addRecord()
			case 1:
				printf("Enter a name: ");
				scanf(" %[^\n]", name);
				name[strcspn(name, "\n")] = 0;

				printf("Enter a birthdate: ");
				scanf(" %[^\n]", birth);
                                birth[strcspn(birth, "\n")] = 0;

				printf("Enter a phone number: ");
				scanf(" %[^\n]", phone);
                                phone[strcspn(phone, "\n")] = 0;


				result = addRecord(name, birth, phone);
				if (result != 0){
					printf("Error: phonebook is full, cannot add anything.\n");
				}
				break;

			// findRecord()
			case 2:
				printf("Enter a name you want to search: ");
				scanf(" %[^\n]", name);
				findRecord(name);
				break;

			// listRecords()
			case 3:
				result = listRecords();
				if (result != 0){
					printf("Error: phonebook is empty, there is nothing to list.\n");
				}
				break;

			// quit program
			case 4:
				break;
			
			// if anything else
			default:
				printf("Invalid menu selection \n");
		}
		if (menu_input == 4){
		       break;
		}
	}
	result = saveCSV("phonebook.csv");
	if (result != 0){
		printf("Failed to save.\n");
	}
	printf("End of phonebook program\n");
	return 0;
}
