#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct frame
{
	
	int fno;
	char  info[20];
};

void sort(struct frame obj[],int n)
{	
	int i,j,k;
	struct frame temp;
	for(i=0;i<n;i++)	
	{
		for(j=i+1;j<n;j++)
		{
				if(obj[i].fno>obj[j].fno)
				{
					temp=obj[i];
					obj[i]=obj[j];
					obj[j]=temp;
				}
		}
	}
}

int main()
{
	
	int n,i,k,j;
	char str1[20];
	printf("enter  no of frames\n");
	scanf("%d",&n);
	int check[n+1]; 
	struct frame obj[n+1];
	
	for(i=0;i<n;i++)
	{
		check[i]=-1;
	}

	for(i=0;i<n;i++)
	{
		k=rand()%(n+1);
		if(check[k]==-1)
		{
			scanf("%[^\n]\n",	str1);
			
			for(i=0;i<20;i++)
				obj[k].info[i]=str1[i];
			
			if(strlen(str1)>20)
			{	
				for(i=0;i<strlen(str1);i++)
				{
					obj[k+1].info[i]=str1[20+i];
				}
			i=i+1;	
			}	
			obj[k].fno=i;	
					
			check[k]=0;
		}				
		else
		{
			for(j=0;j<n;j++)
			{
				if(check[j]==-1)
				{
				scanf("%[^\n]\n",	str1);
			
			for(i=0;i<20;i++)
				obj[i].info[i]=str1[i];
				obj[k].fno=i;
				check[j]=0;
			if(strlen(str1)>20)
			{	
				for(i=0;i<strlen(str1);i++)
				{
					obj[i+1].info[i]=str1[20+i];
				}
			i=i+1;	
			}	
					obj[j].fno=i;	
					check[j]=0;
					break;
				}
			}
		}
	}	
	for(i=0;i<n;i++)
	{
		printf("\t %d \t %s\n ",obj[i].fno,obj[i].info);
	}
	
	sort(obj,n);
	printf("\t sorted \n");
	for(i=0;i<n;i++)
	{
		printf("\t %d \t %s\n ",obj[i].fno,obj[i].info);
	}

return 0;
}

