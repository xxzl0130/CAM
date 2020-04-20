#pragma once
#include <Eigen/Dense>
#include <Polynomial/Polynomial.hpp>
#include <map>
#include <vector>
#include <algorithm>
typedef polynomial::Polynomial<Eigen::Dynamic> Polynomial;
class CAM_Private
{
public:
	CAM_Private();
	/**
	 * \brief 重置
	 */
	void reset();
	/**
	 * \brief 添加一个点的约束
	 * \param x x坐标
	 * \param y y坐标
	 * \param order 阶数，即y是几阶导数
	 */
	void addPoint(double x, double y, unsigned order = 0);
	/**
	 * \brief 求解曲线
	 */
	bool solve();
	/**
<<<<<<< HEAD
	 * \brief 求解x处的任意阶导数的值
	 * \param x x
	 * \param order 阶次，默认0即不求导
	 * \return f(x)
	 */
	double eval(double x, unsigned order = 0);
private:
	typedef std::pair<double, double> Point;
	std::map<unsigned, std::vector<Point>> points_;
	std::map<unsigned, Eigen::VectorXd> polynomials_;
	int nPoints_;
	bool solved_;

	void makeDiff(unsigned order);
};

