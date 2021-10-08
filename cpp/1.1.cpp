#include<stdio.h>
#include<stdlib.h>

typedef struct city{
	char *name;
	double x;
	double y;
}city;
typedef struct CList
{
	city data;
	struct CList *next;
}CList,*CLinkList;
void InitList(CLinkList &L)
{
	L=(CLinkList)malloc(sizeof(CList));
    L->next = NULL;//初始化 
    //输入数据 
    char *Cname[7]={"北京","上海","天津","长沙","广州","深圳","杭州"};
    //char **s=Cname;
	double Cx[7]={116.4,121.4,117.2,113.0,113.2,114.1,120.2};
	double Cy[7]={39.9,34.5,39.1,28.2,23.1,22.6,30.3};
	int i=7;
    while(i--){
		CLinkList p=L;
		if(p->next!=0)
	        p = p->next;
	    CLinkList t=(CLinkList)malloc(sizeof(CList));
	    t->data.name=Cname[i]; t->data.x=Cx[i];t->data.y=Cy[i];
	    t->next =p->next;
	    p->next=t;
		printf("x");	}
	CLinkList temp=L->next;  
	while(temp!=0){
		printf("%s:%.1f,%.1f",temp->data.name,temp->data.x,temp->data.y);
		temp=temp->next;
		printf("y");
	}
}
void AddList(CLinkList &L,char ncity,double nx,double ny)//增加新城市 
{
	//CLinkList p=L;
	//if(p->next!=0)
	//    p = p->next;
	CLinkList t=(CLinkList)malloc(sizeof(CList));//将每一个增加的城市结点插在表头后 
	t->data.name=&ncity; t->data.x=nx;t->data.y=ny;
	t->next=L->next;
	L->next=t;
}
void DeleList(CLinkList &L,char ocity)
{
	CLinkList p=L->next;
	CLinkList q=(CLinkList)malloc(sizeof(CList));
	if(p==0) printf("链表不存在") ; 
	while(p!=0){
		q=p->next;
		if(p->data.name==&ocity){
			q->next=p->next;
			q->data.name=p->data.name;q->data.x=p->data.x;q->data.y=p->data.y;
			free(p); 
			break;
		}
		else p=p->next;
	}
	if(p==0) printf("未找到删除的数据"); 
}
void ModList(CLinkList &L,char ncity,double nx,double ny) 
{
	CLinkList p=L->next;
	while(p!=0){
		if(p->data.name==&ncity){
			p->data.x=nx;
			p->data.y=ny;
			printf("更新完成");
			break;
		}
		else p=p->next;
	}	
}
void SearchList(CLinkList &L,char ncity,int &t)
{ 
	t=0;
	CLinkList p=L->next;
	while(p!=0){
		if(p->data.name==&ncity){
			printf("%c:%f,%f",p->data.name,p->data.x,p->data.y);
			t=1; break;	}
		else p=p->next;
	}
	
}
void PriList(CLinkList &L)
{
	CLinkList p=L->next;
	while(p!=0){
		printf("%c:%f,%f",p->data.name,p->data.x,p->data.y);
		p=p->next;
	}
}
void DistList(CLinkList &L,double x,double y,double distance)
{
	double d2; int i=0;
	CLinkList p=L->next;
	while(p!=0){
		d2=(x-p->data.x)*(x-p->data.x)+(y-p->data.y)*(y-p->data.y);
		if(distance*distance>=d2){
			printf("%c ",p->data.name);
			i=1;
			}
		p=p->next;
	}
	printf("计算完成"); 
	if(i==0) printf("没有符合条件的城市"); 
}
int main()
{
	CLinkList L;  InitList(L);
	/*double nx,ny,distance;
	char ncity; 
	while(1){
		printf("请输入要执行的操作：插入输入1,删除输入2,更新输入3,查找输入4");
		printf("查找距离小于D的城市清输入5");
		int i,t=0;
		scanf("%d",&i);
		if(i==1){
			printf("请输入要插入的数据（名字 坐标x y）");	
			scanf("%c %f %f",&ncity,&nx,&ny);
			SearchList(L,ncity,t);
			if(t==1)
				AddList(L,ncity,nx,ny);
			else printf("增加的城市已存在");  
		} 
		else if(i==2){
			printf("请输入要删除的数据（名字）");
			scanf("%c",&ncity);
			DeleList(L,ncity);
		}
		else if(i==3){
			printf("请输入要更新的数据（名字 坐标x y）");	
			scanf("%c %f %f",&ncity,&nx,&ny);
			SearchList(L,ncity,t);
			if(t==0)
				ModList(L,ncity,nx,ny);
			else printf("更新的城市不存在");
		}
		else if(i==4){
			printf("请输入要查询的数据（名字）");
			scanf("%c",&ncity);
			SearchList(L,ncity,t);
			if(t==0)
				printf("查询的数据不存在"); 
		}
		else if(i==5){
			printf("请输入位置坐标和距离");
			scanf("%f %f %f",&nx,&ny,&distance);
			DistList(L,nx,ny,distance);
		} 
		else("输入无效") ;
	}*/
	return 0;
}

