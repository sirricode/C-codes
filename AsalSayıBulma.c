#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, altsinir, ustsinir, bolundu=0,sayac=0,sayac1=0;
    
    printf("Alt siniri giriniz: \t");
    scanf("%d",&altsinir);
    printf("Ust siniri giriniz: \t");
    scanf("%d",&ustsinir);
    
    
    for(i=altsinir;i<ustsinir;i++)
    {
         bolundu=0;
         for(j=2;j<i/2+1;j++)
         {
                sayac++;
                if(i%j==0)
                 {
                           bolundu=1;    
                           break;  
                 }        
                 else  
                 {
                       bolundu=0;
                 }
         }
         if(bolundu==0)
         {
                  printf("%d sayisi asaldir\n",i);
                  sayac1++;
         }
    }
    printf("%d\n",sayac);
    printf("%d\n",sayac1);
    system("\nPause");
    return 0;
}
