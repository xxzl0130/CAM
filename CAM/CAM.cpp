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

void CAM::addPoint(double x, double y, int order)
{
	cam_->addPoint(x, y, order);
}

bool CAM::solve()
{
	return cam_->solve();
}

double CAM::eval(double x)
{
	return cam_->eval(x);
}
