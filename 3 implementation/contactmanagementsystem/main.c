#include<contactmanagementsystem.h>
#include "test_contactmanagementsystem.h"
int ADD_CONTACT();
int VIEW_CONTACT();
int SEARCH_CONTACT();
int EDIT_CONTACT();
int DELETE_CONTACT();
int test_main();

int main()
{
	int ch,y;
 lebel:	system("cls");
	printf("\n\t **** Welcome to Contact Management System ****");
	printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t[6] Exit\n\t\t=================\n\t\t");
	printf("\n\t\tEnter the choice: ");
	scanf("%d",&ch);
	test_main();
    return 0;
	switch(ch)
	{
		case 1:
			ADD_CONTACT();
			break;
		case 2:
			VIEW_CONTACT();
			break;
		case 3:
			SEARCH_CONTACT();
			break;
		case 4:
			EDIT_CONTACT();
			break;
		case 5:
			DELETE_CONTACT();
			break;
		case 6:
			break;
		default:
			printf("..::Invalid Input::..");
			break;
    }

    printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");
    scanf("%d",&y);
    switch (y)
    {
	case 1: goto lebel; break;
	case 0: break;
	default: printf("Invalid choice"); break;
    }
getch();
return 0;
}

