#pragma once
class CAM_Private;
class CAM
{
public:
	CAM();
	
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
=======
	 * \brief ���x����ֵ
	 * \param x x
	 * \return f(x)
	 */
	double eval(double x);
>>>>>>> 528f77a... 完成
private:
	CAM_Private* cam_;
};

