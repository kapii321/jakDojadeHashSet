cmake_minimum_required(VERSION 3.25)
project(jakDojadeHashSet)

set(CMAKE_CXX_STANDARD 17)

add_executable(jakDojadeHashSet main.cpp DoubleLinkedList.cpp DoubleLinkedList.h NeighboursList.cpp NeighboursList.h PathReconstructionList.cpp PathReconstructionList.h PriorityQueue.cpp PriorityQueue.h Queue.cpp Queue.h SingleLinkedList.cpp SingleLinkedList.h String.cpp String.h HashSet.cpp HashSet.h)
