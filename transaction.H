/*
  Mini Blockchain.
  
  Author: Alejandro Mujica (aledrums@gmail.com)
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
