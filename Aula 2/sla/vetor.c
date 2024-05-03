#include <stdio.h>
#include <stdlib.h>

int main(){
    const int qtdNumero = 3;
    int numeros[qtdNumero];


    for (int i = 0; i < qtdNumero; i++)
    {
        printf("Informe um valor: \n");
        scanf("%i", &numeros[i]);
    }
    system("clear");

    for (int i = 0; i < qtdNumero; i++)
    {
        printf("Os valores são Numeros[%i] = %i\n", i, numeros[i]*2);
    }
    
}