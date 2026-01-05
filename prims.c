#include<stdio.h>
#define INF 999
#define  V 4
int i;
int main(){
    int cost[V][V]={
        {0, 6, 1, 0},
        {6, 0, 4, 3},
        {1, 4, 0, 5},
        {0, 3, 5, 0}
    };
    int visited[V]={0};
    int min,u,v,mincost=0,edges=0,i,j;
    visited[0]=1;
    printf("edges in minimum spanning tree\n ");
    while(edges < V-1){
        min=INF;

        for(i=0;i<V;i++){
           if(visited[i]){
            for(j=0;j<V;j++){
                if( !visited[j] && cost[i][j] !=0  && cost[i][j] < min){
                    min=cost[i][j];
                    u=i;
                    v=j;
                }
            }
           }
        }
        printf("%c - %c  :  %d \n",u+'A',v+'A',min);
        mincost += min;
        visited[v]=1;
        edges ++;

    }
      printf("Minimum Cost = %d\n", mincost);
    return 0;

    }

