#ifndef TRIGAME_JOGO_H_INCLUDED
#define TRIGAME_JOGO_H_INCLUDED


#endif // TRIGAME_JOGO_H_INCLUDED


typedef struct
{
    SDL_Surface *n1;
    SDL_Surface *n2;
    SDL_Surface *n3;
    SDL_Surface *n1p;
    SDL_Surface *n2p;
    SDL_Surface *n3p;
    SDL_Surface *n4;
    SDL_Surface *n5;
    SDL_Surface *n6;
    SDL_Surface *n4p;
    SDL_Surface *n5p;
    SDL_Surface *n6p;
    SDL_Surface *n1c;
    SDL_Surface *n2c;
    SDL_Surface *n3c;
    SDL_Surface *n4c;
    SDL_Surface *n5c;
    SDL_Surface *n6c;
    SDL_Surface *btOpcoesb;
    SDL_Surface *fundo2;
    SDL_Surface *pontoVerde;
    Mix_Music *musica_menu;
    TTF_Font *font;
}botoesMenujogo;

botoesMenujogo btgame;

void recursosjogo()
{
 btgame.n1 = SDL_LoadBMP("img/n1.bmp");
 btgame.n2 = SDL_LoadBMP("img/n2.bmp");
 btgame.n3 = SDL_LoadBMP("img/n3.bmp");
 btgame.n4 = SDL_LoadBMP("img/n4.bmp");
 btgame.n5 = SDL_LoadBMP("img/n5.bmp");
 btgame.n6 = SDL_LoadBMP("img/n6.bmp");
 btgame.n1p = SDL_LoadBMP("img/n1p.bmp");
 btgame.n2p = SDL_LoadBMP("img/n2p.bmp");
 btgame.n3p = SDL_LoadBMP("img/n3p.bmp");
 btgame.n4p = SDL_LoadBMP("img/n4p.bmp");
 btgame.n5p = SDL_LoadBMP("img/n5p.bmp");
 btgame.n6p = SDL_LoadBMP("img/n6p.bmp");
 btgame.n1c = SDL_LoadBMP("img/n1c.bmp");
 btgame.n2c = SDL_LoadBMP("img/n2c.bmp");
 btgame.n3c = SDL_LoadBMP("img/n3c.bmp");
 btgame.n4c = SDL_LoadBMP("img/n4c.bmp");
 btgame.n5c = SDL_LoadBMP("img/n5c.bmp");
 btgame.n6c = SDL_LoadBMP("img/n6c.bmp");
 btgame.fundo2 = SDL_LoadBMP("img/fundo2.bmp");
 btgame.pontoVerde = SDL_LoadBMP("img/pontoVerde.bmp");
 btgame.musica_menu = Mix_LoadMUS("music/botoes.wav");
 btgame.font = TTF_OpenFont("font/font1.ttf",28);
}


