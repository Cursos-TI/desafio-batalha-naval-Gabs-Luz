#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

        // 0 == Água
    // 3 == Navio
    char linha[10] = {'A', 'B','C','D','E','F','G','H','I','J'};
    int Coluna[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //1. Criando Tabuleiro
    int Tabuleiro[10][10];

    //preencher tudo com Água (0)
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            Tabuleiro[i][j] = 0;
        }
        
    }
    
    //Colocar Navios (3)

    //vertical
    Tabuleiro[1][1] = 3; // linha 2, coluna B
    Tabuleiro[2][1] = 3; // linha 3, coluna B
    Tabuleiro[3][1] = 3; // linha 4, coluna B

    //Horizontal
    Tabuleiro[6][6] = 3; // linha 7, coluna G
    Tabuleiro[6][7] = 3; // linha 7, coluna H
    Tabuleiro[6][8] = 3; // linha 7, coluna I

    //4. Exibindo o Tabuleiro
    printf(" TABULEIRO BATALHA NAVAL \n");
    printf("  ");
    for ( int i = 0; i < 10; i++)
    {
        printf("%c ", linha[i]); //Imprime as letras 
    }  
    printf("\n");

    //Números lateral
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", Coluna[i]); // imprime 1 2 3...
        
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", Tabuleiro[i][j]); // mostra 0 (água) ou 3 (navio)
        }
        
        printf("\n");
    }
    
    return 0;
}


    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

}
