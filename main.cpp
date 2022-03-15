#include<iostream>

using namespace std;

int n = 10;

void init(int n, double** b, double* col_sum, double*a)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = rand();
		}
		col_sum[i] = 0.0;
		a[i] = rand();
	}


}

void row_major(int n,double**b,double *col_sum, double* a)
{
	//重复10次实验
	for (int u = 0; u < 10; u++)
	{
		for (int i = 0; i < n; i++)
		{
			col_sum[i] = 0.0;
			for (int j = 0; j < n; j++)
			{
				col_sum[j] += b[i][j]*a[i];
			}
		}
	}
}

void col_major(int n, double** b, double* col_sum,double*a)
{
	//重复10次实验
	for (int u = 0; u < 10; u++)
	{
		for (int i = 0; i < n; i++)
		{
			col_sum[i] = 0.0;
			for (int j = 0; j < n; j++)
			{
				col_sum[j] += b[j][i]*a[j];
			}
		}
	}
}

int main()
{


		double** b = new double* [n];
		for (int i = 0; i < n; i++)
		{
			b[i] = new double[n];
		}
		double* col_sum = new double[n];
		double* a = new double[n];

		init(n, b,col_sum,a);

		col_major(n, b, col_sum,a);




		for (int i = 0; i < n; i++)
		{
			col_sum[i] = 0.0;
		}

		row_major(n, b, col_sum,a);


		delete[]col_sum;
		for (int i = 0; i < n; i++)
		{
			delete[]b[i];
		}
		delete[]b;






		return 0;
}
