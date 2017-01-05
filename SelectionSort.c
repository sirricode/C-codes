#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0])) // dizi eleman sayısını bulan makro


int dizidoldur(int *ptr,int);
int dizibas(int *ptr,int);		//prototipleme
int dizisirala(int *ptr,int);


int i,j;


int main(int argc, char *argv[]) {
	srand( time( NULL ) );
	
	int dizi[100];
	
	
	dizidoldur(	dizi,	NELEMS(dizi));		//dizi dolduran fonksiyon
	
	dizisirala(	dizi,	NELEMS(dizi));		//dizinin değerlerini sıralayan fonksiyon
	
	dizibas(	dizi,	NELEMS(dizi));		//diziyi ekrana bastıran fonksiyon
	
	
	return 0;
}

int dizidoldur(int *ptr,int boyut)
{
	for(i=0;i<boyut;i++)
	{
		ptr[i] = rand()%1000;
	}
}


int dizibas(int *ptr,int boyut)
{
	for(i=0;i<boyut;i++)
	{
		printf("%d: %d\n",i,*(ptr+i));
	}
}


int dizisirala(int dizi[],int boyut)
{
	int kova,maks,indis;
	for(i=0;i<boyut;i++)
	{
		maks=-1;
		for(j=0;j<boyut-i;j++)
		{
			if(dizi[j]>maks)
			{
				maks= dizi[j];
				indis= j;
			}
		}
		dizi[indis]=dizi[j-1];
		dizi[j-1] = maks;
	}
}
