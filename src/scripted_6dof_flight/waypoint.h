#pragma once

#include <geometry3d/position.h>
#include <geometry3d/orientation.h>

using namespace Geometry3D;

namespace Scripted6DoFFlight
{
	class Velocity;

	class Waypoint
	{};

	class VelocityWaypoint : Waypoint
	{
	public:
		VelocityWaypoint(const Position& p, const Orientation& o, double timeToArrival);
	private:
		Position targetPos;
		Orientation targetOrient;
		double timeToArrival;
		VelocityWaypoint() = delete;
	};

	// https://www.skybrary.aero/index.php/Waypoint

	/*class Flyby : Waypoint
	{
	public:
		Flyby(const Position& p, const Orientation& o);
	private:
		Position p;
		Flyby() = delete;
	};

	class Flyover : Waypoint
	{
	public:
		Flyover(const Position& p, const Orientation& o);
	private:
		Position p;
		Flyover() = delete;
	};*/
}