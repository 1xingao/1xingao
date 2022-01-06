//第二个代码 我一共写了俩程序

#define MAXsize 10000

typedef struct{
	int Score[MAXsize];
	int length;
}SList;
//简单选择排序
void SelectSort(SList &L){
	int min;
	for(int i=0;i<L.length-1;i++){
		min=i;
		for(int j=i+1;j<L.length;j++){
			if(L.Score[j]<L.Score[min])
				min=j;
		}
		if(min!=i){
			int temp=L.Score[i];
			L.Score[i]=L.Score[min];
			L.Score[min]=temp;
		}
	}
} 
//冒泡排序 
void BubbleSort(SList &L){
	for(int i=0;i<L.length-1;i++){
		for(int j=0;j<L.length-i-1;j++)
			if(L.Score[j]>L.Score[j+1]){
				int temp=L.Score[j];
				L.Score[j]=L.Score[j+1];
				L.Score[j+1]=temp;
			}
	}
} 
//两路排序 
int HalfInsertLocal(int a[],int length,int key){
	int low,high,m;
	low=0;high=length-1;
	while(low<=high){
		m=(low+high)/2;
	if(*(a+m)<key)
	    low=m+1;
	else
	    high=m-1;
	}
	return high+1;
}
void TwoPathInsert(SList &L){
    int A[10000]={0};
    int first=0,final=0;
    int j=0,k=0;int cur;
    A[0]=L.Score[0];
    for(int i=1;i<=L.length-1;i++){
		if(L.Score[i]>=A[0]){
			if(L.Score[i]>=A[final]){
			     A[++final]=L.Score[i];
			     j++;
			}
			else{
				cur=HalfInsertLocal(A,j+1,L.Score[i]);
				for(int g=final;g>=cur;g--)
					A[g+1]=A[g];
				*(A+cur)=L.Score[i];
				j++;
				final++;
				}	
		}
        else{
            if(L.Score[i]<A[first]){
                first=(first-1+L.length)%(L.length);
                A[first]=L.Score[i];
                k++;
            }
            else{
                cur=HalfInsertLocal(&A[first],k,L.Score[i]);
                cur--;
                for (int h=first;h<=(first+cur);h++)
                    A[h-1]=A[h];
                A[first+cur]=L.Score[i];
                first--;
                k++;
            }
        }
    }
    for(int i=0;i<=L.length-1;i++)
    {
        cur=(first+i)%(L.length);
        L.Score[i]=A[cur];
    }
    return;
}
//堆排序
void Down(SList &L, int i,int n) { // 最后结果就是大顶堆
    int parent=i;           // 父节点下标
    int child =2*i+1;    // 子节点下标
    while(child<n){
        if(child+1<n&&L.Score[child]<L.Score[child+1]) // 判断子节点那个大，大的与父节点比较
            child++;
        if (L.Score[parent]<L.Score[child]) { // 判断父节点是否小于子节点
            int temp=L.Score[child]; // 交换顶点和第 i 个数据
        	L.Score[child]=L.Score[parent];
        	L.Score[parent]=temp;
            parent = child;                 // 子节点下标 赋给 父节点下标
        }
        child=child*2+1; // 换行，比较下面的父节点和子节点
    }
}
void BuildHeap(SList &L){
    for(int i=L.length/2-1;i>=0;i--) { // 倒数第二排开始, 创建大顶堆，必须从下往上比较
        Down(L, i,L.length);                 // 否则有的不符合大顶堆定义
    }
    for (int i=L.length-1; i>0; i--) {
        int temp=L.Score[i]; // 交换顶点和第 i 个数据
        L.Score[i]=L.Score[0];
        L.Score[0]=temp;
        Down(L, 0, i); // 重新建立大顶堆
    }
}
//归并排序
int merge(int r[],int s[],int left,int mid,int right)
{
    int i=left,j=mid+1,k=left;
    while((i<=mid)&&(j<=right))
        if(r[i]<=r[j]){
            s[k] = r[i];
            i++;k++;	}
        else{
            s[k]=r[j];
            j++;k++;	}
    while(i<=mid) s[k++]=r[i++];
    while(j<=right) s[k++]=r[j++];
    return 0;
}
int merge_sort(int r[],int s[],int left,int right)
{
    int mid;
    int t[20000];
    if(left==right)
        s[left]=r[right];
    else
    {
        mid=(left+right)/2;
        merge_sort(r,t,left,mid);
        merge_sort(r,t,mid+1,right);
        merge(t,s,left,mid,right);
    }
    return 0;
} 
// int main()
// {
// 	int arr[100];
// 	SList L;
// 	L.length=100;
// 	srand((int)time(NULL));
// 	for(int i=0;i<100;i++){	
// 		arr[i]=(rand()%10000)+1; //cout<<arr[i]<<endl;
// 		L.Score[i]=arr[i];
// 	}
// 	//TwoPathInsert(L);
// 	//BubbleSort(L);
// 	//SelectSort(L);
// 	//BuildHeap(L); 
// 	merge_sort(L.Score,L.Score,0,L.length);
// 	for(int i=0;i<100;i++){	
// 		cout<<L.Score[i]<<"\t";
// 	}
// }