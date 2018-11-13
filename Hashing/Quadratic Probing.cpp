#include<iostream>
using namespace std;
int hash(int key,int size)
{
  return key%size;
}
int main()
{
  int size,key,n,loc,i;
  cout<<"Enter the size of hash table: ";
  cin>>size;
  int table[size]={0};
  cout<<"Enter the no. of keys: ";
  cin>>n;
  cout<<"Enter the key values:";
  for(i=0;i<n;i++)
  {
    cin>>key;
    loc=hash(key,size);
    if(table[loc]==0)
      table[loc]=key;
    else
    {
      int j=0;
      while(true)
      {
        loc=((key%size)+(j*j))%size;
        if(table[loc]==0)
        {
          table[loc]=key;
          break;
        }
        else
          j++;
      }
    }
  }
  cout<<"Hash table: ";
  for(i=0;i<size;i++)
  {
    cout<<table[i]<<"  ";
  }
}
