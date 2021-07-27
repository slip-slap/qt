#pragma once

#include "nsga_chromosome.h"
#include <vector>

class NSGA
{
	public:
		NSGA(int population);
		void SelectionOperator();
		void display();
        std::vector<NSGAChromosome>& GetPopulation();
        std::vector<std::vector<NSGAChromosome>>& GetFronters();

	private:
		std::vector<NSGAChromosome> m_population;
        std::vector<std::vector<NSGAChromosome>> m_fronters;

};
