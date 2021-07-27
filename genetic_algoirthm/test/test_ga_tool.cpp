#include <gtest/gtest.h>
#include "../src/ga_tool.h"

TEST(a, c)
{
	std::vector<int> binary_string_vec;
    std::vector<std::pair<double, double>> domain_vec;
    domain_vec.push_back(std::make_pair(1,4));
    std::vector<double> real_value_vec;
    GenerateRandomBinaryString(binary_string_vec,30);
    BinaryStringWithMultipleGenes2RealWithMinAndMax(binary_string_vec,
                                            domain_vec,real_value_vec);
    for(auto itr=real_value_vec.begin(); itr!=real_value_vec.end(); itr++){
        std::cout<<*itr<<std::endl;
    }

}
