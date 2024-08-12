#include<iostream>
using namespace std;
class Stack
{
private:
    int top;
    int siz;
    int* arr;
public:
    Stack(int size)
    {
        siz=size;
        top=-1;
        arr=new int[siz];
    }

    ~Stack( )
    {
        delete[ ] arr;
    }

    void push(int t)
    {
      if(top>=siz-1)
        {
            cout<<"Stack Overflow";
        }
        top++;
        arr[top]=t;
    }

    int pop()
    {
       if(top<0)
        {
            cout<<"Stack Underflow";
        }
        top--;
        return arr[top];
    }

    void peek()
    {
        if(top<0)
        {
            cout<<"Stack Underflow";
        }
        else
            cout<<arr[top];
    }

    void display()
    {
        int i;
        for(i=top;i>=0;i--)
        {
            cout<<arr[i]<<" ";
        }
    }
};
 int main()
 {
     int n,i,t,c;
     cout<<"Enter size for the stack : ";
     cin>>n;
     Stack st(n);
     for(i=0;i<n;i++)
     {
         cin>>t;
         st.push(t);
     }

     cout<<"Stack Elements : \n" ;
     st.display();
     cout<<endl;
     st.pop();
     cout<<"After popping the top Element, The stack will be: \n";
     st.display();
     cout<<endl;
     cout<<"Top Element is : ";
     st.peek();
   }


