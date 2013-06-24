#include <iostream>
#include <string>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>
#include <vector>

using namespace std;
using namespace boost;

std::string remove_numbers(std::string input)
{
boost::regex digit("\\d");
std::string fmt = "";
std::string output = boost::regex_replace(input,digit,fmt);
return output;
}

std::string remove_whitespace(std::string input)
{
boost::regex white("\\s+");
std::string fmt = " ";
std::string output = boost::regex_replace(input,white,fmt);
return output;
}

std::string remove_punctuation(std::string input)
{
boost::regex punct("[[:punct:]]");
std::string fmt = " ";
std::string output = boost::regex_replace(input,punct,fmt);
return output;
}

vector<std::string> isolate_words(std::string input)
{
vector<std::string> output_vector;
boost::split(output_vector,input,boost::is_any_of("\t "));
return output_vector;
}

vector<std::string> eliminate_empty_words(vector<std::string> input)
{
vector<std::string> output_vector;
int length = input.size();
for (int i=0;i<length;i++)
{
if (input[i]=="\0") cout << "eine leerzeile";
else
    {output_vector.push_back(input[i]);
	cout << "input" << input[i];
	}
}
return output_vector;
}

void print_vector(vector<std::string> input)
{
for( std::vector<string>::iterator i = input.begin(); i != input.end(); ++i)
	    std::cout << *i << ' ';
}

int main()
{
	std::string str = "Loans to first lenders go bust.";
	str = remove_numbers(str);
	str = remove_punctuation(str);
	str = remove_whitespace(str);
	boost::algorithm::to_lower(str);
	vector<std::string> w = isolate_words(str);
	w = eliminate_empty_words(w);
    print_vector(w);
	cout << w.size();
	cout << "w6:" << w[6];

}

