
#define MAXsize 10000

typedef struct{
	int key;
}SNode; 
typedef struct{
	SNode R[MAXsize+1]; //两个代码这里不一样 就数组第一个是不是哨兵的区别
	int length;
}SList_1;
//直接插入排序 
void InsertSort(SList_1 &L){
	for(int i=2;i<=L.length;++i){
		L.R[0]=L.R[i];
		int j=i-1;	
		while(j>=0&&L.R[j].key>L.R[0].key){
			L.R[j+1]=L.R[j];
			j--;
		}
		L.R[j+1]=L.R[0];
	}	
}
//折半排序 
void BInsertSort(SList_1 &L){
	for(int i=2;i<=L.length;i++){
		L.R[0]=L.R[i];
		int low=1,high=i-1,mid;
		while(low<=high){
			mid=(high+low)/2;
			if(L.R[0].key<=L.R[mid].key)	high=mid-1;
			else	low=mid+1;
		}
		for(int j=i;j>low;j--)
			L.R[j]=L.R[j-1];
		L.R[low]=L.R[0];
	}
}
//希尔排序 
void ShellInsert(SList_1 &L,int dk){
	for(int i=dk+1;i<=L.length;i++)
		if(L.R[i].key<=L.R[i-dk].key){
			L.R[0]=L.R[i];//暂存 不是哨兵
		int j=i-dk;
		for(j;j>0&&L.R[0].key<=L.R[j].key;j-=dk)
			L.R[j+dk]=L.R[j];
		L.R[j+dk]=L.R[0];
		}
}
void ShellSort(SList_1 &L,int dlta[],int t){
	for(int k=0;k<t;k++)
		ShellInsert(L,dlta[k]);
}
//快速排序
int Partition(SList_1 &L,int low,int high){
	L.R[0]=L.R[low];
	int pivotkey=L.R[low].key;
	while(low<high){
		while(low<high&&L.R[high].key>=pivotkey)
			--high;
		L.R[low]=L.R[high];
		while(low<high&&L.R[low].key<=pivotkey)
			++low;
		L.R[high]=L.R[low];
	}
	L.R[low]=L.R[0];
	return low;
} 
void QSort(SList_1 &L,int low,int high){
	if(low<high){
		int pivotloc=Partition(L,low,high);
		QSort(L,low,pivotloc-1);
		QSort(L,pivotloc+1,high);
	}
}

// int main()
// {
// 	int arr[100];
// 	SList_1 L;
// 	L.length=100;L.R[0].key=-1;
// 	srand((int)time(NULL));
// 	for(int i=0;i<100;i++){	
// 		arr[i]=(rand()%10000)+1; //cout<<arr[i]<<endl;
// 		L.R[i+1].key=arr[i];
// 	}
// 	//InsertSort(L);
// 	//BInsertSort(L);
// 	//int dlta[]={10,7,4,2,1};
// 	//ShellSort(L,dlta,5);
// 	QSort(L,1,L.length);
// 	for(int i=0;i<100;i++){	
// 		cout<<L.R[i+1].key<<"\t";
// 	}
// 	return 0;
// }













