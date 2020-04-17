#pragma once

#include "physics/environment.h"

namespace physics
{
	class SeaLevel : public Environment
	{
		double gravity(double /*altitude*/) const override;
	};
}