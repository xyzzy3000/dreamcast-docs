// candlg.h : interface of the CCancelDlg class

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) 1992-1998 Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/////////////////////////////////////////////////////////////////////////////
// CCancelDlg dialog

class CCancelDlg : public CDialog
{
// Construction
public:
	CCancelDlg(CWnd* pParent = NULL);   // standard constructor

	virtual void OnCancel();

// Dialog Data
	//{{AFX_DATA(CCancelDlg)
	enum { IDD = IDD_CANCELDLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCancelDlg)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCancelDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
