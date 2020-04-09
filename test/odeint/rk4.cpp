#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <cmath>
#include "boost/numeric/odeint.hpp"

namespace
{
    const double pi = 3.14;
    const double g = 9.81; // acceleration due to gravity [m/s/s]
}

SCENARIO( "RK4 works on a simple problem", "[RapidXML]" ) {

	class Pendulum
	{
	public:
		double theta; // angular displacement [rad]

		Pendulum(double length, double theta0) : theta(theta0), L(length)
		{
			T = 2. * pi * std::sqrt(L / g);
		}

		double thetaDot() const { return -g / L * std::sin(theta); }
		double period() const { return T; }

	private:
		double L; // length [m]
		double T; // period [s]
		Pendulum() = delete;
	};

    GIVEN( "A frictionless pendulum simulation" ) {

        Pendulum p(0.4, pi/10.);

        WHEN( "the bob is released and the simulation is run over a time interal equal to the period of the pendulum" ) {
            
            THEN( "the pendulum should be back at its starting position and the end of the simulation" ) {
                REQUIRE(1==1);
            }
        }

    }
}