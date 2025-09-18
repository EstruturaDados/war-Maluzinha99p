// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
#define TAM_STRING 50

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
struct war
{
    char nome[TAM_STRING];
    char cor[TAM_STRING];
    int tropas;
};


// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.
// Funções de setup e gerenciamento de memória:
// Funções de interface com o usuário:
// Funções de lógica principal do jogo:
// Função utilitária:
void limparBufferEntrada(){
    int c;
    while((c=getchar()) != '\n' && c != EOF);
}

void gerarNum()
{
    int num1 = 1 + rand() %6;
    int num2 = 1 + rand() %6;
}
// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main() {
    // 1. Configuração Inicial (Setup):
    // - Define o locale para português.
    // - Inicializa a semente para geração de números aleatórios com base no tempo atual.
    // - Aloca a memória para o mapa do mundo e verifica se a alocação foi bem-sucedida.
    // - Preenche os territórios com seus dados iniciais (tropas, donos, etc.).
    // - Define a cor do jogador e sorteia sua missão secreta.

    srand(time(NULL));
    
    int terri1 = 0, terri2 = 0, indice = 0, NUM_TER = 0, j = 0, v1 = 0, v2 = 0;
    struct war *territorio;

    printf("Quantos territorios voce deseja: \n");
    scanf("%d", &NUM_TER);

    territorio = (struct war*) calloc(NUM_TER, sizeof(struct war));

    printf("\n========================================\n");
    printf("\tCADASTRO DOS %d TERRITORIOS\n", NUM_TER);
    printf("=========================================\n");

    for(int i = 0; i < NUM_TER; i++)
    {
        printf("\n--> TERRITORIO %d", j);
        printf("\nNome do territorio: ");
        fgets(territorio[i].nome, TAM_STRING, stdin);

        printf("Cor do exercito: ");
        fgets(territorio[i].cor, TAM_STRING, stdin);

        printf("Quantidade de tropas: ");
        scanf("%d", &territorio[i].tropas);

        territorio[i].nome[strcspn(territorio[i].nome, "\n")] = '\0';
        territorio[i].cor[strcspn(territorio[i].cor, "\n")] = '\0';
        limparBufferEntrada();
        j++;
    }

    j=1;
    //exibindo os territorios
    printf("\n\n========================================\n");
    printf("\tMAPA DO MUNDO - ESTADO ATUAL\n");
    printf("=========================================\n");

    do{
        for(int i = 0; i < NUM_TER; i++)
        {
            printf("%d - %s (Exercito %s, Tropas: %d)\n", i + 1, territorio[i].nome, territorio[i].cor, territorio[i].tropas);
        }

        printf("----- Fase do Ataque -----");

        printf("Escolha o territorio atacante (1 a 5, ou 0 para sair): %d\n");
        scanf("%d", &terri1);
        v1 = 1 + rand() %6;

        printf("Escolha o territorio defensor (1 a 5): %d\n");
        scanf("%d", &terri2);
        v2 = 1 + rand() %6;

        printf("O atacante %d rolou o dado e tirou %d\n", territorio[terr1 - 1].nome, v1);
        printf("O defensor %d rolou o dado e tirou %d\n", territorio[terr2 - 1].nome, v2);


    }while(terri1 != 0)
    


    // 2. Laço Principal do Jogo (Game Loop):
    // - Roda em um loop 'do-while' que continua até o jogador sair (opção 0) ou vencer.
    // - A cada iteração, exibe o mapa, a missão e o menu de ações.
    // - Lê a escolha do jogador e usa um 'switch' para chamar a função apropriada:
    //   - Opção 1: Inicia a fase de ataque.
    //   - Opção 2: Verifica se a condição de vitória foi alcançada e informa o jogador.
    //   - Opção 0: Encerra o jogo.
    // - Pausa a execução para que o jogador possa ler os resultados antes da próxima rodada.

    // 3. Limpeza:
    // - Ao final do jogo, libera a memória alocada para o mapa para evitar vazamentos de memória.

    return 0;
}

// --- Implementação das Funções ---

// alocarMapa():
// Aloca dinamicamente a memória para o vetor de territórios usando calloc.
// Retorna um ponteiro para a memória alocada ou NULL em caso de falha.

// inicializarTerritorios():
// Preenche os dados iniciais de cada território no mapa (nome, cor do exército, número de tropas).
// Esta função modifica o mapa passado por referência (ponteiro).

// liberarMemoria():
// Libera a memória previamente alocada para o mapa usando free.

// exibirMenuPrincipal():
// Imprime na tela o menu de ações disponíveis para o jogador.

// exibirMapa():
// Mostra o estado atual de todos os territórios no mapa, formatado como uma tabela.
// Usa 'const' para garantir que a função apenas leia os dados do mapa, sem modificá-los.

// exibirMissao():
// Exibe a descrição da missão atual do jogador com base no ID da missão sorteada.

// faseDeAtaque():
// Gerencia a interface para a ação de ataque, solicitando ao jogador os territórios de origem e destino.
// Chama a função simularAtaque() para executar a lógica da batalha.

// simularAtaque():
// Executa a lógica de uma batalha entre dois territórios.
// Realiza validações, rola os dados, compara os resultados e atualiza o número de tropas.
// Se um território for conquistado, atualiza seu dono e move uma tropa.

// sortearMissao():
// Sorteia e retorna um ID de missão aleatório para o jogador.

// verificarVitoria():
// Verifica se o jogador cumpriu os requisitos de sua missão atual.
// Implementa a lógica para cada tipo de missão (destruir um exército ou conquistar um número de territórios).
// Retorna 1 (verdadeiro) se a missão foi cumprida, e 0 (falso) caso contrário.

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
