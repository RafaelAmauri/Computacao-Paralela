//
// Created by Dave Nash on 20/10/2017.
//

#include "../headers/Blockchain.h"

Blockchain::Blockchain(uint32_t nDifficulty)
{
    _vChain.emplace_back(Block(0, "Genesis Block"));
    _nDifficulty = nDifficulty;
}

void Blockchain::AddBlock(Block bNew)
{
    bNew.sPrevHash = _GetLastBlock().sHash;
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const
{
    return _vChain.back();
}
