#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::literals::chrono_literals;

std::string padIntToTimeStr(int num)
{
  return (num < 10 ? "0" : "") + std::to_string(num);
}

std::string makeTimeFriendly(int secs)
{
  int mins, hours;
  std::string friendlySecs, friendlyMins = "00", friendlyHours = "00";

  // These will all round down automatically as integers
  friendlySecs = padIntToTimeStr(secs % 60);

  if (secs >= 60) {
    mins = secs / 60;

    friendlyMins = padIntToTimeStr(mins % 60);

    if (mins >= 60) {
      hours = mins / 60;

      friendlyHours = padIntToTimeStr(hours);
    }
  }

  return friendlyHours + ":" + friendlyMins + ":" + friendlySecs;
}

int main()
{
  int numSecs = 0;

  // Begin infinite loop until process is killed
  while (true) {
    // Edit same line repeatedly and flush straight to console
    std::cout << "\r" << makeTimeFriendly(numSecs) << std::flush;

    // Wait for 1 second to repeat loop
    std::this_thread::sleep_for(1s);
    numSecs++;
  }

  return 0;
}

