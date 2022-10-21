#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>

#define MIN_PARCELAS 4
#define MAX_PARCELAS 10

//#define UTILIZACAO_ALVO 60

int random(int min, int max)
{
    return (rand() % (min - max)) + min;
}

int main(int argc, char **argv)
{

    // initializa o gerador de números pseudo-aleatórios com uma semente
    // diferente a cada inicialização
    srand(time(NULL));

    int UTILIZACAO_ALVO;
    UTILIZACAO_ALVO = atoi(argv[1]);

    // gera um número de parcelas entre MIN_PARCELAS e MAX_PARCELAS
    int num_parcelas = random(MIN_PARCELAS, MAX_PARCELAS);

    // o montante de CPU disponível é dado por UTILIZACAO_ALVO. Enquanto não
    // atingirmos essa utilização, geramos novas parcelas
    int utilizacao_atual = 0;

    int min_valor_parcela, max_valor_parcela;
    double parcelas[num_parcelas];
    double parcelasSuperiores[num_parcelas];

    for (int i = 0; i < num_parcelas; i++)
    {

        // parcela terá no mínimo 5% da utilizacao faltante (valor mínimo = 1)
        min_valor_parcela = ((UTILIZACAO_ALVO - utilizacao_atual) / 20) + 1;

        // parcela terá no mínimo 20% da utilização faltante (valor mínimo = 1)
        max_valor_parcela = ((UTILIZACAO_ALVO - utilizacao_atual) / 5) + 1;

        int parcela = random(min_valor_parcela, max_valor_parcela);
        utilizacao_atual += parcela;

        parcelas[i] = parcela;
    }

    parcelas[num_parcelas - 1] = parcelas[num_parcelas - 1] + (UTILIZACAO_ALVO - utilizacao_atual); // adicionando o que falta na ultima parcela

    //**********Transformando as parcelas em frações que somem o coeficiente e colocando em um array de numeradores chamado de "parcelasSuperiores"
    for (int i = 0; i < num_parcelas; i++)
    {
        double aux = parcelas[i];
        parcelas[i] = parcelas[i] * 100;
        parcelasSuperiores[i] = (aux * UTILIZACAO_ALVO)/num_parcelas;
    }
    
    //**********Mandando as parcelas para o arquivo yaml
    std::ofstream arqOutYaml;
    arqOutYaml.open("./data/processes.yaml", std::ios::out);
    if (!arqOutYaml.is_open())
    {

        std::cout << "erro na geração do arquivo";
        return 1;
    }
    arqOutYaml << "Processos:"<<std::endl;
    for(int i = 0; i < num_parcelas;i++){
    arqOutYaml << "  processo"<<i+1<<":"<<" ["<<parcelasSuperiores[i]<<", "<<parcelas[i]<<"]"<<std::endl;
    }
    arqOutYaml.close();

    return 0;    
}
