#include <RcppArmadillo.h>
// [[Rcpp::depends("RcppArmadillo")]]

#include <boost/regex.hpp>
#include <boost/foreach.hpp>
#include <boost/range.hpp>

using namespace Rcpp;
using namespace std;
using namespace boost;

#include <iostream>
#include <string>

// [[Rcpp::export]]
void main()
{

std::string str = "hellooooooooo";
std::string target = "o Bob";

// Das ist jetzt das Suchpattern
boost::regex re("ooooooooo");


std::string result = boost::regex_replace(str, re, newtext);
}
