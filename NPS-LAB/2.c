
// #include <stdio.h>

// struct node
// {
//     unsigned dist[20];
//     unsigned from[20];
// }rt[10];

// int main()
// {
//     int count=0;
    
//     //-------------------------------------------------------------------------------------------------------------
//     //	> Take the inputs:
//     //-------------------------------------------------------------------------------------------------------------
//     	int nodes;
//     	printf("\nEnter the number of nodes: ");
//     	scanf("%d",&nodes);
//     //-------------------------------------------------------------------------------------------------------------
//     	printf("\nEnter the cost matrix :\n");
//     //-------------------------------------------------------------------------------------------------------------
//     	int costmat[20][20];
//     	int i, j, k;
//    	for(i=0;i<nodes;i++)
//     	{
// 		for(j=0;j<nodes;j++)
// 		{
// 		    scanf("%d", &costmat[i][j]);
// 		    costmat[i][i]=0;
// 		    rt[i].dist[j]=costmat[i][j];//initialise the distance equal to cost matrix
// 		    rt[i].from[j]=j;
// 		}
//     	}
//     //-------------------------------------------------------------------------------------------------------------
//     //	> Bellman ford algorithm:
//     //-------------------------------------------------------------------------------------------------------------
//         do
//         {
//             count=0;
//             for(i=0;i<nodes;i++)
//             	for(j=0;j<nodes;j++)
//             		for(k=0;k<nodes;k++)
// 				if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
// 				{
// 				    rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
// 				    rt[i].from[j]=k;
// 				    count++;
// 				}
//         } while(count!=0);
//     //-------------------------------------------------------------------------------------------------------------
//     //	> Print the resultant:
//     //-------------------------------------------------------------------------------------------------------------
//         for(i=0;i<nodes;i++)
//         {
//             printf("\n\nRouter %d to\n",i+1);
//             for(j=0;j<nodes;j++)
//             {
//                 printf("\t\nrouter %d: distance = %d, next hop = node %d ",j+1,rt[i].dist[j],rt[i].from[j]+1);
//             }
//         }
//     //-------------------------------------------------------------------------------------------------------------
//     printf("\n\n");
// }


// instructor manula 


#include<stdio.h>
int A[10][10], n, d[10], p[10];
void BellmanFord(){
    int i,u,v;
    for(i=1;i<n;i++){
        for(u=0;u<n;u++){
            for(v=0;v<n;v++){
                if(d[v] > d[u] + A[u][v]) //remember A[u][v] u comes first
                {
                    d[v] = d[u] + A[u][v];
                    p[v] = u;
                }
        }
    }
}
for(u=0;u<n;u++){
    for(v=0;v<n;v++){
        if(d[v] > d[u] + A[u][v]){
        printf("Negative Edge");
        exit(0);
    }
    }
    }
}
int main(){
    printf("Enter the no. of vertices : ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    int i,j;
    for(i=0;i<n;i++) ////see how to give input from instructor manual ,diagnol elements shuld be 0
    for(j=0;j<n;j++)
    scanf("%d",&A[i][j]);

    int source;
    for(source=0;source<n;source++)
    {
        for(i=0;i<n;i++)
        {
            d[i] = 999;
            p[i] = -1;
        }
        d[source] = 0;
        BellmanFord();
        printf("Router %d\n",source);
        for(i=0;i<n;i++)
        {
            if(i != source)
            {
                j = i;              //u forgot this line 
                while(p[j] != -1)   // this condition
                {
                    printf("%d <- ",j);
                    j = p[j];
                }
            }
        printf("%d\tCost %d\n\n",source,d[i]);  // and the position of this statement and "source"
        }
    }
    return 0;
}
