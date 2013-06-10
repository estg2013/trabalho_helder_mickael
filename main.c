#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//SDL
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_Mixer.h>

//TRIGAME
#include <trigame_administracao.h>
#include <trigame_jogo.h>
#include <trigame_interface.h>

#define RAND_MAX = 255;


int main(int argc, char* args[])
{
    /*
    *
    * SDL
    *   iniciar o frontend
    */


    //definir estrutura para o ecra e inicializar SDL
    SDL_Surface* ecra = NULL;
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    SDL_VideoInfo* info = SDL_GetVideoInfo();

    //definir a resolucao do ecra e o numero de cores
    ecra = SDL_SetVideoMode(1024,768,32,SDL_SWSURFACE);

    //inicializar o som
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,4096);

    //titulo da janela
    SDL_WM_SetCaption("TriGame v0.1a",NULL);

    /*
    *  inicializar dados
    */
    //funcoes iniciais
    carregarRecursos(); //carregar imagens, sons e fonts

    //filas
    //filaUtilizadores fU;
    //filaPerguntas fP;

    //preencher filas
    //if(fU = lerUtilizadores("users.db")) printf("Utilizadores - OK\n");
    //if(fP = lerPergunta("perguntas.db")) printf("Perguntas - OK\n");


    /*
    * loop menu
    */
    menu(ecra);

    /*
    *   fechar os processos do SDL
    */

    SDL_Quit();

    return 0;
}
