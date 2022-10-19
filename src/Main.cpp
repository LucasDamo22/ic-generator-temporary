#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main(int argc, char **argv)
{
    unsigned seed = time(0);
    srand(seed);
    int n_parcelas;
    int coef;
    int sum = 0;

    coef = atoi(argv[1]);
    n_parcelas = atoi(argv[2]);

    std::vector<int> v1;

    do
    {
        int coef_aux = coef;
        int flag;
        int aux;
        for (int i = 0; i < n_parcelas; i++)
        {

            aux = rand() % coef_aux+3;
            v1.push_back(aux);
            
        }
        sum = 0;
        for (int i = 0; i < n_parcelas; i++)
        {
            sum += v1[i];
        }

        if (sum != coef)
        {
            v1.clear();
        }

    } while (sum != coef);

    for (int i = 0; i < n_parcelas; i++)
    {
        std::cout << v1[i] << std::endl;
    }

    std::cout << sum << std::endl;

    return 0;
}