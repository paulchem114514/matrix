#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	double **mat;
	int row;
	int col;
} Matrix;
int get_matrix_num();
int get_row();
int get_col();
//����ռ䲻��ʼ�� 
void InitialMatrix(Matrix *A,int row,int col);
//Ҫ�ȷ����ڴ�����ʹ�ã�����Ԫ�س�ʼ��Ϊ0
void InitialMatrixZero(Matrix *A,int row,int col);
 //Ҫ�ȷ����ڴ�����ʹ�ã�����Ԫ��1-50������
void InitialMatrixRand(Matrix *A,int row,int col);
//Ҫ�ȷ����ڴ�����ʹ��,��������
void InputMatrix(Matrix *A);
 //����һ�������
int Randnum(); 
 //�ͷž���ռ� 
void DestroyMatrix(Matrix *A); 
//�������
void PrintfMatrix(Matrix *A);
//A+B=C
int AddMatrix(Matrix *A,Matrix *B,Matrix *C);
//A-B=C
int MinusMatrix(Matrix *A,Matrix *B,Matrix *C);
//A*B=C
int MuitiMatrix(Matrix *A,Matrix *B,Matrix *C);
//����Ԫ�ؾ�ֵ
double MeanMatrix(Matrix *T);
//����Ԫ�����ֵ
int MaxMatrix(Matrix *T);
//��T1������T2
int SubMatrix(Matrix *T1,Matrix *T2,int row_1,int row_2,int col_1,int col_2);
//�����zhuanzhi
void TransMatrix(Matrix *T);
//�����һ��
void NormMatrix(Matrix *T);
//B**(-1)=A
void ReverseMatrix(Matrix *A,Matrix *B);
//ʹĳһ�п���ʹ�ø�˹��Ԫ��
void SwapRow(Matrix *T,Matrix *A,int UseRow);

