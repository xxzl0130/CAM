#include "CAM.h"
#include "CAM_Private.h"

CAM::CAM():
	cam_(new CAM_Private)
{
}

void CAM::reset()
{
	cam_->reset();
}

<<<<<<< HEAD
void CAM::addPoint(double x, double y, unsigned order)
=======
void CAM::addPoint(double x, double y, int order)
>>>>>>> 528f77a... 完成
{
	cam_->addPoint(x, y, order);
}

bool CAM::solve()
{
	return cam_->solve();
}

<<<<<<< HEAD
double CAM::eval(double x, unsigned order)
{
	return cam_->eval(x, order);
=======
double CAM::eval(double x)
{
	return cam_->eval(x);
>>>>>>> 528f77a... 完成
}
