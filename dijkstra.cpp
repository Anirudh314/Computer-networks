#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>
#define max  999999999
using namespace std;
class frame
{
	public:
	int fno;
	string info;
};
	
frame obj[20];
int n;

void sort()
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			frame temp;
			if(obj[i].fno>obj[j].fno)
			{
				temp=obj[i];
				obj[i]=obj[j];
				obj[j]=temp;
			}
		}
	}
}
void input_frame()
{
	cout<<"enter number of frames \n";
	cin>>n;
	int check[n+1];
	for(int i=0;i<n;i++)
		check[i]=-1;
	
	for(int i=0;i<n;i++)
	{
		int k=rand()%(n+1);
		if(check[k]==-1)
		{
			cin>>obj[k].info;
			obj[k].fno=i;
			check[k]=0;
		}
		else
		{
			for(int l=0;l<n;l++)
			{
				k=l;
				if(check[l]==-1)
				{
					obj[l].fno=i;
					check[l]=0;
					break;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<obj[i].fno<<"\t"<<obj[i].info<<endl;
	}
	
}




typedef pair<int , int >pII;
vector<pII>adj[10000];

int edges;int nodes;
	
vector<int >parent(20);

void printpath(int i)
{
	
	if(parent[i]==-1)
	{
		cout<<i<<"  ";
		return ;
	}
	printpath(parent[i]);
	cout<<i<<"  ";
}

void dijkstra(int src)
{
	int count=0;
	priority_queue< pII,vector<pII>,greater<pII> >pq;		
	vector< int >dist;  //set max vector size 10000 and distance of each max
	for(int i=1;i<1000;i++)
		dist.push_back(999999);
	pq.push(make_pair(0,src));
	
		
	parent[1]=-1;
	dist[1]=0;		

	while(!pq.empty())
	{
		pII s=pq.top();
		pq.pop();
		int u = s.second;

		//dist[v]=s.first;
		
	
		for(int i=0;i<adj[u].size();i++)
		{
			 int weight=adj[u][i].first;
			 int v=adj[u][i].second;
			if(dist[v]>dist[u]+weight)
			{
				dist[v]=dist[u]+weight;
				pq.push(adj[u][i]);
				parent[v]=u;
			}
			
		}		count++;
	}
int sum=0;
  for (int i = 2; i<=nodes  ; i++)
 {
	cout<<i <<"  " <<dist[i]<<endl;
	sum=sum+dist[i];
 }

	cout<<sum<<endl;

//for(int i=0;i<nodes;i++)
	//cout<<parent[i]<<"\t";

}


void input_graph()
{
	

	cout<<"enter no of nodes and edges "<<endl;
	cin>>nodes>>edges;
	
	cout<<"ender edges -i.e  source ,destination ,weight "<<endl;
	for(int i=0;i<edges;i++)
	{
		 int x,y,weight;
			
		cin>>x>>y>>weight;
		
		adj[x].push_back(make_pair(weight,y));
		//adj[y].push_back(make_pair(weight,x));

	}
}


int main()
{	
	
	//input_frame();	
	
	input_graph();
	
	dijkstra(1);

		cout<<"nodes = "<<nodes<<endl;

		for(int i=2;i<=nodes;i++)
		{
	
			cout<<"path for node "<<i <<" is :  ";		
			printpath(i);
			cout<<endl;
		}
	
	while(1)
	{
		
		cout<<" enter 1 to block and edge 2 to exit"<<endl;
		int z;
		cin>>z;int temp;
		if(z==1)
		{
			int x,y,w;
			cout<<"enter from ,  to"<<endl;
			cin>>x>>y;
			
			//changed
			parent[y]=-1;
			for(int i=0;i<adj[x].size();i++)
			{
								
					if(adj[x][i].second==y)
					{
						cout<<"label "<<endl;
						 temp=adj[x][i].first;
						cout<<adj[x][i].second<<endl;
						adj[x][i].first=999999999;
						//changed here
						adj[x][i].second=-1;
						cout<<temp<<endl;
						cout<<"label"<<endl;
					}
				cout<<adj[x][i].first<<"  "<<adj[x][i].second<<endl;
			}
						
			dijkstra(1);
			
			for(int i=2;i<=nodes;i++)
			{
	
			cout<<"path for node "<<i <<" is :  ";		
			printpath(i);
			cout<<endl;
			}
	
		
		
			for(int i=0;i<999999;i++)
				for(int j=0;j<999;j++);  

			adj[x][y].first=temp;
			
		}
		else
		{
			break;
		}

	}
	//if one edge disconnected
	//if edge is reconnected


	//sort();
		
	/*for(int i=0;i<n;i++)
	{
		cout<<obj[i].fno<<"   \t "<<obj[i].info<<endl;

	}
	*/

	

return 0;
}
