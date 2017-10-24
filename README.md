# Bibliotecas-de-C
Todas as Bibliotecas Gráficas para criação de jogos em  Linguagem C

Algumas bibliotecas estão em extensão em .zip . 
Todas com os direitos autorais de cada criador.



**Biblioteca windows.h**

Contém declarações para todas as funções da API do Windows, todos os macros comuns utilizados pelos programadores do Windows, e todos os tipos de dados utilizados pelas várias funções e subsistemas.

Possibilita você a fazer coisas como:

-Criar janelas e botões;

-Enumerar arquivos de um diretório;

-Consultar informações sobre o sistema(eg processos, serviços, janelas);

-Coisas do gênero;

**Box2D**

Box2D executa simulação restrita de corpo rígido . Pode simular corpos compostos por polígonos convexos , círculos e formas de borda. Os corpos são unidos juntamente com articulações e atuados pelas forças . O motor também aplica gravidade , fricção e restituição .

O sistema de resolução e resolução de colisão da Box2D consiste em três peças: uma varredura incremental e uma fase ampla de poda , uma unidade de detecção de colisão contínua e um solucionador de contato estável de tempo linear. Esses algoritmos permitem simulações eficientes de corpos rápidos e grandes pilhas sem colisões faltantes ou causando instabilidades. 

**Biblioteca SFML**

O SFML fornece uma interface simples para os vários componentes do seu PC, para facilitar o desenvolvimento de jogos e aplicativos multimídia. É composto por cinco módulos: sistema, janela, gráficos, áudio e rede.

**Biblioteca graphics.h**

Esta interface fornece acesso a uma biblioteca de gráficos simples que permite desenhar linhas, retângulos, ovais, arcos, polígonos, imagens e cordas em uma janela gráfica.
_Instruções da Biblioteca -> graphics.docx_


**Biblioteca conio.h**

As funções da biblioteca declaradas pelo conio.h variam um pouco do compilador para o compilador.
Funções dos membros:

-**kbhit** - Determina se uma tecla do teclado foi pressionada.

-**g cgets** - lê uma string diretamente do console.

-**cscanf** - Lê valores formatados diretamente do console.

-**putch** - Grava um personagem diretamente no console.

-**cputs** - Grava uma string diretamente no console.

-**cprintf** - Formata valores e os grava diretamente no console.

-**Clrscr** - Limpa a tela.

-**getch** - Obter entrada de char do console

**Biblioteca locale.h**

Para caracteres especiais.
Sintaxe:

 setlocale(LC_ALL,"portuguese");
 
_OBS.:_ Essa linha tem que ser colocada depois do _int main(){_

**SDL**

Simple DirectMedia Layer é uma biblioteca de desenvolvimento multiplataforma projetada para fornecer acesso de baixo nível ao áudio, teclado, mouse, joystick e hardware gráfico via OpenGL e Direct3D. É usado por software de reprodução de vídeo, emuladores e jogos populares, incluindo o catálogo premiado da Valve e muitos jogos do Humble Bundle .

SDL está escrito em C, funciona nativamente com C ++, e existem ligações disponíveis para vários outros idiomas, incluindo C # e Python.
SDL 2.0 é distribuído sob a licença zlib . Esta licença permite que você use SDL livremente em qualquer software.


