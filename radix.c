#include <stdio.h>

int maior(int vetor[], int tamanho) {
    int maior = vetor[0];

    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }

    return maior;
}

void countingSort(int vetor[], int tamanho, int posicao) {
    int resultado[tamanho];
    int contagem[10] = {0};

    // Conta os dígitos
    for (int i = 0; i < tamanho; i++) {
        int digito = (vetor[i] / posicao) % 10;
        contagem[digito]++;
    }

    // Soma as posições
    for (int i = 1; i < 10; i++) {
        contagem[i] += contagem[i - 1];
    }

    // Organiza os elementos
    for (int i = tamanho - 1; i >= 0; i--) {
        int digito = (vetor[i] / posicao) % 10;

        resultado[contagem[digito] - 1] = vetor[i];
        contagem[digito]--;
    }

    // Copia de volta
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = resultado[i];
    }
}

void radixSort(int vetor[], int tamanho) {
    int maiorValor = maior(vetor, tamanho);

    // Começa pelas unidades, depois dezenas, centenas...
    for (int posicao = 1; maiorValor / posicao > 0; posicao *= 10) {
        countingSort(vetor, tamanho, posicao);
    }
}

int main() {
    int vetor[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original: ");

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    radixSort(vetor, tamanho);

    printf("\nVetor ordenado: ");

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");

    return 0;
}
