#pragma once
#include <string>
#include "Block.h"
#include "Configure.h"
#include "Utils.h"

namespace BlockNDN
{
	class CheckBlockUtils
	{
		Configure conf;
		Utils util;

	public:
		bool checkData(std::string s);
		bool checkBlockSize(Block block);
		bool checkPrevHash(std::vector<unsigned char> prevHash, Block block);
		bool NrawCheckProofOfWork(Block block);
	};
}


