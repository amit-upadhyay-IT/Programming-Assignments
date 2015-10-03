
#include<stdio.h>

#include<stdlib.h>


void print(int[],int);

void input(int[],int[],int*,int*);

void set_union(int[],int[],int,int,int[],int*);

void inter(int[],int[],int,int,int[],int*);

void diff(int[],int[],int,int,int[],int*);

void sdiff(int[],int[],int,int,int[],int*);

int main()

{

	int sw,i,len;										// sw -switch choice

	int set1[10],set2[10],setr[20];

	int k1=0,k2=0;								          // no of elememts in simple sets: set1 and set2


	system("cls");

	printf("\t\t\tPROGRAMME ON SETS\n");

	prog_start:									//prog_start    TAG


	printf("Enter choice and press enter\n");

	printf("1. Enter SETS\n");

	printf("0. Exit\n>");

	scanf("%d",&sw);

	switch(sw)

	{

		case 1 :

		system("cls");

		printf("\t\t\tPROGRAMME ON SETS \n");

		printf("> Enter SETS\n");

		input(set1,set2,&k1,&k2);

		break;

		case 0 :


system("cls");

		exit(0);

		break;

		default :

		system("cls");

		printf("\t\t\tPROGRAMME ON SETS\n");
		printf("EROOR : wrong input !\n");

		goto prog_start;

	}


		system("cls");


		printf("\t\t\tPROGRAMME ON SETS \n");

					printf("\nSET 1 ={");
					print(set1,k1);
					printf("\nSET 2 ={");
					print(set2,k2);
					printf("\n");
		back:												//back 		TAG

		printf("Enter choice and press enter\n");
	printf("1. Re-enter SETS\n");
		printf("2. Union\n");

		printf("3. Intersection\n");

		printf("4. Difference\n");

		printf("5. Symmetric difference\n");

		printf("0. Exit\n>");

		scanf("%d",&sw);

		switch(sw)
		{

			case 1 :
			system("cls");

			printf("\t\t\tPROGRAMME ON SETS \n");
			printf("> Re-enter SETS\n");

			input(set1,set2,&k1,&k2);

			system("cls");

			printf("\t\t\tPROGRAMME ON SETS \n");

			printf("\nSET 1 ={");

			print(set1,k1);

			printf("\nSET 2 ={");

			print(set2,k2);

			printf("\n");

			break;

			case 2 :

			system("cls");

			printf("\t\t\tPROGRAMME ON SETS \n");

				printf("\nSET 1 ={");

				print(set1,k1);

				printf("\nSET 2 ={");

				print(set2,k2);

				printf("\n>>UNION SET ={");
				set_union(set1,set2,k1,k2,setr,&len);

				print(setr,len);

				printf("\n");

				break;

			case 3 :

				system("cls");

				printf("\t\t\tPROGRAMME ON SETS \n");

				printf("\nSET 1 ={");

				print(set1,k1);

				printf("\nSET 2 ={");

				print(set2,k2);

				printf("\n>>INTERSECTION SET ={");

				inter(set1,set2,k1,k2,setr,&len);

				print(setr,len);

				printf("\n");system("cls");

				break;


			case 4 :

				system("cls");

				printf("\t\t\tPROGRAMME ON SETS \n");
				printf("\nSET 1 ={");

				print(set1,k1);

				printf("\nSET 2 ={");

				print(set2,k2);

				printf("\n>>DIFFERENCE : SET 1-SET 2 ={");
				diff(set1,set2,k1,k2,setr,&len);

				print(setr,len);

				printf("\tSET 2-SET 1 ={");

				diff(set2,set1,k2,k1,setr,&len);

				print(setr,len);

				printf("\n");

				break;


			case 5 :

			system("cls");
				printf("\t\t\tPROGRAMME ON SETS \n");

				printf("\nSET 1 ={");

				print(set1,k1);

				printf("\nSET 2 ={");

				print(set2,k2);

				printf("\n>>SYMM DIFFERENCE SET ={");

				sdiff(set1,set2,k1,k2,setr,&len);

				print(setr,len);

				printf("\n");system("cls");

				break;


			case 0 :
            system("cls");


				exit(0);

			default :

				system("cls");

				printf("\t\t\tPROGRAMME ON SETS \n");

				printf("\nSET 1 ={");

				print(set1,k1);

				printf("\nSET 2 ={");

				print(set2,k2);

				printf("\nEROOR : wrong input !\n");

				goto back;


		}


		goto back;

}


