#include "nsga_chromosome.h"


NSGAChromosome:: NSGAChromosome(int max_length)
{
	std::cout<<"max_length "<<max_length<<std::endl;
	m_chromosome_length = max_length;
	std::cout<<"chromosome length "<<m_chromosome_length<<std::endl;
	GenerateRandomBinaryString(m_chromosome, m_chromosome_length);
	UpdateFitness();
}

NSGAChromosome::NSGAChromosome(const NSGAChromosome& another)
{
	this->m_chromosome = another.m_chromosome;
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
	//std::cout<<m_chromosome_length<<std::endl;
	//std::cout<<BinaryString2RealNormalization(m_chromosome, m_chromosome_length)<<std::endl;
			double real_value =BinaryString2RealWithMinAndMax(m_chromosome,m_chromosome_length,-1000,1000);
			std::get<0>(m_fitness_tuple) = problem::SCH::TargetFunction1(real_value);
			std::get<1>(m_fitness_tuple) = problem::SCH::TargetFunction2(real_value);
		}

