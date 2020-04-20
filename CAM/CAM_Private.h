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
<<<<<<< HEAD
	void addPoint(double x, double y, unsigned order = 0);
=======
	void addPoint(double x, double y, int order = 0);
>>>>>>> 528f77a... 完成
	/**
	 * \brief �������
	 */
	bool solve();
	/**
<<<<<<< HEAD
	 * \brief ���x��������׵�����ֵ
	 * \param x x
	 * \param order �״Σ�Ĭ��0������
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
=======
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
>>>>>>> 528f77a... 完成
};

