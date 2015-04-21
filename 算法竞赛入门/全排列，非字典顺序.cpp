#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int A[20];
int cnt;
int recur;

void perm(int cur, int n, int *A)
{
    recur++;
    if(cur==n)//empty
    {
        cnt++;
        for(int i=0;i<n;i++)
            printf("%d ", A[i]);
        printf("\n");
    }
    else
    {
        for(int i=cur;i<n;i++)
        {
            swap(A[i], A[cur]);
            perm(cur+1, n, A);
            swap(A[i], A[cur]);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        A[i]=i+1;
    perm(0, n, A);
    cout<<cnt<<endl;
    cout<<recur<<endl;

    return 0;
}
