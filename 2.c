#include<stdio.h>
#include<stdlib.h>
int lessThanEqual(int need[],int work[],int m)
{
      int flag=1;
      for(int i=0;i<m;i++)
         {
             if(!(need[i]<=work[i]))
                 {
                   flag=0;
                   break;
                 }
         }
          return flag;
}
int trueForall(int Finish[],int n)
{
     int flag=1;
      for(int i=0;i<n;i++)
         {
             if(Finish[i]==0)
             {
               flag=0;
               break;
             }
         }
           return flag;
}
int main()
{
   int m,n,i,j;
   printf("Enter the no. of processes:");
   scanf("%d",&n);
   printf("Enter the no. of resource types:");
   scanf("%d",&m);
   int *Available=(int *)malloc(sizeof(int)*m);
   int **Max=(int **)malloc(sizeof(int *)*n);
   for(i=0;i<n;i++)
      Max[i]=(int *)malloc(sizeof(int)*m);
  int **Allocation=(int **)malloc(sizeof(int *)*n);
     for(i=0;i<n;i++)
      Allocation[i]=(int *)malloc(sizeof(int)*m);
  int **Need=(int **)malloc(sizeof(int *)*n);
    for(i=0;i<n;i++)
      Need[i]=(int *)malloc(sizeof(int)*m);
      printf("\nEnter the Available Vector:\n");
       for(i=0;i<m;i++)
         scanf("%d",&Available[i]);
      printf("\nHere is the Available Vector:\n");
        for(i=0;i<m;i++)
          printf("%d ",Available[i]);

      printf("\nEnter the value of the max matrix:\n");
      for(i=0;i<n;i++ )
         for(j=0;j<m;j++)
            scanf("%d",&Max[i][j]);
      printf("Here is the max matrix:\n");
        for(i=0;i<n;i++)
        {
           for(j=0;j<m;j++)
              printf("%d ",Max[i][j]);
            printf("\n");
        }
        printf("Enter the Allocation matrix:\n");
        for(i=0;i<n;i++ )
           for(j=0;j<m;j++)
              scanf("%d",&Allocation[i][j]);
       for(i=0;i<n;i++ )
          for(j=0;j<m;j++)
             Need[i][j]=Max[i][j]-Allocation[i][j];
        printf("\n Here is the need matrix:\n");
        for(i=0;i<n;i++ )
        {
           for(j=0;j<m;j++)
                printf("%d ",Need[i][j]);
                printf("\n");
        }
         int *work=(int *)malloc(sizeof(int)*m);
         for(i=0;i<m;i++)
             work[i]=Available[i];
       int *Finish=(int *)malloc(sizeof(int)*n);
          for(i=0;i<n;i++)
             Finish[i]=0;
             for(i=0;i<n;i++)
              {
                   if(Finish[i]==0 && lessThanEqual(Need[i],work,m))
                   {
                        for(j=0;j<m;j++)
                        work[j]+=Allocation[i][j];
                        Finish[i]=1;
                        i=0;
                   }
              }
           if(trueForall(Finish,n)==1)
              printf("The system is in safe state\n");
          else
             printf("The system is in unsafe state\n");






return 0;
}
