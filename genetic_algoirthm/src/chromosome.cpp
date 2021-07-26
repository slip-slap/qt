#include "chromosome.h"


Chromosome::Chromosome(int max_length)
        {
            m_chromosome_length = max_length;
            GenerateRandomBinaryString(m_chromosome, m_chromosome_length);
            UpdateFitness();
        }
Chromosome::Chromosome(const Chromosome& another)
        {
            this->m_chromosome = another.m_chromosome;
            m_chromosome_length = another.m_chromosome_length;
            UpdateFitness();
        }

Chromosome& Chromosome::operator=(const Chromosome& rhs)
        {
            this->m_chromosome = rhs.m_chromosome;
            m_chromosome_length = rhs.m_chromosome_length;
            UpdateFitness();
            return *this;
        }
std::vector<int> Chromosome::GetChromosome()
        {
            return m_chromosome;
        }
void Chromosome::SetChromosome(std::vector<int> chromo)
        {
            this->m_chromosome = chromo;
        }
double  Chromosome::GetFitness()
        {
            return m_fitness;
        }
double Chromosome::DistanceMeasure(Chromosome& another)
        {   std::vector<int> bits = another.GetChromosome();
            return GetDistanceBetweenTwoBits(this->m_chromosome,bits);

        }
void Chromosome::CrossoverOpeartor(Chromosome& another, Chromosome& child1,
                                                    Chromosome& child2)
        {
            std::vector<int> bits1 = this->m_chromosome;
            std::vector<int> bits2 = another.GetChromosome();
            CombineTwoChromosome(bits1, bits2);
            child1.SetChromosome(bits1);
            child2.SetChromosome(bits2);
        }
void Chromosome::MutationOperator()
        {
            UpdateFitness();
        }
std::ostream& operator<<(std::ostream& out, Chromosome& item)
        {
            out<<item.m_chromosome_length<<" "
               <<item.m_fitness
               <<std::endl;
            return out;
        }

void Chromosome::UpdateFitness()
        {
            m_fitness = problem::SO::M1(BinaryString2RealNormalization(
                        m_chromosome,m_chromosome_length));
        }



