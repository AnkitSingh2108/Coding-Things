#include<bits/stdc++.h>
using namespace std;
void inplacer(int a[], int n)
{
    if(n>0)
    {
        int p = (n-1)/2;
        if(a[p]<a[n])
        {
            swap(a[p],a[n]);
            inplacer(a,p);
        }
    }
}
void insert(int arr[],int i,int item)
{
    arr[i]= item;
    inplacer(arr, i);
}
void heapify(int a[], int n, int i)
{
    if(n>1)
    {
        int largest = i; int l = 2*i +1; int r = 2*i + 2;
        if(l<n && a[largest]<a[l])
        largest = l;
        if(r<n && a[largest]<a[r])
        largest = r;
        if(largest!=i)
        {
            swap(a[largest],a[i]);
            heapify(a,n,largest);
        }
    }
}
void del(int a[], int n, int i)
{
    int temp= a[0];
    a[0] = a[n-1];
    a[n-1] = temp;
    heapify(a,n-1,0);
}
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}
int main()
{
    int n; cin>>n;
    int arr[n];  // int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        insert(arr,i,x);
    }
    print(arr,n); cout<<endl;
    int d; cin>>d;
    int size = n;
    for(int i=0;i<d;i++)
    {
        del(arr,size,i); size--;
    }
    print(arr,n);
}
