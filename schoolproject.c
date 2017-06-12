#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define C 200

int N , M , W;
int c;
int number = 0;
int exist = 1;
int a = 1;
char nac[200];


struct student {
	 char college[200];
	 char name[200];
	 char item[200];
	 short sex; 
	 short position;   
	 short score;
}stu[C];

int main();
int writein();

int initialization()
{
	printf("\nThe number of colleges attended is:");
	scanf("%d",&N); 
	printf("\nThe number of men item is:"); 
	scanf("%d",&M);   
	printf("\nThe number of women item is:");   
	scanf("%d",&W);
	return writein();
}

void printf_one(int x) {
	 printf("\n%-20s%-20s%-20s%-5c%-9d%-5d",stu[x].college,stu[x].name,stu[x].item,stu[x].sex,stu[x].position,stu[x].score); 
}

int printf_face_whole() 
{
	printf("\n\nCollege name        man        woman               total");
}



int printf_face() 
{
	printf("\n\nCollege name        student name        item               sex  position score");
}

int printf_sum(int sum) {
	 printf("\n\nThe sum of score is:\t %d",sum); 
	 printf("\nThe college number is: \t%d",N); 
	 printf("\nThe item number is: \t%d\n",W+M);
}

int display_college()
{
	int x = 0;
	int sum = 0;
	int w = 0;
	char college[200];
	printf("\nEnter the name of the college that you want to search:");
	scanf("%s", college);
	printf_face();
	for (; x < number + 1 ; x++)
		if( strcmp( college, stu[x].college) == 0 ){
			sum += stu[x].score;	
			printf_one(x);
		}
	printf_sum(sum);
}

int display_college_whole(char college[200])
{
	int x = 0;
	int sum = 0;
	int w = 0;
	int ms = 0;
	int ws = 0;
	for (; x < number + 1 ; x++)
		if( strcmp( college, stu[x].college) == 0 ){
			if(stu[x].sex == M)
				ms += stu[x].score;
			else
				ws += stu[x].score;
			sum += stu[x].score;	
		}
	printf("\n%-20s%-7d%-7d%-5d",stu[x].college,stu[x].name,stu[x].item,stu[x].sex,stu[x].position,stu[x].score); 
}

int ascending(int *a , int i )
{
	int y = 0;
	int j = 0;
	int temp = 0;
	int tempn = 0;
	int ii = 0;
	for( y = 0 ; y < i - 1; y++ ){
		temp = stu[a[y]].position;
		tempn = a[y];
		j = y ;
		while( j >= 0 && temp > stu[a[j + 1]].position ){
			a[j] = a[j + 1];
			a[j + 1] = tempn;
			j--;
		}
	}
	for( ; ii < i ; ii++ )
		printf_one(a[ii]);
}

int display_item()
{
	int i = 0;
	int x,sum=0,w=0;
	char item[200];
	int a[200];
	int *array = &a[0];
	printf("\nPlease enter the name of the item that you want to search:");  
	scanf("%s",&item[0]); 
	printf("\n\nCollege name        student name        item               sex  position score");
	for( x = 0 ;x < number + 1; x++ )  
		if(strcmp(item,stu[x].item) == 0){
			a[i] = x ;
			i++ ;
		}
	ascending( array , i );
}

int display_person()
{
	int x;
	char person[200];
	int a[200];
	printf("\nEnter the name of the person that you want to search:");
	scanf("%s", person );
	printf_face();
	for (x = 0; x < number ; x++)
		if( strcmp(person,stu[x].name) == 0 )
			printf_one(x);
}
int whole()
{
	int all[N];
	int others[200];
	int other ;
	int nn;
	int now;
	int i;
	for( nn = N - 1;nn != -1; nn-- ){
		for ( other = 0 ; other < number ; other ++ )
			for ( now = 0 , i = 0 ; i < number ; i++ ){
				if (now = others[i]) 
					now++;
				else if( strcmp( stu[now].college, stu[other].college) == 0 ){
  			 		others[now] = other;
					now++;
				}
			}
	}
	printf("1");

	for( nn = N - 1; nn != -1 ; nn-- )
		display_college_whole(stu[all[nn]].college);
	printf("\n\nCollege name        man    woman  total");
}

int display()
{
	int e;
	printf("\nThe form of searching you want to choose:\n(1).By college\n(2).By item(ascending)\n(3).By person\n(4).the whole school\n(5).return to main menu\n");
	scanf("%d",&e);    
	switch(e){
		case 1:
			display_college();
			return display();
		    break;     
		case 2:
			display_item();
			return display();
			break; 
		case 3:
			display_person();
			return display();
			break;
		case 4:
			whole();
			return display();
			break;
		case 5:
			return main();
			break;
		default:
			break;
	}
}

