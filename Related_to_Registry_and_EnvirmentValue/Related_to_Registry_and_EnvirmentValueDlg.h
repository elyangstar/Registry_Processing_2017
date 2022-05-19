
// Related_to_Registry_and_EnvirmentValueDlg.h: 헤더 파일
//

#pragma once


// CRelatedtoRegistryandEnvirmentValueDlg 대화 상자
class CRelatedtoRegistryandEnvirmentValueDlg : public CDialog
{
// 생성입니다.
public:
	CRelatedtoRegistryandEnvirmentValueDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RELATED_TO_REGISTRY_AND_ENVIRMENTVALUE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCreateFolder();


	CString m_strRegistryPath;
	HKEY	m_hRegKey;

	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButtonNewCreate();
	CString m_strItemName;
	CString m_strItemValue;
	CString m_strRegistryRead;
	afx_msg void OnBnClickedButtonRead();
	CString m_strRegistryName2;
	afx_msg void OnBnClickedButtonModifyPath();
	CString m_strRegiModifyPath;
	afx_msg void OnBnClickedButtonDeletePath();
	afx_msg void OnBnClickedButtonClose();
	CString m_strEnvirName;
	CString m_strEnvirValue;
	afx_msg void OnBnClickedButtonReadEnvirvalue();
	CString m_strModifyEnvirValue;
	afx_msg void OnBnClickedButtonReadEnvirvalue2();
	CString m_strRefreshData;
	afx_msg void OnBnClickedButtonReadEnvirvalue3();
};
