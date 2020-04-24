#pragma once
#include "stdafx.h"
#include "BaseMapper.h"

class NROM : public BaseMapper
{
	protected:
		virtual uint16_t GetPRGPageSize() override { return 0x4000; }
		virtual uint16_t GetCHRPageSize() override {	return 0x2000; }

		virtual void InitMapper() override
		{
			SelectPRGPage(0, 0);
			SelectPRGPage(1, 1);

			SelectCHRPage(0, 0);
			uint8_t* ptr = _prgPages[0xff];
			uint64_t sum = 0;
			for (int i = 0; i < 256; i++)
			{
				sum += ptr[i];
				std::cout << i << " " << (int)ptr[i] << std::endl;
			}
			std::cout << "sum is " << sum << std::endl;
		}
};
