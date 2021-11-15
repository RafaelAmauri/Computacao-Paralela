gcc -lstdc++ -o TestChain -O3 -std=c++11 -x c++ main.cpp -fopenmp classes/Block.cpp classes/Blockchain.cpp classes/sha256.cpp
time ./TestChain
