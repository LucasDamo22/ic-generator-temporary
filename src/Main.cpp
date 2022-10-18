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

    for (int i = 0; i < n_parcelas; i++)
    {
        int aux;

        aux = rand() % (coef/2)+1;

        if (sum < coef)
        {
            sum = sum + aux;
            v1.push_back(aux);
            
        }
    }
    for (int i = 0; i < n_parcelas; i++)
    {

        std::cout << v1[i] << std::endl;
    }
    for (int i = 0; i < n_parcelas; i++)
    {

        double aux;
        aux += v1[i];
        std::cout << "\n\n\n\n"
                  << aux / n_parcelas;
    }

    return 0;
}