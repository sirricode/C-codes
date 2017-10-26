#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
		4 basamaklý sayý tahmin etme oyunu
*/



int puanHesapla(int arti, int eksi, int hak){
	return 10 * arti + 5 * eksi + 1000/hak  - (arti * eksi) / (arti + eksi);
}

int ekranBas(int * randSayi, int * arti, int * eksi, int hak){
	int tahmin;
	int i=0,j=0,tahminInt[4];
	system("cls");
	printf("Kalan hak: %d\nSayiyi tahmin ediniz: ", 10 - hak +1);
	scanf("%d",&tahmin);
	for(i = 3; i >= 0; i--){			//alinan tahmin int ini basamaklarýna ayýr
		tahminInt[i] = tahmin % 10;
    	tahmin /= 10;
	}
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(randSayi[j] == tahminInt[i]){		//elimizdeki random sayi ile tahmin basamaklarýný karþýlaþtýr
				if(i == j)
					*arti = *arti + 1;
				else
					*eksi = *eksi + 1;
			}
		}
	}
	printf("-%d +%d\n",*eksi,*arti);
	system("pause");
	if(*arti == 4){				//4 artimiz varsa bildik demektir
		printf("Bildiniz!");
		return 0;
		
	}
	return 1;
}

int oyunaBasla(){
	int randSayi[4], gecici = 0,hak = 1, puan = 0;
	int arti=0, eksi=0, artiToplam=0, eksiToplam=0, flag = 1;
	
	
	//4 basamaklý random sayý üret
	randSayi[0] = rand() % 10;
	do{
		randSayi[1] = rand() % 10; 
	}
	while(randSayi[1] == randSayi[0]);
	do{
		randSayi[2] = rand() % 10; 
	}
	while(randSayi[2] == randSayi[0] || randSayi[2] == randSayi[1]);
	do{
		randSayi[3] = rand() % 10; 
	}
	while(randSayi[3] == randSayi[0] || randSayi[3] == randSayi[1] || randSayi[3] == randSayi[2]);

	while(flag){               //flag 0 olunca döngüden çýk
		if(hak == 11){		//hak 11 olursa
			system("cls");
			printf("\tHakkiniz doldu...\n");
			flag = 0;		//döngüden çýk
			break;
		}
		flag = ekranBas(randSayi, &arti, &eksi, hak);    //ekranBas fonksiyonunu çalýþtýr ve dönen deðeri flag a eþitle
		if(flag == 1){		 //flag 1 olduðu sürece hak i arttýr
			hak++;
		}
		artiToplam += arti;	//yapilan artilari toplama ekle
		arti = 0;			//ve artilari sýfýrla
		eksiToplam += eksi;	//yapilan eksileri toplama ekle
		eksi = 0;			//ve eksileri sýfýrlar
		if(flag == 0)		//flag 0 ise diziden çýk
			break;
	}
	
	puan = puanHesapla(artiToplam, eksiToplam, hak);	//toplam artilardan, eksilerden ve kaçýncý hakta bilindiðine göre puani hesaplayýp puana yaz
	printf("\n\tPuaniniz:  %d\n",puan);  //puani kullanýcýya göster
	system("pause");
	return puan; //puan döndür
}

