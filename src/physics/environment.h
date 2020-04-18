#pragma once

namespace physics
{
	class Environment
	{
	public:
		virtual double gravity(double /*altitude*/) const = 0;
	};
}