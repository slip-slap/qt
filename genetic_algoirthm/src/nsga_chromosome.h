#pragma once

#include <vector>
#include <iostream>
#include <tuple>

#include "ga_tool.h"
#include "ga_problem.h"

typedef int binary_t;

class NSGAChromosome 
{
	public:
        NSGAChromosome(int chromosome_length, int number_of_gene);

        // copy and assignment function
		NSGAChromosome(const NSGAChromosome& another);
        NSGAChromosome& operator=(NSGAChromosome rhs);
        void swap(NSGAChromosome& first, NSGAChromosome& sec);

		std::vector<int> GetChromosome();
        std::vector<double>& GetFitnessReference();
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
        std::vector<binary_t> m_chromosome;
        std::vector<int> m_chromosome_int;
        std::vector<double> m_fitness_vector;
        double m_crowding_distance;
        int m_chromosome_length;
        int m_rank;
        int m_number_of_objectives;
};