int writein()
{
	int t;
	char nb[200];
	FILE *fp;
	if(a == 1){
		printf("\nPlease name for the input:");

		scanf("%s",&nac[0]);
		strcpy(nb, nac);
		strcat(nb,"@@0.txt");
		fp=fopen(nb,"r");
		if(fp==NULL)
			;
		else {
			printf("The name has already existed!");
			return writein();
		}
		a = 0;
		initialization();
	}
	else{
		printf("\nPlease writein the student's name:");
		scanf("%s",&stu[number].name);
	printf("\nPlease writein the student's college:");
	scanf("%s",&stu[number].college);
	printf("\nPlease writein the student's item:");
	scanf("%s",&stu[number].item);
	printf("\nPlease writein the student's sex(M or W):");
	scanf("%s",&stu[number].sex);
	printf("\nPlease writein the student's position:");
	scanf("%d",&stu[number].position);
	printf("\nSomething wrong?\n1.No 2.discard the record created just now and redo\n");
	scanf("%d" , &t);
	if ( t == 1 ){
		switch (stu[number].position){
			case 1:
	 			stu[number].score = 7;
 				break;
			case 2:
 	 			stu[number].score = 5;
				break;
			case 3:
  	 			stu[number].score = 3;
				break;
			case 4:
  	 			stu[number].score = 2;
			 	break;
			case 5:
 	 			stu[number].score = 1;
			 	break;
			default:
 	  			stu[number].score = 0;
				break;
		}
		char filename[255];
		strcpy(nb, nac);
		sprintf(filename, "@@%d.txt", number);
		strcat(nb,filename);
		fp=fopen( nb , "w+" );
		if( !fp ){
			printf("error!\n");
			exit(-1);
		}
		printf("college:%s,name:%s,item：%s,sex:%d,position:%d,score:%d",stu[number].college,stu[number].name,stu[number].item,stu[number].sex,stu[number].position,stu[number].score);
		fwrite(&stu[number],sizeof(stu[number]),1,fp);
		fclose(fp);
		number++;
	}
	else if ( t == 2 )
		return writein();
	printf("\nDo again?\t1).Yes\t2).No\t\n");
	scanf("%d" , &t);
	if ( t == 1 ){
		printf("Successs");
		return writein();
	}
	else if ( t == 2 ){
		return main();
	}
	}
}


int help()
{
	printf("  ");
	return main();
}

int isfileexisted(char na[200] , int ncc )
{
	FILE *fp;
	char nb[200];
	char nc[255];
	strcpy(nb, na);
	sprintf(nc, "@@%d.txt", ncc);
	strcat(nb, nc);
	fp=fopen(nb,"r");
	if(fp == NULL)
		exist = 0;	
	else
		exist = 1;
}

int read()
{
	int i;
	FILE *fp;
	char na[200];
	printf("\nPlease write the name\n");
	scanf("%s", &na[0] );
	isfileexisted(na,0);
	if ( exist == 0 ){
		printf("We do not have such a file!\n\n");
		return main();
	}
	for(i = 0 ; exist == 1 ; i++ ){
		isfileexisted(na,i);
	}
	for(i = i - 2 ; i != -1 ; i--){
		char nb[200];
		char nc[255];
		strcpy(nb, na);
		sprintf(nc, "@@%d.txt", i);
		strcat(nb, nc);
		fp = fopen(nb , "r");
		fread(&stu[i],sizeof(stu[i]),1,fp);	
		fclose(fp);
	}
	printf("\nSuccess!\n\n");
	display();
}

int main(){
	printf("Welcome to School Sport Meeting Management System\n");
    printf("*****************************************\n");     
	printf("   1.The result records to display\n");
	printf("   2.The result records to input\n");
	printf("   3.help\n");
	printf("   4.exit\n");
	printf("*****************************************\n");
	printf("Choose your number:\n");
    scanf("%d",&c);
	switch(c){
		case 1:
			c = 3;
			printf("Do you need to read the existed record?\n1.Yes 2.No\n");
			scanf("%d" , &c );
			if ( c == 1 )
				read();
			else
				display();
			break;
		case 2: 
			writein();
			break;
		case 3:
			help();
			break;
		case 4: 
			exit (0);
		default:
			break;
	}
}

