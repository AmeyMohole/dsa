#include <iostream>
using namespace std;

class Set
{
    int a[100];int  cnt;
    int no;
    public:
    Set()
    {
        cnt=0;
    }

    void add();
    void display();
    Set unionop(Set);
    int search(int);
    Set intersection(Set);
    Set subset(Set);

};

void Set :: add()
{
    cout<<"Enter how many number you want to enter "<<endl;
    cin>>no;
    for (int i=0; i<no; i++)
    {
        cout<<"Enter your number "<<i+1<<" :";
        cin>>a[i];
        cnt++;
    }
}

void Set :: display()
{
    for (int i=0;i<cnt;i++)
    {
        cout<<a[i]<<"  ";
    }
}

Set Set :: unionop(Set B)
{
    Set temp;
    for (int i = 0; i<cnt; i++)
    {
        temp.a[i] = a[i];
        temp.cnt++;
    }
    for (int i = 0; i<B.cnt;i++)
    {
        if(!temp.search(B.a[i]))
        {
            temp.a[temp.cnt++] = B.a[i];
        }
    }

    return temp;
}

int Set :: search(int s)
{
    for (int i = 0; i<cnt;i++)
    {
        if (s == a[i])
        {
            return 1;

        }

    }
    return 0;
}

Set Set :: intersection(Set B)
{   int flag;
    Set temp;
    for (int i = 0; i<cnt; i++)
    {
    flag=B.search(a[i]);
    if(flag==1)
    {
    temp.a[temp.cnt++]=a[i];
    }

    }return(temp);
 }

Set Set:: subset(Set B)
{

      int i;
      for(i=0;i<B.cnt;i++)
      {
       if(!search(B.a[i]))
        {
        cout<<"B is not subset of A";
        break;

        }
       }
        if(i==B.cnt)
       {
        cout<<"B is subset of A";

      }
 }


int main()
{
    int ch;int snumber;
    Set obj;
    int ans;
    Set B;
    Set C;
    do{
        cout<<"\n--------------------------------------------------"<<endl;
        cout<<"\n1.Insert in the set A"<<endl;
        cout<<"2.Insert in the set B"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Search in the set"<<endl;
        cout<<"5.Union of two set "<<endl;
        cout<<"6.Intersection of two set "<<endl;
        cout<<"7. subset "<<endl;
        cout<<"8.Exit"<<endl;

        cout<<"\nEnter your choice "<<endl;
        cin>>ch;
        cout<<endl;

        switch(ch)
        {
            case 1:
            obj.add();
            break;

            case 2:
            B.add();
            break;

            case 3:
            obj.display();
            break;

            case 4:
            cout<<"Enter the number to be searched "<<endl;
            cin>>snumber;
            ans = obj.search(snumber);
            if (ans == 1)
            {
                cout<<"Element found"<<endl;
                break;
            }
            else
            {
                cout<<"Element not found"<<endl;
                break;
            }

            case 5:
            C = obj.unionop(B);
            C.display();
            break;

            case 6:
            C = obj.intersection(B);
            C.display();
            break;

            case 7:
            obj.subset(B);
            break;


        }
    }while(ch!=8);


    return 0;
}