void print(int set[],int len)
//print() defined

{

	int i;


	if(len==0)

	{

	printf("{");

	}

	for(i=0;i<len;++i)

	{

		printf("%d,",set[i]);

	}

	printf("\b}");

}


void input(int set1[],int set2[],int *k1,int *k2)
// input() defined

{

	int nos;
								//nos-number of elements in SET

	int i,j,flag=0;


	start:										// start:        TAG

	printf("Enter number of elements : ");

	scanf("%d",&nos);

	if(nos<=0||nos>10)

	{

		printf(">>>ERROR : elements can not be zero,negative and more than 10 !\n");

		goto start;

	}

	printf("SET 1\n");
						//enter set1

		for(i=0;i<nos;++i)

		{

			printf("element %d : ",i+1);

			scanf("%d",&set1[i]);

		}

		printf("\nSET 2\n");			//enter set2

				for(i=0;i<nos;++i)

			{

				printf("element %d : ",i+1);

				scanf("%d",&set2[i]);

			}


											//TO SIMPLE SET - eleminating repeating elements

		for(i=0,*k1=0;i<(nos-1);++i)

			{

				for(j=(i+1);j<nos;++j)

				{

					if(set1[i]==set1[j])

					{

						flag=1;

					}


		}



				if(flag==0)

				{

					set1[*k1]=set1[i];

					++*k1;

				}

				flag=0;

	}

	set1[*k1]=set1[i];

	++*k1;

			for(i=0,*k2=0;i<(nos-1);++i)
			{
				for(j=(i+1);j<nos;++j)
				{
					if(set2[i]==set2[j])
					{
					flag=1;
					}

				}

				if(flag==0)
				{
					set2[*k2]=set2[i];
					++*k2;
				}
				flag=0;
			}
		set2[*k2]=set2[i];
		++*k2;
}

void set_union(int set1[],int set2[],int k1,int k2,int setr[],int *count)						//union deifined
{
	int i,j,flag=0;
	*count=k1;
	for(i=0;i<k1;++i)
	{
		setr[i]=set1[i];
	}

		for(i=0;i<k2;++i)
		{
			for(j=0;j<k1;++j)
			{
				if(set2[i]==set1[j])
				{
					flag=1;
				}
			}

			if(flag==0)
			{
				setr[*count]=set2[i];
				++*count;
			}
			flag=0;
		}

}
void inter(int set1[],int set2[],int k1,int k2,int setr[],int *count)				//intersection defined
{
	int i,j,flag=0;
	*count=0;

		for(i=0;i<k2;++i)
		{
			for	(j=0;j<k1;++j)
			{
				if(set2[i]==set1[j])
				{
					flag=1;
				}
			}

			if(flag==1)
			{
				setr[*count]=set2[i];
				++*count;
			}
			flag=0;
		}



}
void diff(int set1[],int set2[],int k1,int k2,int setr[],int *len)					// difference defined
{

	int count=0,i,j,flag=0,dif[10];
	*len=0;
	inter(set1,set2,k1,k2,dif,&count);

		for(i=0;i<k1;++i)
		{
			for(j=0;j<count;++j)
			{
				if(set1[i]==dif[j])
				{
					flag=1;
				}
			}

			if(flag==0)
			{
				setr[*len]=set1[i];
				++*len;
			}
			flag=0;
		}



}
void sdiff(int set1[],int set2[],int k1,int k2,int setr[],int *len)
{
	int l,buffer[10],buffer2[10],i,j;
	diff(set1,set2,k1,k2,setr,&l);

	for(i=0;i<l;++i)
	buffer[i]=setr[i];

	diff(set2,set1,k2,k1,setr,&l);

	for(j=0;j<l;++j)
	buffer2[j]=setr[j];


	set_union(buffer,buffer2,i,j,setr,&(*len));

}





