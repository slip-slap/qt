#pragma once

#include <vector>
#include <iostream>
#include <tuple>

#include "ga_tool.h"
#include "ga_problem.h"

class NSGAChromosome 
{
	public:
		NSGAChromosome(int max_length); 
		NSGAChromosome(const NSGAChromosome& another);
		NSGAChromosome& operator=(const NSGAChromosome& rhs);
		std::vector<int> GetChromosome();
		void SetChromosome(std::vector<int> chromo);
		double GetFirstFitness();
		double GetSecondFitness();
		double DistanceMeasure(NSGAChromosome& another);
		void CrossoverOpeartor(NSGAChromosome& another, NSGAChromosome& child1,
												    NSGAChromosome& child2);
		void MutationOperator();
		friend std::ostream& operator<<(std::ostream& out, NSGAChromosome& item);

	private:
		void UpdateFitness();

	private:
		std::vector<int> m_chromosome;
		std::tuple<double, double> m_fitness_tuple;
		int m_chromosome_length;
};
