// BattleMap.cpp : implementation file
//

#include "stdafx.h"
#include "Slay_the_Spire_MFC.h"
#include "BattleMap.h"
#include "afxdialogex.h"


// CBattleMap dialog

IMPLEMENT_DYNAMIC(CBattleMap, CDialogEx)

CBattleMap::CBattleMap(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBattleMap::IDD, pParent)
{

}

CBattleMap::~CBattleMap()
{
}

void CBattleMap::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBattleMap, CDialogEx)
	ON_BN_CLICKED(IDOK, &CBattleMap::OnBnClickedOk)
END_MESSAGE_MAP()


// CBattleMap message handlers


void CBattleMap::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
