/*
  This file contains the implementation of a utility function to get a 
  string representation of the current date time.

  Copyright (C) 2018 by Alejandro J. Mujica

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

  Any user request of this software, write to 

  Alejandro Mujica

  aledrums@gmail.com
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
