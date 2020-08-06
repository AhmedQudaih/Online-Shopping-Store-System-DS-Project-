typedef struct Product
{
    int ID ;
    char Name [20];
    int Price;
    int Quantity;
} Product_info;

typedef struct node
{
    Product_info Data ;
    struct node *Next;
} Node;

typedef Node *LinkedList;
void DeletProduct(LinkedList *L);
int IsEmpty(LinkedList*L);
void AddProduct(LinkedList *L);
void UpdateProduct(LinkedList *L);
void ProductDisplay(LinkedList *L);
void Buy(LinkedList *L,int ID);
int CheckProduct(LinkedList *L, int ID );
void menu(LinkedList *L);

