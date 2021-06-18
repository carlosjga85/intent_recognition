#include "../intent_recognizer.h"
#include <gtest/gtest.h>
#include <string>
#include <iostream>

using namespace std;

TEST(intent_recognizerTest, get_intent) {
	string str_test1 = "What is the weather like today?";
	string str_test2 = "What is the weather like in Paris today?";
	string str_test3 = "What is the weather like in New York today?";
	string str_test4 = "Am I free at 13:00 PM tomorrow?";
	string str_test5 = "Tell me an interesting fact";
	string expected_city = "Intent: Get Weather City";
	string expected_weather = "Intent: Get Weather";
	string expected_fact = "Intent: Get Fact";
	string expected_calendar = "Intent: Check calendar";

	EXPECT_EQ(expected_weather,get_intent(str_test1)) << "Result:"<<get_intent(str_test1);
	EXPECT_EQ(expected_city,get_intent(str_test2)) << "Result:"<<get_intent(str_test2);
	EXPECT_EQ(expected_city,get_intent(str_test3)) << "Result:"<<get_intent(str_test3);
	EXPECT_EQ(expected_calendar,get_intent(str_test4)) << "Result:"<<get_intent(str_test4);
	EXPECT_EQ(expected_fact,get_intent(str_test5)) << "Result:"<<get_intent(str_test5);
}