void menujogo(SDL_Surface* ecra)
{

    char texto[100];
    int ratoX, ratoY,but1 = 0, but2 = 0, but3 = 0,but4= 0, but5 = 0, but6 = 0, but7 = 0;
    int estadoBotao[6] = {0,0,0,0,0,0};
    int butPressionado = 0;
    int dificuldade = 1;




    SDL_Event evento;
    SDL_Rect rect = {0,0,100,100};
    SDL_Surface *msg = NULL;
    SDL_Surface *voltar = NULL;
    SDL_Surface *Jogar = NULL;
    SDL_Surface  *facil, *medio, *dificil;
    SDL_Color cor1 = {0,0,0};SDL_Color cor2 = {0,255,0};SDL_Color cor3 = {255,0,0};

    facil = TTF_RenderText_Solid(btgame.font,"Facil",cor1);
    medio = TTF_RenderText_Solid(btgame.font,"Medio",cor1);
    dificil = TTF_RenderText_Solid(btgame.font,"Dificil",cor1);

    msg = TTF_RenderText_Solid(btgame.font,"Quantos Utilizadores pretendem jogar?",cor1);
    voltar = TTF_RenderText_Solid(btgame.font,"<- Voltar ",cor2);
    Jogar = TTF_RenderText_Solid(btgame.font," Iniciar ->",cor3);

    while(1)
    {
        SDL_PollEvent(&evento);
        SDL_BlitSurface(btgame.fundo2,NULL,ecra,NULL); //fundo

        rect.y = 680;

        switch(dificuldade)
        {
            case 1:
                rect.x = 300;
                break;
            case 2:
                rect.x = 490;
                break;
            case 3:
                rect.x = 650;
                break;
        }

        SDL_BlitSurface(btgame.pontoVerde,NULL,ecra,&rect);


        //botao n1
        rect.x = 240;
        rect.y = 210;
        if(estadoBotao[0] == 0) SDL_BlitSurface(btgame.n1,NULL,ecra,&rect);
        if(estadoBotao[0] == 1) SDL_BlitSurface(btgame.n1c,NULL,ecra,&rect);

        rect.x = 440;
        rect.y = 210;
        if(estadoBotao[1] == 0) SDL_BlitSurface(btgame.n2,NULL,ecra,&rect);
        if(estadoBotao[1] == 1) SDL_BlitSurface(btgame.n2c,NULL,ecra,&rect);

        rect.x = 640;
        rect.y = 210;
        if(estadoBotao[2] == 0) SDL_BlitSurface(btgame.n3,NULL,ecra,&rect);
        if(estadoBotao[2] == 1) SDL_BlitSurface(btgame.n3c,NULL,ecra,&rect);
        rect.x = 240;

        rect.y = 405;
        if(estadoBotao[3] == 0) SDL_BlitSurface(btgame.n4,NULL,ecra,&rect);
        if(estadoBotao[3] == 1) SDL_BlitSurface(btgame.n4c,NULL,ecra,&rect);

        rect.x = 440;
        rect.y = 405;
        if(estadoBotao[4] == 0) SDL_BlitSurface(btgame.n5,NULL,ecra,&rect);
        if(estadoBotao[4] == 1) SDL_BlitSurface(btgame.n5c,NULL,ecra,&rect);

        rect.x = 640;
        rect.y = 405;
        if(estadoBotao[5] == 0) SDL_BlitSurface(btgame.n6,NULL,ecra,&rect);
        if(estadoBotao[5] == 1) SDL_BlitSurface(btgame.n6c,NULL,ecra,&rect);

        rect.x = 105;
        rect.y = 127;
        SDL_BlitSurface(msg,NULL,ecra,&rect);

        rect.x = 30;
        rect.y = 650;
        SDL_BlitSurface(voltar,NULL,ecra,&rect);

        rect.x = 280;
        SDL_BlitSurface(facil,NULL,ecra,&rect);

        rect.x = 460;
        SDL_BlitSurface(medio,NULL,ecra,&rect);

        rect.x = 620;
        SDL_BlitSurface(dificil,NULL,ecra,&rect);

        rect.x = 800;
        rect.y = 650;
        SDL_BlitSurface(Jogar,NULL,ecra,&rect);


         if(evento.type == SDL_MOUSEMOTION)
        {
            ratoX = evento.motion.x;
            ratoY = evento.motion.y;
            sprintf(texto,"X:%i Y:%i",ratoX,ratoY);
            SDL_WM_SetCaption(texto,NULL); //altera o titulo da janela
        }

        if(evento.type == SDL_MOUSEMOTION)
        {
            ratoX = evento.motion.x;
            ratoY = evento.motion.y;
            if(ratoX > 241 && ratoX < 385 && ratoY > 211 && ratoY < 344){

               rect.x = 240;
               rect.y = 210;
               SDL_BlitSurface(btgame.n1p,NULL,ecra,&rect);
               if(but1 == 0)
                    Mix_PlayMusic(btgame.musica_menu,1);
                    but1 = 1;
                    but6 = but2= but3= but4= but5= 0;
            }else

            if (ratoX > 441 && ratoX < 582 && ratoY > 211 && ratoY < 344)
            {
                rect.x = 440;
                rect.y = 210;
                SDL_BlitSurface(btgame.n2p,NULL,ecra,&rect);
                if(but2 == 0)
                    Mix_PlayMusic(btgame.musica_menu,1);
                    but2 = 1;
                    but1 = but6= but3= but4= but5= 0;
            }else

            if (ratoX > 641 && ratoX < 782 && ratoY > 211 && ratoY < 344)
            {
                rect.x = 640;
                rect.y = 210;
                SDL_BlitSurface(btgame.n3p,NULL,ecra,&rect);
                if(but3 == 0)
                    Mix_PlayMusic(btgame.musica_menu,1);
                    but3 = 1;
                    but1 = but2= but6= but4= but5= 0;
            }

            else

            if (ratoX > 240 && ratoX < 382 && ratoY > 406 && ratoY < 540)
            {
                rect.x = 240;
                rect.y = 405;
                SDL_BlitSurface(btgame.n4p,NULL,ecra,&rect);
                if(but4 == 0)
                    Mix_PlayMusic(btgame.musica_menu,1);
                    but4 = 1;
                    but1 = but2= but3= but6= but5= 0;
            }
            else

            if (ratoX > 441 && ratoX < 582 && ratoY > 406 && ratoY < 540)
            {
                rect.x = 440;
                rect.y = 405;
                SDL_BlitSurface(btgame.n5p,NULL,ecra,&rect);
                if(but5 == 0)
                    Mix_PlayMusic(btgame.musica_menu,1);
                    but5 = 1;
                    but1 = but2= but3= but4= but6= 0;
            }
            else

            if (ratoX > 641 && ratoX < 782 && ratoY > 406 && ratoY < 540)
            {
                rect.x = 640;
                rect.y = 405;
                SDL_BlitSurface(btgame.n6p,NULL,ecra,&rect);
                 if(but6 == 0)
                    Mix_PlayMusic(btgame.musica_menu,1);
                    but6 = 1;
                    but1 = but2= but3= but4= but5= 0;
            } else if(ratoY > 650 && ratoY < 680)
            {
                if(ratoX > 270 && ratoX < 360)
                {
                    dificuldade = 1;
                }else if(ratoX > 455 && ratoX < 550)
                {
                    dificuldade = 2;
                }else if(ratoX > 615 && ratoX < 715)
                {
                    dificuldade = 3;
                }
            }
        }



         if(evento.type == SDL_KEYDOWN)
        {
            //ESC -> voltar ao principal
            if(evento.key.keysym.sym == SDLK_ESCAPE)
               exit(1);
        }

         if(evento.type == SDL_MOUSEBUTTONDOWN)
        {
            ratoX = evento.motion.x;
            ratoY = evento.motion.y;
            if(ratoX > 30 && ratoX < 245 && ratoY > 646 && ratoY < 680)
            {
               menu(ecra);
            }else
            if (ratoX > 17 && ratoX < 278 && ratoY > 15 && ratoY < 62)
            {
                menu(ecra);
            }else if(ratoX > 811 && ratoX < 1012 && ratoY > 645 && ratoY < 685)
            {
                //iniciar o jogo se existirem numero de jogadores seleccionados
                if(butPressionado > 0) iniciarJogo(butPressionado,dificuldade,ecra);
            }

        }

                  if(evento.type == SDL_MOUSEBUTTONDOWN)
                {
                    ratoX = evento.motion.x;
                    ratoY = evento.motion.y;
                    if  (ratoX > 241 && ratoX < 385 && ratoY > 211 && ratoY < 344)
                    {
                        butPressionado = 1;
                        if(estadoBotao[0] == 0)
                        {
                            estadoBotao[0] = 1;
                            estadoBotao[1] = 0;
                            estadoBotao[2] = 0;
                            estadoBotao[3] = 0;
                            estadoBotao[4] = 0;
                            estadoBotao[5] = 0;
                        }else{
                            estadoBotao[0] = 0;
                        }
                    }
                     if (ratoX > 441 && ratoX < 582 && ratoY > 211 && ratoY < 344)
                    {
                        butPressionado = 2;
                         if(estadoBotao[1] == 0)
                        {
                            estadoBotao[1] = 1;
                            estadoBotao[0] = 0;
                            estadoBotao[2] = 0;
                            estadoBotao[3] = 0;
                            estadoBotao[4] = 0;
                            estadoBotao[5] = 0;
                        }else{
                            estadoBotao[1] = 0;
                        }
                    }
                     if (ratoX > 641 && ratoX < 782 && ratoY > 211 && ratoY < 344)
                    {
                        butPressionado = 3;
                        if(estadoBotao[2] == 0)
                        {
                            estadoBotao[2] = 1;
                            estadoBotao[1] = 0;
                            estadoBotao[0] = 0;
                            estadoBotao[3] = 0;
                            estadoBotao[4] = 0;
                            estadoBotao[5] = 0;
                        }else{
                            estadoBotao[2] = 0;
                        }
                    }
                     if (ratoX > 240 && ratoX < 382 && ratoY > 406 && ratoY < 540)
                    {
                        butPressionado = 4;
                        if(estadoBotao[3] == 0)
                        {
                            estadoBotao[3] = 1;
                            estadoBotao[2] = 0;
                            estadoBotao[0] = 0;
                            estadoBotao[1] = 0;
                            estadoBotao[4] = 0;
                            estadoBotao[5] = 0;
                        }else{
                            estadoBotao[3] = 0;
                        }
                    }

                    if (ratoX > 441 && ratoX < 582 && ratoY > 406 && ratoY < 540)
                    {
                        butPressionado = 5;
                         if(estadoBotao[4] == 0)
                        {
                            estadoBotao[4] = 1;
                            estadoBotao[2] = 0;
                            estadoBotao[3] = 0;
                            estadoBotao[0] = 0;
                            estadoBotao[1] = 0;
                            estadoBotao[5] = 0;
                        }else{
                            estadoBotao[4] = 0;
                        }
                    }
                    if (ratoX > 641 && ratoX < 782 && ratoY > 406 && ratoY < 540)
                    {
                        butPressionado = 6;
                        if(estadoBotao[5] == 0)
                        {
                            estadoBotao[5] = 1;
                            estadoBotao[2] = 0;
                            estadoBotao[3] = 0;
                            estadoBotao[0] = 0;
                            estadoBotao[4] = 0;
                            estadoBotao[1] = 0;
                        }else{
                            estadoBotao[5] = 0;
                        }
                    }


                }
        SDL_Flip(ecra);
        SDL_Delay(50);

    }

    /* miss piggy
           /  '.     .'  \
          | |`\ \,,,/ /`| |
           \.;;;;;-;;;;;./
          .;;;;-'"'"'-;;;;,
         ;;.-((((   ))))-.;;
       ,;;/ =/_o/___\o_\= \;;,
     ,;;;/    .-'   '-.    \;;;,
   ,;;;;/    /         \    \;;;;,
  ,;;;;|     \  \   /  /     |;;;;,
  ;;;;;\    /-`.__.__.`-\    /;;;;;
   ;;;;;\  `    \.-./    `  /;;;;;
    ;;;;;;-._  , '-' ,  _.-;;;;;;
     ';;;;/()`'-'-=-'-'`()\;;;;'
  jgs  `/`\ '()()()()()() /`\`*/


}



