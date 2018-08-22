#include<iostream>

#include<pthread.h>
#include<time.h>
#include<stdio.h>

using namespace std;



#define NUM_THREADS 5
//#define CLK_TCK 1000


struct threadCount

{
	int thread1_count=0;
	int thread2_count=0;
	int thread3_count=0;
}threadCount;



//线程的运行函数

void* thread1(void* args)
{
	for(int j=0;j<1000;j++)
		cout<<"Thread1 run times:"<<threadCount.thread1_count++<<endl;
		//threadCount.thread1_count++;
} 

void* thread2(void* args)
{
	for(int i=0;i<1000;i++)
		//threadCount.thread2_count++;
		cout<<"Thread2 run times:"<<threadCount.thread2_count++<<endl;
}

void* thread3(void* args)
{
	for(int k=0;k<1000;k++)
		//threadCount.thread3_count++;
		cout<<"Thread3 run times:"<<threadCount.thread3_count++<<endl;
}

int main()

{
	clock_t start,end;
	//定义线程id变量，多个变量使用数组

	pthread_t tids[NUM_THREADS];
	start=clock();
	int ret = pthread_create(&tids[0], NULL, thread1, NULL);

	if(ret != 0)
	{
		cout << "pthread_create error: error_code=" << ret << endl;
	}
	ret = pthread_create(&tids[1], NULL, thread2, NULL);

	if(ret != 0)
	{
		cout << "pthread_create error: error_code=" << ret << endl;
	}
	
	ret = pthread_create(&tids[2], NULL, thread3, NULL);
	if(ret != 0)
	{
		cout << "pthread_create error: error_code=" << ret << endl;
	}
	cout<<"#####################################"<<endl;
	pthread_exit(NULL);
	end=clock();
	//printf("time=%f\n",(double)(end-start)/CLK_TCK);
	//cout<<(double)(end-start)/CLK_TCK<<endl;
	
}
