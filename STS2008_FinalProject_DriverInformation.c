#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char name[10];
	int age;
	char carnum[20];
	int accid;
}driver;

driver Person;
driver*pdriver;
int nmax=0;
int i=0;

void max(int acnum);
int main(void) 
{
	FILE *ifp;
	int inage;
	int res;

	printf("This program shows the list of drivers, who have the bigggest number of car accident,\n");
	printf("among drivers who are in the age you entered.\n\n");
	
	printf("Enter an age: ");
	scanf("%d", &inage);

	ifp=fopen("Info_file.txt","r");
	if(ifp==NULL)
	{
		printf("input file open error!\n");
		return 1;
	}
	
	pdriver=(driver*)malloc(5*sizeof(driver));
	if (pdriver==NULL)
	{
		printf("memory not allocated!\n");
		return 1;
	}
	
	while(1)
	{
		res=fscanf(ifp, "%[^,], %d, %[^,], %d\n", Person.name, &Person.age, Person.carnum, &Person.accid);
		if(res==EOF) break;
		if (inage==Person.age)
			max(Person.accid);
	}
	
	if (i==0){
			printf("\nNo one is %d years old.\n",inage);
	}
	else
	{
		printf("\nBiggest Accident number: %d\n\n", nmax);
		printf("Name   | Car number\n");
		printf("--------------------\n");
		int j;
		for(j=0; j<i; j++)
			printf("%-7s|%11s\n", (pdriver+j)->name, (pdriver+j)->carnum);
	}
	
	free(pdriver);
	fclose(ifp);
	return 0;
}

void max(int acnum)
{	
	if (nmax==acnum)
	{
		if(i<5)
		{	
			strcpy((pdriver+i)->name, Person.name);
			(pdriver+i)->age=Person.age;
			strcpy((pdriver+i)->carnum, Person.carnum);
			(pdriver+i)->accid=Person.accid;
			i+=1;
		}
		else{
			pdriver=(driver*)realloc(pdriver, 5*sizeof(driver));
		}
	}
	else if(nmax<acnum)
	{
		nmax=acnum;
		strcpy(pdriver->name, Person.name);
		pdriver->age=Person.age;
		strcpy(pdriver->carnum, Person.carnum);
		pdriver->accid=Person.accid;
		i=1;
	}
	return;
}
