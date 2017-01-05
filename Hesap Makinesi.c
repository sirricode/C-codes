/* 
    
    Bu kod Algoritmalar ve Programlamaya Giriþ dersi için yazýlmýþtýr.
    
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    
    {
	int islem,sayi1,sayi2;
    float sonuc;
    //Kullanýcýdan 2 sayý al.
    printf("Birinci Sayiyi Girin: ");
    scanf("%d",&sayi1);
    printf("Ikinci Sayiyi Girin: ");
    scanf("%d",&sayi2);
    //Ýþlem türünü ekrana yazdýr. Kullanýcýya iþlemi seçtir.
    printf("\n1.Toplama""\n2.Cikarma""\n3.Bolme""\n4.Carpma\n""\nIslemi seciniz: ");
    scanf("%d",&islem);
    //Ýslemi uygula ve sonucu yazdýr.
    switch(islem){
	case 1:
        sonuc = (float)sayi1+(float)sayi2;  
        printf("\nSonuc:       %0.1f",sonuc);
    	break;
    case 2:
        sonuc = (float)sayi1-(float)sayi2;
        printf("\nSonuc:       %0.1f",sonuc);
        break;
    case 3:
        sonuc = (float)sayi1/(float)sayi2;
        printf("\nSonuc:       %0.1f",sonuc);
        break;
    case 4:
        sonuc = (float)sayi1*(float)sayi2;      
        printf("\nSonuc:       %0.1f",sonuc);
		break;
    default:
         printf("\n""Sectigin islem gecersiz...");       
		 break;
	}
	getchar();
	return 0;
	}
}
