#include "selection_method.h"

SelectionMethod::SelectionMethod(std::vector<double>& fitness)
{
	m_fitness_vector = fitness;
}

SelectionMethod::SelectionMethod(std::vector<double>& fitness, unsigned long tournament_size)
{
	m_fitness_vector = fitness;
    m_tournament_size = tournament_size;
}

void SelectionMethod::TournamentSelection(int size,std::vector<int>& selected_individual_index)
{   
    for(int size_counter = 0; size_counter < size; size_counter++)
    {
        double MIN = std::numeric_limits<double>::max();
        int MIN_index = -1;
        for(unsigned long tournament_size = 0; tournament_size < m_tournament_size; tournament_size++)
        {
            int pos = GenerateRandomNumber(0, m_fitness_vector.size());
            if(m_fitness_vector[pos] < MIN)
            {
                MIN = m_fitness_vector[pos];
                MIN_index = pos;
            }
        }
        selected_individual_index.push_back(MIN_index);
    }
}

