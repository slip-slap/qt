#ifndef CROWDINGGA_H
#define CROWDINGGA_H
#include "chromosome.h"
class CrowdingGA
{
public:
    CrowdingGA(int poplulation);
    void Selection();
    void Crossover();
    std::vector<Chromosome> GetPopulation();

private:
    std::vector<Chromosome> m_population;
    std::vector<std::tuple<Chromosome,Chromosome,Chromosome,Chromosome>> m_pop_and_child;
};

#endif // CROWDINGGA_H
