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
	void addPoint(double x, double y, int order = 0);
	/**
	 * \brief 求解曲线
	 */
	bool solve();
	/**
	 * \brief 求解x处的值
	 * \param x x
	 * \return f(x)
	 */
	double eval(double x);
private:
	typedef std::pair<double, double> Point;
	std::map<int, std::vector<Point>> points_;
	Polynomial polynomial_;
	int nPoints_;
	bool solved_;
};

