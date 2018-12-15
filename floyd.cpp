#include<iostream>
#include<vector>
using namespace std;

void floyd(vector < vector < int> >a)
{
	int m=a[0].size()-1;
	
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if( i!=j)
				{
					if(a[i][j]==0 || a[i][j]>a[i][k]+a[k][j])
					{
						a[i][j]=a[i][k]+a[k][j];
					}
				}
			}
		}
	}
	
	for(int i=1; i<a[0].size(); i++)
	{
		cout<<"\nMinimum cost with respect to node: "<<i<<endl;
		for(int j=1; j<a[0].size(); j++)
		{
			cout<<a[i][j]<<"\t";
		}
	}
	cout<<endl;
	

}




int main()
{

	int n;
	cin>>n;
	vector< vector <int > > a(n+1);
		
		
		cout<<"99 for infinity"<<endl;
	for(int i=0;i<=n;i++)
	{	
		for(int j=0;j<=n;j++)
		{
			if(i==0||j==0)
				a[i].push_back(0);
			else
			{
				
				int x;
				cin>>x;
				if(x==99)
				a[i].push_back(999999);
				else
				a[i].push_back(x);
			}
		}
	}
	
	
	/*for(int i=0;i<n;i++)
	{	

		cout<<a[i].size()<<endl;
	}*/
	floyd(a);
	
	cout<<"enter from to edge to block";
	int aa,bb;
	cin>>aa>>bb;

	a[aa][bb]=999999;
	
	floyd(a);
	
	


	
	return 0;
}
	
