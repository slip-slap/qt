#include "nsga.h"

NSGA::NSGA(int population)
{
	for(int i=0; i<population; i++)
	{
        NSGAChromosome temp(30,2);
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
    if(m_population_offspring.size()!=0)
    {
        m_population.insert(std::end(m_population),std::begin(m_population_offspring), std::end(m_population_offspring));
        CalculateFronters();
        CalcuateCrowdingDistanceAndRank();

        for(unsigned long fronter_counter=0; fronter_counter<m_fronters.size();fronter_counter++ )
        {
            std::sort(m_fronters[fronter_counter].begin(), m_fronters[fronter_counter].end(),
                      [](const auto& lhs, const auto& rhs)
                    {
                        return lhs.GetCrowdingDistance() > rhs.GetCrowdingDistance();
                    });
        }

        std::vector<NSGAChromosome> temp;
        for(unsigned long fronter_counter=0; fronter_counter<m_fronters.size();fronter_counter++ )
        {
            for(unsigned long number_counter=0; number_counter< m_fronters[fronter_counter].size(); number_counter++)
            {
                temp.push_back(m_fronters[fronter_counter][number_counter]);
            }
        }
        std::vector<NSGAChromosome> sub_temp;
        sub_temp.insert(std::begin(sub_temp),std::begin(temp),std::begin(temp)+30);
        m_population = sub_temp;
        CalculateFronters();
    }
    CalculateFronters();
    CalcuateCrowdingDistanceAndRank();
}

void NSGA::CrossoverOperator()
{
    std::vector<NSGAChromosome> temp_pop;
    for(unsigned long i=0; i<m_population.size()/2; i++)
    {
        int far1_pos = GenerateRandomNumber(0,m_population.size());
        int far2_pos = GenerateRandomNumber(0,m_population.size());
        NSGAChromosome child1(30,2), child2(30,2);
        m_population[far1_pos].CrossoverOpeartor(m_population[far2_pos],child1, child2);
        temp_pop.push_back(child1);
        temp_pop.push_back(child2);
    }
    m_population_offspring = temp_pop;
}

void NSGA::CalculateFronters()
{
    std::vector<std::vector<NSGAChromosome>> fronters;
    std::vector<NSGAChromosome> remain_pop = m_population;
    std::vector<NSGAChromosome> previous_pop = m_population;
    while(remain_pop.size()!=0)
    {
        std::vector<NSGAChromosome> fronter;
        std::vector<unsigned long> enclose_index;
        if(remain_pop.size() == 1){
            fronter.push_back(remain_pop[0]);
            fronters.push_back(fronter);
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
                    if(remain_pop[i].GetIndexedFitness(0) <= remain_pop[k].GetIndexedFitness(0)
                        ||
                      remain_pop[i].GetIndexedFitness(1) <= remain_pop[k].GetIndexedFitness(1))
                    {
                        counter++;
                       if(counter == remain_pop.size() - 1)
                       {
                           fronter.push_back(remain_pop[i]);
                           enclose_index.push_back(i);
                       }
                    }
                }
            }
        }
        fronters.push_back(fronter);
        remain_pop = CopyUnindexedItem(previous_pop,enclose_index);
        previous_pop = remain_pop;
    }
    m_fronters = fronters;
}

void NSGA::CalcuateCrowdingDistanceAndRank()
{
    for(unsigned long fronter_index = 0; fronter_index < m_fronters.size(); fronter_index++)
	{
        std::vector<NSGAChromosome> temp = m_fronters[fronter_index];
        for(int objective_index=0; objective_index < 2; objective_index++)
        {
            std::sort(
                        temp.begin(), temp.end(),
                  [objective_index](const auto& lhs, const auto& rhs)
                {return lhs.GetIndexedFitness(objective_index) < rhs.GetIndexedFitness(objective_index);
				});
            for(unsigned long ind_index = 0; ind_index < temp.size(); ind_index++)
			{
                temp[ind_index].SetRank(fronter_index);
                if(ind_index == 0){temp[ind_index].SetCrowdingDistance(std::numeric_limits<int>::max());continue;;}
                if(ind_index == temp.size() - 1)
                {
                    temp[ind_index].SetCrowdingDistance(std::numeric_limits<int>::max());
                    continue;
                }
                double distance = (double(temp[ind_index+1].GetIndexedFitness(objective_index)
                                   -temp[ind_index-1].GetIndexedFitness(objective_index)))/
                             (double(temp[temp.size()-1].GetIndexedFitness(objective_index)
                              - temp[0].GetIndexedFitness(objective_index)));
                temp[ind_index].SetCrowdingDistance(distance + temp[ind_index].GetCrowdingDistance());
			 }
		}
        m_fronters[fronter_index] = temp;
	}
}

void NSGA::display()
{
	for(int i=0; i<m_population.size(); i++){
		std::cout<<m_population[i];
	}
}
