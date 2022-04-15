nvcc main.cu classes/Block.cu classes/Blockchain.cu classes/sha256.cu -o TestChain 2> warning.log
time ./TestChain 