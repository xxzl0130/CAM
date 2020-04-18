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
	 * \brief ����
	 */
	void reset();
	/**
	 * \brief ���һ�����Լ��
	 * \param x x����
	 * \param y y����
	 * \param order ��������y�Ǽ��׵���
	 */
	void addPoint(double x, double y, int order = 0);
	/**
	 * \brief �������
	 */
	bool solve();
	/**
	 * \brief ���x����ֵ
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

