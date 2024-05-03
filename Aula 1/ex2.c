#include <stdio.h>

int main(){
    int nota1, nota2;
    float media;

    printf("Digite a primeira nota:\n");
    scanf("%i", &nota1);

    printf("Informoe o segundo valor:\n");
    scanf("%i", &nota2);

    media = (nota1+nota2)/2;


    if (media >= 6)
    {
        printf("A Média é: %.2f\n", media);
        printf("Passou de ano\n");
    }
    else{
        
        printf("A Média é: %.2f", media);
        printf("Reprovado\n");
    }
    
    return 0;
}