#include <stdio.h>

/* Torre: chamada recursiva reduz passos até zerar, imprimindo a direção atual. */
void moverTorre(int passosRestantes) {
    if (passosRestantes <= 0) {
        return;
    }

    printf("Direita\n");
    moverTorre(passosRestantes - 1);
}

/* Bispo: combina recursão com loops aninhados para formar o movimento diagonal. */
void moverBispo(int passosRestantes) {
    if (passosRestantes <= 0) {
        return;
    }

    const char *direcoesVerticais[] = {"Cima"};
    const char *direcoesHorizontais[] = {"Direita"};
    const int totalVerticais = 1;
    const int totalHorizontais = 1;

    for (int indiceVertical = 0; indiceVertical < totalVerticais; ++indiceVertical) {
        for (int indiceHorizontal = 0; indiceHorizontal < totalHorizontais; ++indiceHorizontal) {
            printf("%s %s\n", direcoesVerticais[indiceVertical], direcoesHorizontais[indiceHorizontal]);
        }
    }

    moverBispo(passosRestantes - 1);
}

/* Rainha: chamada recursiva simples que caminha sempre para a esquerda. */
void moverRainha(int passosRestantes) {
    if (passosRestantes <= 0) {
        return;
    }

    printf("Esquerda\n");
    moverRainha(passosRestantes - 1);
}

int main(void) {
    const int torrePassos = 5;
    const int bispoPassos = 5;
    const int rainhaPassos = 8;

    printf("Torre:\n");
    moverTorre(torrePassos);
    printf("\n");

    printf("Bispo:\n");
    moverBispo(bispoPassos);
    printf("\n");

    printf("Rainha:\n");
    moverRainha(rainhaPassos);
    printf("\n");

    /* Cavalo: loops aninhados controlam dois passos para cima e um para a direita. */
    const int cavaloTotalMovimentos = 3;
    int cavaloMovimentosEmitidos = 0;

    printf("Cavalo:\n");
    for (int passosVerticais = 0; passosVerticais <= 2; ++passosVerticais) {
        for (int passosHorizontais = 0; passosHorizontais <= 1; ++passosHorizontais) {
            if (cavaloMovimentosEmitidos >= cavaloTotalMovimentos) {
                break;
            }

            if (passosVerticais < 2) {
                if (passosHorizontais > 0) {
                    continue;
                }

                printf("Cima\n");
                ++cavaloMovimentosEmitidos;
                break;
            }

            if (passosHorizontais == 0) {
                continue;
            }

            printf("Direita\n");
            ++cavaloMovimentosEmitidos;
        }

        if (cavaloMovimentosEmitidos >= cavaloTotalMovimentos) {
            break;
        }
    }

    return 0;
}
