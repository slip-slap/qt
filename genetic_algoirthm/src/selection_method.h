#pragma once

#include <vector>
#include "ga_tool.h"
/*
 * Given the vector of fitness, return the index
 *
 */
class SelectionMethod
{
    public:
        SelectionMethod(std::vector<double>& fitness);
        SelectionMethod(std::vector<double>& fitness, unsigned long tournament_size);
        void TournamentSelection(int number, std::vector<int>& selected_individual_index);
	private:
        unsigned long m_tournament_size;
		std::vector<double>  m_fitness_vector;;

};
