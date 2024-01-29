//11. Write a program to remove extra space from a Line

#include<stdio.h>

int main()
{
    int i=0,j=0;
    char na[100],sna[100];
    printf("Enter the string: ");
    gets(na);
    while(na[i] != '\0') {
        if(!(na[i]==' ' && na[i+1]==' ')) {
            sna[j] = na[i];
            j++;
        }
        i++;
    }
    sna[j] = '\0';
    printf("After removing space the string is: %s\n",sna);
    return 0;
}
