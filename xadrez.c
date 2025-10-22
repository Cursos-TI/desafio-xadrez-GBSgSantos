#include <stdio.h>

/* Programa que demonstra movimentos básicos de peças de xadrez.
 *
 * Torre, Bispo e Rainha são movidos através de funções recursivas,
 * evidenciando a chamada repetida enquanto há casas a percorrer.
 * O Cavalo utiliza loops aninhados com fluxo controlado via continue/break
 * para simular o deslocamento em "L".
 */

/* Torre: chamada recursiva imprime "Direita" até a contagem zerar.
 * passosRestantes controla o número de iterações recursivas ainda pendentes.
 */
void moverTorre(int passosRestantes) {
    if (passosRestantes <= 0) {
        return;
    }

    printf("Direita\n");
    moverTorre(passosRestantes - 1);
}

/* Bispo: para cada chamada recursiva, loops aninhados geram a combinação
 * vertical/horizontal que resulta no movimento diagonal "Cima Direita".
 * passosRestantes mantém quantas diagonais ainda precisam ser executadas.
 */
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

/* Rainha: chamada recursiva simples que move a peça para a esquerda.
 * passosRestantes marca a quantidade de casas que faltam.
 */
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

    /* Cavalo: loops aninhados controlam dois passos para cima e um para a direita.
     * cavaloTotalMovimentos define o total de impressões e cavaloMovimentosEmitidos
     * acompanha quantos movimentos já foram realizados.
     */
    const int cavaloTotalMovimentos = 3;
    int cavaloMovimentosEmitidos = 0;

    printf("Cavalo:\n");
    for (int passosVerticais = 0; passosVerticais <= 2; ++passosVerticais) {
        for (int passosHorizontais = 0; passosHorizontais <= 1; ++passosHorizontais) {
            /* Se já percorremos as três casas (duas verticais, uma horizontal), encerramos. */
            if (cavaloMovimentosEmitidos >= cavaloTotalMovimentos) {
                break;
            }

            /* Enquanto passosVerticais for menor que 2, garantimos a impressão de "Cima".
             * O segundo loop se repete apenas uma vez graças ao break após emitir a direção.
             */
            if (passosVerticais < 2) {
                if (passosHorizontais > 0) {
                    continue;
                }

                printf("Cima\n");
                ++cavaloMovimentosEmitidos;
                break;
            }

            /* Ao atingir passosVerticais == 2, passamos a emitir o passo horizontal.
             * Utilizamos continue para pular iterações que ainda não atingiram o índice desejado.
             */
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
