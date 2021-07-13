#ifndef FOURIER_H
#define FOURIER_H

#include <iostream>
#include <boost/math/quadrature/trapezoidal.hpp>
#include <math.h>
#include <vector>
#include <tuple>

namespace fourier{
        int frequency = 1;
        double (*target_function)(double);
        std::vector<std::tuple<int, double, double>> vec;

        double targetFunctionMultiplySin(double x)
        {
                return 	(*target_function)(x) * std::sin(frequency * x);
        }

        double targetFunctionMultiplyCos(double x)
        {
                return 	(*target_function)(x) * std::cos(frequency * x);
        }

        void simulation(int max_frequency)
        {
            double T0 = 6.14;
            double start = 0;
            vec.clear();
            for(int i=1;i<max_frequency;i++)
            {
                frequency = i;
                double sin_intgrand = boost::math::quadrature::trapezoidal(targetFunctionMultiplySin,start,start+T0);
                double cos_intgrand = boost::math::quadrature::trapezoidal(targetFunctionMultiplyCos,start,start+T0);
                double coefficient_sin = sin_intgrand*2/T0;
                double coefficient_cos = cos_intgrand*2/T0;
                vec.push_back(std::make_tuple(frequency, coefficient_sin, coefficient_cos));
            }
        }

        double cos_and_sin(std::tuple<int, double, double>& tup, double x){
            return std::get<1>(tup) * std::sin(std::get<0>(tup) * x ) +
                std::get<2>(tup) * std::cos(std::get<0>(tup) * x );
        }

        double fourier_expansion(double x){

            double result = 0;
            for(auto itr = vec.begin(); itr!= vec.end(); itr++){
                result = result + cos_and_sin(*itr, x);
            }
            return result;
        }
};


#endif // FOURIER_H
