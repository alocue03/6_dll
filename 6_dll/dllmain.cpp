// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <string>
//6_dll

//declarar funciones expuestas
extern "C"
{
    //ejmplo de funcion sin parametros que retorna una cadena de texto
    __declspec(dllexport) const char* GetCodeName()
    {
        const char* msg = "Codename Aldo";
        return msg;
    }

    //funcion qu recibe 2 parametros y retorna un valor
    __declspec(dllexport) double Sumar(double a, double b)
    {
        return a + b;
    }
    __declspec(dllexport) std::string Concatenar(const std::string A, const std::string B)
    {
        return A + B;
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

