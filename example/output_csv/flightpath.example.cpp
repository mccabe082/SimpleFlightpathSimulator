#include <flightpath.h>
#include <fstream>

namespace
{
	const double pi = std::acos(-1.);

	const char* waypoint_filename = "johns_mountain_demo.xml";
	const char* csv_filename = "johns_mountain_demo.csv";
	int nSamples = 2000;
	double tMin = 0.;
	double tMax = 9.;
	double tStep = (tMax - tMin) / double(nSamples);
}

double rad2deg(double alpha)
{
	return alpha * 180. / pi;
}

int main(int argc, char** argv)
{
	double t;
	double x, y, z;
	double pitch, roll, yaw;
	bool status_ok = true;

	std::ofstream f;
	f.open(csv_filename);
	f << "t,x,y,z,yaw,pitch,roll\n";

	void* iSim = loadFlightpathSim(waypoint_filename);

	if (iSim)
	{
		for (int i = 0; i < nSamples; ++i)
		{
			t = double(i) * tStep + tMin;

			status_ok = advanceWaypointSim(iSim, tStep, x, y, z, pitch, roll, yaw);

			if (!status_ok) return false;

			f << t << ",";
			f << x << "," << y << "," << z << ",";
			f << rad2deg(yaw) << "," << rad2deg(pitch) << "," << rad2deg(roll) << ",\n";
		}
	}

	f.close();
	return 0;

}