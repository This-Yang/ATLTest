// Calculator.h : Calculator ������

#pragma once
#include "resource.h"       // main symbols
#include "ATLProject1_i.h"  // �������ɵĽӿڶ���

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ����"
#endif

using namespace ATL;

// Calculator
class ATL_NO_VTABLE Calculator :                    // ATL_NO_VTABLE�Ż��麯����
    public CComObjectRootEx<CComSingleThreadModel>, // COM������࣬���߳�ģ��
    public CComCoClass<Calculator, &CLSID_Calculator>, // COM�����֧��
    public IDispatchImpl<ICalculator, &IID_ICalculator, &LIBID_ATLProject1Lib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
    Calculator()  // ���캯��
    {
    }

    DECLARE_REGISTRY_RESOURCEID(IDR_CALCULATOR)        // ����ע�����ԴID

    BEGIN_COM_MAP(Calculator)                          // ��ʼCOM�ӿ�ӳ��
        COM_INTERFACE_ENTRY(ICalculator)               // ���ICalculator�ӿ�
        COM_INTERFACE_ENTRY(IDispatch)                 // ���IDispatch�ӿ�
    END_COM_MAP()                                      // ����COM�ӿ�ӳ��

    DECLARE_PROTECT_FINAL_CONSTRUCT()             // �������չ���

        HRESULT FinalConstruct()                       // ���չ��캯��
    {
        return S_OK;  // �ɹ�����
    }

    void FinalRelease()                            // �����ͷź���
    {
    }

public:
    // ICalculator�ӿڵ�ʵ��
    STDMETHOD(Add)(double a, double b, double* result);      // �ӷ�ʵ������
    STDMETHOD(Subtract)(double a, double b, double* result); // ����ʵ������
    STDMETHOD(Multiply)(double a, double b, double* result); // �˷�ʵ������
    STDMETHOD(Divide)(double a, double b, double* result);   // ����ʵ������
};

OBJECT_ENTRY_AUTO(__uuidof(Calculator), Calculator)         // �Զ�������ں