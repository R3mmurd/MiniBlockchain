/*
  This file is part of a simple example of a Blockchain implementation.

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

# include <transaction.H>

Transaction transaction(const std::string & s, const std::string & r, double a)
{
  return std::make_tuple(s, r, a);
}

std::string to_str(const Transaction & t)
{
  std::stringstream s;
  s << "{"
    << "(sender: " << std::get<0>(t) << "), "
    << "(receiver: " << std::get<1>(t) << "), "
    << "(amount: " << std::get<2>(t) << ")"
    << "}";
  return s.str();
}

std::string to_str(const std::list<Transaction> & ts)
{
  std::stringstream s;
  s << "[";
  
  auto b = ts.begin();
  auto e = ts.end();

  if (b != e)
    {
      s << to_str(*b);
      ++b;
    }

  while (b != e)
    {
      s << ", " << to_str(*b);
      ++b;
    }

  s << "]";
  return s.str();
}