void iniciarJogo(int numeroJogadores, int dificuldade, SDL_Surface *ecra)
{
    int Xini, Yini, cont, jogadoresSeleccionados=0;
    char texto[100];
    int ratoX, ratoY;
    filaUtilizadores fU, fUinicial;
    SDL_Event evento;
    SDL_Rect rect;
    SDL_Color cor = {0,0,0};
    SDL_Color corSeleccionado = {0,255,0};

    fUinicial = lerUtilizadores("users.db");

    SDL_Surface *txt = NULL;

    //ciclo para seleccionar os jogadores
    while(jogadoresSeleccionados<numeroJogadores)
    {
        SDL_PollEvent(&evento); //capturar eventos do rato e teclado

        jogadoresSeleccionados = 0;
        fU = fUinicial;

        rect.x = 425;
        rect.y = 100;

        SDL_BlitSurface(btgame.fundo2,NULL,ecra,NULL); //fundo


        //corre a fila para mostrar os jogadores todos
        while(fU != NULL)
        {
            fU->pos.x = rect.x;
            fU->pos.y = rect.y;

            if(fU->jogador.seleccionado == 1)
                {
                    jogadoresSeleccionados++;
                    txt = TTF_RenderText_Solid(btgame.font,fU->jogador.username,corSeleccionado);
                }else{
                    txt = TTF_RenderText_Solid(btgame.font,fU->jogador.username,cor);
                }


            SDL_BlitSurface(txt,NULL,ecra,&rect);

            rect.y = rect.y + 50;
            fU = fU->proximoJogador;
        }

        if(evento.type == SDL_KEYDOWN) //teclado
        {
            switch(evento.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                menujogo(ecra);
                break;
            default:
                break;
            }
        }

        if(evento.type == SDL_MOUSEMOTION) //movimento do rato
        {
            ratoX = evento.motion.x;
            ratoY = evento.motion.y;

            sprintf(texto,"X:%i Y:%i",ratoX,ratoY);
            SDL_WM_SetCaption(texto,NULL);
        }else if(evento.type == SDL_MOUSEBUTTONDOWN)
        {
            fU = fUinicial;
            while(fU != NULL)
            {
                if(ratoX > fU->pos.x && ratoX < (fU->pos.x + 200) && ratoY > fU->pos.y && ratoY < (fU->pos.y + 30))
                    {
                        switch(fU->jogador.seleccionado)
                        {
                            case 1:
                                fU->jogador.seleccionado = 0;
                                break;
                            default:
                                fU->jogador.seleccionado = 1;
                                fU->jogador.jogoCertas = 0;
                                fU->jogador.jogoErradas = 0;
                                break;
                        }
                    }
                fU = fU->proximoJogador;
            }
        }

        SDL_Flip(ecra);
        SDL_Delay(80);
    }

    jogo(ecra,numeroJogadores,dificuldade,fUinicial);
}

