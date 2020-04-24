#pragma once

#include <geometry3d/position.h>
#include <geometry3d/orientation.h>

using namespace Geometry3D;

namespace Scripted6DoFFlight
{
	class Velocity;

	class Waypoint
	{
	public:
		Waypoint(double arrivalTime);
		Waypoint(const Waypoint&) = default;
		virtual ~Waypoint() = default;
	private:
		double timeToArrival;
		Waypoint() = delete;
	};

	class FranksWaypoint : Waypoint
	{
	public:
		FranksWaypoint(const Position& p, double timeToArrival, const Orientation& o);
	private:
		Position targetPos;
		Orientation targetOrient;
		FranksWaypoint() = delete;

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