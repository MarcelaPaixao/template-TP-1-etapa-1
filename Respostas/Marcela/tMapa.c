#include "tTunel.h"

typedef struct tMapa{
    /* Número de linhas e de colunas do mapa */
    int nLinhas, nColunas;
    /* Número atual de frutas no mapa */
    int nFrutasAtual;
    /* Número máximo permitido de movimentos do pacman no mapa */
    int nMaximoMovimentos;
    /* O grid (matriz) de informações do mapa */
    char** grid;
    /* O tunel do mapa contendo 2 acessos */
    tTunel* tunel;
} tMapa;

/**
 * Cria o mapa dinamicamente
 * \param caminho caminho do arquivo com as configurações do mapa
 */
tMapa* CriaMapa(const char* caminhoConfig){
    tMapa * mapa;
    mapa->grid = (tMapa *)malloc(mapa->nLinhas * sizeof(tMapa*));
    
    /*tMapa InicializaJogo(FILE *entrada, char *dir) {
	FILE *inicializa;
	tMapa mapa;
	int i, j, comida = 0, l_inicial, c_inicial;
	char simb[40][100], nome_dir[1000];
	
	// Armazena nas variaveis adequadas as informacoes do arquivo de entrada
	fscanf(entrada, "%d %d %d", &mapa.linhas, &mapa.colunas, &mapa.limite_mov);
	fscanf(entrada, "\n");
	sprintf(nome_dir, "%s/saida/inicializacao.txt", dir);
	inicializa = fopen(nome_dir, "w");

	mapa.game_over = 0;
	mapa.comida = 0;
	mapa.qtd_parede = 0;
	mapa.tunel = 0;
	
	// Lê o arquivo de entrada e preenche arquivo de inicializacao
	for (i = 0; i < mapa.linhas; i++) {
		for (j = 0; j < mapa.colunas; j++) {

			fscanf(entrada, "%c", &simb[i][j]);
			fprintf(inicializa, "%c", simb[i][j]);
			mapa.matriz[i][j] = simb[i][j];
			// Preenche toda a matriz trilha com -1
			mapa.trilha[i][j] = -1;
			
			// Inicializa tipo Jogador e tipo Fantasma
			if (simb[i][j] == '>') {
				l_inicial = i;
				c_inicial = j;
				mapa.trilha[i][j] = 0;
				mapa.pacman = InicializaJogador(i, j, mapa.pacman);
			} else if (simb[i][j] == 'B') {
				mapa.fant_B = InicializaFantasma(i, j, simb[i][j], mapa.fant_B);
			} else if (simb[i][j] == 'P') {
				mapa.fant_P = InicializaFantasma(i, j, simb[i][j], mapa.fant_P);
			} else if (simb[i][j] == 'I') {
				mapa.fant_I = InicializaFantasma(i, j, simb[i][j], mapa.fant_I);
			} else if (simb[i][j] == 'C') {
				mapa.fant_C = InicializaFantasma(i, j, simb[i][j], mapa.fant_C);
			} else if (simb[i][j] == '*') {
				mapa.comida++; // Conta qtd total de comida
			}
		}
		fscanf(entrada, "\n");
		fprintf(inicializa, "\n");
	}
	fprintf(inicializa, "Pac-Man comecara o jogo na linha %d e coluna %d\n",
			l_inicial + 1, c_inicial + 1);
	fclose(inicializa);
	return mapa;
}*/
}

/**
 * Obtem a posição de um item do mapa
 * \param mapa mapa
 * \param item item a ser procurado no mapa
 */
tPosicao* ObtemPosicaoItemMapa(tMapa* mapa, char item){
    tPosicao *posicao = CriaPosicao(-1, -1);
    for(int i=0; i < mapa->nLinhas; i++){
        for(int j=0; j < mapa->nColunas; j++){
            if(mapa->grid[i][j] == item){
                //tPosicao *posicao = CriaPosicao(i, j);
                AtualizaPosicao(posicao, CriaPosicao(i, j));
                return posicao;
            }
        }
    }
    return posicao;
}

