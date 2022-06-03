// Diablo-Chinese.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Memory.h"
#include "Opcode.h"

bool scan(UINT64 startAddr,byte* buffer)
{
    int count = 0;
    //替换字符
    UINT32 zhCN = 0x4E43687A;
    std::cout << "替换开始(如果时间过长请重新尝试)" << std::endl;
    for (int i = 0; i < 260000; i++)
    {
        UINT64 addrTemp = startAddr + i * 102400;
        //随便显示下
        std::cout << "进度" << i/ 260000.0*100<<std::endl;
        Memory::RM(addrTemp, 102400, buffer);
        for (int j = 0; j < 102400; j++)
        {
            //寻找符合"itIT"的字符串
            if (buffer[j] == 0x69)
            {
                if (buffer[j + 1] == 0x74 && buffer[j + 2] == 0x49 && buffer[j + 3] == 0x54)
                {
                    addrTemp = addrTemp + j;
                    count++;
                    std::cout << "替换成功" << std::hex << count << std::endl;
         
                    if (count >= 1)
                    {
                        std::cout << "替换结束" << std::endl;
                        for (int k = 0; k < 5; k++)
                        {
                            //替换
                            Memory::W4(addrTemp,zhCN);
                            std::cout << "请切换语言为Itali" << std::endl;
                         
                        }
                        getchar();
                        return true;
                    }

                }

            }
        }
    }
    return false;
}



int main()
{
    UINT64 address[30] = { 0 };
    auto mem = new Memory();
    auto opcode = new Opcode(Memory::pid);
    //随便找个特征码目的是缩短寻找地址的时间
	opcode->findBaseAddressOffset("48 8B ?? ?? ?? ?? ?? 45 33 C9 48 8B CD 4D 8B C3 49 8B D2", address, 3, 4);
	UINT64 addStart = mem->R8(mem->getGameModuleBase()+ address[0] +0x10);
	addStart = ((addStart >> 28) - 1) << 28;

    //用于存储内存
    byte *copyBuf=new byte[102400]{0};

    //开始遍历内存并替换
    scan(addStart, copyBuf);
    delete[] copyBuf;
	delete mem;
    delete opcode;
    std::cout << "Hello World!\n";
}

