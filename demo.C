/*
  This file contains a demo to use the implementation of the Blockchain.

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

# include <iostream>
# include <vector>
# include <random>

using namespace std;

# include <blockchain.H>


Transaction gen_transaction(mt19937_64 & rng)
{
  using ss_t = vector<string>;
  ss_t names = { "James", "Paul", "Bruce", "Steve", "Alex",
		 "Jason", "John", "Lars", "Tarja", "Floor",
		 "Thomas", "Rob", "Robert", "Mark", "Ferb" };

  using sss_t = ss_t::size_type;
  uniform_int_distribution<sss_t> unif0(0, names.size() - 1);
  uniform_int_distribution<sss_t> unif1(0, names.size() - 2);
  uniform_real_distribution<double> amount(10, 500);

  auto f = unif0(rng);
  auto s = unif1(rng);

  string fn = names[f];
  swap(names[f], names[names.size()-1]);
  string sn = names[s];

  return transaction(fn, sn, amount(rng));
}

Transaction pop(std::list<Transaction> & ts)
{
  auto t = ts.front();
  ts.pop_front();
  return t;
}

std::list<Transaction> popn(std::list<Transaction> & ts, int n)
{
  std::list<Transaction> ret;

  while (not ts.empty() and ret.size() < n)
    ret.push_back(pop(ts));

  return ret;
}

int main()
{
  mt19937_64 rng(time(0) % mt19937_64::max());

  std::list<Transaction> mempool;

  for (int i = 0; i < 50; ++i)
    mempool.push_back(gen_transaction(rng));

  Blockchain local_blockchain;

  cout << "Empty blockchain: " << local_blockchain.to_string() << "\n\n";

  while (not mempool.empty())
    {
      auto t = local_blockchain.add_block(popn(mempool, 3));

      cout << "Added block: " << get<1>(t)->to_string() << endl
	   << "Proof: " << get<0>(t) << endl;

      if (local_blockchain.is_valid())
	cout << "Blockchain is valid\n";
      else
	cout << "Blockchain is not valid\n";

      cout << endl;
    }

  cout << "Final blockchain: " << local_blockchain.to_string() << endl;
  
  return 0;
}
