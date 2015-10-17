#include<stdio.h>
#include<stdlib.h>

void printMatrix(int [][3]);
int inputMatrix(int matrix[][10] , int row, int column)
{
	int i, j, nonZero  = 0;
	printf("\n Enter the elements of the matrix : \n");
	for(i=0; i<row; i++)
	{
		for(j=0; j<column; j++)
		{
			scanf("%d",&matrix[i][j]);
			if(matrix[i][j]!=0)
				nonZero++;
		}
	}
	return nonZero;
}

void convertToSparse(int nMatrix[][10], int sMatrix[][3] , int row, int column, int nonZero)
{
	int i, j, k =1;		// k is for the number of rows in the sparse matrix.
	sMatrix[0][0] = row;
	sMatrix[0][1] = column;
	sMatrix[0][2] = nonZero;
	for(i=0; i<row; i++)
	{
		for(j=0; j<column; j++)
		{
			if(nMatrix[i][j]!=0)
			{
				sMatrix[k][0] = i;
				sMatrix[k][1] = j;
				sMatrix[k][2] = nMatrix[i][j];
				k++;
			}
		}
	}
	//printMatrix(sMatrix);
}

void printMatrix(int sMatrix[10][3])
{
	int i;
	for(i=0; i<sMatrix[0][2]+1; i++)
	{
		printf("\n");
		printf("%d\t%d\t%d",sMatrix[i][0],sMatrix[i][1],sMatrix[i][2]);
	}
}

void simpleTranspoe(int sMatrix[][3], int st[][3])
{
	int i,j;
	int k = 1;
	st[0][0] = sMatrix[0][1];
	st[0][1] = sMatrix[0][0];
	st[0][2] = sMatrix[0][2];

	for(i=0; i<sMatrix[0][1]; i++)
	{
		for(j=1; j<sMatrix[0][2]+1; j++)
		{
			if(i == sMatrix[j][1])
			{
				st[k][0] = i;
				st[k][1] = sMatrix[j][0];
				st[k][2] = sMatrix[j][2];
				k++;
			}
		}
	}
	printMatrix(st);
}

void fastTranspose(int sMatrix[][3], int ft[][3])
{
	int nonZero = sMatrix[0][2];
	int column = sMatrix[0][1];
	int count[20], rowIndex[20],i,col_index, location;
	ft[0][0] = sMatrix[0][1];
	ft[0][1] = sMatrix[0][0];
	ft[0][2] = sMatrix[0][2];
	// initializing the number of elements in each column of matrix to zero
	for(i=0; i<column; i++)
	{
		count[i] = 0;
	}
	// counting the number of elements in each column of matrix
	for(i=1; i<nonZero+1; i++)
	{
		col_index = sMatrix[i][1];
		count[col_index]++;
	}
	rowIndex[0] = 1; 	// because the zeroth row will start from the first line.
	for(i=1; i<column; i++)
	{
		rowIndex[i] = rowIndex[i-1]+count[i-1];
	}
	// now we need to place the elements at its right position
	for(i=1; i<nonZero+1; i++)
	{
		col_index = sMatrix[i][1];
		location = rowIndex[col_index];
		rowIndex[col_index]++;
		ft[location][0] = sMatrix[i][1];
		ft[location][1] = sMatrix[i][0];
		ft[location][2] = sMatrix[i][2];
	}
	printMatrix(ft);
}

