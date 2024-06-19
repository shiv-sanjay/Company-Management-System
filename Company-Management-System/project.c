#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct employee{
	int id, join_year;
	long int salary;
	long phone;
 	char name[30], designation[30], dob[30];
}employee;

void display();
void add_employee();
void create();
void Noofrecord();
void search_employee();
void update_employee_data();
void fired_employee();

int main(){
	int ch;
	int h1;
	
	printf("\n\n\n");
	system("color 3");
	printf("\t\t*    *    *  *******    *         *********   ***********   *       *   *******\n");
	printf("\t\t*   * *   *  *          *         *           *         *   * *   * *   *\n");
	printf("\t\t*  *   *  *  *******    *         *           *         *   *   *   *   *******\n");
	printf("\t\t* *     * *  *          *         *           *         *   *       *   *\n");
	printf("\t\t*         *  *******    ********  *********   ***********   *       *   *******\n");
	printf("\n");
	printf("\t\t\t\t\t To office manegemnet system .\n");
	printf("\t\t\t\t\t------------------------------\n");
	printf("\n\n");
	printf("built by : \n");
	printf("SHIV SANJAY \n");
	printf("\npress any key to continue...");
	getch();

	menu:
		system("cls");
	printf("\n\n\t\t\tWELCOME TO OFFICE MANAGEMENT SYSTEM\n");
	printf("Press:\n1 for displaying employee data\n");
	printf("2 for searching specific employee(ID required)\n");
	printf("3.for CREATE the file \n");
	printf("4 for No of records in office \n");
	printf("5 for hiring new employee\n");
	printf("6 for changing detail of specific employee(ID required)\n");
	printf("7 for firing current employee\n");
	printf("0 for EXIT. ");
		
		printf("\n\nchoice : ");
		scanf("%d",&ch);
printf("\n");
		switch(ch){
			case 1:
				display();
				break;
			case 2:
				search_employee();
				break;
			case 3:
				create();
				break;	
			case 4:
				Noofrecord();
				break;
			case 5:
				add_employee();
				break;
			case 6:
				update_employee_data();
				break;
			case 7:
				fired_employee();
				break;
			case 0:
				printf("thank you for using . \n");
			exit(1);	
			default :
			printf("invalid choice \n");	
		}
	

	printf("\nEnter 1 to return to Main menu, or 2 to exit: ");
scanf("%d",&h1);
if(h1==1){
	goto menu;
	
}else if(h1==2){
	printf("Thank you for using .");
}	
	return 0;
}



void display(){
	employee s1;
	FILE *fp;
	fp = fopen("name.txt","r");
	
	while(fread(&s1,sizeof(employee),1,fp)){
		printf("%d %s %ld %d %lu %s %s\n",s1.id,s1.name,s1.salary,s1.join_year,s1.phone,s1.dob,s1.designation);
	}
	fclose(fp);
}
void create(){
	employee *s;
	FILE *fp;
	int n,i;
	printf("Enter the number of employees you want : ");
	scanf("%d",&n);
	
	s=(employee*)calloc(n,sizeof(employee));
	fp=fopen("name.txt","w");
	
	for(i=0;i<n;i++){
			printf("\nEmployee ID : ");
			scanf("%d",&s[i].id);
			printf("Name : ");
			fflush(stdin);
			scanf("%s",&s[i].name); 
			printf("Salary : ");
			fflush(stdin);
			scanf("%ld",&s[i].salary);
			printf("Join year : ");
			scanf("%d",&s[i].join_year);
			printf("Phone number : ");
			scanf("%lu",&s[i].phone);
			printf("Date of Birth : ");
			fflush(stdin);
			gets(s[i].dob);
			printf("Designation : ");
			fflush(stdin);
			gets(s[i].designation);
		fwrite(&s[i],sizeof(employee),1,fp);	
	}
	fclose(fp);
}
void add_employee(){
	
	employee *s;
	FILE *fp;
	int n,i;
	printf("Enter the number of employees you want : ");
	scanf("%d",&n);
	
	s=(employee*)calloc(n,sizeof(employee));
	fp=fopen("name.txt","a");
	
	for(i=0;i<n;i++){
			printf("\nEmployee ID : ");
			scanf("%d",&s[i].id);
			printf("Name : ");
			fflush(stdin);
			scanf("%s",&s[i].name); 
			printf("Salary : ");
			fflush(stdin);
			scanf("%ld",&s[i].salary);
			printf("Join year : ");
			scanf("%d",&s[i].join_year);
			printf("Phone number : ");
			scanf("%lu",&s[i].phone);
			printf("Date of Birth : ");
			fflush(stdin);
			gets(s[i].dob);
			printf("Designation : ");
			fflush(stdin);
			gets(s[i].designation);
		fwrite(&s[i],sizeof(employee),1,fp);	
	}
	fclose(fp);
	
}

