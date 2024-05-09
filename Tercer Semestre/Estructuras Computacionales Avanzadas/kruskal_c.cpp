#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i,j,k,a,b,u,v,n=9,ne=0;
int min,mincost=0,parent[9];
int find(int);
int uni(int,int);

int cost[9][9]={

{0,6,0,10,0,0,8,0,0},
{6,0,11,0,15,0,0,13,0},
{0,11,0,0,0,0,0,4,0},
{10,0,0,0,6,0,0,0,0},
{0,15,0,6,0,2,0,0,0},
{0,0,0,0,2,0,4,0,6},
{8,0,0,0,0,4,0,5,5},
{0,13,4,0,0,0,5,0,7},
{0,0,0,0,0,6,5,7,0}

};


int main()
{
	
	printf("\n\tImplementation of Kruskal's algorithm\n");

	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(cost[i][j]==0){
			cost[i][j]=999;
            }
		}
	}

    for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			printf("%d , ",cost[i][j]);
		}
        printf("\n");
	}
    

	printf("The edges of Minimum Cost Spanning Tree are\n");
	while(ne < n-1)
	{
		for(i=0,min=999;i<9;i++)
		{
			for(j=0;j <9;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;

                   
				}
                


			}
		}
        
        
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
			mincost +=min;
		}
		cost[a][b]=cost[b][a]=999;
        
	}
	printf("\n\tMinimum cost = %d\n",mincost);
	getch();
    
}
int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}

