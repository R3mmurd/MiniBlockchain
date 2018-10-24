CXX = clang++ -std=c++14 -Ofast

default: demo

demo: sha256.o datetime.o transaction.o block.H blockchain.o demo.C
	$(CXX) -I. $@.C -o $@ sha256.o datetime.o transaction.o blockchain.o

sha256.o: sha256.H sha256.C
	$(CXX) -c -I. sha256.C

datetime.o: datetime.H datetime.C
	$(CXX) -c -I. datetime.C

transaction.o: transaction.H transaction.C
	$(CXX) -c -I. transaction.C

blockchain.o: blockchain.H blockchain.C
	$(CXX) -c -I. blockchain.C

clean:
	$(RM) *~ *.o demo
