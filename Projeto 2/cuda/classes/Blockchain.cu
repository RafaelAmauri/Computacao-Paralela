#include "../headers/Blockchain.cuh"

Blockchain::Blockchain(uint32_t nDifficulty)
{
	_vChain.emplace_back(new Block(0, "Genesis Block"));
	_nDifficulty = nDifficulty;
}

void Blockchain::AddBlock(Block* bNew)
{
	bNew->sPrevHash = _GetLastBlock()->GetHash();
	bNew->MineBlock(_nDifficulty);
	_vChain.push_back(bNew);
}

void Blockchain::PrintBlockchain()
{
	for (Block* bBlock : _vChain)
	{
		bBlock->PrintBlock();
	}
}

Block* Blockchain::_GetLastBlock() const
{
	return _vChain.back();
}