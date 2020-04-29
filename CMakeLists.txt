CMAKE_MINIMUM_REQUIRED (VERSION 3.10.2)
PROJECT(Practical-Lab CXX)

IF(${CMAKE_CXX_COMPILER_ID} MATCHES "(GNU|Clang)")
  ADD_COMPILE_OPTIONS(-Wall -Wextra -pedantic)
ENDIF(${CMAKE_CXX_COMPILER_ID} MATCHES "(GNU|Clang)")

ADD_EXECUTABLE(blatt1
  world.cpp
  velocityverlet.cpp
  blatt1.cpp
  observer.cpp
  timediscretization.cpp
  gravitypotential.cpp
  )
SET_PROPERTY(TARGET blatt1 PROPERTY CXX_STANDARD 98)
