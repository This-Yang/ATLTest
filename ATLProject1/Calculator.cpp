// Calculator.cpp : Calculator ��ʵ��

#include "pch.h"
#include "Calculator.h"
#include <cmath>  // ������ѧ������

// Calculator

// �ӷ�ʵ��
STDMETHODIMP Calculator::Add(double a, double b, double* result)
{
    // �����������Ƿ�Ϊ��
    if (result == nullptr)
        return E_POINTER;  // ���ؿ�ָ�����

    // ִ�мӷ�����
    *result = a + b;

    // ������Ƿ���Ч����ֹ�����
    if (!_finite(*result))
        return E_INVALIDARG;  // ������Ч��������

    return S_OK;  // �ɹ�����
}

// ����ʵ��
STDMETHODIMP Calculator::Subtract(double a, double b, double* result)
{
    if (result == nullptr)
        return E_POINTER;

    *result = a - b;

    if (!_finite(*result))
        return E_INVALIDARG;

    return S_OK;
}

// �˷�ʵ��
STDMETHODIMP Calculator::Multiply(double a, double b, double* result)
{
    if (result == nullptr)
        return E_POINTER;

    *result = a * b;

    if (!_finite(*result))
        return E_INVALIDARG;

    return S_OK;
}

// ����ʵ��
STDMETHODIMP Calculator::Divide(double a, double b, double* result)
{
    if (result == nullptr)
        return E_POINTER;

    // �������Ƿ�Ϊ��
    if (b == 0.0)
        return E_INVALIDARG;  // �������

    *result = a / b;

    if (!_finite(*result))
        return E_INVALIDARG;

    return S_OK;
}