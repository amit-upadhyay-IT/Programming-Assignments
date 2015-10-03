// this program includes various operations on sparse matrix.

#include<stdio.h>
#include<stdlib.h>
void input(int [][10],int ,int );
void output(int [][10],int ,int );
int sparse(int [][10],int ,int ,int [][10]);
void fast_transpose(int [][10],int ,int ,int ,int [][10]);
void sim_transpose(int [][10],int ,int [][10]);
void sum(int [][10],int [][10],int [][10]);


int main()
{
    printf("\n Code made by :- Amit Upadhyay\n SE - IT \n Army Institute of Technology, Pune");
    int row,col,row1,col1,t,t1,x=0;
    int m[10][10],m2[10][10], s1[20][10],s2[20][10],s3[20][10],T[20][10];
    do
    {

        printf("\n 1:input\n 2:output\n 3:sparse\n 4:simple transpose\n 5:fast transpose\n 6:addition of sparse matrices\n 7:exit\nenter your choice : ");
        scanf("%d",&x);
        switch(x)
        {

        case 1:
                printf("\n enter your col,row for matrix\n");
                scanf("%d %d",&row,&col);
                input(m,row,col);
                break;
        case 2: printf("\n output of given matrix\n");
                output(m,row,col);
                break;
        case 3:
                t= sparse(m,row,col,s1);
                break;
        case 4:sim_transpose(s1,t,T);
               break;
        case 5:
        fast_transpose(s1,row,col,t,T);
               break;
        case 6 :  printf("\n enter your col,row for matrix\n");
                scanf("%d %d",&row1,&col1);
                input(m2,row1,col1);

               printf("\n output of given matrix\n");
                output(m2,row1,col1);
                t1= sparse(m2,row1,col1,s2);

                sum(s1,s2,s3);
                 break;

        }
    }while(x!=7);
    return 0;
}
void input(int m[][10],int row,int col)

{

	int i,r,j;

	int **a;
//printf("%d %d",row,col);

	a= (int**) malloc (row*sizeof(int*));


	for(r=0;r<row;r++)

		a[r] =(int*) malloc(col*sizeof(int));


	printf("\n enter the elements of matrix\n");

	for(i=0;i<row;i++)

	{

		for(j=0;j<col;j++)

			scanf("%d",&m[i][j]);

	}



}

void output(int m[][10],int row,int col)

{

	int i,j;

	for(i=0;i<row;i++)

	{

		for(j=0;j<col;j++)

		printf("%d\t",m[i][j]);

		   printf("\n");


      	}

}
int sparse(int m[][10],int row,int col,int s1[10][10])
{
    int i,j,p,q,t=1;

    p=row;
    q=col;
    s1[0][0]=p;
    s1[0][1]=q;
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            if(m[i][j]!=0)
            {
                s1[t][0]=i;
                s1[t][1]=j;
                s1[t][2]=m[i][j];
                t++;
            }

        }
    }
   s1[0][2]=t-1;
   printf("\nsparse matrix of given matrix\n");
   output(s1,t,3);
   return t-1;
}
void fast_transpose(int s[][10],int row,int col,int t,int T[][10])
{
   int s1[col],T1[col];
   int i,j,p,q,col_num;
   p=row;
   q=col;
   T[0][0]=q;
   T[0][1]=p;
   T[0][2]=t;

   for(i=0;i<p;i++)
        s1[i]=0;
   for(i=1;i<=t;i++)
   {
       col_num=s[i][1];
       s1[col_num]++;
   }
   T1[0]=1;
   for(i=1;i<p;i++)
   {
       T1[i]=T1[i-1]+s1[i-1];
   }
   for(i=1;i<=t;i++)
   {
       int loc;
       col_num=s[i][1];
       loc=T1[col_num];
       T1[col_num]++;
       T[loc][0]=s[i][1];
       T[loc][1]=s[i][0];
       T[loc][2]=s[i][2];

   }
   printf("\n after fast transpose sparse matrix is ....\n");
   output(T,t+1,3);
}
void sim_transpose(int s[][10],int t,int T[][10])
{
    int i,j,k;
      T[0][1]=s[0][0];
      T[0][0]=s[0][1];
      T[0][2]=s[0][2];
      k=1;


          for(i=0;i<s[0][1];i++)
          {
              for(j=1;j<=t;j++)
              {
                  if(s[j][1]==i)
                  {
                     T[k][0]=i;
                     T[k][1]=s[j][0];
                      T[k][2]=s[j][2];
                      k++;
                  }
              }
          }
       printf("\n after simple transpose sparse matrix is ....\n");
      output(T,t+1,3);
}
void sum(int s1[][10],int s2[][10],int s3[][10])
{
    int i=0,j=0,k=0,t1,t2;
    t1=s1[0][2];
    t2=s2[0][2];
    if(s1[0][0]!=s2[0][0]&&s1[0][1]!=s2[0][1])
        printf("additon is not possible");

     s3[0][0]=s1[0][0];
     s3[0][1]=s1[0][1];
    while(i<=t1&&j<=t2)
    {
        if(s1[i][0]<s2[j][0])//if row r  not equal
        {
            s3[k][0]=s1[i][0];
             s3[k][1]=s1[i][1];
              s3[k][2]=s1[i][2];
              i++;
              k++;

        }

     else    if(s2[j][0]<s1[i][0])//if row r  not equal
        {
            s3[k][0]=s2[j][0];
             s3[k][1]=s2[j][1];
              s3[k][2]=s2[j][2];
              j++;
              k++;

        }


       else    if(s1[i][1]<s2[j][0])//if row r equal bt column different
         {
            s3[k][0]=s1[i][0];
             s3[k][1]=s1[i][1];
              s3[k][2]=s1[i][2];
              i++;
              k++;

        }
      else   if(s2[j][1]<s1[i][1])//if row r equal bt column different
        {
            s3[k][0]=s2[j][0];
             s3[k][1]=s2[j][1];
              s3[k][2]=s2[j][2];
              j++;
              k++;

        }

   else    {//if no of column and row are equal
            s3[k][0]=s2[j][0];
             s3[k][1]=s2[j][1];
              s3[k][2]=s2[j][2]+s1[i][2];
              j++;
              k++;
              i++;

       }
    }
  while(i<=t1)
     {
            s3[k][0]=s2[i][0];
             s3[k][1]=s2[i][1];
              s3[k][2]=s2[i][2];
              j++;
              k++;
    }

   while(j<=t2)
          {
             s3[k][0]=s2[j][0];
             s3[k][1]=s2[j][1];
              s3[k][2]=s2[j][2];
              j++;
              k++;

            }
            s3[0][2]=k-1;
            printf("\n after addition \n");
            output(s3,k,3);
}
