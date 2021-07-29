#include "nsga_chromosome.h"



NSGAChromosome::NSGAChromosome(int chromosome_length, int number_of_gene)
{
    m_number_of_objectives = number_of_gene;
    m_chromosome_length = chromosome_length;
    m_crowding_distance = 0;
    m_rank = -1;
    for(int i=0; i<number_of_gene; i++){m_fitness_vector.push_back(0);}
    GenerateRandomBinaryString(m_chromosome, m_chromosome_length);
    UpdateFitness();
}

NSGAChromosome::NSGAChromosome(const NSGAChromosome& another)
{
	this->m_chromosome = another.m_chromosome;
    this->m_chromosome_length = another.m_chromosome_length;
    this->m_fitness_vector = another.m_fitness_vector;
    this->m_crowding_distance = another.m_crowding_distance;
    this->m_rank = another.m_rank;
    this->m_number_of_objectives = another.m_number_of_objectives;
}

NSGAChromosome& NSGAChromosome::operator=(const NSGAChromosome& rhs)
{
	this->m_chromosome = rhs.m_chromosome;
    this->m_chromosome_length = rhs.m_chromosome_length;
    this->m_fitness_vector = rhs.m_fitness_vector;
    this->m_crowding_distance = rhs.m_crowding_distance;
    this->m_rank = rhs.m_rank;
    this->m_number_of_objectives = rhs.m_number_of_objectives;
	return *this;
}
std::vector<int> NSGAChromosome::GetChromosome()
{
	return m_chromosome;
}
void NSGAChromosome::SetChromosome(std::vector<int> chromo)
{
	this->m_chromosome = chromo;
    UpdateFitness();
}

double NSGAChromosome::GetIndexedFitness(int index) const
{
    return m_fitness_vector[index];
}

double NSGAChromosome::GetCrowdingDistance() const
{
    return m_crowding_distance;
}

void NSGAChromosome::SetCrowdingDistance(double distance)
{
    m_crowding_distance = distance;
}

int NSGAChromosome::GetRank() const{return m_rank;}
void NSGAChromosome::SetRank(int rank){m_rank = rank;}

void NSGAChromosome::CrossoverOpeartor(NSGAChromosome& another, NSGAChromosome& child1,
										    NSGAChromosome& child2) 
{
	std::vector<int> bits1 = this->m_chromosome;
	std::vector<int> bits2 = another.GetChromosome();
	CombineTwoChromosome(bits1, bits2);
	child1.SetChromosome(bits1);
	child2.SetChromosome(bits2);
}
void NSGAChromosome::MutationOperator()
{
	UpdateFitness();
}
std::ostream& operator<<(std::ostream& out, NSGAChromosome& item)
{
	out<<"chromosome lenght: "<<item.m_chromosome_length<<",  first fitness: "
        <<item.m_fitness_vector[0]
		<<", second fitness:"
        <<item.m_fitness_vector[1]
		<<std::endl;
	return out;
}
void NSGAChromosome:: UpdateFitness()
{
    std::vector<std::pair<double,double>> domain;
    domain.push_back(std::make_pair(-5, 5));
    domain.push_back(std::make_pair(-5, 5));
    domain.push_back(std::make_pair(-5, 5));
    std::vector<double> real_value_vec;
    BinaryStringWithMultipleGenes2RealWithMinAndMax(m_chromosome,domain, real_value_vec);
    m_fitness_vector[0]=problem::KUR::TargetFunction1(real_value_vec[0],real_value_vec[1], real_value_vec[2]);
    m_fitness_vector[1]=problem::KUR::TargetFunction2(real_value_vec[0],real_value_vec[1], real_value_vec[2]);
}

