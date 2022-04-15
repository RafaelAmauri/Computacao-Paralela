#include <cstdint>
#include <sstream>
#include <iostream>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

using namespace std;

class Block
{
public:
	Block(uint32_t nIndexIn, const string& sDataIn);

	string sPrevHash;

	string& GetHash();

	void hostRandomGen(unsigned long long* x);

	int MineBlock(uint32_t nDifficulty);

	void PrintBlock();

private:
	uint32_t _nIndex;
	string _sNonce;
	string _sData;
	string _sHash;
	time_t _tTime;

	inline string _CalculateHash() const;
};