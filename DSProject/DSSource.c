#include"DSHeader.h"
#include <stddef.h>
 void menu(LinkedList *L){
      int y,x,ID;
     printf("Who are you ?\n 1-Owner? \n 2-User want to buy?\n 0- Exit\n");
            scanf("%d",&x);
    while(x){
        if (x==1){
            printf("What do you want To Do ? \n 1- Add product?\n 2-Delete product?\n 3-Update Product?\n 0-Exit\n");
            scanf("%d",&y);
        while(y){
            switch(y){
            case 1:
                 AddProduct(L);
                 break;
            case 2:
                DeletProduct(L);
                break;
            case 3:
                 UpdateProduct(L);
                 break;
            case 0:
                break;
            default:
                printf("Wrong Enter");
            }
            printf("What do you want To Do ? \n 1- Add product?\n 2-Delete product?\n 3-Update Product?\n 0-Exit\n");
            scanf("%d",&y);
            }
        }
        else if (x==2){
                y=1;
            while(y){
                if (*L=='\0'){
                    printf("There NO Product Yet!\n"); break;}
                else{
                ProductDisplay(L);
                printf("Enter ID You Want To Buy\n");
                scanf("%d",&ID);
                Buy(L,ID);}
                printf("1-Buy More?\n 0-Exit? \n");
                scanf("%d",&y);}

        }

         printf("Who are you ?\n 1-Owner? \n 2-User want to buy?\n 0- Exit\n");
            scanf("%d",&x);
            }
 }
int IsEmpty(LinkedList*L)
{
    return(*L=='\0');
}

void ProductDisplay(LinkedList *L)
{
    Node *q=*L,*r=*L,*s=*L;
    int x,temp;
    printf("Which Way Do you prefer ?\n 1-Display by Best Seller \n 2-Display by Recently Added\n");
    scanf("%d",&x);
    if (x==1)
    {
        int size=0;
        while(s)
        {
            size = size+1;
            s=s->Next;
        }
        int a[size];
        int m=0;

        while (r)
        {
            a[m]=r->Data.Quantity;
            m++;
            r=r->Next;
        }
        int *Qtemp = a;
        int i, j, t;
        for (i = 0; i < size; i++)
        {

            for (j = i + 1; j < size; j++)
            {

                if (*(Qtemp + j) < *(Qtemp + i))
                {

                    t = *(Qtemp + i);
                    *(Qtemp + i) = *(Qtemp + j);
                    *(Qtemp + j) = t;
                }
            }
        }
        for(int m=0; m<size;m++)
        {
          printf("Quantity: %d\n",a[m]);


        }
        for(int m=0; m<size;m++)
        {q=*L;
            while(q)
            {
                if(q->Data.Quantity==a[m])
                {
                    printf("ID : %d \t Name:%s \t price:%d$ \t Quantity: %d\n",q->Data.ID,q->Data.Name,q->Data.Price,q->Data.Quantity);

                }q=q->Next;
            }

        }
        }
        else if (x==2)
        {
            while (q)
            {
                printf("ID : %d \t Name:%c \t price:%d$ \t Quantity: %d\n",q->Data.ID,q->Data.Name,q->Data.Price,q->Data.Quantity);
                q=q->Next;
            }
        }
        else
        {
            printf("Wrong Answer !!");
        }
    }

    void Buy(LinkedList *L,int ID)
    {
        if (CheckProduct(L,ID))
        {
            Node *q=*L;
            while(q)
            {
                if(q->Data.ID == ID)
                {
                    if (q->Data.Quantity<=0)
                    {
                        printf("Product NOT Available !\n");
                        return;
                    }
                    else
                    {
                        q->Data.Quantity --;
                        printf("Buy Is DONE ! \n");
                        return ;
                    }
                }
                else
                {
                    q = q->Next;
                }
            }
        }
        else
        {
            printf("Product Not Found Or Wrong ID !!");
        }
        return ;
    }

    int CheckProduct(LinkedList *L, int ID )
    {
        Node *q=*L;
        while(q)
        {
            if(q->Data.ID == ID)
                return 1;
            else
                q = q->Next;
        }
        return 0;
    }
    void AddProduct(LinkedList*L )
    {
        Product_info x;
        printf("Enter Product Id ");
        scanf("%d",&x.ID);
        if(CheckProduct(L,x.ID)==0)
        {
            printf("Enter Product Name ");
            scanf("%s",&x.Name);
            printf("Enter Product Quantity ");
            scanf("%d",&x.Quantity);
            printf("Enter Product Price ");
            scanf("%d",&x.Price);
            Node* newproduct = (Node *) malloc(sizeof(Node));
            newproduct->Data=x;
            newproduct->Next = *L;
            *L=newproduct;
        }
        else
            printf("This Id is Exist");
    }
    void DeletProduct(LinkedList*L)
    {
        if (IsEmpty(L) == 1)
        {
            printf("There is no Product to delete\n");
            return;
        }
        int ID;
        printf("Enter the Product ID \n");
        scanf("%d",&ID);
        if(CheckProduct(L,ID)==0)
        {
            printf("This ID is not Exist , try another one later \n");
            return;
        }
        Node *temp,*S = *L;
        if(S->Data.ID==ID)
        {
            temp=S->Next;
            *L=temp;
            free(S);
            printf("This Product is deleted\n");
        }
        else
        {
            while(S)
            {
                if(S->Next->Data.ID == ID)
                    break;
                else
                    S=S->Next;
            }

            if(S->Next)
            {
                temp=S->Next;
                S->Next=temp->Next;
                free(temp);
                printf("This Product is deleted\n");
            }

        }
    }
    void UpdateProduct(LinkedList *L)
    {         if (IsEmpty(L) == 1)
        {
            printf("There is no Product to delete\n");
            return;
        }
        int x,y,temp;
        char m;
        Node *q=*L;
        printf("Enter the Product ID \n");
        scanf("%d",&x);
        if(CheckProduct(L,x)==0)
            printf("The product is not Here");
        else
        {
            printf("(1)to change Product Name \t(2)to change Product ID\n (3)to change Product Price\t(4)to change Product Quantity\n");
            scanf("%d",&y);
            while(q && q->Data.ID!=x)
            {
                q=q->Next;

            }
            switch (y)
            {
            case 1:
            {
                printf("Enter The New Name");
                scanf("%s",&q->Data.Name);
                printf("Done your Name is %s\n",q->Data.Name);
                break;
            }
            case 2:
            {
                printf("Enter The New ID");
                scanf("%d",&temp);
                if (CheckProduct(L,temp)==1)
                {
                    printf("This ID is Exist");
                }
                else
                {
                    q->Data.ID=temp;
                    printf("Done your ID is %d\n",q->Data.ID);
                }

                break;
            }
            case 3:
            {
                printf("Enter the new Price\n");
                scanf("%d",&q->Data.Price);
                printf("Done your Product Price is %d\n",q->Data.Price);
                break;
            }
            case 4:
            {
                printf("Enter the new Quantity\n");
                scanf("%d",&q->Data.Quantity);
                printf("Done your Product Quantity is %d\n",q->Data.Quantity);
                break;
            }
            default:
            {
                printf("Wrong Enter\n");
            }
            }
        }
    }




