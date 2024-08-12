#include<iostream>
#include<vector>
using namespace std;

class maxheap
{
    vector <int> heap;
    int parent(int i)
    {
        return (i-1)/2;
    }
    int leftchild(int i)
    {
        return 2*i+1;
    }
    int rightchild(int i)
    {
        return 2*i+2;
    }

  void heapifyupmax(int i)
  {
      while(i!=0&&heap[parent(i)]<heap[i])
      {
          swap(heap[parent(i)],heap[i]);
          i=parent(i);
      }
  }

  void heapifydown(int i)
  {
      int left=leftchild(i);
      int right=rightchild(i);
      int largest=i;

      if(left<heap.size()&&heap[left]>heap[i])
      {
          largest=left;
      }
       if(right<heap.size()&&heap[right]>heap[i])
      {
          largest=right;
      }
      if(largest!=i)
      {
          swap(heap[largest],heap[i]);
          heapifydown(largest);
      }
  }
  public:

      void insertt(int val)
      {
          heap.push_back(val);
          heapifyupmax(heap.size()-1);
      }

      int extractmax()
      {
          int maxvalue;
          maxvalue=heap[0];
          heap[0]=heap.back();
          heap.pop_back();
          heapifydown(0);

          return maxvalue;
      }

      void display()
      {

          for(int i:heap)
          {
              cout<<i<<"  ";
          }
      }
};
int main()
{
      maxheap m;
      int n,i,t,choice;
      cout<<"Enter How Many Elements : "<<endl;
       cin>>n;
              for(i=0;i<n;i++)
              {
                  cin>>t;
                  m.insertt(t);
              }
        cout<<"Maximum heap will be : "<<endl;
         m.display();
         cout<<endl;

      cout<<"Extract max : ";
      m.extractmax();
      cout<<endl;
      cout<<"After extracting Maximum element of the heap : \n";
      m.display();
}
