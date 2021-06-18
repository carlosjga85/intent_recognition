#include "../intent_recognizer.h"
#include <gtest/gtest.h>
#include <string>
#include <iostream>

using namespace std;

TEST(intent_recognizerTest, get_intent_weather) {
	string str_test1 = "What is the weather like today?";

	string expected_weather = "Intent: Get Weather";

	EXPECT_EQ(expected_weather,get_intent(str_test1)) << "Result:"<<get_intent(str_test1);

}

TEST(intent_recognizerTest, get_intent_city) {

	string str_test2 = "What is the weather like in Paris today?";
	string str_test3 = "What is the weather like in New York today?";

	string expected_city = "Intent: Get Weather City";

	EXPECT_EQ(expected_city,get_intent(str_test2)) << "Result:"<<get_intent(str_test2);
	EXPECT_EQ(expected_city,get_intent(str_test3)) << "Result:"<<get_intent(str_test3);

}

TEST(intent_recognizerTest, get_intent_calendar) {

	string str_test4 = "Am I free at 13:00 PM tomorrow?";
	string expected_calendar = "Intent: Check Calendar";

	EXPECT_EQ(expected_calendar,get_intent(str_test4)) << "Result:"<<get_intent(str_test4);
}

TEST(intent_recognizerTest, get_intent_fact) {

	string str_test5 = "Tell me an interesting fact";
	string expected_fact = "Intent: Get Fact";

	EXPECT_EQ(expected_fact,get_intent(str_test5)) << "Result:"<<get_intent(str_test5);
}

int main(int argc, char **argv) {

	string input;

    while (true) {
    	cout << "Hey there! Please, enter the request: \nIf you wanna run the tests, type in tests. \nType exit to quit the program.\n";
		getline (cin, input);
		if (input == "exit")
			return 0;
		else if(input == "tests"){
			testing::InitGoogleTest(&argc, argv);
			return RUN_ALL_TESTS();
		}
		cout<<"Input: "<<input<<endl;

		cout<<get_intent(input)<<endl;
	}

    return 0;
}
