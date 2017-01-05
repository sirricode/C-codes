#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int sayi[6];
    int toplar[6];
	int i;                                  
    int j;                                   
    int k;
    int l;         
	int sayac;
			 for (i=0;i<6;i++)
             {
             printf("%d. sayinizi giriniz :",i+1);
             scanf("%d",&sayi[i]);
             }
      printf("----------\n");
     
             for (j=0;j<6;j++)
            {
              toplar[j] = rand()%50 +1;

			}	  
	      printf("Cekilis Sonucu Toplarimiz;\n");
		  for(j=0;j<6;j++)
	      {
	      	printf("%d. top: %d\n",j+1,toplar[j]);
		  }
	 
	 
	 printf ("----------\n"); 
	  i=0;
	  j=0;
	  sayac=0;
	       for(k=0;k<6;k++)
	       {
	   	    
		       if ( sayi[i]==toplar[j] ) 
		       {
		       printf("%d sayisini tutturdunuz.\n",sayi[i]);
		       sayac++;
	   	       } 
		        else     printf("%d sayiniz toplarla eslesmemektedir.\n",sayi[i]); 
          i++;
	   	  j++;
		  }
    printf("----------------\n");		  
   if(sayac!=0)
   printf("TEBRIKLER! %d bildiniz.",sayac);
   else printf("MALESEF! hicbir sayiyi bilemediniz.");
	
	
	return 0;
}
