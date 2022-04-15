num_blocks="${1}"
difficulty="${2}"

gcc -lstdc++ -o TestChain -std=c++11 -x c++ main.cpp classes/Block.cpp classes/Blockchain.cpp classes/sha256.cpp
time ./TestChain "${num_blocks}" "${difficulty}"
