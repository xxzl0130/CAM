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
	CAM_Private* cam_;
};

