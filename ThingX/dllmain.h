// dllmain.h : Declaration of module class.

class CThingXModule : public ATL::CAtlDllModuleT< CThingXModule >
{
public :
	DECLARE_LIBID(LIBID_ThingXLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_THINGX, "{6A09AE49-F0EA-4DE5-8BCE-BCAA77C0DC0C}")
};

extern class CThingXModule _AtlModule;
