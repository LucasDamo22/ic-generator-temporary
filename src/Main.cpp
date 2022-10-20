#include <iostream>
#include <cstdlib>
#include <ctime>

#define MIN_PARCELAS 9
#define MAX_PARCELAS 20

#define UTILIZACAO_ALVO 80

int random(int min, int max) {
	return (rand() % (min - max)) + min;
}

int main(int argc, char** argv){

	// initializa o gerador de números pseudo-aleatórios com uma semente 
	// diferente a cada inicialização
	srand(time(NULL));

	// gera um número de parcelas entre MIN_PARCELAS e MAX_PARCELAS
	int num_parcelas = random(MIN_PARCELAS, MAX_PARCELAS);

	// o montante de CPU disponível é dado por UTILIZACAO_ALVO. Enquanto não 
	// atingirmos essa utilização, geramos novas parcelas
	int utilizacao_atual = 0;

	int min_valor_parcela, max_valor_parcela;
	int parcelas[num_parcelas];

	for(int i = 0; i < num_parcelas; i++){

		std::cout << "[" << utilizacao_atual << "%] ";

		// parcela terá no mínimo 5% da utilizacao faltante (valor mínimo = 1)
		min_valor_parcela = ((UTILIZACAO_ALVO - utilizacao_atual) / 20) + 1; 

		// parcela terá no mínimo 20% da utilização faltante (valor mínimo = 1)
		max_valor_parcela = ((UTILIZACAO_ALVO - utilizacao_atual) / 5) + 1;

		std::cout << " gerando na faixa (" << min_valor_parcela << ", " << max_valor_parcela << ")... ";
	
		int parcela = random(min_valor_parcela, max_valor_parcela);
		utilizacao_atual += parcela;

		std::cout << parcela << "^-1" << std::endl;
		parcelas[i] = parcela;
	}

	std::cout << "[" << utilizacao_atual << "] completando utilização adicionando " << (UTILIZACAO_ALVO - utilizacao_atual) << " à última parcela" << std::endl;

	std::cout << "conjunto final de parcelas: [ ";

	for(int i = 0; i < num_parcelas -1 ; i++)
		std::cout << parcelas[i] << ", ";

	std::cout << (parcelas[num_parcelas-1] + (UTILIZACAO_ALVO - utilizacao_atual)) << "]" << std::endl;

}
