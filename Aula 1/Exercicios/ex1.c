// Crie um algoritmo que peça ao usuário um numero e calcule a tabuada do 1 até 10.

#include <stdio.h>

int main(){
    int num;

    printf("Informe um valor para ter a tabuada:\n");
    scanf("%i", &num);

    for (int i = 0; i <= 10; i++)
    {
        printf("%i x %i = %i\n", num, i, num*i);
    }
    printf("Fim!");
    return 0;
}