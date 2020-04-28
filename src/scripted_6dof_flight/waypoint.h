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
		Waypoint(const Position& p, const Orientation& o, double arrivalTime);
		Waypoint(const Waypoint&) = default;
		virtual ~Waypoint() = default;
		double arrivalTime() const;
		Position position() const;
		Orientation orientation() const;
	private:
		Position flythroughPosition;
		Orientation flythroughOrientation;
		double timeOnArrival;
		Waypoint() = delete;
	};

}