#include<bits/stdc++.h>
#include<windows.h>
#include<string>
using namespace std;

HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void gotoXY(int x, int y)
{
    CursorPosition.X=x;
    CursorPosition.Y=y;
    SetConsoleCursorPosition(console, CursorPosition);
}


int i,g1=0,g2=0,g3=0,g4=0,g5=0,g6=0,g7=0,g8=0,gr;

int BSTcount=0;


struct Node
{
   int data;
   int id;
   char name[100];
   char group[10];
    struct Node *next,*dnr;
    struct Node *left;
    struct Node *right;
}*temp,*n,*d,*t1,*t2,*temp1, *addDonor,*node;
struct Node *root;

struct Head
{
    int c,donorCount;
    struct Node *f,*r;
    struct Node *donorHead;
}*head;


struct Node* FindMin(struct Node *node)
{
        if(node==NULL)
        {

                return NULL;
        }
        if(node->left)
                return FindMin(node->left);
        else
                return node;
}


struct Node* Insert(struct Node *node,int data)
{
        if(node==NULL)
        {
                struct Node *temp;
                temp = (struct Node *)malloc(sizeof(struct Node));
                temp -> data = data;
                temp -> left = temp -> right = NULL;
                return temp;
        }

        if(data >(node->data))
        {
                node->right = Insert(node->right,data);
        }
        else if(data < (node->data))
        {
                node->left = Insert(node->left,data);
        }

        return node;

}


struct Node * Find(struct Node *node, int data)
{
        if(node==NULL)
        {

                return NULL;
        }
        else if(data > node->data)
        {

                return Find(node->right,data);
        }
        else if(data < node->data)
        {

                return Find(node->left,data);
        }
        else if(data==node->data)
        {

                return node;
        }
}
//Camp
struct Node2
{
    int day;
    string mon;
    int yr;
    struct Node2 *next;
}*temp41,*n2,*m,*d30;

struct Head2
{
    int c;
    struct Node2 *p;
}*head21,*newhead;

 void create_head2()
    {
    head21=(struct Head2*)malloc(sizeof(struct Head2));
    head21->c=0;
    head21->p=NULL;

    }

    void push(int x,string y,int z)
    {
        n2=(struct Node2*)malloc(sizeof(struct Node2));
        n2->day=x;
        n2->mon=y;
        n2->yr=z;
        n2->next=head21->p;
        head21->p=n2;
        head21->c++;
    }

    void pop()
    {
        temp41=head21->p;
        head21->p=temp41->next;
        free(temp41);
    }

    void reverse_date()
    {
        int v1,v3,i;
        string v2;

         newhead=(struct Head2*)malloc(sizeof(struct Head2));
            newhead->c=0;
            newhead->p=NULL;

        for(i=0;i<head21->c;i++)
        {
            temp41=head21->p;
            head21->p=temp41->next;
            v1=temp41->day;
            v2=temp41->mon;
            v3=temp41->yr;


            if(newhead->c==0)
            {
                 m=(struct Node2*)malloc(sizeof(struct Node2));
                  newhead->p=m;
                  m->day=v1;
                  m->mon=v2;
                  m->yr=v3;

                  m->next=NULL;
                  newhead->c++;
            }
            if(newhead->c>0)
            {
                 m=(struct Node2*)malloc(sizeof(struct Node2));
                 m->day=v1;
                  m->mon=v2;
                  m->yr=v3;

                 m->next=newhead->p;
                 newhead->p=m;
                 newhead->c++;
            }

        }

    }
void displayCamp()
{

    int k=0;

    d30=newhead->p;
    for(int i=0;i<newhead->c-1;i++)

    {
        k++;
        cout<<"Camp "<<k<<":\n"<<d30->day<<" "<<d30->mon<<" "<<d30->yr<<endl<<endl;
        d30=d30->next;
    }
}
//camp end
 void create_head()
    {
    head=(struct Head*)malloc(sizeof(struct Head));
    head->c=0;
    head->donorCount=0;
    head->f=NULL;
    head->r=NULL;
    head->donorHead=NULL;
    }

    int enqueue()
    {

 n=(struct Node*)malloc(sizeof(struct Node));
 n->data=1;
      if(head->c==0)
      {

           head->f=n;
           head->r=n;
       }

        if(head->c>0)
        {
            head->r->next=n;
            head->r=n;
        }
        n->next=NULL;
        head->c++;
        return head->c;
    }
    int dequeue()
    {
        if(head->c==0)
        {
            printf("there is no element");
        }
        if(head->c>0)
        {
        temp=head->f;
        head->f=head->f->next;
        free(temp);
        }
        head->c--;
        return head->c--;
    }

    void display()
    {

        d=head->f;
        for(i=0;i<head->c;i++)
        {
            printf("%d",d->data);
            d=d->next;
        }
    }
    void stock();
    void donor();
    void donorNode();
    void displayDonor();
    void bloodEqDis();
    void PrintInorder(struct Node *node);
    void camp();
    void delete_any();

