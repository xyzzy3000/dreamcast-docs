/* This header file machine-generated by mktyplib.exe */
/* Interface to type library: DifferentDesignerObjects */

#ifndef _DifferentDesignerObjects_H_
#define _DifferentDesignerObjects_H_

DEFINE_GUID(LIBID_DifferentDesignerObjects,0xCFA323D0L,0x97D0,0x11CF,0xA0,0xD2,0x00,0xAA,0x00,0x62,0xBE,0x57);
#ifndef BEGIN_INTERFACE
#define BEGIN_INTERFACE
#endif

DEFINE_GUID(IID_IDifferentDesigner,0xD0C700A0L,0x97D0,0x11CF,0xA0,0xD2,0x00,0xAA,0x00,0x62,0xBE,0x57);

/* Definition of interface: IDifferentDesigner */
#undef INTERFACE
#define INTERFACE IDifferentDesigner

DECLARE_INTERFACE_(IDifferentDesigner, IDispatch)
{
BEGIN_INTERFACE
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

    /* IDifferentDesigner methods */
    STDMETHOD(get_MyString)(THIS_ BSTR FAR* pbstrMyString) PURE;
    STDMETHOD(put_MyString)(THIS_ BSTR bstrMyString) PURE;
    STDMETHOD_(void, AboutBox)(THIS) PURE;
};

DEFINE_GUID(DIID_DDifferentDesignerEvents,0xD2096D30L,0x97D0,0x11CF,0xA0,0xD2,0x00,0xAA,0x00,0x62,0xBE,0x57);

/* Definition of dispatch interface: DDifferentDesignerEvents */
#undef INTERFACE
#define INTERFACE DDifferentDesignerEvents

DECLARE_INTERFACE_(DDifferentDesignerEvents, IDispatch)
{
BEGIN_INTERFACE
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif
};

DEFINE_GUID(CLSID_DifferentDesigner,0xD342AEA0L,0x97D0,0x11CF,0xA0,0xD2,0x00,0xAA,0x00,0x62,0xBE,0x57);

#ifdef __cplusplus
class DifferentDesigner;
#endif

#endif