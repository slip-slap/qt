#pragma once
#include <cmath>

namespace problem
{
	namespace SCH 
	{
		double TargetFunction1(double x);
		double TargetFunction2(double x);
	}
	namespace POL
	{
		double TargetFunction1(double x1, double x2);
		double TargetFunction2(double x1, double x2);
	}
	namespace KUR
	{
		double TargetFunction1(double x1, double x2, double x3);
		double TargetFunction2(double x1, double x2, double x3);
	}
	namespace SO 
	{
		double M1(double x);
		double M2(double x);
		double M3(double x);
		double M4(double x);
//		double M5(double x);
//		double M6(double x);
	}
	namespace MO
	{
		namespace CONSTR
		{
			double TargetFunction1(double x1);
			double TargetFunction2(double x1, double x2);
			bool TargetConstraint1(double x1, double x2);
			bool TargetConstraint2(double x1, double x2);
		}
		namespace SRN 
		{
			double TargetFunction1(double x1, double x2);
			double TargetFunction2(double x1, double x2);
			bool TargetConstraint1(double x1, double x2);
			bool TargetConstraint2(double x1, double x2);
		}
	}
}

