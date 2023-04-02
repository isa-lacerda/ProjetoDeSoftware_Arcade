# ProjetoDeSoftware_Arcade

## Índice.
* [Introdução](#Introdução)
* [Cobra na Caixa!](#Cobra-na-Caixa)
* [Quiz](#Quiz)
* [Bibliotecas](#Bibliotecas-Utilizadas)

## Introdução
Este programa é um Arcade que contém dois mini jogos, criado por [Isadora Lacerda](https://github.com/isa-lacerda) e [Bruna Melido](https://github.com/BrunaMelido) Um deles é um [Quiz](#Quiz), e o outro é o "[Cobra na Caixa!](#Cobra-na-Caixa)". O programa inicia mostrando um menu inicial do qual podem ser acessados os dois jogos. O programa utiliza conceitos iniciais de C, como estruturas condicionais e estruturas de repetição. Toda interação com o jogo é feita pelo terminal.
## Cobra na Caixa!
 Você e seu amigo estão se aventurando pela Tumba do Faraó Neebe, e acabam presos, tendo como única opção de saída abrir 5 caixas dispostas no centro da tumba.
 Em uma das cinco caixas há um botão que abrirá todas as saídas dali, e em outra caixa há uma cobra! Você e seu amigo alternarão turnos para abrir as caixas, um erro será fatal.

## Quiz.
 Um simples quiz de um jogador só, contém 5 perguntas e no fim do quiz você saberá sua pontuação total.
 
 ## Bibliotecas Utilizadas.
 * *__stdio.h__*: neste programa é usada para imprimir mensagens na tela e para solicitar entrada de dados do usuário.
 * *__unistd.h__*: utilizamos a função sleep() para pausar o programa por alguns segundos antes de imprimir mensagens na tela, para dar tempo do jogador ler o texto na tela.
 * *__string.h__*: usamos a biblioteca para manipular os nomes dos jogadores.
 * *__time.h__*: usamos a função srand() no jogo "Cobra na Caixa!" para aleatorizar o conteúdo das caixas a cada vez que o jogo for jogado, e para aleatorizar também o jogar da vez.
