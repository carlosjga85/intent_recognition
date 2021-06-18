cmake_minimum_required (VERSION 3.10)

set(This intent_recognizerTest)

set(Sources
	intent_recognizerTest.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
	gtest_main
	intent_recognizer
)

add_test(
	NAME ${This}
	COMMAND ${This}
)