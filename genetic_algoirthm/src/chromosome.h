#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include <vector>
#include <iostream>
#include "ga_tool.h"
#include "ga_problem.h"
class Chromosome
{
public:
    Chromosome(int max_length);
    Chromosome(const Chromosome& another);
    Chromosome& operator=(const Chromosome& rhs);
    std::vector<int> GetChromosome();
    void SetChromosome(std::vector<int> chromo);
    double GetFitness();
    double DistanceMeasure(Chromosome& another);
    void CrossoverOpeartor(Chromosome& another, Chromosome& child1,
                                                Chromosome& child2);
    void MutationOperator();
    void UpdateFitness();
    friend std::ostream& operator<<(std::ostream& out, Chromosome& item);
private:


private:
    std::vector<int> m_chromosome;
    double  m_fitness;
    int m_chromosome_length;
};

#endif // CHROMOSOME_H