int dosyayaYaz(int puan){
	FILE *fptr;
	char buffer[128], dosyadanStringler[10][128], isimler[10][128], isim[16];
	int puanListesi[10], elemanSayisi = 0, sonIndex = 0, hedefIndex = 11,i = 0, flag = 0, offset = 0;
	fptr = fopen("top10.txt","r");						
	if(fptr == NULL)									// dosya kontrolleri yapýldý
		fptr = fopen("top10.txt","w+");					// dosya yoksa yeni dosya oluþtur
	fclose(fptr);
	
	fptr = fopen("top10.txt","r");						// artýk dosya kesin olarak var o yüzden okumak için aç
	fseek(fptr, 0, SEEK_END);							//dosyada imleci sona getir
    if (ftell(fptr) != 0){								// eðer imlec hala 0 nokta deðilse 
    	fseek(fptr, 0, SEEK_SET);						//imleci dosyanýn baþýna getir
		while(fgets(buffer,128,fptr) != NULL && buffer != "\n"){		//dosyadan veri çek eðer veri NULL ve \n deðilse
			strcpy(dosyadanStringler[elemanSayisi], buffer);			//çektiðin veriyi dosyadanStringler dizisine ata
			elemanSayisi++;							//kaç tane sayý aldýðýmýzý saklýyor
			if(elemanSayisi == 10)					//eleman sayisi 10 olduysa döngüden çýk
				break;
		}
		sonIndex = elemanSayisi - 1;
	
		for(i = sonIndex; i >= 0; i--){												// sonIndexten baþlayýp 0 a kadar dön
			sscanf(dosyadanStringler[i],"%d %s\n",&puanListesi[i],isimler[i]);		// dosyadanStringler dizisinin içindeki stringlerden formatlý çekip puanListesi ve isimler dizisine kaydet
			if(puan > puanListesi[i]){						//eðer fonksiyona gelen puan, puanListesinin i. elemanýndan yüksekse 
				hedefIndex = i;								//hedefIndexi i ye eþitle
				flag = 1;									//ve flagi 1 yap
			}
		}
		if(sonIndex < 9){					//sonIndex 9 dan küçükse kesin olarak gir çünkü en iyi 10 oyuncuyu daha tamamlamadýðýmýz için kesinlikle isme ihtiyac var
			flag = 1;
			if(hedefIndex == 11)				//eðer hedefIndex default deðerindeyse sonIndex'in 1 büyüðüne getir ki son elemandan bir sonraki yere yerleþsin
				hedefIndex = sonIndex + 1;
		}
		if(flag){								//flag 1 ise
			printf("\tIsminizi giriniz: \t");	//kullanýcýya ismini sor
			scanf("%s",isim);
		}
		else
			return -1;							//eðer flag 0 ise ilk 10 a giremedi o yüzden fonksiyonu kapat yapýlmasý gereken bir iþlem yok
		fclose(fptr);
		fptr = fopen("temp10.txt", "w+");
		
		for(i = 0; i <= sonIndex + 1; i++){					//i sonIndex in 1 büyüðüne gelene kadar dön
			if(i == 10)										//i 10 a gelmiþse döngüden çýk çünkü ilk 10 kiþi doldu
				break;
			if(i == hedefIndex){							//eðer i hedefIndex e eþit ise o zaman fonksiyona gelen puaný yerleþtir
				fprintf(fptr,"%d %s\n",puan,isim);
				offset = 1;									//ve offseti 1 yap ki sýradaki elemanlarýn yeri bozulmasýn
			}
			else
				fputs(dosyadanStringler[i-offset],fptr);
		}
		fclose(fptr);
		remove("top10.txt");								//top10 dosyasýný sil
		rename("temp10.txt","top10.txt");					// ve geçiçi dosyayý top10 yap
	}
	else{										//eðer dosyanýn sonundaki imleç 0 a eþitse dosya boþ
    	fseek(fptr, 0, SEEK_SET);
    	fclose(fptr);
    	printf("Isminizi giriniz: ");			//dosya boþ ise direk ismi sorup dosyaya yazdýr
		scanf("%s",isim);
    	fptr = fopen("top10.txt", "a");
    	fprintf(fptr,"%d %s\n",puan, isim);
	}
	fclose(fptr);
}

void top10(){
	FILE *fptr;
	char buffer[128];				//dosyadan çektiðim satýrlarý saklayan dizi
	system("cls");
	fptr = fopen("top10.txt","r");	//dosyayý okumak için açtýk
	if(fptr == NULL){				//dosya yok ise
		printf("-------------------------------------------------\n|\t\t\t\t\t\t|\n|\ttop10.txt dosyasi bulunamadi...\t\t|\n|\t\t\t\t\t\t|\n-------------------------------------------------\n");
		return;
	}
	printf("--------------------------------\n\tEn iyi 10 skor\n--------------------------------\n");
	while(fgets(buffer,128,fptr) != NULL && buffer != "\n"){	//dosyadan okunan veri NULL ve \n deðilse devam et döngüye
		printf("%s",buffer);	//çektiðin veriyi yazdýr
	}
	fclose(fptr);
	printf("--------------------------------\n");
}

int main(){
	srand(time(NULL));          //Random sayýlarýn random olmasýný saðlayan fonksiyon
	int flag = 1;				//Bool yerine kullandýðým int deðeri
	int secenek, puan=0;
	while(1){
		system("cls");
		printf("---------------------------------\n|\t1-Oyuna Basla\t\t|\n|\t2-En iyi 10 puan\t|\n|\t3-Cikis\t\t\t|\n---------------------------------\n\nSeciminizi giriniz:\t");  //menüyü yazdýr
		scanf("%d",&secenek);
		switch(secenek){
			case 1:
				puan = oyunaBasla();		//oyunaBasla fonksiyonundan dönen deðeri puana eþitledik
				dosyayaYaz(puan);			//puaný dosyaya yazýlmak üzere yolladýk
				break;
			case 2:
				top10();					//en iyi 10 oyuncuyu ekrana yazdýran fonksiyonum
				system("pause");
				break;
			case 3:
				return -1;
			default:
				printf("Girdiginiz secenek bulunmamaktadir...");
		}
	}
}
