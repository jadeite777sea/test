#include<iostream>
#include<fstream>
#include<time.h>
#include<windows.h>
using namespace std;
int BinarySum(int a[],int n)
{
	if (n == 1)
	{
		return a[0];
	}
	for (int i = 0; i < n / 2; i++)
	{
		a[i] += a[n - i - 1];
	}
	n = (n + 1) / 2;
	return BinarySum(a, n);
}
int main()
{
	ofstream outfile;
	outfile.open("C:/Users/30492/Desktop/并行作业/data2.txt", ofstream::app);
	int n=0;
	srand(time(NULL));
	for (int n = 100000,i=0; i<500 ; i ++)
	{

		n +=rand()%1000* pow(-1, i);
		int* b = new int[n];
		for (int i = 0; i < n; i++)
		{
			b[i] = 1;
		}
		int* a = new int[n];
		for (int i = 0; i < n; i++)
		{
			a[i] = b[i];
		}


		//平凡算法
		LARGE_INTEGER head, tail, freq;
		QueryPerformanceFrequency(&freq);
		QueryPerformanceCounter(&head);
		 int sum = 0;
		 for (int i = 0; i < n; i++)
		 {
			sum += a[i];
		 }
			cout << sum<<endl;
		
		QueryPerformanceCounter(&tail);
		outfile << (double)(tail.QuadPart - head.QuadPart) / (double)freq.QuadPart * 1000 << " ";
		for (int i = 0; i < n; i++)
		{
			a[i] = b[i];
		}


		//多路链式
		
		QueryPerformanceFrequency(&freq);
		QueryPerformanceCounter(&head);
			int sum1 = 0;
			int sum2 = 0;
			for (int i = 0; i < n - 1; i += 2)
			{
				sum1 += a[i];
				sum2 += a[i + 1];
			}
			if (n % 2 != 0)
			{
				sum1 += sum2;
				sum1 += a[n - 1];
			}
			else
			{
				sum1 += sum2;
			}
			cout << sum1 << endl;
		
		QueryPerformanceCounter(&tail);
		outfile << (double)(tail.QuadPart - head.QuadPart) / (double)freq.QuadPart * 1000 << " ";


		for (int i = 0; i < n; i++)
		{
			a[i] = b[i];
		}


		// 折半递归
		QueryPerformanceFrequency(&freq);
		QueryPerformanceCounter(&head);
		 sum = 0;
		 int y = BinarySum(a, n);
		 cout << y<<endl;
		QueryPerformanceCounter(&tail);
		outfile << (double)(tail.QuadPart - head.QuadPart) / (double)freq.QuadPart * 1000 << " ";
		for (int i = 0; i < n; i++)
		{
			a[i] = b[i];
		}


		//2重循环
		QueryPerformanceFrequency(&freq);
		QueryPerformanceCounter(&head);
		for (int i = n; i > 1; i = (i + 1) / 2)
		{
			for (int j = 0; j < i / 2; j++)
			{
				a[j] += a[i - 1 - j];
			}
		}
			cout << a[0] << endl;
		
		QueryPerformanceCounter(&tail);
		outfile << (double)(tail.QuadPart - head.QuadPart) / (double)freq.QuadPart * 1000 << " " << n << endl;
		




	}
	outfile.close();

}