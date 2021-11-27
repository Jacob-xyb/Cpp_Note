#include <iostream>
#include "torch/torch.h"
#include "torch/script.h"
#include "LibTorch.h"


int main()
{
    test_Jx();

    std::cout << "press [ENTER] to continue " << std::endl;
    std::cin.get();
    return 0;
}
