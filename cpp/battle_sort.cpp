#include<iostream>
#include<stdlib.h>
#include<time.h> 
#include <vector>
#include "sort.h"
#include "sort1.h"
using namespace std;

int calc(vector<int> x)
{
	int all=0;
	for (int i=0;i<x.size();i++){
		all+=x[i];
	}
	return all/x.size();
}
void test_battle()
{
	int time_sort,data_volume;
	cout<<"[不同排序方法的对比]"<<endl;
	cout<<"请输入实验次数"<<endl;
	cin >> time_sort ;
	vector<int> times,times1,times2,times3,times4,times5,times6,times7,times8;
	clock_t start,end;
	for(int i = 0;i<time_sort;i++){
		int arr[10000];
 		SList L,L1,L2,L3,L4;
		SList_1 L5,L6,L7,L8;
 		L.length=10000;L1.length=10000;L2.length=10000;L3.length=10000;L4.length=10000;
		L5.length=100;L5.R[0].key=-1;L6.length=100;L6.R[0].key=-1;L7.length=100;L7.R[0].key=-1;L8.length=100;L8.R[0].key=-1;
 		srand((int)time(NULL));
 		for(int i=0;i<10000;i++){	
 			arr[i]=(rand()%1000000)+1; //cout<<arr[i]<<endl;
			L.Score[i]=arr[i];
			L1.Score[i]=arr[i];
			L2.Score[i]=arr[i];
			L3.Score[i]=arr[i];
			L4.Score[i]=arr[i];
			L5.R[i+1].key=arr[i];
			L6.R[i+1].key=arr[i];
			L7.R[i+1].key=arr[i];
			L8.R[i+1].key=arr[i];
 		}
		start = clock();
		SelectSort(L);
		end = clock();
		times.push_back(end-start);//简单选择排序
		start = clock();
		BubbleSort(L1);
		end = clock();
		times1.push_back(end-start);//冒泡排序
		start = clock();
		TwoPathInsert(L2);
		end = clock();
		times2.push_back(end-start);//两路排序
		start = clock();
		BuildHeap(L3);
		end = clock();
		times3.push_back(end-start);//堆排序
		start = clock();
		merge_sort(L4.Score,L4.Score,0,L4.length);
		end = clock();
		times4.push_back(end-start);//归并排序
		start = clock();
		InsertSort(L5);
		end = clock();
		times5.push_back(end-start);//直接插入排序
		start = clock();
		BInsertSort(L6);
		end = clock();
		times6.push_back(end-start);//折半排序
		start = clock();
		int dlta[]={10,7,4,2,1};
		ShellSort(L7,dlta,5);
		end = clock();
		times7.push_back(end-start);//希尔排序
		start = clock();
		QSort(L8,1,L8.length);
		end = clock();
		times8.push_back(end-start);//快速排序
	}
	cout<<"简单选择排序      耗时:  "<<"\t";
	for(int i=0;i<times.size();i++){
	 	cout<<times[i]<<"ms"<<"\t";
	}
	cout<<endl;
	cout<<"冒泡排序          耗时:  "<<"\t";
	for(int i=0;i<times1.size();i++){
	 	cout<<times1[i]<<"ms"<<"\t";
	}
	cout<<endl;
	cout<<"两路排序          耗时:  "<<"\t";
	for(int i=0;i<times2.size();i++){
	 	cout<<times2[i]<<"ms"<<"\t";
	}
	cout<<endl;
	cout<<"堆排序            耗时:  "<<"\t";
	for(int i=0;i<times3.size();i++){
	 	cout<<times3[i]<<"ms"<<"\t";
	}
	cout<<endl;
	cout<<"归并排序          耗时:  "<<"\t";
	for(int i=0;i<times4.size();i++){
	 	cout<<times4[i]<<"ms"<<"\t";
	}
	cout<<endl;
	cout<<"直接插入排序      耗时:  "<<"\t";
	for(int i=0;i<times5.size();i++){
	 	cout<<times5[i]<<"ms"<<"\t";
	}
	cout<<endl;
	cout<<"折半排序          耗时:  "<<"\t";
	for(int i=0;i<times6.size();i++){
	 	cout<<times6[i]<<"ms"<<"\t";
	}
	cout<<endl;
	cout<<"希尔排序          耗时:  "<<"\t";
	for(int i=0;i<times7.size();i++){
	 	cout<<times7[i]<<"ms"<<"\t";
	}
	cout<<endl;
	cout<<"快速排序          耗时:  "<<"\t";
	for(int i=0;i<times8.size();i++){
	 	cout<<times8[i]<<"ms"<<"\t";
	}
	cout<<endl;
	cout<<"平均时长"<<endl;
	cout<<"简单选择排序      耗时:  "<< calc(times) <<"ms"<<endl;
	cout<<"冒泡排序          耗时:  "<< calc(times1) <<"ms"<<endl;
	cout<<"两路排序          耗时:  "<< calc(times2)<<"ms" <<endl;
	cout<<"堆排序            耗时:  "<< calc(times3) <<"ms"<<endl;
	cout<<"归并排序          耗时:  "<< calc(times4)<<"ms" <<endl;
	cout<<"直接插入排序      耗时:  "<< calc(times5) <<"ms"<<endl;
	cout<<"折半排序          耗时:  "<< calc(times6) <<"ms"<<endl;
	cout<<"希尔排序          耗时:  "<< calc(times7)<<"ms" <<endl;
	cout<<"快速排序          耗时:  "<< calc(times8) <<"ms"<<endl;
	
}


int main()
{
    test_battle();
    return 0;
}