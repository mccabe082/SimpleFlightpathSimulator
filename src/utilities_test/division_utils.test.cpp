#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <utilities/division_utils.h>
#include <cmath>

using namespace Utilities;

TEST_CASE("Divisions work correctly", "[division]") {

	// acknowledge this blog https://harry.garrood.me/blog/integer-division/

	SECTION("Test Truncated division") { /* returns maximum |quotient| which is nearest to zero */

		{
			double dividend = -5.;
			double divisor = 3.;

			double quotientExected = -1.;
			double remainderExpected = -2.;

			double quotientActual = truncatingDivide(dividend, divisor);
			double remainderActual = truncatingModulo(dividend, divisor);

			REQUIRE(quotientActual == quotientExected);
			REQUIRE(remainderActual == remainderExpected);
			REQUIRE(Approx(dividend) == quotientActual * divisor + remainderActual);
		}

		{
			double dividend = 5.;
			double divisor = -3.;

			double quotientExected = -1.;
			double remainderExpected = 2.;

			double quotientActual = truncatingDivide(dividend, divisor);
			double remainderActual = truncatingModulo(dividend, divisor);

			REQUIRE(quotientActual == quotientExected);
			REQUIRE(remainderActual == remainderExpected);
			REQUIRE(Approx(dividend) == quotientActual * divisor + remainderActual);
		}
	}

	SECTION("Test Flooring/Knuthian division") {  /* returns maximum |quotient| which is nearest to -ve infinity */

			{
				double dividend = -5.;
				double divisor = 3.;

				double quotientExected = -2.;
				double remainderExpected = 1.;

				double quotientActual = flooringDivide(dividend, divisor);
				double remainderActual = flooringModulo(dividend, divisor);

				REQUIRE(quotientActual == quotientExected);
				REQUIRE(remainderActual == remainderExpected);
				REQUIRE(Approx(dividend) == quotientActual * divisor + remainderActual);
			}

			{
				double dividend = 5.;
				double divisor = -3.;

				double quotientExected = -2.;
				double remainderExpected = -1.;

				double quotientActual = flooringDivide(dividend, divisor);
				double remainderActual = flooringModulo(dividend, divisor);

				REQUIRE(quotientActual == quotientExected);
				REQUIRE(remainderActual == remainderExpected);
				REQUIRE(Approx(dividend) == quotientActual * divisor + remainderActual);
			}
	}

	SECTION("Test Euclidean division") { /* returns maximum |quotient| with a positive remainder */

		{
			double dividend = -5.;
			double divisor = 3.;

			double quotientExected = -2.;
			double remainderExpected = 1.;

			double quotientActual = euclideanDivide(dividend, divisor);
			double remainderActual = euclideanModulo(dividend, divisor);

			REQUIRE(quotientActual == quotientExected);
			REQUIRE(remainderActual == remainderExpected);
			REQUIRE(Approx(dividend) == quotientActual * divisor + remainderActual);
		}

		{
			double dividend = 5.;
			double divisor = -3.;

			double quotientExected = -1.;
			double remainderExpected = 2.;

			double quotientActual = euclideanDivide(dividend, divisor);
			double remainderActual = euclideanModulo(dividend, divisor);

			REQUIRE(quotientActual == quotientExected);
			REQUIRE(remainderActual == remainderExpected);
			REQUIRE(Approx(dividend) == quotientActual * divisor + remainderActual);
		}
	}
}