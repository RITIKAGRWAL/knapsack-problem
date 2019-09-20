#include<stdio.h>

int n,m;
float f[10],p[10],w[10],pt[10],wt[10];

void knapsack()
{
float x[10]={0},v[10]={0},s=0;
int i;
for(i=0;i<n;i++)
{
if(m==0)
{
 for(i=0;i<n;i++)
{ 
 s=s+v[i];}
 printf("total profit=%f",s);
}
else
{
   if(w[i]<=m)
   {
 	m=m-wt[i];
	x[i]=1;
	v[i]=pt[i];
   }
   else
   {
	x[i]=m/wt[i];
	v[i]=pt[i]*x[i];
        m=0;
   }
}
}
}

void sort()
{
int i,j,t;
for(i=0;i<n-1;i++)
{
 for(j=0;j<n-1;j++)
   if(f[j]<f[j+1])
    {
	t=f[j];
	f[j]=f[j+1];
	f[j+1]=t;

	t=pt[j];
	pt[j]=pt[j+1];
	pt[j+1]=t;

	t=wt[j];
	wt[j]=wt[j+1];
	wt[j+1]=t;
    }
}
}

void main()
{
int i;
printf("Enter knapsack weight\n");
scanf("%d",&m);
printf("Enter no. of articles\n");
scanf("%d",&n);
printf("Enter elements weight and profit:\n");
for(i=0;i<n;i++)
{
scanf("%f",&w[i]);
scanf("%f",&p[i]);
}
for(i=0;i<n;i++)
{
f[i]=p[i]/w[i];
}
for(i=0;i<n;i++)
{
 pt[i]=p[i];
 wt[i]=w[i];
}
sort();
knapsack();
}
