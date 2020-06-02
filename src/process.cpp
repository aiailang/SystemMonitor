#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <unistd.h>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) : pid_(pid) {
  ComputeCPUUtilization();
}

// TODO: Return this process's ID
int Process::Pid() const { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() const { 
  return utilization_; 
}

// TODO: Return the command that generated this process
string Process::Command() const { return LinuxParser::Command(pid_); }

// TODO: Return this process's memory utilization
string Process::Ram() const { return LinuxParser::Ram(pid_); }

// TODO: Return the user (name) that generated this process
string Process::User() const { return LinuxParser::User(pid_);}

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() const { 
  return LinuxParser::UpTime(pid_);
}

void Process::ComputeCPUUtilization() {
  long activeJiffies = LinuxParser::ActiveJiffies(pid_);
  long upTime = LinuxParser::UpTime(pid_);
  utilization_ = (float)activeJiffies/sysconf(_SC_CLK_TCK)/upTime; 
  //fprintf(stderr, "pid %d active %ld, %ld, upTime %ld uti %f\n", pid_, activeJiffies, sysconf(_SC_CLK_TCK), upTime, utilization_);
}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const & a) const{
  return (utilization_ < a.utilization_ ? true : false);
}

bool Process::operator>(Process const & a) const{
  return (utilization_ > a.utilization_ ? true : false);
}