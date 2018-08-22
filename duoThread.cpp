#include<iostream>
#include<pthread.h>

using namespace std;

#define NUM_THREADS 2

struct threadCount
{
	int thread1_count=0;
	int thread2_count=0;
}threadCount;

//线程的运行函数
void* thread1(void* args)
{
	for(int j=0;j<10000;j++)
		cout<<"Thread1 run times:"<<threadCount.thread1_count++<<endl;
} 

void* thread2(void* args)
{
	for(int i=0;i<10000;i++)
		cout<<"Thread2 run times:"<<threadCount.thread2_count++<<endl;
}

int main()
{
	//定义线程id变量，多个变量使用数组
	pthread_t tids[NUM_THREADS];
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
	pthread_exit(NULL);
}
