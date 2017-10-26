#include<stdio.h>
#include<stdlib.h>



/* 
	Temel Hesap Birimi 								Birim Zaman 		Frekans(Tekrar)			Toplam
													(Unit Time)			(Frequency)				(Total)
	------------------------------------------------------------------------------------------------------------
*/
int donguluCozum(int nSayi){				//			-			//		-				//		-
	int i,toplam=0;			 				//			-			//		-				//		-
	for(i = 1; i <= nSayi; i++){			//		  1,1,1			//	1, (n+1), n 		//	  2n+2
		toplam += i;						//			1			//		n				//		n
	}										//			-			//		-				//		-
	return toplam;							//			1			//		1				//		1
}											//						//						//
											//						//						//	T(n)=3n+4

int matematikselCozum(int nSayi){			//			-			//		-				//		-
	int toplam=0;							//			-			//		-				//		-
	toplam = (nSayi*(nSayi+1))/2;			//			5			//		1				//      5
	return toplam;      					//			1			//		1				//		1					
											//						//						//	T(n)=6
}											//
											// Sonuc olarak matematiksel islem ile yapýlan algoritma
											// yürütme zamaný açýsýndan daha iyidir çünkü
											// donguyle yapýlan islem N sayýsýna baðlý olarak artarken 
											// matematiksel islem daima sabittir.
int main(){
	int i,nSayi;
	printf("N sayisi giriniz: ");
	scanf("%d",&nSayi);
	
		printf("dongu islemi ile: %d\n",donguluCozum(nSayi));
	
	matematikselCozum(nSayi);
	
}
