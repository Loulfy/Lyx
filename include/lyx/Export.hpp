//
// Created by loulfy on 22/09/16.
//

#ifndef LYX_EXPORT_HPP
#define LYX_EXPORT_HPP

#ifdef _WIN64
#ifdef BUILDING_LYX_DLL
        #define API_LYX __declspec(dllexport)
    #else
        #define API_LYX
    #endif
#else
#define API_LYX
#endif

#endif //LYX_EXPORT_HPP