/**
 * Retorna o túnel do mapa com os 2 acessos
 * \param mapa mapa
 */
tTunel* ObtemTunelMapa(tMapa* mapa){
    return mapa->tunel;
}

/**
 * Obtem o item do mapa dada a posição
 * \param mapa mapa
 * \param posicao posicao do item a ser retornado
 */
char ObtemItemMapa(tMapa* mapa, tPosicao* posicao){
    return mapa->grid[posicao->linha][posicao->coluna];
}

/**
 * Retorna o número de linhas do mapa
 * \param mapa mapa
 */
int ObtemNumeroLinhasMapa(tMapa* mapa){
    return mapa->nLinhas;
}

/**
 * Retorna o número de colunas do mapa
 * \param mapa mapa
 */
int ObtemNumeroColunasMapa(tMapa* mapa){
    return mapa->nColunas;
}

/**
 * Retorna a quantidade de frutas iniciais do mapa
 * \param mapa mapa
 */
int ObtemQuantidadeFrutasIniciaisMapa(tMapa* mapa){
    return mapa->nFrutasAtual;
    //ABRIR O ARQUIVO DNV P VERIFICAR A QTD INICIAL?
}

/**
 * Retorna o número máximo de movimentos permitidos do mapa
 * \param mapa mapa
 */
int ObtemNumeroMaximoMovimentosMapa(tMapa* mapa){
        return mapa->nMaximoMovimentos;
}

/**
 * Retorna se a posição passada como parâmetro representa uma comida no mapa
 * \param mapa mapa
 * \param posicao posicao a ser verificada
 */
bool EncontrouComidaMapa(tMapa* mapa, tPosicao* posicao){
    return(mapa->grid[posicao->linha][posicao->coluna] == '*');
}

/**
 * Retorna se a posição passada como parâmetro representa uma parede no mapa
 * \param mapa mapa
 * \param posicao posicao a ser verificada
 */
bool EncontrouParedeMapa(tMapa* mapa, tPosicao* posicao){
    return(mapa->grid[posicao->linha][posicao->coluna] == '#');
}

/**
 * Atualiza um item do mapa
 * \param mapa mapa
 * \param posicao posicao do item
 * \param item posicao item que vai atualizar o mapa
 */
void AtualizaItemMapa(tMapa* mapa, tPosicao* posicao, char item){

}

/**
 * Verifica se o mapa possui tunel ou não
 * \param mapa mapa
 */
bool PossuiTunelMapa(tMapa* mapa){
    //for(int i=0; i < mapa->nLinhas; i++){
       // for(int j=0; j < mapa->nColunas; j++){
          //  if(mapa->grid[i][j] == '@'){
            //    return true;
           // }
       // }
   // }
    //return false; 
    if(mapa->tunel != NULL){ //Quando n tiver tunel vai ser inicializado com NULL ???
        return true;
    }
    return false;
}

/**
 * Retorna se o tunel foi acessado ou não
 * \param mapa mapa
 * \param posicao posicao a ser verificada
 */
bool AcessouTunelMapa(tMapa* mapa, tPosicao* posicao){
    if(EntrouTunel(mapa->tunel, posicao) == true){
        return true;
    }
    return false;
}

/**
 * Entra no túnel do mapa.
 * \param mapa mapa
 * \param posicao posicao que vai entrar no túnel
 */
void EntraTunelMapa(tMapa* mapa, tPosicao* posicao){
    LevaFinalTunel(mapa->tunel, posicao);
}

/**
 * Libera o espaço alocado para a estrutura tMapa
 * \param mapa mapa
 */
void DesalocaMapa(tMapa* mapa){
    DesalocaTunel(mapa->tunel); //Antes ou depois??
    for(int i=0; i < mapa->nLinhas; i++){
        free(mapa->grid[i]);
    }
    free(mapa->grid);
}