#include "ga_problem.h"

double problem::SCH::TargetFunction1(double x) { return x * x; }
double problem::SCH::TargetFunction2(double x)
{
	return (x - 2) * (x - 2);
}
double problem::POL::TargetFunction1(double x1, double x2)
{
	double a1 = 0.5 * std::sin(1) - 2 * std::cos(1) 
				+ std::sin(2) - 1.5 * std::cos(2);
	double a2 = 1.5 * std::sin(1) - std::cos(1) 
				+ 2 * std::sin(2) - 0.5 * std::cos(2);
	double b1 = 0.5 * std::sin(x1) - 2 * std::cos(x1) 
				+ std::sin(x2) - 1.5 * std::cos(x2);
	double b2 = 1.5 * std::sin(x1) - std::cos(x1) 
				+ 2 * std::sin(x2) - 0.5 * std::cos(x2);
	return 1 + (a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2);
}
double problem::POL::TargetFunction2(double x1, double x2)
{
	return (x1 + 3) * (x1 + 3) + (x2 + 1) * (x2 + 1);
}

double problem::KUR::TargetFunction1(double x1, double x2, double x3)
{
	return -10*std::exp(-0.2 * std::sqrt(x1*x1 + x2*x2 ))
		 + -10*std::exp(-0.2 * std::sqrt(x2*x2 + x3*x3 ));
}

double problem::KUR::TargetFunction2(double x1, double x2, double x3)
{
	return std::pow(std::abs(x1),0.8) + 5*std::sin(x1*x1*x1) 
		+  std::pow(std::abs(x2),0.8) + 5*std::sin(x2*x2*x2)
		+  std::pow(std::abs(x3),0.8) + 5*std::sin(x3*x3*x3);
}

double problem::SO::M1(double x)
{
	return std::pow(std::sin( 5 * M_PI * x ), 6);
}
double problem::SO::M2(double x)
{
	return problem::SO::M1(x) * std::exp(-2 * std::log(2) 
									* std::pow((x - 0.1)/0.8, 2));
}

double problem::SO::M3(double x)
{
	return std::pow(std::sin( 5 * M_PI * (std::pow(x, 0.75) - 0.05)), 6);
}

double problem::SO::M4(double x)
{
	return std::exp(-2 * std::log(2)* std::pow((x-0.08)/0.854,2)) * problem::SO::M3(x);
}

double problem::MO::CONSTR::TargetFunction1(double x1){return x1;}
double problem::MO::CONSTR::TargetFunction2(double x1, double x2)
{
	return (1+x2)/x1;
}

bool problem::MO::CONSTR::TargetConstraint1(double x1, double x2)
{
	if(9 * x1 + x2 > 6){return true;} else{return false;}
}

bool problem::MO::CONSTR::TargetConstraint2(double x1, double x2)
{
	if(9 * x1 - x2 > 1){return true;} else{return false;}
}


double problem::MO::SRN::TargetFunction1(double x1, double x2)
{
	return std::pow(x1-2,2) + std::pow(x2-2,2) + 2;
}
double problem::MO::SRN::TargetFunction2(double x1, double x2)
{
	return 9*x1 - std::pow(x2-1,2);
}

bool problem::MO::SRN::TargetConstraint1(double x1, double x2)
{
	if(std::pow(x1,2)+std::pow(x2,1) < 225){return true;} else{return false;}
}

bool problem::MO::SRN::TargetConstraint2(double x1, double x2)
{
	if(x1 - 3*x2 < -10){return true;} else{return false;}
}


