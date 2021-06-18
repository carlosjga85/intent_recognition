cmake_minimum_required (VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(This intent_recognizer)
project (${This})


enable_testing()

add_subdirectory(googletest)

set(Headers
	intent_recognizer.h
)
set(Sources
	intent_recognizer.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)

