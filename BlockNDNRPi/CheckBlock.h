#pragma once

#include "Block.h"

namespace BlockNDN
{

	class CheckBlock
	{
	public:
		bool isBlockLegal(Block block, std::vector<unsigned char> prevBlockHash);
	};
}


