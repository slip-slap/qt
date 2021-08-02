#include <gtest/gtest.h>
#include "../src/selection_method.h"
#include "../src/ga_tool.h"


TEST(GA, selection_method)
{
    std::vector<double> fitness{2,3,8,4,9,0.1};
    SelectionMethod sm(fitness,2);
    std::vector<int> pos;
    sm.TournamentSelection(3,pos);
    std::cout<<"position"<<std::endl;
    for(int i=0; i<pos.size(); i++){
        std::cout<<pos[i]<<std::endl;
    }
}

