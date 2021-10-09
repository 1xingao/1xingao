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
    L->next = NULL;//????? 
    //???????? 
    char *Cname[7]={"????","???","???","???","????","????","????"};
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
void AddList(CLinkList &L,char ncity,double nx,double ny)//????????? 
{
	//CLinkList p=L;
	//if(p->next!=0)
	//    p = p->next;
	CLinkList t=(CLinkList)malloc(sizeof(CList));//?????????????§ß????????? 
	t->data.name=&ncity; t->data.x=nx;t->data.y=ny;
	t->next=L->next;
	L->next=t;
}
void DeleList(CLinkList &L,char ocity)
{
	CLinkList p=L->next;
	CLinkList q=(CLinkList)malloc(sizeof(CList));
	if(p==0) printf("??????????") ; 
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
	if(p==0) printf("¦Ä????????????"); 
}
void ModList(CLinkList &L,char ncity,double nx,double ny) 
{
	CLinkList p=L->next;
	while(p!=0){
		if(p->data.name==&ncity){
			p->data.x=nx;
			p->data.y=ny;
			printf("???????");
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
	printf("???????"); 
	if(i==0) printf("??§Ù????????????"); 
}
int main()
{
	CLinkList L;  InitList(L);
	/*double nx,ny,distance;
	char ncity; 
	while(1){
		printf("?????????§Ö??????????????1,???????2,????????3,????????4");
		printf("???????§³??D???????????5");
		int i,t=0;
		scanf("%d",&i);
		if(i==1){
			printf("????????????????????? ????x y??");	
			scanf("%c %f %f",&ncity,&nx,&ny);
			SearchList(L,ncity,t);
			if(t==1)
				AddList(L,ncity,nx,ny);
			else printf("?????????????");  
		} 
		else if(i==2){
			printf("??????????????????????");
			scanf("%c",&ncity);
			DeleList(L,ncity);
		}
		else if(i==3){
			printf("????????????????????? ????x y??");	
			scanf("%c %f %f",&ncity,&nx,&ny);
			SearchList(L,ncity,t);
			if(t==0)
				ModList(L,ncity,nx,ny);
			else printf("???????§Ó?????");
		}
		else if(i==4){
			printf("??????????????????????");
			scanf("%c",&ncity);
			SearchList(L,ncity,t);
			if(t==0)
				printf("??????????????"); 
		}
		else if(i==5){
			printf("??????¦Ë??????????");
			scanf("%f %f %f",&nx,&ny,&distance);
			DistList(L,nx,ny,distance);
		} 
		else("??????§¹") ;
	}*/
	return 0;
}

