cmake_minimum_required(VERSION 3.10)
project(generic_tree)

set(CMAKE_CXX_STANDARD 98)

add_executable(generic_tree main.cpp Tree.cpp Tree.h Node.cpp Node.h Field.cpp Field.h Node.h Node.cpp Player.h Player.cpp Point.h Point.cpp Simulation.cpp Simulation.h Speed.cpp Speed.h Spot.h Spot.cpp Team.h Team.cpp Goalie.cpp Goalie.h Defensemen.cpp Defensemen.h Forwards.cpp Forwards.h PlayerTree.cpp PlayerTree.h)