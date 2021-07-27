#include "nsga.h"

NSGA::NSGA(int population)
{
	for(int i=0; i<population; i++)
	{
		NSGAChromosome temp(30);
		m_population.push_back(temp);
	}
}
std::vector<NSGAChromosome>& NSGA::GetPopulation()
{
    return m_population;
}

std::vector<std::vector<NSGAChromosome>>& NSGA::GetFronters()
{
    return m_fronters;
}
std::vector<NSGAChromosome> CopyUnindexedItem(std::vector<NSGAChromosome>& pop,
                                              std::vector<unsigned long> index)
{
    std::vector<NSGAChromosome> unindex_items;
    for(unsigned long i=0; i<pop.size(); i++){
        if(std::find(index.begin(), index.end(), i)==index.end())
        {
            unindex_items.push_back(pop[i]);
        }
    }
    return unindex_items;
}
void NSGA::SelectionOperator()
{	

    std::vector<NSGAChromosome> remain_pop = m_population;
    std::vector<NSGAChromosome> previous_pop = m_population;
    while(remain_pop.size()!=0)
    {
        std::vector<NSGAChromosome> fronter;
        std::vector<unsigned long> enclose_index;
        if(remain_pop.size() == 1){
            fronter.push_back(remain_pop[0]);
              m_fronters.push_back(fronter);
              break;
        }
        for(unsigned long i = 0; i < remain_pop.size(); i++)
        {

            unsigned long counter = 0;
            for(unsigned long k = 0; k < remain_pop.size(); k++)
            {
                if(k!=i)
                {
                    // check whether it is dominated solution
                    if(remain_pop[i].GetFirstFitness() < remain_pop[k].GetFirstFitness()
                        ||
                      remain_pop[i].GetSecondFitness() < remain_pop[k].GetSecondFitness())
                    {
                        counter++;
                       if(counter == remain_pop.size() - 1){
                           fronter.push_back(remain_pop[i]);
                           enclose_index.push_back(i);
                       }
                    }
                }
            }
        }
        m_fronters.push_back(fronter);
        remain_pop = CopyUnindexedItem(previous_pop,enclose_index);
        previous_pop = remain_pop;
    }
}

void NSGA::display()
{
	for(int i=0; i<m_population.size(); i++){
		std::cout<<m_population[i];
	}
}
