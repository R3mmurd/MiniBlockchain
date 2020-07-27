/*
  Mini Blockchain.
  
  Author: Alejandro Mujica (aledrums@gmail.com)
*/

# include <ctime>
# include <chrono>
# include <iomanip>
# include <datetime.H>

std::string s_now()
{
  using clock_t = std::chrono::system_clock;
  using time_point_t = clock_t::time_point;
  using duration_t = clock_t::duration;
  
  time_point_t now = clock_t::now(); // Current time point

  // Duration in nanoseconds
  duration_t d_ns = now.time_since_epoch();
  // Duration in seconds
  duration_t d_s = std::chrono::duration_cast<std::chrono::seconds>(d_ns);
  duration_t diff = d_ns - d_s;

  std::time_t now_c = clock_t::to_time_t(now);

  std::stringstream s;
  s << std::put_time(localtime(&now_c), "%F %T") << "." << diff.count();

  return s.str();  
}
