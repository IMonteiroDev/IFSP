#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

int main(){
    srand(time(0));
    int num = rand() % 11;
    int resposta, qtd=0;

    do
    {
        fflush(stdin);
        printf("Adivinhe o número:\n");
        scanf("%i", &resposta);

        qtd++;

        if(resposta == num){
            system("clear");
            printf("Parabéns, você acertou!! O valor era %i\n", num);
            printf("Após %i tentativas!\n", qtd);
        }
    } while (resposta != num);
    
}