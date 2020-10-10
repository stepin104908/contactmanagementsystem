#include<contactmanagementsystem.h>
int ADD_CONTACT()
{
	int ch;
	FILE *fp;
	struct contact c;

	system("cls");
	x: fp=fopen("contact.dll","a");
	fflush(stdin);
	printf("\n\n\t..::ADD CONTACT::..\t\n\nName (Use identical) : ");
	scanf("%[^\n]",&c.name);
	if(stricmp(c.name,"")==0 || stricmp(c.name," ")==0)
	fflush(stdin);
	printf("Phone : ");
	scanf("%ld",&c.phone);
	fflush(stdin);
	printf("address : ");
	scanf("%[^\n]",&c.add);
	fflush(stdin);
	printf("email address : ");
	gets(c.email);
	printf("\n");
	fwrite(&c,sizeof(c),1,fp);
	printf("Contact Added Successfully\n");
	printf("Want to add more contact?\n[1]. Yes\n[2]. No\n");
	scanf("%d",&ch);
	if(ch==1)
		goto x;
	fclose(fp);
	getch();
}

	/* *********************list of contacts*************************  */
int VIEW_CONTACT()
{
	int i,found;
	FILE *fp;
	struct contact c;

	system("cls");
	printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n=================================================================\n\n");
	for(i=97; i<=122; i=i+1)
	{
		fp=fopen("contact.dll","r");
		fflush(stdin);
		found=0;
		while(fread(&c,sizeof(c),1,fp)==1)
		{
			if(c.name[0]==i || c.name[0]==i-32)
			{
				printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n",c.name,c.phone,c.add,c.email);
				found++;
			}
		}
		if(found!=0)
		{
			printf("=========================================================== [%c]-(%d)\n\n",i-32,found);
			getch();
		}
		fclose(fp);
	}
		getch();
}

	/* *******************search contacts**********************  */

int SEARCH_CONTACT()
{
	int found,l,i,ch;
	char query[20],name[20];
	FILE *fp;
	struct contact c;

	system("cls");
	do
	{
		found=0;
		printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of contact to search: ");
		fflush(stdin);
		scanf("%[^\n]",&query);
		l=strlen(query);
		fp=fopen("contact.dll","r");
		system("cls");
		printf("\n\n..::Search result for '%s' \n===================================================\n",query);
		while(fread(&c,sizeof(c),1,fp)==1)
		{
			for(i=0; i<=l; i++)
			      name[i]=c.name[i];
			name[l]='\0';
			if(stricmp(name,query)==0)
			{
				printf("\n..::Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n..::Email\t: %s\n",c.name,c.phone,c.add,c.email);
				found++;
				if (found%4==0)
				{
					printf("..::Press any key to continue...");
					getch();
				}
			 }
		}
		if(found==0)
			printf("\n..::No match found!");
		else
			printf("\n..::%d match(s) found!",found);
		fclose(fp);
		printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
		scanf("%d",&ch);
	}
	while(ch==1);
	getch();
}

	/* *********************edit contacts************************/

int EDIT_CONTACT()
{
	FILE *fp,*ft;
	char name[20];
	struct contact c;

	system("cls");
	fp=fopen("contact.dll","r");
	ft=fopen("temp.dat","w");
	fflush(stdin);
	printf("..::Edit contact\n===============================\n\n\t..::Enter the name of contact to edit:");
	scanf("%[^\n]",name);
	while(fread(&c,sizeof(c),1,fp)==1)
	{
		if(stricmp(name,c.name)!=0)
			fwrite(&c,sizeof(c),1,ft);
	}
	fflush(stdin);
	printf("\n\n..::Editing '%s'\n\n",name);
	printf("..::Name(Use identical):");
	scanf("%[^\n]",&c.name);
	fflush(stdin);
	printf("..::Phone:");
	scanf("%ld",&c.phone);
	fflush(stdin);
	printf("..::address:");
	scanf("%[^\n]",&c.add);
	fflush(stdin);
	printf("..::email address:");
	gets(c.email);
	printf("\n");
	fwrite(&c,sizeof(c),1,ft);
	fclose(fp);
	fclose(ft);
	remove("contact.dll");
	rename("temp.dat","contact.dll");
	printf("\t\tContact Eddited Successfully");
	getch();
}

	/* ********************delete contacts**********************/

int DELETE_CONTACT()
{
	FILE *fp,*ft;
	struct contact c;
	char name[20];

	system("cls");
	fflush(stdin);
	printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of contact to delete:");
	scanf("%[^\n]",&name);
	fp=fopen("contact.dll","r");
	ft=fopen("temp.dat","w");
	while(fread(&c,sizeof(c),1,fp)!=0)
		if (stricmp(name,c.name)!=0)
			fwrite(&c,sizeof(c),1,ft);
	fclose(fp);
	fclose(ft);
	remove("contact.dll");
	rename("temp.dat","contact.dll");
	printf("\t\tContact Deleted Successfully");
	getch();
}
