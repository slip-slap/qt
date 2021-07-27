#include "nsga_chromosome.h"


NSGAChromosome::NSGAChromosome(int max_length)
{	
	m_chromosome_length = max_length;	
	GenerateRandomBinaryString(m_chromosome, m_chromosome_length);
	UpdateFitness();
}

NSGAChromosome::NSGAChromosome(int chromosome_length, int number_of_gene)
{

}

NSGAChromosome::NSGAChromosome(const NSGAChromosome& another)
{
	this->m_chromosome = another.m_chromosome;
    this->m_chromosome_length = another.m_chromosome_length;
	UpdateFitness();
}

NSGAChromosome& NSGAChromosome::operator=(const NSGAChromosome& rhs)
{
	this->m_chromosome = rhs.m_chromosome;
	UpdateFitness();
	return *this;
}
std::vector<int> NSGAChromosome::GetChromosome()
{
	return m_chromosome;
}
void NSGAChromosome::SetChromosome(std::vector<int> chromo)
{
	this->m_chromosome = chromo;
}
double NSGAChromosome::GetFirstFitness()
{
	return std::get<0>(m_fitness_tuple);
}
double NSGAChromosome::GetSecondFitness()
{
	return std::get<1>(m_fitness_tuple);
}
double NSGAChromosome::DistanceMeasure(NSGAChromosome& another)
{
	return 3;

}
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
		<<std::get<0>(item.m_fitness_tuple)
		<<", second fitness:"
		<<std::get<1>(item.m_fitness_tuple)
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
    std::get<0>(m_fitness_tuple) = problem::KUR::TargetFunction1(real_value_vec[0],real_value_vec[1], real_value_vec[2]);
    std::get<1>(m_fitness_tuple) = problem::KUR::TargetFunction2(real_value_vec[0],real_value_vec[1], real_value_vec[2]);
}

