#include <stdio.h>
#include<conio.h>
int acc[4]={0};
void right_shift(int a[],int q[],int*q_1)
{
  int i;
  *q_1=q[3];
  for(i=2;i>=0;i--)
  q[i+1]=q[i];

  q[0]=a[3];
  for(i=2;i>=0;i--)
  a[i+1]=a[i];
}

void swap(int a[],int b[])
{
  int i,temp;
  for(i=0;i<4;i++) //Swap 2 arrays
  {
    temp=a[i];
    a[i]=b[i];
    b[i]=temp;
  }
}

void add(int a[],int b[])
{
  int carry[4];
  int i;
  for(i=3;i>=0;i--)
  {
    if(i==3)
    {
    carry[i]=a[i]&b[i];
    a[i]=a[i]^b[i];
    }
    else
    {

      carry[i]=(a[i]&carry[i+1])||(b[i]&carry[i+1])||(a[i]&b[i]);
      a[i]=a[i]^b[i]^carry[i+1];
    }
  }
}

void twoscomp(int a[],int n)
{
    int i;
  for(i=0;i<n;i++) //To find ones compliment
  {
    if(a[i]==1)
      a[i]=0;
    else
      a[i]=1;
  }
  int r;
  for(i=n-1;i>0;i--)
  {
    if(i==n-1)
    {
      r=a[i]&1;
      a[i]=a[i]^1;
      continue;
    }
    if(r==1)  //Only calculate if carry is one
    {
      int t=a[i]&r;
      a[i]=a[i]^r;
      r=t;
    }
  }
}

void print(int a[],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    printf("%d",a[i]);
  }
}

