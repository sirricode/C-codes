#include <stdio.h>
#include <stdlib.h>

struct node {
   int oncelikSirasi;
   char isim[20];
   struct node *next;
};

struct node *start;

node* DugumOlustur(){
	struct node *link = (struct node*) malloc(sizeof(struct node));
	printf("\nIsminiz: ");
	scanf("%s",link->isim);
	printf("Oncelik siraniz: ");
	scanf("%d",&(link->oncelikSirasi));
	link->next=NULL;
	return link;
}

void disp()
{
	struct node *temp;
	temp = start;
	printf("Oncelik Sirasi: ");
	while(temp!=NULL)
	{
		printf("(%d,%s) ", temp->oncelikSirasi,temp->isim);
		temp=temp->next;
	}
printf("\n");
}

//Bagli Liste olustur
void push(){
	struct node *temp, *t;
	temp = DugumOlustur();

	
	if(start==NULL)
		start = temp;
	else if(start->oncelikSirasi>temp->oncelikSirasi)
	{
		temp->next=start;
		start=temp;
	}
	else
	{
		t=start;
		while(t->next!=NULL && (t->next)->oncelikSirasi<=temp->oncelikSirasi )
			t=t->next;
		temp->next=t->next;
		t->next=temp;
	}
} 
void pop()
{
	if(start!=NULL)
	{
	printf("\nSilindi: (%d,%s) \n",start->oncelikSirasi,start->isim);
	start = start->next;
	disp();
	}
	else
		printf("\nHata! Liste bos.");
}
int main(){
	int secim, flag=1;
	while(flag==1)
	{
		system("cls");
		printf("\nIslem seciniz:\n1. Musteri ekle\n2. Musteri iste\n3. Exit\n");
		scanf("%d",&secim);
		system("cls");
		switch(secim)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				flag=0;
				break;
			default:
				printf("Yanlis secim!");
		}
		system("pause");
	}
	return 0;
}	
