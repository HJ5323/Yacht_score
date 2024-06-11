#pragma once
#include "afxdialogex.h"
#include <vector>
#include <algorithm>
#include <numeric>

// CYachtDice1Dlg dialog

class CYachtDice1Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CYachtDice1Dlg)

public:
	bool picture = true;
	CYachtDice1Dlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CYachtDice1Dlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YACHTDICE1_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
public:
	CImage back;

protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnBnClickedRoll();
	afx_msg HCURSOR OnQueryDragIcon();
	LRESULT OnUpdateDice(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

private:
	CButton m_btnPlayers[12]; // 모든 버튼을 담을 배열
	CBitmapButton* m_btnRoll;

	CString m_strData;

	CButton* pButton2, *pButton3, *pButton4, *pButton5, *pButton6;
	CButton* pButton7, *pButton8, *pButton9, *pButton10, *pButton11;


public:

	//vector<int> player_scores(12, -1); // 플레이어의 스코어를 저장하는 벡터

	CBitmapButton m_bitmapBtn;

	afx_msg void OnPaint();
	afx_msg void OnBnClickedTutorialBtn();

	void SetData(const CString& str);
	CFont m_font;


	CBitmapButton m_dice1;
	CBitmapButton m_dice2;
	CBitmapButton m_dice3;
	CBitmapButton m_dice4;
	CBitmapButton m_dice5;

	CButton m_showScore;
	CButton m_score1;
	CButton m_score2;
	CButton m_score3;
	CButton m_score4;
	CButton m_score5;

	CStatic m_p1Sub;
	CStatic m_p1Bonus;
	CStatic m_p1Total;
	CEdit m_p1[12];

	afx_msg void OnBnClickedDiceButton2();
	afx_msg void OnBnClickedDiceButton3();
	afx_msg void OnBnClickedDiceButton4();
	afx_msg void OnBnClickedDiceButton5();
	afx_msg void OnBnClickedDiceButton6();
	afx_msg void OnBnClickedDiceButton7();
	afx_msg void OnBnClickedDiceButton8();
	afx_msg void OnBnClickedDiceButton9();
	afx_msg void OnBnClickedDiceButton10();
	afx_msg void OnBnClickedDiceButton11();
	afx_msg void OnBnClickedChoosecategory();
//	int GetBitmapResourceID(CButton* button);
	void UpdateScoreBoard();

	void AdjustButtonToBitmap(CButton& button, HBITMAP hBitmap);
	afx_msg void OnBnClickedp1_1();
	afx_msg void OnBnClickedp1_2();
	afx_msg void OnBnClickedP1_3();
	afx_msg void OnBnClickedP1_4();
	afx_msg void OnBnClickedP1_5();
	afx_msg void OnBnClickedP1_6();
	afx_msg void OnBnClickedP1_7();
	afx_msg void OnBnClickedP1_8();
	afx_msg void OnBnClickedP1_9();
	afx_msg void OnBnClickedP1_10();
	afx_msg void OnBnClickedP1_11();
	afx_msg void OnBnClickedP1_12();
};
