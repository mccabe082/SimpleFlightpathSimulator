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
		Waypoint(const Position& p, double arrivalTime, const Orientation& o);;
		Waypoint(const Waypoint&) = default;
		virtual ~Waypoint() = default;
		double arrivalTime() const;
		void updateArrivalTime(double tNew);
		bool passed() const;
		Position position() const;
		Orientation orientation() const;
	private:
		Position flythroughPosition;
		Orientation flythroughOrientation;
		double timeOnArrival;
		Waypoint() = delete;
	};

}