int main()
{
    int y=14,menu_item=0,f;
    int t,x,choise=0,choise2=0;


    Home:
    system("cls");
    system("COLOR 3F");
    bool running=true;
    create_head();

 string pass="admin";
        t=enqueue();
        t=enqueue();
        t=enqueue();
        t=enqueue();
        t=enqueue();
        t=enqueue();

    gotoXY(12,2); ;printf("********************************************************************************************************\n");
    gotoXY(12,4);printf("                             Blood Bank Management \n\n");
    gotoXY(12,6);printf("********************************************************************************************************\n");
    gotoXY(40,9);printf("Main Menu\n\n");


  while(choise2!=8)
           {
            printf("\t1.Add Blood Donor\n");
            printf("\t2.Equipments\n");
            printf("\t3.Display Donor List\n");
            printf("\t4.Camp Details \n");
            printf("\t5.Stock details\n");
            printf("\t6.Search\n");
            printf("\t7.Delete\n");
            printf("\t8.Exit\n");
            printf(" \n\tEnter Your Choice:");
            scanf("%d",&choise2);
            printf("\n\n");
            switch(choise2)
            {
                case 1: {system("cls");
                    cout<<"How Many Donor You want to add?"<<endl;
                    cin>>choise;
                    while(choise--)
                    {
                        donorNode();
                        donor();
                    }
                    cout<<"\n\n";

                    break;
                    }
                case 2: system("cls");bloodEqDis();break;
                case 3: system("cls");displayDonor();break;
                case 4:system("cls");camp();break;
                case 5: system("cls");stock();break;
                case 6:{system("cls");
                            printf("which id u want to  find?\n");
                            scanf("%d",&f);
                            temp = Find(root,f);
                            if(temp==NULL)
        {
                printf("id not found\n\n");
        }
        else
        {
                 t2=head->donorHead;
     while(t2->id!=f)
     {
        t2=t2->dnr;
     }
    if(t2->id==f)
    {
        printf("ID\t Name \t\t\t\t Blood Group\n");
    printf("---\t -------- \t\t\t ----------------\n");
        printf("%d\t %s \t\t\t\t %s\n",t2->id,t2->name,t2->group);

    }
        }
         break;}
         case 7: system("cls");delete_any();
            break;
                default: break;
            }
           }
}



void stock()
{
         int t,x;
        printf("which group of blood you need?:\n");
          printf("\t1.For A+ blood\n");
          printf("\t2.For A- blood\n");
          printf("\t3.For B+ blood\n");
          printf("\t4.For B- blood\n");
          printf("\t5.For AB+ blood\n");
          printf("\t6.For AB- blood\n");
          printf("\t7.For O+ blood\n");
          printf("\t8.For O- blood\n");
               scanf("%d",&gr);
               if(gr==1)
               {
                   if(g1>=1)
                   {
                       printf("Now the bags of A+ blood available is %d\n \n",g1);
                       g1--;
                       x=dequeue();

                   }
                   else printf("sorry.not available\n\n");


               }
                 if(gr==2)
               {
                   if(g2>=1)
                   {
                       printf("Now the bags of A- blood is %d\n\n",g2);
                       g2--;
                       x=dequeue();

                   }
                   else printf("sorry.not available\n\n");


               }
                 if(gr==3)
               {
                   if(g3>=1)
                   {
                        printf("Now the bags of B+ blood is %d\n\n",g3);
                       g3--;
                       x=dequeue();

                   }
                   else printf("sorry.not available\n\n");
               }

                if(gr==4)
                {
                   if(g4>=1)
                   {
                        printf("Now the bags of B- blood is %d\n\n",g4);
                       g4--;
                       x=dequeue();

                   }
                   else printf("sorry.not available\n\n");
                }
                if(gr==5)
                {

                    if(g5>=1)
                   {
                       printf("Now the bags of AB+ blood is %d\n\n",g5);

                       g5--;
                       x=dequeue();
                   }
                   else printf("sorry.not available\n\n");
                }
                if(gr==6)
                {

                    if(g6>=1)
                   {
                       printf("Now the bags of AB- blood is %d\n\n",g6);

                       g6--;
                       x=dequeue();
                   }
                   else printf("sorry.not available\n\n");
                }
                if(gr==7)
                {

                    if(g7>=1)
                   {
                         printf("The bags of O+ blood available is %d\n\n",g7);
                            x=dequeue();

                            g7--;


                   }
                   else printf("sorry.not available\n\n");
                }
                if(gr==8)
                {

                     if(g8>=1)
                   {

                             printf("The bags of O- blood available is %d\n\n",g8);
                            x=dequeue();

                             g8--;
                   }
                   else printf("sorry.not available\n\n");
                }

               }

