#include<bits/stdc++.h>
using namespace std;
void heapify(int ar[],int n,int i)
{
      
      int l=2*i+1;
      int r=2*i+2;
      int largest;
      if(l<n && ar[l]>ar[i])
      {
         largest=l;
      }
      else largest=i;
      if(r<n && ar[r]>ar[largest])
      {
        largest=r;
      }
      if(largest!=i)
      {
        swap (ar[i],ar[largest]);
        heapify (ar,n,largest);

      }

}
void heapsort(int ar[],int n)
{
    //build heap 
    for(int i=n/2-1;i>=0;i--)
    {
        heapify (ar,n,i);

    }
    for(int i=n-1;i>0;i--)
    {
        swap(ar[0],ar[i]);
        heapify(ar,i,0);
    }
}

void print(int ar[],int n)
{
    for (int i = 0; i <n; ++i)
        cout << ar[i] << " ";
    cout << "\n";
}


int main()
{
    int ar[]= { 12, 11, 13, 5, 6, 7 };
    int n=sizeof(ar)/sizeof(ar[0]);
    heapsort(ar,n);
    cout<<"SOrted array"<<endl;
    print(ar,n);

}