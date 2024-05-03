/* 1 - Crie um algoritmo em C que armazene 10 números inteiros. Realize a soma dos números e verifique qual é o maior e menor número*/

#include <stdio.h>

int main(){
    int soma, qtdTamanho = 5;
    int menor, maior=0, numeros[qtdTamanho];

    for (int i = 0; i < qtdTamanho; i++)
    {
        printf("Informe um número: \n");
        scanf("%i", &numeros[i]);
        soma +=numeros[i];

        if(maior<numeros[i]){
            maior=numeros[i];
            
        }
        if (menor>numeros[i])
        {
            menor=numeros[i];
        }
    }

    printf("Maior: %i\n", maior);
    printf("Menor: %i\n", menor);
    
}