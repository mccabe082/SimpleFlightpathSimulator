#include <flightpath.h>
#include <fstream>

namespace
{
	const double pi = std::acos(-1.);

	const char* filename = "D:/simple-flightpath-simulator/test/example_waypoint_queue.xml";
	int nSamples = 200;
	double tMin = 0.;
	double tMax = 3.;
	double tStep = (tMax - tMin) / double(nSamples);
}

int main(int argc, char** argv)
{
	double t;
	double x, y, z;
	double pitch, roll, yaw;
	bool status_ok = true;

	std::ofstream f;
	f.open(filename);
	f << "t,x,y,z,yaw,pitch,roll\n";

	void* iSim = loadFlightpathSim(filename);

	if (iSim)
	{
		for (int i = 0; i < nSamples; ++i)
		{
			t = double(i) * tStep + tMin;

			status_ok = advanceWaypointSim(iSim, t, x, y, z, pitch, roll, yaw);

			if (!status_ok) return false;

			f << t << ",";
			f << x << "," << y << "," << z << ",";
			f << yaw << "," << pitch << "," << roll << ",\n";
		}
	}

	f.close();
	return 0;

}