void jogo(SDL_Surface *ecra, int nJogadores, int nPerguntas, filaUtilizadores fUinicial)
{
    srand(time(NULL));
    char texto[100], nomes[200];
    filaUtilizadores fU;
    filaPerguntas fP, fPinicial;
    SDL_Event evento;
    SDL_Surface *txt = NULL;
    SDL_Surface *txtPergunta;
    SDL_Surface *txtR[4];
    SDL_Surface *txtR2;
    SDL_Surface *txtR3;
    SDL_Surface *txtR4;
    SDL_Rect rect;
    SDL_Color cor = {0,0,0};
    int perguntaActual = 0;
    int totalPerguntas = 0;
    int contPerguntas;
    int ratoX, ratoY;
    int perguntaRandom;
    int activa = 0;
    int certa = 69;
    int contRespostas;
    int i;
    int jogadorActual = 0;

    srand(time(NULL));

    posicoes pos[4];

    fPinicial = lerPergunta("perguntas.db");

    fP = fPinicial;
    while(fP != NULL)
    {
        totalPerguntas++;
        fP = fP->proximaPergunta;
    }

    while(perguntaActual < nPerguntas) //ciclo principal jogo
    {

        SDL_PollEvent(&evento);
        SDL_BlitSurface(btgame.fundo2,NULL,ecra,NULL);
        fU = fUinicial;
        fP = fPinicial;
        rect.y = 400;
        rect.x = 50;
        perguntaRandom = rand() % totalPerguntas;

        //desenhar utilizadores
        while(fU != NULL)
        {
            if(fU->jogador.seleccionado == 1)
                {
                    sprintf(nomes,"%s - C(%i) E(%i)",fU->jogador.username,fU->jogador.jogoCertas,fU->jogador.jogoErradas);
                    txt = TTF_RenderText_Solid(btgame.font,nomes,cor);
                    rect.y = rect.y + 50;
                    SDL_BlitSurface(txt,NULL,ecra,&rect);
                }
            fU=fU->proximoJogador;
        }


        contPerguntas = 0; //inicializa a variavel do random a zero
        if(activa == 0) //verifica se é para obter uma pergunta nova
        {
            while(fP != NULL)
            {
                if(contPerguntas == perguntaRandom) //desenha a pergunta e as respostas
                {
                    sprintf(texto,"Pergunta: %s",fP->perg.pergunta);
                    txtPergunta = TTF_RenderText_Solid(btgame.font,texto,cor);
                    sprintf(texto,"%s",fP->perg.resposta[0]);
                    txtR[0] = TTF_RenderText_Solid(btgame.font,texto,cor);
                    sprintf(texto,"%s",fP->perg.resposta[1]);
                    txtR[1] = TTF_RenderText_Solid(btgame.font,texto,cor);
                    sprintf(texto,"%s",fP->perg.resposta[2]);
                    txtR[2] = TTF_RenderText_Solid(btgame.font,texto,cor);
                    sprintf(texto,"%s",fP->perg.resposta[3]);
                    txtR[3] = TTF_RenderText_Solid(btgame.font,texto,cor);
                }
                contPerguntas++;
                fP = fP->proximaPergunta;
            }
        }
        rect.x = 170;
        rect.y = 150;
        SDL_BlitSurface(txtPergunta,NULL,ecra,&rect);




        rect.x = 200;

        if(activa == 0)
        {
            contRespostas = rand() % 4;
                for(i=0;i<4;i++)
                {
                    if(contRespostas==4) contRespostas = 0;
                    if(contRespostas==0) certa = i;

                    if(i>1) rect.x = 650;
                    if(i==1 || i==3) {
                            rect.y = 250;
                    }else{
                            rect.y = 320;
                    }
                    pos[contRespostas].x = rect.x;
                    pos[contRespostas].y = rect.y;
                    pos[contRespostas].pos = contRespostas;
                    contRespostas++;
                }
            activa = 1;
        }

        for(i=0;i<4;i++)
        {
            rect.x = pos[i].x;
            rect.y = pos[i].y;
            SDL_BlitSurface(txtR[pos[i].pos],NULL,ecra,&rect);
        }



        //movimento do rato
        if(evento.type == SDL_MOUSEMOTION)
        {
            ratoX = evento.motion.x;
            ratoY = evento.motion.y;

            sprintf(texto,"X:%i Y:%i Certa: %i",ratoX,ratoY,certa);
            SDL_WM_SetCaption(texto,NULL);
        }else if(evento.type == SDL_MOUSEBUTTONDOWN) //clique esquerdo do rato
        {
            if(ratoX > 14 && ratoX < 287 && ratoY > 12 && ratoY < 68) //voltar para o menu inicial
                menujogo(ecra);
            for(i=0;i<4;i++)
            {
                if(ratoX > pos[i].x && ratoX < (pos[i].x+140) && ratoY > pos[i].y && ratoY < (pos[i].y+30))
                {
                    if(certa == i)
                    {
                        SDL_WM_SetCaption("acertou",NULL);
                    }else{
                        SDL_WM_SetCaption("errou",NULL);
                    }
                    jogadorActual++;
                }
            }
        }

        if(jogadorActual == nJogadores)
        {
            SDL_Delay(2000);
            jogadorActual = 0;
            perguntaActual++;
            activa = 0;
        }

        SDL_Flip(ecra);
        SDL_Delay(80);
    }

    menu(ecra);
}