void donorNode()
{

    addDonor= (struct Node *) malloc((sizeof(struct Node)));
    printf("\nEnter Name: ");
   scanf("%s",&addDonor->name);
    cout<<"Enter Blood Group: ";
    scanf("%s",&addDonor->group);
    cout<<"Enter Id: ";
    scanf("%d",&addDonor->id);
    addDonor->dnr=NULL;
    root=Insert(root,addDonor->id);
    if(strcmp(addDonor->group, "A+")==0||strcmp(addDonor->group, "a+")==0)
        {g1++;}
    else if(strcmp(addDonor->group, "A-")==0||strcmp(addDonor->group, "a-")==0)
        {g2++;}
    else if(strcmp(addDonor->group, "B+")==0||strcmp(addDonor->group, "b+")==0)
        {g3++;}
    else if(strcmp(addDonor->group, "B-")==0||strcmp(addDonor->group, "b-")==0)
        {g4++;}
    else if(strcmp(addDonor->group, "AB+")==0||strcmp(addDonor->group, "ab+")==0)
        {g5++;}
    else if(strcmp(addDonor->group, "AB-")==0||strcmp(addDonor->group, "ab-")==0)
        {g6++;}
    else if(strcmp(addDonor->group, "O+")==0||strcmp(addDonor->group, "o+")==0)
        {g7++;}
    else if(strcmp(addDonor->group, "O-")==0||strcmp(addDonor->group, "o-")==0)
        {g8++;}

}
void donor()
{
    if(head->donorCount==0)
    {
        head->donorHead=addDonor;
        head->donorCount++;
    }
    else
    {
        temp=head->donorHead;
     while(temp->dnr!=NULL)
     {
        temp=temp->dnr;
     }
        temp->dnr=addDonor;
        head->donorCount++;
    }
}
void displayDonor()
{
    struct Node *temp32;
    temp32=head->donorHead;
    if(head->donorHead==NULL)
    {
        printf("\tAdd Donor First\n\n");
    }
    else
    {
    printf("\tID\t Name \t\t\t\t Blood Group\n");
    printf("\t---\t -------- \t\t\t ----------------");
            while(temp32->dnr!=NULL)
    {
        printf("\n");
       printf("\t%d\t %s \t\t\t\t %s",temp32->id,temp32->name,temp32->group);
        temp32=temp32->dnr;
        printf("\n");
    }
    if(temp32->dnr==NULL)
    {
        printf("\n");
        printf("\t%d\t %s \t\t\t\t %s",temp32->id,temp32->name,temp32->group);
         printf("\n\n");
    }
    }

}
void bloodEqDis()
{
    printf("\tLaboratory Equipment\n");
    printf("--------------------------------\n");
    printf("\t1.Typenex\n");
    printf("\t2.Blood Transfusion Equipment\n");
    printf("\t3.Temperature Monitors\n");
    printf("\t4.Laboratory Fridges & Freezers\n");
    printf("\t5.Slide Stainers\n");
     printf("--------------------------------\n\n");
}
void PrintInorder(struct Node *node)
{
        if(node==NULL)
        {
                return;
        }
        PrintInorder(node->left);
        printf("%d\n ",node->data);
        PrintInorder(node->right);
}
void camp()
{
create_head2();
  int a,c,g,h;
  string b;
cout<<"How many camp will you add?\n";
  cin>>g;

  while(g>0)
    {
  cout<<"Enter day\n";
  cin>>a;
  cout<<"Enter month\n";
  cin>>b;
  cout<<"Enter year\n";
  cin>>c;


  push(a,b,c);
  g--;
  }
   cout<<"\nCamping dates are:\n";

  reverse_date();
  cout<<"Day-Mon-Year\n";

  displayCamp();
}
void delete_any()
{
	struct Node *ptr,*ptr1;
	int key;

	if(head->donorHead == NULL)
	{
		printf("\nEmpty  List. Deletion not possible.\n\n");
	}
	else
	{
		printf("\nEnter the id  to be deleted: ");
		scanf("%d", &key);

		ptr = head->donorHead;
		if(ptr->id==key)
        {
            head->donorHead=ptr->dnr;
            free(ptr);
        }
        else
        {
                while((ptr->dnr != NULL) && (ptr->id != key))
		{
			ptr1 = ptr;
			ptr = ptr->dnr;
		}
		if(ptr->id == key)
		{
			ptr1->dnr = ptr->dnr;
			free(ptr);
		}
		else
		{
			printf("\nValue %d not found. Deletion not possible.\n", key);
		}
	}
        }

}

