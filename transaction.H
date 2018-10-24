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

# ifndef TRANSACTION_H
# define TRANSACTION_H

# include <list>
# include <sstream>
# include <tuple>

using Transaction = std::tuple<std::string, std::string, double>;

Transaction transaction(const std::string &, const std::string &, double);

std::string to_str(const Transaction &);

std::string to_str(const std::list<Transaction> &);

# endif // TRANSACTION_H
