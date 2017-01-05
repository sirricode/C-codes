#include <stdio.h>
#include <stdlib.h>
// 0 dan 300 e kadar kullanýcýdan alýnan sayýya bölünen sayýlarý yazdýran program
int main()
{
    int i,bolen;
    int sayac=0;
    printf("Boleni giriniz: ");
    scanf("%d",&bolen);
    for(i=1; i <= 300; i ++)
    {
                if(i%bolen==0)
                {
                              sayac++;
                              printf("%d\n",i);
                              i = i + (bolen-1);
                }
    }
    printf("Ýslem %d kere yapildi",sayac);
    getchar();
    return 0;
}
