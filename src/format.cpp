#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
  long second = seconds;
  int hour = second/3600;
  second = second%3600;
  int min = second/60;
  second = second%60;
  string result = std::to_string(hour)
    		+":"+std::to_string(min)
    		+":"+std::to_string(second);
  return result;
}