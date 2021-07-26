#pragma once

#include "nsga_chromosome.h"
#include <vector>

class NSGA
{
	public:
		NSGA(int population);
		void display();
	private:
		std::vector<NSGAChromosome> m_population;

};