//������Ϊ�н����ξ���
void REM(Matrix *A,Matrix *B);
//���н����ξ���ΪI
void Matrix_I(Matrix *A,Matrix *B);
int main()
{ 
	for(int i=0;i<45;i++)
	{
		printf("*");
	}
	printf("\n");
	printf("ѡ����Ҫִ�еĹ��ܣ������Ӧ�����֣�\n 1. ����һ������������ֵ\n");
	printf(" 2. ����һ�����������������ֵ\n");
	printf(" 3. ��������������������\n 4. ��������������������\n");
	printf(" 5. ��������������������\n 6. �������������������������\n 7. �������������������������\n");
	printf(" 8. �������������������������\n 9. ����������������2-4�У�1-3�е�����\n");
	printf("10. ����һ�����������Ԫ�ص����ֵ\n11. ����һ����������������Ԫ�ص����ֵ\n12. ����һ�����������ת��\n13. ����һ����������������ת��\n14. ����һ������������һ��\n15. ����һ�����������������һ��\n16. ����һ��������������\n");
	printf("17. ����һ�������������������\n 0:����!\n");
	printf("���ܣ�"); 
	int select;
	scanf("%d",&select);
	switch(select)
	{
		case 1:
		{		
			Matrix *A=(Matrix *)malloc(sizeof(Matrix));
			int row_1=get_row();
			int col_1=get_col();
			InitialMatrix(A,row_1,col_1);
			InputMatrix(A);
			printf("%lf\n",MeanMatrix(A));
			DestroyMatrix(A);
            break;
		} 
		case 2:
		{
			Matrix *A=(Matrix *)malloc(sizeof(Matrix));
			printf("������Ҫ���������������������\n");
			int row_1=get_row();
			int col_1=get_col();
			InitialMatrix(A,row_1,col_1);
			InitialMatrixRand(A,row_1,col_1);
			PrintfMatrix(A);
			printf("%lf\n",MeanMatrix(A));
			DestroyMatrix(A);
			break;
		}
		case 3:
		{
			Matrix *A=(Matrix *)malloc(sizeof(Matrix));
			printf("��һ���������Ϣ\n");
			int row_1=get_row();
			int col_1=get_col();
			InitialMatrix(A,row_1,col_1);
			InputMatrix(A);
			Matrix *B=(Matrix *)malloc(sizeof(Matrix));
			printf("�ڶ����������Ϣ\n");
			row_1=get_row();
			col_1=get_col();
			InitialMatrix(B,row_1,col_1);
			InputMatrix(B);
			Matrix *C=(Matrix *)malloc(sizeof(Matrix));
			InitialMatrix(C,row_1,col_1);
			if(AddMatrix(A,B,C)==1)
			{
				printf("��������Ӻ�ľ������Ϣ\n");
				PrintfMatrix(C);
			}
			else
			{
				printf("�����������޷����\n");
			}
			DestroyMatrix(A);
			DestroyMatrix(B);
			DestroyMatrix(C);
			break;
		}
		case 4:{
			Matrix *A=(Matrix *)malloc(sizeof(Matrix));
			printf("��һ���������Ϣ\n");
			int row_1=get_row();
			int col_1=get_col();
			InitialMatrix(A,row_1,col_1);
			InputMatrix(A);
			Matrix *B=(Matrix *)malloc(sizeof(Matrix));
			printf("�ڶ����������Ϣ\n");
			row_1=get_row();
			col_1=get_col();
			InitialMatrix(B,row_1,col_1);
			InputMatrix(B);
			Matrix *C=(Matrix *)malloc(sizeof(Matrix));
			InitialMatrix(C,row_1,col_1);
			if(MinusMatrix(A,B,C)==1)
			{
				printf("�����������ľ������Ϣ\n");
				PrintfMatrix(C);
			}
			else
			{
				printf("�����������޷����\n");
			}
			DestroyMatrix(A);
			DestroyMatrix(B);
			DestroyMatrix(C);
			break;
		}
		case 5:{
			Matrix *A=(Matrix *)malloc(sizeof(Matrix));
			printf("��һ���������Ϣ\n");
			int row_1=get_row();
			int col_1=get_col();
			InitialMatrix(A,row_1,col_1);
			InputMatrix(A);
			Matrix *B=(Matrix *)malloc(sizeof(Matrix));
			printf("�ڶ����������Ϣ\n");
			int row_2=get_row();
			int col_2=get_col();
			InitialMatrix(B,row_2,col_2);
			InputMatrix(B);
			Matrix *C=(Matrix *)malloc(sizeof(Matrix));
			InitialMatrix(C,row_1,col_2);
			if(MuitiMatrix(A,B,C)==1)
			{
				printf("��������˺�ľ������Ϣ\n");
				PrintfMatrix(C);
			}
			else
			{
				printf("�����������޷����\n");
			}
			DestroyMatrix(A);
			DestroyMatrix(B);
			DestroyMatrix(C);
			break;
		}
		case 6:
		{
			Matrix *A=(Matrix *)malloc(sizeof(Matrix));
			printf("������Ҫ���������������������\n");
			int row_1=get_row();
			int col_1=get_col();
			InitialMatrix(A,row_1,col_1);
			InitialMatrixRand(A,row_1,col_1);
			printf("��һ������\n");
			PrintfMatrix(A);
			Matrix *B=(Matrix *)malloc(sizeof(Matrix));
			InitialMatrix(B,row_1,col_1);
			InitialMatrixRand(B,row_1,col_1);
			printf("�ڶ�������\n");
			PrintfMatrix(B);
			Matrix *C=(Matrix *)malloc(sizeof(Matrix));
			InitialMatrix(C,row_1,col_1);
			if(AddMatrix(A,B,C)==1)
			{
				printf("��������Ӻ�ľ������Ϣ\n");
				PrintfMatrix(C);
			}
			else
			{
				printf("�����������޷����\n");
			}
			DestroyMatrix(A);
			DestroyMatrix(B);
			DestroyMatrix(C);
			break;
		}
		case 7:
		{
			Matrix *A=(Matrix *)malloc(sizeof(Matrix));
			printf("������Ҫ���������������������\n");
			int row_1=get_row();
			int col_1=get_col();
			InitialMatrix(A,row_1,col_1);
			InitialMatrixRand(A,row_1,col_1);
			printf("��һ������\n");
			PrintfMatrix(A);
			Matrix *B=(Matrix *)malloc(sizeof(Matrix));
			InitialMatrix(B,row_1,col_1);
			InitialMatrixRand(B,row_1,col_1);
			printf("�ڶ�������\n");
			PrintfMatrix(B);
			Matrix *C=(Matrix *)malloc(sizeof(Matrix));
			InitialMatrix(C,row_1,col_1);
			if(MinusMatrix(A,B,C)==1)
			{
				printf("�����������ľ������Ϣ\n");
				PrintfMatrix(C);
			}
			else
			{
				printf("�����������޷����\n");
			}
			DestroyMatrix(A);
			DestroyMatrix(B);
			DestroyMatrix(C);
			break;
		}
		case 8:
        {
            Matrix *A=(Matrix *)malloc(sizeof(Matrix));
			printf("������Ҫ���������������������\n");
			int row_1=get_row();
			int col_1=get_col();
			InitialMatrix(A,row_1,col_1);
			InitialMatrixRand(A,row_1,col_1);
			printf("��һ������\n");
			PrintfMatrix(A);
			Matrix *B=(Matrix *)malloc(sizeof(Matrix));
            row_1=get_row();
			col_1=get_col();
			InitialMatrix(B,row_1,col_1);
			InitialMatrixRand(B,row_1,col_1);
			printf("�ڶ�������\n");
			PrintfMatrix(B);
			Matrix *C=(Matrix *)malloc(sizeof(Matrix));
			InitialMatrix(C,row_1,col_1);
			if(MuitiMatrix(A,B,C)==1)
			{
				printf("��������˺�ľ������Ϣ\n");
				PrintfMatrix(C);
			}
			else
			{
				printf("�����������޷����\n");
			}
			DestroyMatrix(A);
			DestroyMatrix(B);
			DestroyMatrix(C);
			break;
        }
		case 9:
        {
            Matrix *A=(Matrix *)malloc(sizeof(Matrix));
			printf("����������Ϣ\n");
			int row_1=get_row();
			int col_1=get_col();
			InitialMatrix(A,row_1,col_1);
			InputMatrix(A);
            int col_2;
            int row_2;
            printf("����Ҫ�鿴���������Ϣ");
            printf("��������ʼĩ��,�Կո����");
            scanf("%d %d",&row_1,&row_2);
            printf("��������ʼĩ��,�Կո����");
            scanf("%d %d",&col_1,&col_2);
            Matrix *T=(Matrix *)malloc(sizeof (Matrix));
            T->mat=(double **)malloc(sizeof(double*)*(row_2-row_1+1));
            for(int i=0;i<row_2-row_1+1;i++)
            {
                T->mat[i]=(double*)malloc(sizeof(double)*(col_2-col_1+1));
            }
            SubMatrix(T ,A , row_1 , row_2 , col_1 , col_2);
            printf("�������Ϣ����\n");
            PrintfMatrix(T);
            DestroyMatrix(T);
            DestroyMatrix(A);
            break;
        }
		case 10:
        {
            Matrix *A=(Matrix *)malloc(sizeof(Matrix));
			printf("����������Ϣ\n");
			int row_1=get_row();
			int col_1=get_col();
			InitialMatrix(A,row_1,col_1);
			InputMatrix(A);
            printf("���Ԫ����");
            printf("%d",MaxMatrix(A));
            DestroyMatrix(A);
            break;
        }
		case 11:
        {
            Matrix *A=(Matrix *)malloc(sizeof(Matrix));
			printf("������Ҫ���������������������\n");
			int row_1=get_row();
			int col_1=get_col();
			InitialMatrix(A,row_1,col_1);
			InitialMatrixRand(A,row_1,col_1);
			PrintfMatrix(A);
            printf("���Ԫ����");
            printf("%d",MaxMatrix(A));
            DestroyMatrix(A);
            break;
        }
		case 12:
        {
            Matrix *A=(Matrix *)malloc(sizeof(Matrix));
			printf("����������Ϣ\n");
			int row_1=get_row();
			int col_1=get_col();
			InitialMatrix(A,row_1,col_1);
			InputMatrix(A);
            printf("�����ת��Ϊ��\n");
            TransMatrix(A);
            DestroyMatrix(A);
            break;
        }
		case 13:
        {
            Matrix *A=(Matrix *)malloc(sizeof(Matrix));
			printf("������Ҫ���������������������\n");
			int row_1=get_row();
			int col_1=get_col();
			InitialMatrix(A,row_1,col_1);
			InitialMatrixRand(A,row_1,col_1);
			PrintfMatrix(A);
            printf("�����ת��Ϊ��\n");
            TransMatrix(A);
            DestroyMatrix(A);
            break;
        }
		case 14:
        {
            Matrix *A=(Matrix *)malloc(sizeof(Matrix));
			printf("����������Ϣ\n");
			int row_1=get_row();
			int col_1=get_col();
			InitialMatrix(A,row_1,col_1);
			InputMatrix(A);
            NormMatrix(A);
            printf("�����ǹ�һ����ľ���\n");
            NormMatrix(A);
            PrintfMatrix(A);
            DestroyMatrix(A);
            break;
        }
		case 15:
        {
            Matrix *A=(Matrix *)malloc(sizeof(Matrix));
			printf("������Ҫ���������������������\n");
			int row_1=get_row();
			int col_1=get_col();
			InitialMatrix(A,row_1,col_1);
			InitialMatrixRand(A,row_1,col_1);
			PrintfMatrix(A);
            NormMatrix(A);
            printf("�����ǹ�һ����ľ���\n");
            NormMatrix(A);
            PrintfMatrix(A);
            DestroyMatrix(A);
            break;
        }
		case 16:
        {
            Matrix *A=(Matrix *)malloc(sizeof(Matrix));
            Matrix *B=(Matrix *)malloc(sizeof(Matrix));
			printf("����������Ϣ\n");
			int row_1=get_row();
			int col_1=get_col();
			InitialMatrix(A,row_1,col_1);
            InitialMatrix(B,row_1,col_1);
			InputMatrix(B);
            ReverseMatrix(A,B);
            DestroyMatrix(A);
            DestroyMatrix(B);
            break;
        }
		case 17:
        {
            Matrix *A=(Matrix *)malloc(sizeof(Matrix));
            Matrix *B=(Matrix *)malloc(sizeof(Matrix));
			printf("������Ҫ���������������������\n");
			int row_1=get_row();
			int col_1=get_col();
			InitialMatrix(B,row_1,col_1);
            InitialMatrix(A,row_1,col_1);
			InitialMatrixRand(B,row_1,col_1);
			PrintfMatrix(B);
            ReverseMatrix(A,B);
            DestroyMatrix(A);
            DestroyMatrix(B);
            break;
        }
		case 0:
		{
			return 0;
		}
		default : printf("�ù��ܲ����ڣ���\n");exit(-1);

	}
}

