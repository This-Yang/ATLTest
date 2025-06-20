// Calculator.cpp : Calculator 的实现

#include "pch.h"
#include "Calculator.h"
#include <cmath>  // 用于数学运算检查

// Calculator

// 加法实现
STDMETHODIMP Calculator::Add(double a, double b, double* result)
{
    // 检查输出参数是否为空
    if (result == nullptr)
        return E_POINTER;  // 返回空指针错误

    // 执行加法运算
    *result = a + b;

    // 检查结果是否有效（防止溢出）
    if (!_finite(*result))
        return E_INVALIDARG;  // 返回无效参数错误

    return S_OK;  // 成功返回
}

// 减法实现
STDMETHODIMP Calculator::Subtract(double a, double b, double* result)
{
    if (result == nullptr)
        return E_POINTER;

    *result = a - b;

    if (!_finite(*result))
        return E_INVALIDARG;

    return S_OK;
}

// 乘法实现
STDMETHODIMP Calculator::Multiply(double a, double b, double* result)
{
    if (result == nullptr)
        return E_POINTER;

    *result = a * b;

    if (!_finite(*result))
        return E_INVALIDARG;

    return S_OK;
}

// 除法实现
STDMETHODIMP Calculator::Divide(double a, double b, double* result)
{
    if (result == nullptr)
        return E_POINTER;

    // 检查除数是否为零
    if (b == 0.0)
        return E_INVALIDARG;  // 除零错误

    *result = a / b;

    if (!_finite(*result))
        return E_INVALIDARG;

    return S_OK;
}