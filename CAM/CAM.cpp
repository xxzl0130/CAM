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

void CAM::addPoint(double x, double y, unsigned order)
{
	cam_->addPoint(x, y, order);
}

bool CAM::solve()
{
	return cam_->solve();
}

double CAM::eval(double x, unsigned order)
{
	return cam_->eval(x, order);
}
