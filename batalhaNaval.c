#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

 // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.
    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
void AplicarCruz(int Tabuleiro[10][10], int OrigemLinha_Cruz, int OrigemColuna_Cruz){
    int cruz[5][5];

    //preencher a matriz da cruz
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 2  || j == 2)
            {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
            
        }
        
    }
    
    //sobrepor a matriz no tabuleiro
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int lin = OrigemLinha_Cruz - 2 + i;
            int col = OrigemColuna_Cruz - 2 + j;

            if (lin >= 0 && lin < 10 && col >= 0 && col < 10)
            {
                if(cruz[i][j] == 1 && Tabuleiro[lin][col] == 0) {
                    Tabuleiro[lin][col] = 1;
                }
            }
            
        }
        
    }
    
}
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0
void AplicarOctaedro(int Tabuleiro[10][10], int OrigemLinha_Octaedro, int OrigemColuna_Octaedro){
    
    int Octaedro[3][3];

    //preenche a matriz com o octaedro
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(i == 1 || j == 1){
                Octaedro [i][j] = 1;
            } else {
                Octaedro [i][j] = 0;
            }
        }
        
    }
    
    //Aplicar a matriz octaedro ao tabuleiro

    for ( int i = 0; i < 3; i++)
    {
            for (int j = 0; j < 3; j++)
        {
            int lin = OrigemLinha_Octaedro - 1 + i;
            int col = OrigemColuna_Octaedro - 1 + j;


            //verifica os limites do tabuleiro
            if (lin >= 0 && lin < 10 && col >= 0 && col < 10)
            {
                if(Octaedro[i][j] == 1 && Tabuleiro[lin][col] == 0) {
                    Tabuleiro[lin][col] = 1;
                }
            }
            
        }
        
    }
}
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
void AplicarCone(int Tabuleiro[10][10], int OrigemLinha_Cone, int OrigemColuna_Cone){

    

    //preencher a matriz cone
    for (int i = 0; i < 3; i++) //altura do cone
    {
        for (int j = -i; j <= i; j++) //largura do cone expandindo
        {
            //Aplicar a matriz cone no tabuleiro
            int lin = OrigemLinha_Cone + i;
            int col = OrigemColuna_Cone + j;

             //Verificar limites do tabuleiro
             if(lin >= 0 && lin < 10 && col >= 0 && col < 10){
                if(Tabuleiro[lin][col] == 0){
                    Tabuleiro[lin][col] = 1; //área afetada
                }
             }
        }
        
    }
    
}
  
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
    
    //Define o ponto de origem da Habilidade
    //Cruz
    int OrigemLinha_cruz = 2;
    int OrigemColuna_cruz = 2;

    //Octaedro
    int OrigemLinha2_octaedro = 8;
    int OrigemColuna2_octaedro = 8;

    //Cone
    int OrigemLinha3_Cone = 4 ;
    int OrigemColuna3_Cone = 4 ;

    //Aplica a habilidade Cruz
    AplicarCruz(Tabuleiro, OrigemLinha_cruz, OrigemColuna_cruz);
    AplicarOctaedro(Tabuleiro, OrigemLinha2_octaedro, OrigemColuna2_octaedro);
    AplicarCone(Tabuleiro, OrigemLinha3_Cone, OrigemColuna3_Cone);

    //4. Exibindo o Tabuleiro
    printf(" TABULEIRO BATALHA NAVAL \n");
    printf("   ");
    for ( int i = 0; i < 10; i++)
    {
        printf("%c ", linha[i]); //Imprime as letras 
    }  
    printf("\n");

    //Números lateral
    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", Coluna[i]); // imprime 1 2 3...
        
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


