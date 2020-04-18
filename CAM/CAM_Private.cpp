#include "CAM_Private.h"
#include <iostream>

CAM_Private::CAM_Private():
	polynomial_(0),
	nPoints_(0),
	solved_(false)
{
	
}

void CAM_Private::reset()
{
	points_.clear();
	polynomial_ = Polynomial(0);
	nPoints_ = 0;
	solved_ = false;
}

void CAM_Private::addPoint(double x, double y, int order)
{
	points_[order].emplace_back(x, y);
	++nPoints_;
	solved_ = false;
}

bool CAM_Private::solve()
{
	if(solved_)
		return true;
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
	polynomial_ = Polynomial(a);
	solved_ = true;
	return solved_;
}

double CAM_Private::eval(double x)
{
	if(solved_ || solve())
	{
		return polynomial_.eval(x);
	}
	return 0;
}
