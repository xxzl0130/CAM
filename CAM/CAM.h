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
	void addPoint(double x, double y, unsigned order = 0);
	/**
	 * \brief �������
	 */
	bool solve();
	/**
	 * \brief ���x��������׵�����ֵ
	 * \param x x
	 * \param order �״Σ�Ĭ��0������
	 * \return f(x)
	 */
	double eval(double x, unsigned order = 0);
private:
	CAM_Private* cam_;
};

