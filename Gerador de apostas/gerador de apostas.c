#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Protótipo da função
int verificarRepeticao(int aposta[], int tamanho, int numero);

int main() {
    int numAposta = 6;  // Quantidade de números na aposta
    int valorMaximo = 60;  // Valor máximo para os números da loteria

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    printf("Gerador de Apostas da Loteria\n\n");

    printf("Quantos jogos você deseja gerar? ");
    int numJogos;
    scanf("%d", &numJogos);

    printf("\nApostas geradas:\n");
	
	int i, j;
	
    for (int i = 0; i < numJogos; i++) {
        printf("Jogo %d: ", i + 1);

        for (int j = 0; j < numAposta; j++) {
            // Gera números aleatórios únicos para a aposta
            int aposta[numAposta];  // Declare o array de aposta aqui
            int numero;
            do {
                numero = rand() % valorMaximo + 1;
            } while (verificarRepeticao(aposta, j, numero));

            aposta[j] = numero;  // Armazena o número na aposta
            printf("%d ", numero);
        }

        printf("\n");
    }

    return 0;
}

// Função para verificar se um número já foi escolhido na aposta
int verificarRepeticao(int aposta[], int tamanho, int numero) {
    for (int i = 0; i < tamanho; i++) {
        if (aposta[i] == numero) {
            return 1;  // Número repetido encontrado
        }
    }
    return 0;  // Número não repetido
}

