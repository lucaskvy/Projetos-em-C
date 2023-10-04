#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prot�tipo da fun��o
int verificarRepeticao(int aposta[], int tamanho, int numero);

int main() {
    int numAposta = 6;  // Quantidade de n�meros na aposta
    int valorMaximo = 60;  // Valor m�ximo para os n�meros da loteria

    // Inicializa o gerador de n�meros aleat�rios com o tempo atual
    srand(time(NULL));

    printf("Gerador de Apostas da Loteria\n\n");

    printf("Quantos jogos voc� deseja gerar? ");
    int numJogos;
    scanf("%d", &numJogos);

    printf("\nApostas geradas:\n");
	
	int i, j;
	
    for (int i = 0; i < numJogos; i++) {
        printf("Jogo %d: ", i + 1);

        for (int j = 0; j < numAposta; j++) {
            // Gera n�meros aleat�rios �nicos para a aposta
            int aposta[numAposta];  // Declare o array de aposta aqui
            int numero;
            do {
                numero = rand() % valorMaximo + 1;
            } while (verificarRepeticao(aposta, j, numero));

            aposta[j] = numero;  // Armazena o n�mero na aposta
            printf("%d ", numero);
        }

        printf("\n");
    }

    return 0;
}

// Fun��o para verificar se um n�mero j� foi escolhido na aposta
int verificarRepeticao(int aposta[], int tamanho, int numero) {
    for (int i = 0; i < tamanho; i++) {
        if (aposta[i] == numero) {
            return 1;  // N�mero repetido encontrado
        }
    }
    return 0;  // N�mero n�o repetido
}

