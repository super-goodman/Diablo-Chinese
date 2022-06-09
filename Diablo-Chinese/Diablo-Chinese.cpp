// Diablo-Chinese.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Memory.h"
#include "Opcode.h"

bool scan(UINT64 startAddr, byte* buffer)
{

    int count = 0;
    //替换字符
    UINT32 zhCN = 0x4E43687A;
    std::cout << "替换开始(如果时间过长请重新尝试)" << std::endl;
    for (int i = 0; i < 260000; i++)
    {
        UINT64 addrTemp = startAddr + i * 102400;
        //随便显示下
        //std::cout << "进度" << i/ 260000.0*100<<std::endl;
        Memory::RM(addrTemp, 102400, buffer);
        for (int j = 0; j < 102400; j++)
        {
            if (buffer[j] == 0x65)
            {
                if (buffer[j + 1] == 0x6e && buffer[j + 2] == 0x55 && buffer[j + 3] == 0x53 && buffer[j + 16] == 0x20 && buffer[j + 17] == 0x2A)
                {
                    addrTemp = addrTemp + j;
                    count++;
                    std::cout << "替换成功" << std::hex << addrTemp << std::endl;
                    std::cout << "傻逼网易,有本事把游戏都删了,这都要修复。有本事把中文删除啊啊啊啊啊啊啊 啊啊" << std::endl;
                    Memory::W4(addrTemp, zhCN);
                    if (count >= 2000)
                    {
                        std::cout << "替换结束" << std::endl;
                        for (int k = 0; k < 5; k++)
                        {
                            //替换
                            std::cout << std::hex << addrTemp << std::endl;
                            //Memory::W4(addrTemp,zhCN);
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
    UINT64 addStart = mem->R8(mem->getGameModuleBase() + address[0] + 0x10);
    addStart = ((addStart >> 28) - 1) << 28;

    //用于存储内存
    byte* copyBuf = new byte[102400]{ 0 };
    //UINT64 of1 = mem->R8(mem->getGameModuleBase() + 0x3D62A60);
    //UINT64 of2 = mem->R8(of1 + 68);
    //UINT64 of3 = mem->R8(of2 + 188);
    //UINT64 of4 = mem->R8(of3 + 628);
    //UINT64 of5 = mem->R8(of4 + 28);
    ////UINT64 of6 = mem->R8(of5 + 0x188);
    ////UINT64 of7 = mem->R8(of6 + 0x628);
    ////UINT64 of8 = mem->R8(of7 + 0x28);
    //std::cout << std::hex << of1 << std::endl;
    //std::cout << std::hex << of2 << std::endl;   
    //std::cout << std::hex << of3 << std::endl;
    //std::cout << std::hex << of4 << std::endl;
    //std::cout << std::hex << of5 << std::endl;
    //std::cout << std::hex << of6 <<std::endl;
    //std::cout << std::hex << of7 << std::endl;
    //std::cout << std::hex << of8 << std::endl;
    //mem->W4(of4 +0x28, 0x4E43687A);
    //getchar();
    //std::cout <<std::hex<< mem->R8(mem->R8(mem->R8(mem->R8(mem->R8(mem->R8(mem->R8(mem->R8(mem->getGameModuleBase() + 0x3D7A958) + 0xEC0) + 0xF0) + 0x1E0) + 0x178) + 0x188) + 0x628) + 0x28);
    //开始遍历内存并替换
    scan(addStart, copyBuf);
    delete[] copyBuf;
    delete mem;
    delete opcode;
   // std::cout << "Hello World!\n";
}

