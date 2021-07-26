#include "nsga.h"

NSGA::NSGA(int population)
{
	for(int i=0; i<population; i++)
	{
		NSGAChromosome temp(30);
		m_population.push_back(temp);
	}
}
void NSGA::display()
{
	for(int i=0; i<m_population.size(); i++){
		std::cout<<m_population[i];
	}
}