void additionOfMatrix(int add[][3])
{
	int i=1, j=1, k=1;
	int r1,c1,r2,c2,n1,n2;
	int a[10][10],b[10][10],c[20][3],d[20][3];
	printf("\n Enter the row and column of matrix A : ");
	scanf("%d%d",&r1,&c1);
	n1 = inputMatrix(a,r1,c1);
	printf("\n Enter the row and column of matrix B : ");
	scanf("%d%d",&r2,&c2);
	n2 = inputMatrix(b, r2, c2);
	// now i want these matrices to be converted into triplet representation
	convertToSparse(a,c,r1,c1,n1);
	convertToSparse(b,d,r2,c2,n2);
	// now i have c and d as the sparse matrix

	if(!(r1 == r2 && c1 == c2))
	{
		printf("\n Sorry..!!! these matrices can't be added ");
		return ;
	}
	add[0][0] = c[0][0];
	add[0][1] = c[0][1];
	while(i<=n1 && j<=n2)
	{
		if(c[i][0]<d[j][0])
		{
			add[k][0] = c[i][0];
			add[k][1] = c[i][1];
			add[k][2] = c[i][2];
			i++;
			k++;
		}
		if(d[j][0]<c[i][0])
		{
			add[k][0] = d[j][0];
			add[k][1] = d[j][1];
			add[k][2] = d[j][2];
			k++;
			j++;
		}
		// note: if we find that program does not go in any of the above if condition then one thing is sure that row indices
		// are same, thus we need to do some operations considering the column indices
		if(c[i][1] < d[j][1])
		{
			add[k][0] = c[i][0];
			add[k][1] = c[i][1];
			add[k][2] = c[i][2];
			k++;
			i++;
		}
		if(d[j][1]<c[i][1])
		{
			add[k][0] = d[j][0];
			add[k][1] = d[j][1];
			add[k][2] = d[j][2];
			k++;
			j++;
		}
		// now the only case left is the one in which row and column indices are equal
		if(c[i][0] == d[j][0] && c[i][1] == d[j][1])
		{
			add[k][0] = c[i][0];
			add[k][1] = c[i][1];
			add[k][2] = c[i][2]+d[j][2];
			k++;
			i++;
			j++;
		}

	}
	while(i<=n1)
	{
		add[k][0] = c[i][0];
		add[k][1] = c[i][1];
		add[k][2] = c[i][2];
		k++;
		i++;
	}
	while(j<=n2)
	{
		add[k][0] = d[j][0];
		add[k][1] = d[j][1];
		add[k][2] = d[j][2];
		k++;
		j++;
	}
	add[0][2] = k-1;
	printf("\n The addition of two matrices is : \n");
	printMatrix(add);

}



int main()
{
	int nMatrix[10][10], sMatrix[10][3], nr, nc, ch, nonZero;
	int flag = 0, flag1 = 0;
	int st[10][3], ft[10][3],add[20][3];
	do
	{
		printf("\n Enter your choice : \n ");
		printf("\n 1. INPUT NORMAL MATRIX : ");
		printf("\n 2. CONVERT TO SPARSE MATRIX : ");
		printf("\n 3. PRINT MATRIX IN TRIPLET FORM ");
		printf("\n 4. SIMPLE TRANSPOSE OF THE MATRIX : ");
		printf("\n 5. FAST TRANSPOSE OF THE MATRIX : ");
		printf("\n 6. ADDITION OF SPARSE MATRIX : ");
		printf("\n 7. EXIT : \n ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
				// input the matrix in normal form
				printf("\n Enter the number of rows : ");
				scanf("%d",& nr);
				printf("\n Enter the number of columns : ");
				scanf("%d",&nc);
				nonZero = inputMatrix(nMatrix,nr,nc);
				flag = 1;
				break;
		case 2:
				// conversion to sparse matrix
				if(flag!=1)
				{
					printf("\n First you need to enter the matrix \n");
					break;
				}
				flag1 = 1;
				convertToSparse(nMatrix,sMatrix,nr,nc,nonZero);
				break;
		case 3:
				// print the matrix in triplet form
				if(flag!=1)
				{
					printf("\n First you need to enter the matrix \n");
					break;
				}
				if(flag1 != 1);
				printMatrix(sMatrix);
				flag = 2;
				break;
		case 4:
				// simple transpose
				if(flag != 2)
				{
					printf("\n You need to enter the matrix and convert it to sparse form \n");
					break;
				}
				simpleTranspoe(sMatrix, st);
				break;
		case 5:
				// fast transpose
				if(flag != 2)
				{
					printf("\n You need to enter the matrix and convert it to sparse form \n");
					break;
				}
				fastTranspose(sMatrix,ft);
				break;
		case 6:
				// addition of matrices
				additionOfMatrix(add);
				break;
		case 7:
				exit(0);
		default:
				printf("\n WRONG CHOICE ");
				break;
		}


	}while(ch!=7);
	return 0;
}
