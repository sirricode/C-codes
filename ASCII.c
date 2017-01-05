/*

    ASCII tablosunu yazdýrmak için kod.

*/

#include <stdio.h>

int main()
{
    int i;
    for (i=0; i < 256; i++)
        {
        printf("Degeri: %d ASCII kodu: %c\n", i, i);
        }
    getchar();
    return 0;   
}
