#include<iostream>
using namespace std;


struct Product
{
    int id;
    string name;
    int price;
};


Product products[5] =
{
    {1,"Laptop",50000},
    {2,"Mouse",500},
    {3,"Keyboard",1000},
    {4,"Headphone",2000},
    {5,"Mobile",15000}
};




struct Node
{
    int id;
    string name;
    int price;

    Node *next;
};


Node *head=NULL;




void displayProducts()
{
    cout<<"\nProduct List\n";

    for(int i=0;i<5;i++)
    {
        cout<<products[i].id<<" "
            <<products[i].name<<" "
            <<products[i].price<<endl;
    }
}




void addCart()
{
    int id;

    cout<<"Enter Product ID:";
    cin>>id;


    for(int i=0;i<5;i++)
    {
        if(products[i].id==id)
        {
            Node *newNode=new Node();

            newNode->id=products[i].id;
            newNode->name=products[i].name;
            newNode->price=products[i].price;
            newNode->next=NULL;


            if(head==NULL)
            {
                head=newNode;
            }

            else
            {
                Node *temp=head;

                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }

                temp->next=newNode;
            }


            cout<<"Added to Cart\n";
            return;
        }
    }

    cout<<"Product Not Found\n";
}



void viewCart()
{
    Node *temp=head;

    int total=0;


    cout<<"\nShopping Cart\n";


    while(temp!=NULL)
    {
        cout<<temp->name<<" "
            <<temp->price<<endl;


        total=total+temp->price;

        temp=temp->next;
    }


    cout<<"Total = "<<total<<endl;
}




void removeCart()
{
    int id;

    cout<<"Enter ID to remove:";
    cin>>id;


    Node *temp=head;
    Node *prev=NULL;


    while(temp!=NULL)
    {
        if(temp->id==id)
        {
            if(prev==NULL)
                head=temp->next;

            else
                prev->next=temp->next;


            delete temp;

            cout<<"Removed Successfully\n";
            return;
        }


        prev=temp;
        temp=temp->next;
    }


    cout<<"Item not found\n";
}




void checkout()
{
    int total=0;

    Node *temp=head;


    while(temp!=NULL)
    {
        total+=temp->price;
        temp=temp->next;
    }


    cout<<"\nFinal Bill = "<<total<<endl;
    cout<<"Thank You Shopping!";
}




int main()
{
    int choice;


    do
    {
        cout<<"\n\n1.Display Products";
        cout<<"\n2.Add Cart";
        cout<<"\n3.View Cart";
        cout<<"\n4.Remove Item";
        cout<<"\n5.Checkout";
        cout<<"\n6.Exit";


        cout<<"\nEnter Choice:";
        cin>>choice;


        switch(choice)
        {
            case 1:
                displayProducts();
                break;

            case 2:
                addCart();
                break;

            case 3:
                viewCart();
                break;

            case 4:
                removeCart();
                break;

            case 5:
                checkout();
                break;

        }

    }while(choice!=6);


    return 0;
}