int get_row()
{
	int n;
	printf("������������\n");
	if(scanf("%d",&n)!=1)
	{
		printf("������Ĳ���һ������,���������룺\n");
		getchar();
		return get_row();
	}
	if(n<1)
	{
		printf("����������ֲ�����Ҫ��,���������룺\n");
		getchar();
		return get_row();
	}
	return n;
}
int get_col()
{
	int n;
	printf("������������\n");
	if(scanf("%d",&n)!=1)
	{
		printf("������Ĳ���һ������,���������룺\n");
		getchar();
		return get_col();
	}
	if(n<1)
	{
		printf("����������ֲ�����Ҫ��,���������룺\n");
		getchar();
		return get_col();
	}
	return n;
}
void InitialMatrix(Matrix *A,int rows,int cols)
{
	A->row=rows;
	A->col=cols;
	A->mat = (double **)malloc(rows * sizeof(double *));
	for (int i = 0; i < rows; i++) 
	{
    	A->mat[i] = (double *)malloc(cols * sizeof(double));
	}
}
void InitialMatrixZero(Matrix *A,int row,int col)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			A->mat[i][j]=0;
		}	
	} 
}
int Randnum()
{
	int i=rand()%50+1;
	return i;
} 
void InitialMatrixRand(Matrix *A,int row,int col)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			A->mat[i][j]=Randnum();
		}
	}
}
void InputMatrix(Matrix *A)
{
	printf("һ��һ�е���������,ÿһ�е������ÿո����\n");
	for(int i=0;i<A->row;i++)
	{
		for(int j=0;j<A->col;j++)
		{
			scanf("%lf",&A->mat[i][j]);
			if(j==A->col)
			{
				printf("\n");
			}
		}
	} 
}
void DestroyMatrix(Matrix *A)
{
	free(A->mat);
	free(A);
}
void PrintfMatrix(Matrix *A)
{
	for(int i=0;i<A->row;i++)
	{
		for(int j=0;j<A->col;j++)
		{
			printf("%10lf",A->mat[i][j]);
			if(j!=A->col-1)
			{
				printf(" ");
			}
			else
			{
				printf("\n");
			}
		}
	}
}
int AddMatrix(Matrix *A,Matrix *B,Matrix *C)
{
	if(A->col==B->col&&A->row==B->row)
	{
		for(int i=0;i<A->row;i++)
		{
			for(int j=0;j<A->col;j++)
			{
				C->mat[i][j]=A->mat[i][j]+B->mat[i][j];
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
int MinusMatrix(Matrix *A,Matrix *B,Matrix *C)
{
	if(A->col==B->col&&A->row==B->row)
	{
		for(int i=0;i<A->row;i++)
		{
			for(int j=0;j<A->col;j++)
			{
				C->mat[i][j]=A->mat[i][j]-B->mat[i][j];
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
int MuitiMatrix(Matrix *A,Matrix *B,Matrix *C)
{
	if(A->col==B->row)
	{
		for(int i=0;i<A->row;i++)
		{
			for(int j=0;j<B->col;j++)
			{
				C->mat[i][j]=0;
				for(int k=0;k<A->col;k++)
				{
					C->mat[i][j]+=A->mat[i][k]*B->mat[k][j];
				}	
			} 
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
double MeanMatrix(Matrix *T)
{
	int K=0;
	for(int i=0;i<T->row;i++)
	{
		for(int j=0;j<T->col;j++)
		{
			K+=T->mat[i][j];	
		}
	}
	return K/(T->row*T->col);
}
int MaxMatrix(Matrix *T)
{
	int Max=T->mat[0][0];
	for(int i=0;i<T->row;i++)
	{
		for(int j=0;j<T->col;j++)
		{
			Max=Max>T->mat[i][j] ? Max : T->mat[i][j];
		}
	}
	return Max;

} 
int SubMatrix(Matrix *T1,Matrix *T2,int row_1,int row_2,int col_1,int col_2)
{
    for(int i=0;i<row_2-row_1+1;i++)
    {
        for(int j=0;j<col_2-col_1+1;j++)
        {
            T1->mat[i][j]=T2->mat[i+row_1][j+col_1];
        }
    }
}
void TransMatrix(Matrix *T)
{
    for(int i=0;i<T->col;i++)
    {
        for(int j=0;j<T->row;j++)
        {
            printf("%10lf",T->mat[i][j]);
			if(j!=T->col-1)
			{
				printf(" ");
			}
			else
			{
				printf("\n");
			}
        }
    }
}
void NormMatrix(Matrix *T)
{
    long sum=0;
    for(int i=0;i<T->row;i++)
    {
        for(int j=0;j<T->col;j++)
        {
            sum+=(long)T->mat[i][j];
        }
    }
    for(int i=0;i<T->row;i++)
    {
        for(int j=0;j<T->col;j++)
        {
            T->mat[i][j]=(long)(T->mat[i][j]/sum);
        }
    }
}
void ReverseMatrix(Matrix *A,Matrix *B)
{
    if(B->col!=B->row)
    {
        printf("�þ����Ƿ��󣬲������������");
    }
    else
    {
        InitialMatrixZero(A,A->row,A->col);
        for(int i=0;i<B->col;i++)
        {
            A->mat[i][i]=1;
        }
        REM(A,B);
		Matrix_I(A,B);
        printf("�������������£�\n");
        PrintfMatrix(A);

    }
}
void SwapRow(Matrix *A,Matrix *B,int UseRow)
{

    for(int i=UseRow+1;i<B->col;i++)
    {
        if(B->mat[UseRow][UseRow]!=0)               
        {
            break;
        }
        else
        {
            double k;
            for(int j=0;j<B->col;j++)
            {
                k=B->mat[UseRow][j];
                B->mat[UseRow][j]=B->mat[i][j];
                B->mat[i][j]=k;
                k=A->mat[UseRow][j];
                A->mat[UseRow][j]=A->mat[i][j];
                A->mat[i][j]=k;
                
            }
        }
        if(B->mat[UseRow][UseRow]==0)
        {
            printf("�þ��󲻿��棡��������");
            exit(-1);
        }
    }
	if(B->mat[UseRow][UseRow]==0)
        {
            printf("�þ��󲻿��棡��������");
            exit(-1);
        }
}
void REM(Matrix *A,Matrix *B)
{
	for(int i=0;i<B->col;i++)
    {
        SwapRow(A,B,i);
		double portion;
		for(int j=i+1;j<B->col;j++)
		{
			portion=B->mat[j][i]/B->mat[i][i];
			for(int k=0;k<B->col;k++)
			{
				B->mat[j][k]-=portion*(B->mat[i][k]);
				A->mat[j][k]-=portion*(A->mat[i][k]);
			}
		}
    }


}
void Matrix_I(Matrix *A,Matrix *B)
{
	for(int i=B->col-1;i>-1;i--)
	{
		double portion;
		for(int j=i-1;j>-1;j--)
		{
			portion=B->mat[j][i]/B->mat[i][i];
			B->mat[j][i]=0;
			for(int k=0;k<B->col;k++)
			{
				A->mat[j][k]-=portion*(A->mat[i][k]);
			}
		}
	}
	for(int i=0;i<B->col;i++)
	{
		double portion=B->mat[i][i];
		for(int j=0;j<B->col;j++)
		{
			A->mat[i][j]/=portion;
		}
	}
	
}