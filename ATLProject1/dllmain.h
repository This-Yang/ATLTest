// dllmain.h: 模块类的声明。

class CATLProject1Module : public ATL::CAtlDllModuleT< CATLProject1Module >
{
public :
	DECLARE_LIBID(LIBID_ATLProject1Lib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLPROJECT1, "{9bb09634-6743-4d98-a512-d8b66764f71c}")
};

extern class CATLProject1Module _AtlModule;
