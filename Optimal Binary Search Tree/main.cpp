#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstring>
#define Very 1000000000
using namespace std;

int n, res;
int f[252], T[252][252], cou[252];

int w(int i, int j)
{
    if(i>j) return 0;
    return cou[j]-cou[i-1];
}

int MYcount(int i, int j)
{
    if(i>j) return 0;
    int s;
    //for(int i=1; i<=n; i++)
      //  {
        //    for(int j=1; j<=n; j++)
          //  {
          if(T[i][j]==INT_MAX){
                for(int k=i; k<=j; k++)
                {
                    s=MYcount(i, k-1)+MYcount(k+1, j)+w(i,k-1)+w(k+1, j);
                    //T[i][j]=min(T[i][j], s);
                    if(T[i][j]>s) T[i][j]=s;
                }

          }
                return T[i][j];
            //}
        //}
}

int main()
{
    //cou=0;
    //for(int i=0; i<252; i++)
    //{
      //  for(int j=0; j<252; j++)
        //{
          //  if(i>=j) T[i][j]=0;
            //else T[i][j]=INT_MAX;
        //}
    //}
    while(scanf("%d", &n)==1)
    {
        int i;
        //memset(T, 1000000000, sizeof(T));
        for(int i=0; i<252; i++)
    {
        for(int j=0; j<252; j++)
        {
            if(i>=j) T[i][j]=0;
            else T[i][j]=INT_MAX;
        }
    }
        for(cou[0]=0, i=1; i<=n; i++)
        {
            //cou[i]=0;
            T[i][i]=0;
            scanf(" %d", &f[i]);
            cou[i]=cou[i-1]+f[i];
        }
        //memset()

        /*for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                for(int k=i; k<=j; k++)
                T[i][j]=min(T[i][j], T[i][k-1]+T[k+1][j]+w(i,j)-f[k]);
            }
        }
        */
        res=MYcount(1, n);
        printf("%d\n", res);
    }
    //cout << "Hello world!" << endl;
    return 0;
}
