#include "intent_recognizer.h"
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <fstream>




using namespace std;

const auto prefix = "^.*?\\b("s;
const auto suffix = ")\\b.*$"s;

vector<pair<string,string>> vec_pattern_city = {
	{prefix + "Paris" + suffix,"city"},
	{prefix + "London" + suffix,"city"},
	{prefix + "Berlin" + suffix,"city"},
	{prefix + "New York" + suffix,"city"},
	{prefix + "Munchen" + suffix,"city"},
	{prefix + "Amsterdam" + suffix,"city"},
	{prefix + "Madrid" + suffix,"city"},
	{prefix + "Lisbon" + suffix,"city"},
	{prefix + "weather" + suffix,"weather"},
	{prefix + "rain" + suffix,"weather"},
	{prefix + "sun" + suffix,"weather"},
	{prefix + "hot" + suffix,"weather"},
	{prefix + "cold" + suffix,"weather"},
	{prefix + "fact" + suffix,"fact"},
	{prefix + "story" + suffix,"fact"},
	{prefix + "AM" + suffix,"calendar"},
	{prefix + "PM" + suffix,"calendar"},
	{"[[:digit:]]+","calendar"}
};

string get_intent(string str) {

	smatch sm;
	string result;
	int c_fact = 0;
	int c_cal = 0;
	int c_city = 0;
	int c_weather = 0;
	for(int i=0; i<vec_pattern_city.size(); i++){

		if(regex_match(str, sm,regex(vec_pattern_city.at(i).first))){
			//cout<<"MATCH:"<<sm[1]<<"-"<<vec_pattern_city.at(i).second<<endl;

			if(vec_pattern_city.at(i).second=="fact")
				c_fact++;
			else if(vec_pattern_city.at(i).second=="calendar")
				c_cal++;
			else if(vec_pattern_city.at(i).second=="city")
				c_city++;
			else if(vec_pattern_city.at(i).second=="weather")
				c_weather++;
		}
	}

	if (c_fact>0)
		result = "Intent: Get Fact";
	else if (c_cal>0)
		result = "Intent: Check Calendar";
	else if (c_city>0)
		result = "Intent: Get Weather City";
	else if (c_weather>0)
		result = "Intent: Get Weather";

	return result;
}

/*
int main(int argc, char **argv) {


	/*cout<<"Type exit to quit the program"<<endl;

	string str="";

	while (true) {
		getline(cin,str);
		if (str == "exit")
			break;
		cout<<"STR:"<<str<<endl;

		cout<<get_intent(str)<<endl;
	}
	/*myfile_city.open("../files/cities.txt");
	if(myfile_city.is_open()) {
		while(getline(myfile_city,line)) {
			vec_city.push_back(line);
			//vec_pattern_city.push_back(move(prefix) + line + move(suffix));
			cout<<line<<endl;
		}
		myfile_city.close();
	}*/
/*
	return 0;
}
*/
