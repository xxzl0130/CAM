#pragma once
class CAM_Private;
class CAM
{
public:
	CAM();
	
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
<<<<<<< HEAD
	void addPoint(double x, double y, unsigned order = 0);
=======
	void addPoint(double x, double y, int order = 0);
>>>>>>> 528f77a... 瀹屾垚
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
=======
	 * \brief 求解x处的值
	 * \param x x
	 * \return f(x)
	 */
	double eval(double x);
>>>>>>> 528f77a... 瀹屾垚
private:
	CAM_Private* cam_;
};

