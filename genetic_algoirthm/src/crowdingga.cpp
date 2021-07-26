#include "crowdingga.h"

int GA_POPULATION = 20;
int GA_CHROMOSOME_LENGTH = 30;
CrowdingGA::CrowdingGA(int poplulation)
        {
            for(int i = 0;i < poplulation; i++)
            {
                Chromosome temp(GA_CHROMOSOME_LENGTH);
                m_population.push_back(temp);
            }
        }

void CrowdingGA::Selection()
        {
            std::vector<Chromosome> temp_pop;
            for(auto itr=m_pop_and_child.begin(); itr!=m_pop_and_child.end(); itr++)
            {
                double father1_to_child1 = std::get<0>(*itr).DistanceMeasure(std::get<2>(*itr));
                double father2_to_child2 = std::get<1>(*itr).DistanceMeasure(std::get<3>(*itr));
                double father1_to_child2 = std::get<0>(*itr).DistanceMeasure(std::get<2>(*itr));
                double father2_to_child1 = std::get<1>(*itr).DistanceMeasure(std::get<3>(*itr));

                if(    father1_to_child1 + father2_to_child2
                        < father1_to_child2 + father2_to_child1
                  )
                {
                    if(  std::get<0>(*itr).GetFitness()
                       > std::get<2>(*itr).GetFitness()
                      )
                    {
                        temp_pop.push_back(std::get<0>(*itr));
                    }
                    else
                    {
                        temp_pop.push_back(std::get<2>(*itr));
                    }
                    if(  std::get<1>(*itr).GetFitness()
                       > std::get<3>(*itr).GetFitness()
                      )
                    {
                        temp_pop.push_back(std::get<1>(*itr));
                    }
                    else
                    {
                        temp_pop.push_back(std::get<3>(*itr));
                    }
                }
                else
                {
                    if(  std::get<0>(*itr).GetFitness()
                       > std::get<2>(*itr).GetFitness()
                      )
                    {
                        temp_pop.push_back(std::get<0>(*itr));
                    }
                    else
                    {
                        temp_pop.push_back(std::get<2>(*itr));
                    }
                    if(  std::get<1>(*itr).GetFitness()
                       > std::get<3>(*itr).GetFitness()
                      )
                    {
                        temp_pop.push_back(std::get<1>(*itr));
                    }
                    else
                    {
                        temp_pop.push_back(std::get<3>(*itr));
                    }

                }
            }
            if(temp_pop.size()!=0){m_population = temp_pop;}
        }

void CrowdingGA::Crossover()
        {   m_pop_and_child.clear();
            std::vector<std::pair<int,int>> pair_vec;
            GeneratePairs(m_population.size(), pair_vec);
            for(auto itr = pair_vec.begin(); itr!=pair_vec.end(); itr++)
            {
                Chromosome child1(GA_CHROMOSOME_LENGTH), child2(GA_CHROMOSOME_LENGTH);
                Chromosome farther1 = m_population[itr->first];
                Chromosome farther2 = m_population[itr->second];
                farther1.CrossoverOpeartor(farther2, child1, child2);
                m_pop_and_child.push_back(std::make_tuple(farther1, farther2, child1, child2));
            }

        }

std::vector<Chromosome> CrowdingGA::GetPopulation()
{
    return m_population;
}
