#include "CAM_Private.h"
#include <iostream>

CAM_Private::CAM_Private():
<<<<<<< HEAD
=======
	polynomial_(0),
>>>>>>> 528f77a... 完成
	nPoints_(0),
	solved_(false)
{
	
}

void CAM_Private::reset()
{
	points_.clear();
<<<<<<< HEAD
	polynomials_.clear();
=======
	polynomial_ = Polynomial(0);
>>>>>>> 528f77a... 完成
	nPoints_ = 0;
	solved_ = false;
}

<<<<<<< HEAD
void CAM_Private::addPoint(double x, double y, unsigned order)
=======
void CAM_Private::addPoint(double x, double y, int order)
>>>>>>> 528f77a... 完成
{
	points_[order].emplace_back(x, y);
	++nPoints_;
	solved_ = false;
}

bool CAM_Private::solve()
{
<<<<<<< HEAD
=======
	if(solved_)
		return true;
>>>>>>> 528f77a... 完成
	Eigen::MatrixXd A = Eigen::MatrixXd::Zero(nPoints_, nPoints_);
	Eigen::VectorXd b;
	b.resize(nPoints_, 1);
	int i = 0;
	for(const auto& it : points_)
	{
		auto order = it.first;
		const auto& pts = it.second;
		for(const auto& pt : pts)
		{
			b(i) = pt.second;
			auto t = 1.0;
			for(auto j = 0;j < nPoints_ - order;++j)
			{
				auto v = t;
				t *= pt.first;
				for(auto k = 0;k < order;++k)
				{
					v *= j - k + order;
				}
				A(i, j + order) = v;
			}
			++i;
		}
	}
	auto LU = A.fullPivLu();
	if (LU.rank() != nPoints_ || LU.rcond() < 1e-15)
		return solved_ = false;
	Eigen::VectorXd a = LU.solve(b);
	for(auto i = 0;i < nPoints_/2;++i)
	{
		std::swap(a(i), a(nPoints_ - i - 1));
	}
<<<<<<< HEAD
	polynomials_[0] = a;
=======
	polynomial_ = Polynomial(a);
>>>>>>> 528f77a... 完成
	solved_ = true;
	return solved_;
}

<<<<<<< HEAD
double CAM_Private::eval(double x, unsigned order)
{
	if(solved_ || solve())
	{
		makeDiff(order);
		return Polynomial(polynomials_[order]).eval(x);
	}
	return 0;
}

void CAM_Private::makeDiff(unsigned order)
{
	if(polynomials_.count(order))
		return;
	auto a = polynomials_[0];
	Eigen::VectorXd b;
	b.resize(nPoints_ - 1);
	for(auto i = 0;i < nPoints_ - 1;++i)
	{
		b(i) = a(i) * (nPoints_ - 1 - i);
	}
	polynomials_[order] = b;
}
=======
double CAM_Private::eval(double x)
{
	if(solved_ || solve())
	{
		return polynomial_.eval(x);
	}
	return 0;
}
>>>>>>> 528f77a... 完成
