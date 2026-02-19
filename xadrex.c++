#include <stdio.h> // Biblioteca padrão para entrada e saída de dados, como printf

// --- Funções Recursivas para Movimento das Peças ---

/**
 * @brief Simula o movimento recursivo da Torre para a direita.
 *
 * @param casas_restantes O número de casas que a Torre ainda precisa se mover.
 */
void moverTorreRecursivo(int casas_restantes) {
    // Caso base da recursão: se não há mais casas para mover, a função termina.
    if (casas_restantes <= 0) {
        return;
    }

    printf("Direita\n"); // Imprime o movimento para a casa atual
    // Chamada recursiva: move para a próxima casa, decrementando o contador.
    moverTorreRecursivo(casas_restantes - 1);
}

/**
 * @brief Simula o movimento recursivo da Rainha para a esquerda.
 *
 * @param casas_restantes O número de casas que a Rainha ainda precisa se mover.
 */
void moverRainhaRecursivo(int casas_restantes) {
    // Caso base da recursão.
    if (casas_restantes <= 0) {
        return;
    }

    printf("Esquerda\n"); // Imprime o movimento
    // Chamada recursiva.
    moverRainhaRecursivo(casas_restantes - 1);
}

/**
 * @brief Simula o movimento recursivo do Bispo na diagonal (Cima, Direita).
 * Também demonstra a parte externa do loop aninhado vertical.
 *
 * @param casas_restantes O número de movimentos diagonais restantes.
 */
void moverBispoRecursivo(int casas_restantes) {
    // Caso base da recursão.
    if (casas_restantes <= 0) {
        return;
    }

    // --- Loops Aninhados para o Bispo (conceptual: vertical/horizontal) ---
    // Loop externo: simula o movimento vertical (Cima)
    // Para cada 'movimento vertical' (que é um passo da diagonal),
    // queremos um 'movimento horizontal'.
    // Aqui, cada chamada recursiva representa um "passo diagonal completo"
    // que conceitualmente é formado por um movimento vertical e um horizontal.
    // Usamos um loop interno para mostrar explicitamente o movimento horizontal.
    
    // O 'i' representa a parte "Cima" do movimento diagonal
    for (int i = 0; i < 1; i++) { // Este loop executa uma vez para cada "passo Cima"
        printf("Cima\n");
        // O 'j' representa a parte "Direita" do movimento diagonal
        for (int j = 0; j < 1; j++) { // Este loop executa uma vez para cada "passo Direita"
            printf("Direita\n");
        }
    }
    // Note: Em um cenário real de xadrez, um único printf("Cima, Direita\n") seria mais comum.
    // Esta implementação detalha o movimento vertical e horizontal individualmente
    // dentro de um passo diagonal para atender ao requisito de loops aninhados no Bispo.

    // Chamada recursiva.
    moverBispoRecursivo(casas_restantes - 1);
}


int main() {
    // --- Simulação do Movimento da Torre (Recursiva) ---
    printf("--- Movimento da Torre (5 casas para a Direita - Recursivo) ---\n");
    int casas_torre = 5;
    moverTorreRecursivo(casas_torre);
    printf("\n");

    // --- Simulação do Movimento da Rainha (Recursiva) ---
    printf("--- Movimento da Rainha (8 casas para a Esquerda - Recursivo) ---\n");
    int casas_rainha = 8;
    moverRainhaRecursivo(casas_rainha);
    printf("\n");

    // --- Simulação do Movimento do Bispo (Recursivo com Loops Aninhados) ---
    printf("--- Movimento do Bispo (5 casas na Diagonal Cima, Direita - Recursivo com Loops Aninhados) ---\n");
    int casas_bispo = 5;
    moverBispoRecursivo(casas_bispo);
    printf("\n");

    // --- Simulação do Movimento do Cavalo (Loops Aninhados Complexos) ---
    printf("--- Movimento do Cavalo (2 casas para Cima, 1 casa para a Direita - Loops Aninhados Complexos) ---\n");

    int movimentos_verticais_cavalo_necessarios = 2; // Deslocamento vertical total
    int movimentos_horizontais_cavalo_necessarios = 1; // Deslocamento horizontal total

    int current_vertical_moves = 0; // Contador de movimentos verticais realizados
    int current_horizontal_moves = 0; // Contador de movimentos horizontais realizados
    int cavalo_movimento_completo = 0; // Flag para indicar que o movimento em L foi concluído

    // Loop externo: controla a fase principal do movimento em "L"
    for (int passo_l = 1; passo_l <= 2; passo_l++) { // Simula as duas etapas do "L" (2 verticais + 1 horizontal)
        if (cavalo_movimento_completo) { // Se o movimento em L já foi concluído, sai do loop
            break;
        }

        printf("Passo L %d:\n", passo_l); // Indicador de qual parte do L está sendo executada

        // Loop interno (while): para os movimentos verticais
        while (current_vertical_moves < movimentos_verticais_cavalo_necessarios) {
            printf("Cima\n");
            current_vertical_moves++;
            // Se já moveu as 2 casas para cima, não precisa continuar imprimindo "Cima"
            if (current_vertical_moves == movimentos_verticais_cavalo_necessarios) {
                // Ao usar 'break' aqui, o loop 'while' interno termina,
                // e o fluxo volta para o loop 'for' externo.
                break;
            }
        }

        // Após completar os movimentos verticais, inicia os horizontais.
        // Usa uma condição adicional para garantir que os horizontais só ocorram após os verticais.
        if (current_vertical_moves == movimentos_verticais_cavalo_necessarios && current_horizontal_moves < movimentos_horizontais_cavalo_necessarios) {
            printf("Direita\n");
            current_horizontal_moves++;
            // Se já moveu a 1 casa para a direita, o movimento em "L" está completo.
            cavalo_movimento_completo = 1; // Define a flag para sair do loop externo
            // Não usamos 'break' aqui para sair do 'for' imediatamente, mas a flag
            // fará com que ele saia na próxima iteração.
        } else if (current_horizontal_moves == movimentos_horizontais_cavalo_necessarios) {
            // Se os movimentos horizontais já foram concluídos, mas o loop 'for' ainda não terminou,
            // usamos 'continue' para pular as iterações restantes do 'for' se necessário,
            // embora a flag 'cavalo_movimento_completo' já cuide disso no início do loop.
            continue;
        }
    }
    printf("\n");

    return 0; // Indica que o programa foi executado com sucesso
}
