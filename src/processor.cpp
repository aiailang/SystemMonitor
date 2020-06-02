#include "processor.h"

#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  long idle = LinuxParser::IdleJiffies();
  long total = LinuxParser::Jiffies();
  long Idled = idle - preIdle;
  long Totald = total - preTotal;
  float util = (float)(Totald-Idled)/Totald;
  preIdle = idle;
  preTotal = total;
  //fprintf(stderr, "util %f\n", util);
  return util;
}