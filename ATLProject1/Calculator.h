// Calculator.h : Calculator 的声明

#pragma once
#include "resource.h"       // main symbols
#include "ATLProject1_i.h"  // 包含生成的接口定义

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。"
#endif

using namespace ATL;

// Calculator
class ATL_NO_VTABLE Calculator :                    // ATL_NO_VTABLE优化虚函数表
    public CComObjectRootEx<CComSingleThreadModel>, // COM对象根类，单线程模型
    public CComCoClass<Calculator, &CLSID_Calculator>, // COM组件类支持
    public IDispatchImpl<ICalculator, &IID_ICalculator, &LIBID_ATLProject1Lib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
    Calculator()  // 构造函数
    {
    }

    DECLARE_REGISTRY_RESOURCEID(IDR_CALCULATOR)        // 声明注册表资源ID

    BEGIN_COM_MAP(Calculator)                          // 开始COM接口映射
        COM_INTERFACE_ENTRY(ICalculator)               // 添加ICalculator接口
        COM_INTERFACE_ENTRY(IDispatch)                 // 添加IDispatch接口
    END_COM_MAP()                                      // 结束COM接口映射

    DECLARE_PROTECT_FINAL_CONSTRUCT()             // 保护最终构造

        HRESULT FinalConstruct()                       // 最终构造函数
    {
        return S_OK;  // 成功返回
    }

    void FinalRelease()                            // 最终释放函数
    {
    }

public:
    // ICalculator接口的实现
    STDMETHOD(Add)(double a, double b, double* result);      // 加法实现声明
    STDMETHOD(Subtract)(double a, double b, double* result); // 减法实现声明
    STDMETHOD(Multiply)(double a, double b, double* result); // 乘法实现声明
    STDMETHOD(Divide)(double a, double b, double* result);   // 除法实现声明
};

OBJECT_ENTRY_AUTO(__uuidof(Calculator), Calculator)         // 自动对象入口宏