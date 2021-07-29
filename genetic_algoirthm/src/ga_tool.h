#pragma once
#include <vector>
#include <cmath>
#include <set>
#include <boost/random.hpp>
#include <boost/chrono.hpp>

int GenerateRandomNumber(int start, int end);
void GenerateRandomBinaryString(std::vector<int>& binary_string_vec, int length );

double BinaryString2Real(std::vector<int>& binary_string);
double BinaryString2RealNormalization(std::vector<int>& binary_string);
double BinaryString2RealWithMinAndMax(std::vector<int>& binary_string, double min, double max);
/*
 * "binary_string" refers to the chromosome
 * "domain" refers to the range of each variable.
 *
 */
void BinaryStringWithMultipleGenes2RealWithMinAndMax(std::vector<int>& binary_string,
                                         std::vector<std::pair<double, double>>& domain,
                                         std::vector<double>& real_value_vec);

int SelectionWithProbability(std::vector<double>& vec);
std::vector<int> SelectionWithProbability(std::vector<double>& vec, int number);
void GeneratePairs(int population, std::vector<int>& parent1_vec,
		std::vector<int>& parent2_vec);
void GeneratePairs(int population, std::vector<std::pair<int,int>>& pair_vec);
void CombineTwoChromosome(std::vector<int>& first, std::vector<int>& sec);
double GetDistanceBetweenTwoBits(std::vector<int>& a, std::vector<int>& b);
