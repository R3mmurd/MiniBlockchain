/*
  This file contains the definition of a utility function to get a 
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

# ifndef DATETIME_H
# define DATETIME_H

# include <sstream>

/// Gets the current datetime in the string format YYYY-MM-DD H:M:s.ns.
std::string s_now();

# endif // DATETIME_H
