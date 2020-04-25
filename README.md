[![Join the team using Discord: https://discord.gg/6zMa4Tp](https://img.shields.io/badge/Discord-collaborate-brightgreen.svg)](https://discord.gg/6zMa4Tp)
[![Build status](https://ci.appveyor.com/api/projects/status/07276mey39n8kaob?svg=true)](https://ci.appveyor.com/project/DavidMcCabe/simpleflightpathsimulator)

# Simple Flightpath Simulator

A desktop application for scripting aircraft motion in three dimensions.

## The Waypoint
![Waypoint Illustration 1](./docs/artwork/Waypoint-Illustrations/Waypoint-Illustration1.PNG)
A **Waypoint** has;
- a **Fly-through Time**
- a **3D Position**
  - x, North (Relative)
  - y, East (Relative)
  - z, Altitude (Relative)

- a **3D Orientation**
  - Roll (Rotation about x)
  - Pitch (Rotation about y)
  - Yaw (Rotation about z)

## Waypoint Queue
![Waypoint Illustration 2](./docs/artwork/Waypoint-Illustrations/Waypoint-Illustration2.PNG)
The course of the aircraft is defined by a sequence of waypoints.  These are read in using 
> Need to add file format details

## Flightpath Calculation
![Waypoint Illustration 3](./docs/artwork/Waypoint-Illustrations/Waypoint-Illustration3.PNG)
This tool simply interpolates between waypoints so values for Position, Orientation, Velocity and Rotation are known at any instant of time. 

# Old stuff

- **[Team Objectives](./docs/programme_goals.md)...**
- **[Programme Structure](./docs/programme_structure.md)...**

![fancy stock image](https://cdn.pixabay.com/photo/2019/03/23/20/01/aircraft-4076160_1280.jpg)

> **Note: This project currently requires [Boost 1.71.0](https://www.boost.org/users/history/version_1_71_0.html)**

