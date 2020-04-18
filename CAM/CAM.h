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
	CAM_Private* cam_;
};

