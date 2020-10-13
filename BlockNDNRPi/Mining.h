#pragma once
#include "CheckBlock.h"

namespace BlockNDN
{
	class Mining : public CheckBlock
	{
	private:
		Block block;
		bool result;
		Configure conf;
	public:
		Mining();
		Mining(std::vector<unsigned char> prevHash);
		bool createNewBlock(std::string txt);
		bool miningBlock();
		Block getMiningBlock();
		bool getResult();
		bool isBlockLegal(Block block, std::vector<unsigned char> prevBlockHash);
	};
}
