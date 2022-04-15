#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "headers/Blockchain.cuh"

#include <stdio.h>

using namespace std;

int main()
{
	uint32_t nDifficulty = 5;
	Blockchain bChain = Blockchain(nDifficulty);

	cout << "Mining block 1..." << endl;
	bChain.AddBlock(new Block(1, "Block 1 Data"));

	cout << "Mining block 2..." << endl;
	bChain.AddBlock(new Block(2, "Block 2 Data"));

	cout << "Mining block 3..." << endl;
	bChain.AddBlock(new Block(3, "Block 3 Data"));

	//bChain.PrintBlockchain();
	return 0;
}