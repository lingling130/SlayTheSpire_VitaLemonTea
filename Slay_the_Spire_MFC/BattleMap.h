#pragma once


// CBattleMap dialog

class CBattleMap : public CDialogEx
{
	DECLARE_DYNAMIC(CBattleMap)

public:
	CBattleMap(CWnd* pParent = NULL);   // standard constructor
	virtual ~CBattleMap();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
