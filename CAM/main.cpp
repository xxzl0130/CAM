#include <iostream>
#include "CAM.h"
#include <fstream>
int main()
{
    CAM cam;
	cam.addPoint(0, 0, 0);
	cam.addPoint(10, 10, 0);
	cam.addPoint(0, 0, 1);
	cam.addPoint(2, 0.5, 1);
	cam.addPoint(5, 2, 1);
	cam.addPoint(10, 0, 1);
	cam.addPoint(2, 0.5, 2);
	cam.addPoint(4, 0.5, 2);
	cam.solve();
	std::fstream fout;
	fout.open("data.csv",std::ios_base::out);
	for(auto i = 0.0;i < 10.0;i += 0.01)
	{
		fout << i << ',' << cam.eval(i) << std::endl;
	}
}
