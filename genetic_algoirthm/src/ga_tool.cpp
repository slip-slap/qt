#include "ga_tool.h"


int GenerateRandomNumber(int start, int end)
{
	boost::chrono::system_clock::time_point now = boost::chrono::system_clock::now();
	std::string count = std::to_string(now.time_since_epoch().count());
	// conversion a string to int, and just keep the last seven digit.
	int system_time = std::stoi(count.substr(count.size()-7,7));
	boost::random::mt19937 gen{static_cast<std::uint32_t>(system_time)}; 
	boost::random::uniform_int_distribution<> dist{start,end-1};
	return dist(gen);
}
double BinaryString2Real(std::vector<int>& binary_string)
{
	int sum = 0;
	int pos = 1;
	for(auto itr=binary_string.begin(); itr!=binary_string.end();itr++)
	{
		sum = (*itr) * std::pow(2, binary_string.size() - pos) + sum;
		pos = pos + 1;
	}
	return sum;
}

double BinaryString2RealNormalization(std::vector<int>& binary_string)
{
    return BinaryString2Real(binary_string)/(std::pow(2,binary_string.size())-1);
}

void GenerateRandomBinaryString(std::vector<int>& binary_string_vec, int length )
{
	for(int i=0; i < length; i++)
	{
		binary_string_vec.push_back(GenerateRandomNumber(0,2));
	}
}
double BinaryString2RealWithMinAndMax(std::vector<int>& binary_string, double min, double max)
{
    double normalize_value = BinaryString2RealNormalization(binary_string);
	// first scarlarization, then translate
	return normalize_value * (max - min) +  min;
}

int SelectionWithProbability(std::vector<double>& vec)
{
	double sum = 0;
	for(int i=0; i<vec.size(); i++) { sum = sum + vec[i]; }
	double random_number = GenerateRandomNumber(0, sum);

	int pos = -1;
	double sum_ = 0;
	for(int i=0; i<vec.size(); i++)
	{
		sum_ = sum_ + vec[i];
		if(random_number < sum_) { pos = i; break; }
	}
	return pos;
}

std::vector<int> SelectionWithProbability(std::vector<double>& vec, int number)
{
	std::vector<int> result;
	for(int i=0;i<vec.size();i++){result.push_back(0);}
	for(int i=0;i<number; i++)
	{
		int pos = SelectionWithProbability(vec);
		result[pos] = result[pos] + 1;
	}
	return result;
}

void GeneratePairs(int population, std::vector<int>& parent1_vec, 
								   std::vector<int>& parent2_vec)
{
	std::set<int> parent1_set;
	while(parent1_set.size() < population/2){
		int b = GenerateRandomNumber(0,population);	
		parent1_set.insert(b);
	}

	for(int i=0; i<population; i++){
		if(!(std::find(parent1_set.begin(), parent1_set.end(), i)!=parent1_set.end())){
			parent2_vec.push_back(i);
		}
	}
	for(auto itr=parent1_set.begin(); itr!=parent1_set.end();itr++){
		parent1_vec.push_back(*itr);
	}
}

void GeneratePairs(int population, std::vector<std::pair<int,int>>& pair_vec)
{
	std::vector<int> parent1_vec, parent2_vec;
	GeneratePairs(population, parent1_vec, parent2_vec);

	for(int i=0; i< population/2; i++)
	{
		int pos1 = GenerateRandomNumber(0, population/2 - i);
		int pos2 = GenerateRandomNumber(0, population/2 - i);
		std::pair<int,int> temp = std::make_pair(parent1_vec[pos1],
												 parent2_vec[pos2]);
		parent1_vec.erase(std::find(parent1_vec.begin(), parent1_vec.end(), 
														 parent1_vec[pos1]));
		parent2_vec.erase(std::find(parent2_vec.begin(), parent2_vec.end(), 
														 parent2_vec[pos2]));
		pair_vec.push_back(temp);
	}
}

void CombineTwoChromosome(std::vector<int>& first, std::vector<int>& sec)
{
	if(first.size()!=sec.size())
	{
		std::cout<<"input wrong"<<std::endl;
		return;
	}
	int crossover_pos = GenerateRandomNumber(0, first.size());	
	std::cout<<crossover_pos<<std::endl;
	std::vector<int> temp_a;
    for(unsigned long i=crossover_pos; i< first.size(); i++){
		temp_a.push_back(first[i]);
	}
    for(unsigned long i = crossover_pos; i< sec.size(); i++){
		first[i]=sec[i];
	}
    for(unsigned long i = 0; i< temp_a.size(); i++){
		sec[crossover_pos] = temp_a[i];;
		crossover_pos++;
	}
}

double GetDistanceBetweenTwoBits(std::vector<int>& a, std::vector<int>& b)
{
	double distance = 0;
	auto itr2 = b.begin();
	for(auto itr1=a.begin();  itr1!=a.end();  itr1++)
	{
		distance = std::pow(*itr1 - *itr2, 2) + distance;
		itr2++;
	}
	return distance;
}

void BinaryStringWithMultipleGenes2RealWithMinAndMax(std::vector<int>& binary_string,
                                         std::vector<std::pair<double, double>>& domain,
                                         std::vector<double>& real_value_vec)
{
    int gene_length = binary_string.size()/domain.size();
    auto slice_start = binary_string.begin();
    for(unsigned long i=0; i<domain.size(); i++)
    {
        std::vector<int> temp(slice_start, slice_start + gene_length);
        double real_value = BinaryString2RealWithMinAndMax(temp, domain[i].first, domain[i].second);
        slice_start = slice_start + gene_length;
        real_value_vec.push_back(real_value);
    }
}
