#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"portuguese");

    // Variáveis incializadas.
    int l, c, linha, coluna, jogador, ganhador, resp, jogadas;
    char jogo[3][3];

    do{
            jogador = 1;
            jogadas = 0;
            ganhador = 0;
            resp = 1;

        // Criando tabuleiro.
        for (l = 0; l < 3; l++){
            for ( c = 0; c < 3; c++){
            jogo[l][c] = ' ';
            }
        }
        do{
            // Imprimir jogo.
            printf("\n\t 0   1   2\n");
            for (l = 0; l < 3; l++){
                printf("\t");
                for ( c = 0; c < 3; c++){
                printf(" %c ", jogo[l][c]);
                if (c < 2){
                    printf("|");
                }
                if (c == 2)
                    printf(" %d", l);

                }
                if (l < 2)
                    printf("\n\t-----------\n");
            }

            // ler jogada.
            do{
                printf("\nJOGADOR %d: Digite a linha e a colunha que deseja jogar: ", jogador);
                scanf("%d%d", &linha, &coluna);
            }while (linha > 2 || linha < 0 || coluna > 2 || coluna < 0 || jogo[linha][coluna] != ' ');

            // marcar jogada.
            if (jogador == 1){
                jogo[linha][coluna] = 'X';
                jogador++;
            } else if (jogador == 2){
                jogo[linha][coluna] = 'O';
                jogador = 1;
            }
            jogadas++;

            // ganhador por linha.
            if (jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X' ||
                jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X' ||
                jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X')
            {
                printf("Parabéns! Jogador 1 ganhou por linha.");
                ganhador = 1;
            }

            if (jogo[0][0] == 'O' && jogo[0][1] == 'O' && jogo[0][2] == 'O' ||
                jogo[1][0] == 'O' && jogo[1][1] == 'O' && jogo[1][2] == 'O' ||
                jogo[2][0] == 'O' && jogo[2][1] == 'O' && jogo[2][2] == 'O')
            {
                printf("Parabéns! Jogador 2 ganhou por linha.");
                ganhador = 1;
            }
            // ganhador por coluna.
            if (jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X' ||
                jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X' ||
                jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X')
            {
                printf("Parabéns! Jogador 1 ganhou por coluna.");
                ganhador = 1;
            }

            if (jogo[0][0] == 'O' && jogo[1][0] == 'O' && jogo[2][0] == 'O' ||
                jogo[0][1] == 'O' && jogo[1][1] == 'O' && jogo[2][1] == 'O' ||
                jogo[0][2] == 'O' && jogo[1][2] == 'O' && jogo[2][2] == 'O')
            {
                printf("Parabéns! Jogador 2 ganhou por coluna.");
                ganhador = 1;
            }

            // ganhador por diagonal principal.
            if (jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X')
            {
                printf("Parabéns! Jogador 1 ganhou por diagonal principal.");
                ganhador = 1;
            }

            if (jogo[0][0] == 'O' && jogo[1][1] == 'O' && jogo[2][2] == 'O')
            {
                printf("Parabéns! Jogador 2 ganhou por diagonal principal.");
                ganhador = 1;
            }

            // ganhador por diagonal secundária.
            if (jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X')
            {
                printf("Parabéns! Jogador 1 ganhou por diagonal secundária.");
                ganhador = 1;
            }

            if (jogo[0][2] == 'O' && jogo[1][1] == 'O' && jogo[2][0] == 'O')
            {
                printf("Parabéns! Jogador 2 ganhou por diagonal secundária.");
                ganhador = 1;
            }
        }while (ganhador == 0 && jogadas < 9);

        // Imprimir jogo.
            printf("\n\t 0   1   2\n");
            for (l = 0; l < 3; l++){
                printf("\t");
                for ( c = 0; c < 3; c++){
                printf(" %c ", jogo[l][c]);
                if (c < 2){
                    printf("|");
                }
                if (c == 2)
                    printf(" %d", l);

                }
                if (l < 2)
                    printf("\n\t-----------\n");
            }

        if(ganhador == 0)
            printf("\nDEU VELHA!\n");

        printf("\n\nDigite 1 para jogar novamente: ");
        scanf("%d", &resp);
    }while(resp == 1);

    return 0;
}

