#pragma once

#include <vector>
#include <iostream>
#include <tuple>

#include "ga_tool.h"
#include "ga_problem.h"

class NSGAChromosome 
{
	public:
        NSGAChromosome(int chromosome_length, int number_of_gene);

        // copy and assignment function
		NSGAChromosome(const NSGAChromosome& another);
		NSGAChromosome& operator=(const NSGAChromosome& rhs);

		std::vector<int> GetChromosome();
		void SetChromosome(std::vector<int> chromo);
        double GetIndexedFitness(int index) const;
        double GetCrowdingDistance() const;
        void   SetCrowdingDistance(double distance);
        int GetRank() const;
        void SetRank(int rank);
        void CrossoverOpeartor(NSGAChromosome& another,
                               NSGAChromosome& child1,
                               NSGAChromosome& child2);
		void MutationOperator();
		friend std::ostream& operator<<(std::ostream& out, NSGAChromosome& item);

	private:
		void UpdateFitness();

	private:
		std::vector<int> m_chromosome;
        std::vector<double> m_fitness_vector;
        double m_crowding_distance;
        int m_chromosome_length;
        int m_rank;
        int m_number_of_objectives;
};
