#include <stdio.h>
#include <unistd.h>
#pragma setlocale("LC_ALL", "en_US.UTF-8")
#include <string.h>
#include <time.h>





void cobraNaCaixa() {

    char boxes[5] = {'-', '-', '-', '-', '-'};
    int snakeBox, buttonBox;
    int playerTurn, chosenBox;
    char player1[30], player2[30];

    printf("A tumba do Fárao Neebe é escura e cheia de mistérios...\n");
    sleep(1);
    printf("Você(Insira seu nome): \n");
    scanf("%s", &player1);
    printf("%s e seu fiel amigo(Insira nome para o segundo jogador): \n",
           player1);
    scanf("%s", &player2);
    printf("Estão se aventurando. Já cansados, encostam em uma das paredes...\n");
    sleep(2);
    printf("Um suave click é escutado e depois um ranger repentino!\n");
    sleep(2);
    printf("Todas as saídas se fecharam e no centro da sala agora estão "
           "dispostas 5 caixas...\n");
    sleep(2);

    char arte[] =
            "         _______              _                 _        _   _          "
            " _          \n    /\\  |__   __|            | |               | |      "
            "| \\ | |         | |         \n   /  \\    | |_   _ _ __ ___ | |__   __ "
            "_    __| | ___  |  \\| | ___  ___| |__   ___\n  / /\\ \\   | | | | | '_ "
            "` _ \\| '_ \\ / _` |  / _` |/ _ \\ | . ` |/ _ \\/ _ \\ '_ \\ / _ \\\n / "
            "____ \\  | | |_| | | | | | | |_) | (_| | | (_| |  __/ | |\\  |  __/  "
            "__/ |_) |  __/\n/_/    \\_\\ |_|\\__,_|_| |_| |_|_.__/ \\__,_|  "
            "\\__,_|\\___| |_| \\_|\\___|\\___|_.__/ \\___|\n";
    printf("%s", arte);
    printf("");
    sleep(2);

    printf("Para sair com vida terão de testar sua sorte!");
    sleep(2);
    printf("Regras do jogo:\n\n");
    sleep(2);
    printf("- O computador escolherá aleatoriamente quem começa abrindo a "
           "primeira caixa.\n");
    sleep(2);
    printf("- O jogador escolhido deve escolher uma das cinco caixas.\n");
    sleep(2);
    printf("- Cada caixa só pode ser escolhida uma vez.\n");
    sleep(2);
    printf("- O jogo deve continuar até que alguém encontre ou o botão ou a "
           "cobra.\n");
    sleep(2);
    printf("- Ao terminar o jogo, vocês terão a escolha de jogar novamente (se "
           "corajosos) ou voltar ao menu principal.\n");
    sleep(2);

    //randomizando as caixas para a cobra, e para o botão.

    srand(time(NULL));
    snakeBox = rand() % 5;
    boxes[snakeBox] = 'S';

    buttonBox = rand() % 5;
    while (buttonBox == snakeBox) {
        buttonBox = rand() % 5;
    }
    boxes[buttonBox] = 'B';

    /* for (int i = 0; i < 5; i++) {
        printf("%c ", boxes[i]);
    }
    printf("\n"); */

    // sorteando qual jogador será o da vez.
    playerTurn = rand() % 2;

    int continueGame = 1;

    while (continueGame == 1) {
        if (playerTurn + 1 == 2) {
            printf("Jogador %s, escolha uma caixa (1-5): ", player2);
        } else {
            printf("Jogador %s, escolha uma caixa (1-5): ", player1);
        }
        scanf("%d", &chosenBox);
        if (boxes[chosenBox - 1] == 'S') {
            printf("Oh não! Você escolheu a caixa com a cobra!\n");
            printf("Em um rápido movimento a cobra morde você e seu amigo!\n");
            printf("GAME OVER\n");
            break;
        } else if (boxes[chosenBox - 1] == 'B') {
            printf("Parabéns! Você achou a caixa com o botão!\n");
            printf("Sem hesitar vocês apertam o botão, as entradas da tumba se "
                   "abrem, e vocês correm para sair!\n");
            printf("GAME CLEAR\n");
            break;
        } else if (boxes[chosenBox - 1] == '-') {
            boxes[chosenBox - 1] = 'X';
        } else if (boxes[chosenBox - 1] == 'X') {
            printf("Essa caixa já foi escolhida, perdeu seu turno.");
        }
        playerTurn = (playerTurn + 1) % 2;
    }

    // resetando as caixas.
    for (int i = 0; i < 5; i++) {
        boxes[i] = '-';
    }

    // tela de fim de jogo.
    printf("1 - Jogar novamente. \n 0 - Voltar ao menu principal): ");
    scanf("%d", &continueGame);
    if (continueGame == 0) {
        main();
    } else if (continueGame == 1) {
        cobraNaCaixa();
    }
}




void quiz() {
    int continueGame = 1;
    int pontuacao = 0;
    char perguntas[5][100] = {
            "Qual o nome da startup criada por alunos de EC?\nA) Zenita\nB) "
            "Zenith\nC) Zona\nD) Drones.com\n",
            "\nQual a melhor turma de Ciencia da Computação do Cesupa?\nA) BCCMA3\nB) "
            "BCCMA1\nC) BCCMA5\nD) BCCTA3\n",
            "\nO melhor sistema de catalogação de livros é?\nA) Dudu\nB) Aranduba\nC) "
            "Arandu\nD) Anduru\n",
            "\nQuem foi o(a) autor(a) da frase -Não gostou, faz melhor-?\nA)  "
            "Isaac\nB) Fabio\nC) Ale\nD) Luciana\n",
            "\nQual predio do Cesupa possui estacionameno para os alunos?\nA) ARGO\nB) "
            "DIREITO\nC) ARQ E ENG\nD) PISC\n"};
    char respostaCorreta[5] = {'B', 'A', 'C', 'C', 'B'};
    int i;
    for (i = 0; i < 5; i++) {
        printf("%s", perguntas[i]);
        char respostaDoUsuário;
        scanf(" %c", &respostaDoUsuário);
        if (respostaDoUsuário == respostaCorreta[i]) {
            printf("\nVoce acertou!\n");
            pontuacao++;
            printf("+1 ponto!");
            sleep(1);
        } else {
            printf("\nVoce errou! Resposta certa %c.\n", respostaCorreta[i]);
            sleep(1);
        }
    }
    printf("\nPontuação total: %d", pontuacao);
    printf("\nDeseja jogar novamente? (1 - Sim, 0 - Não): ");
    scanf("%d", &continueGame);
    if (continueGame == 0) {
        main();
    } else if (continueGame == 1) {
        quiz();
    }
}

int main() {
    int gameChoice;
    printf("   __    ____   ___    __    ____  ____ \n");
    printf("  /__\\  (  _ \\ / __)  /__\\  (  _ \\( ___)\n");
    printf(" /(__)\\  )   /( (__  /(__)\\  )(_) ))__) \n");
    printf("(__)(__)(_\\_) \\___)(__)(__)(____/(____)\n");
    printf("Bem-vindo ao arcade, qual jogo gostaria de jogar?\n 1-Quiz \n "
           "2-Tumba do Faraó \n 3 - Quit.\n");
    scanf("%d", &gameChoice);
    switch (gameChoice) {
        case 1:
            quiz();
            break;
        case 2:
            cobraNaCaixa();
            break;
        case 3:
            break;
        default:
            break;
    }
}
