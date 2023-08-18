#include <stdio.h>
#include <Windows.h>

void Func_Read_ini()
{
    char zeiss_params_path[] = "D:\\ProgramData2023\\EometricsEE3.0.2.90\\EometricsEE3.0.2.90\\Bin\\ConfigData\\EoTemp.ini";
    char rst[64] = {0};

    GetPrivateProfileString("SE", "SaveIntensity", "0", rst, 64, zeiss_params_path);

    printf("rst = %d", atoi(rst));
}

int main(int argc, char const *argv[])
{
    return 0;
}
