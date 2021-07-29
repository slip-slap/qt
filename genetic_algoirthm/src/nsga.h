#pragma once

#include "nsga_chromosome.h"
#include <vector>

class NSGA
{
	public:
		NSGA(int population);
		void SelectionOperator();
        void CrossoverOperator();
		void display();
        std::vector<NSGAChromosome>& GetPopulation();
        std::vector<std::vector<NSGAChromosome>>& GetFronters();

    private:
        void CalculateFronters();
        void CalcuateCrowdingDistanceAndRank();

	private:
		std::vector<NSGAChromosome> m_population;
        std::vector<NSGAChromosome> m_population_offspring;
        std::vector<std::vector<NSGAChromosome>> m_fronters;

};
