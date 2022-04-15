#include <cstdint>
#include <vector>
#include "Block.cuh"

using namespace std;

class Blockchain
{
public:
	Blockchain(uint32_t nDifficulty);

	void AddBlock(Block* bNew);

	void PrintBlockchain();

private:
	uint32_t _nDifficulty;
	vector<Block*> _vChain;

	Block* _GetLastBlock() const;
};