void Noofrecord(){
	employee s1;
	FILE *fp;
	fp = fopen("name.txt","r");
	fseek(fp,0,SEEK_END);
	int n =ftell(fp)/sizeof(employee);
	printf("NO of records = %d \n",n);
	fclose(fp);
	
}

void search_employee(){
	employee s1;
	FILE *fp;
	int n,found=0;
	fp = fopen("name.txt","r");
	printf("Enter employee id to search : ");
	scanf("%d",&n);
	while(fread(&s1,sizeof(employee),1,fp)){
		if(s1.id==n){
		found = 1;
			printf("\nEmployee ID : %d\n",s1.id);
			printf("Name : %s\n",s1.name); 
			printf("Salary : %ld\n",s1.salary);
			printf("Join year : %d\n",s1.join_year);
			printf("Phone number : %lu\n",s1.phone);
			printf("Date of Birth : %s\n",s1.dob);
			printf("Designation : %s\n",s1.designation);
//		printf("%d %s %ld %d %lu %s %s\n",s1.id,s1.name,s1.salary,s1.join_year,s1.phone,s1.dob,s1.designation);
}
		
	}
	if(!found){
		printf("\nrecord not found \n");
	}
	fclose(fp);
	
	
}

void update_employee_data(){
		employee s1;
	FILE *fp, *ft;
	int n,found=0;
	fp = fopen("name.txt","r");
	ft = fopen("temp.txt","w");
	printf("Enter employee id to change data : ");
	scanf("%d",&n);
	while(fread(&s1,sizeof(employee),1,fp)){
		if(s1.id==n){
		found = 1;
		printf("new Name : ");
			fflush(stdin);
		scanf("%s",&s1.name); 
		printf("new Salary : ");
			fflush(stdin);
		scanf("%ld",&s1.salary);
		printf("new Join year : ");
		scanf("%d",&s1.join_year);
		printf("new Phone number : ");
		scanf("%lu",&s1.phone);
		printf("new Date of Birth : ");
			fflush(stdin);
		gets(s1.dob);
		printf("new Designation : ");
			fflush(stdin);
		gets(s1.designation);
}
	fwrite(&s1,sizeof(employee),1,ft);	
	}
	fclose(ft);
	fclose(fp);
	
	if(found){
		ft=fopen("temp.txt","r");
		fp=fopen("name.txt","w");
		
		while(fread(&s1,sizeof(employee),1,ft)){
			fwrite(&s1,sizeof(employee),1,fp);
		}
		
		fclose(ft);
		fclose(fp);
		
	}else{
		printf("\nrecord not found \n");
	}
	
}


void fired_employee(){
		employee s1;
	FILE *fp, *ft;
	int n,found=0;
	fp = fopen("name.txt","r");
	ft = fopen("temp.txt","w");
	printf("Enter employee id to fired : ");
	scanf("%d",&n);
	while(fread(&s1,sizeof(employee),1,fp)){
		if(s1.id==n){
		found = 1;
	
}else
	fwrite(&s1,sizeof(employee),1,ft);	
	}
	fclose(ft);
	fclose(fp);
	
	if(found){
		ft=fopen("temp.txt","r");
		fp=fopen("name.txt","w");
		
		while(fread(&s1,sizeof(employee),1,ft)){
			fwrite(&s1,sizeof(employee),1,fp);
		}
		
		fclose(ft);
		fclose(fp);
		
	}else{
		printf("\nrecord not found \n");
	}
	
}
