// YachtDice1Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "YachtDicePrototype2.h"
#include "afxdialogex.h"
#include <afxwin.h> // MFC 윈도우 및 컨트롤 클래스에 대한 기본 헤더 파일
#include <atlimage.h> // CImage 클래스와 관련된 헤더 파일
#include "YachtDice1Dlg.h"
#include "resource.h" 
#include "CTutorial.h"

#include <Windows.h>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

bool arr[5] = { 1,1,1,1,1 };
vector<int> dice_result;

// CYachtDice1Dlg dialog

IMPLEMENT_DYNAMIC(CYachtDice1Dlg, CDialogEx)

CYachtDice1Dlg::CYachtDice1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_YACHTDICE1_DIALOG, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CYachtDice1Dlg::~CYachtDice1Dlg()
{
}

void CYachtDice1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TUTORIAL_BTN, m_bitmapBtn);


    DDX_Control(pDX, IDC_DICE_BUTTON2, m_dice1);
    DDX_Control(pDX, IDC_DICE_BUTTON3, m_dice2);
    DDX_Control(pDX, IDC_DICE_BUTTON4, m_dice3);
    DDX_Control(pDX, IDC_DICE_BUTTON5, m_dice4);
    DDX_Control(pDX, IDC_DICE_BUTTON6, m_dice5);

    DDX_Control(pDX, IDC_DICE_BUTTON7, m_score1);
    DDX_Control(pDX, IDC_DICE_BUTTON8, m_score2);
    DDX_Control(pDX, IDC_DICE_BUTTON9, m_score3);
    DDX_Control(pDX, IDC_DICE_BUTTON10, m_score4);
    DDX_Control(pDX, IDC_DICE_BUTTON11, m_score5);

    // 컨트롤과 멤버 변수를 연결
    DDX_Control(pDX, IDC_p1_sub, m_p1Sub);
    DDX_Control(pDX, IDC_p1_bonus, m_p1Bonus);
    DDX_Control(pDX, IDC_p1_total, m_p1Total);
    for (int i = 0; i < 12; i++) {
        DDX_Control(pDX, IDC_p1_1 + i, m_p1[i]);
    }
}


BEGIN_MESSAGE_MAP(CYachtDice1Dlg, CDialogEx)
    ON_WM_CTLCOLOR()
    ON_WM_DRAWITEM()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_Roll, &CYachtDice1Dlg::OnBnClickedRoll)
    ON_WM_PAINT()
    ON_BN_CLICKED(IDC_TUTORIAL_BTN, &CYachtDice1Dlg::OnBnClickedTutorialBtn)


    ON_MESSAGE(WM_USER + 1, &CYachtDice1Dlg::OnUpdateDice)
    ON_BN_CLICKED(IDC_DICE_BUTTON2, &CYachtDice1Dlg::OnBnClickedDiceButton2)
    ON_BN_CLICKED(IDC_DICE_BUTTON3, &CYachtDice1Dlg::OnBnClickedDiceButton3)
    ON_BN_CLICKED(IDC_DICE_BUTTON4, &CYachtDice1Dlg::OnBnClickedDiceButton4)
    ON_BN_CLICKED(IDC_DICE_BUTTON5, &CYachtDice1Dlg::OnBnClickedDiceButton5)
    ON_BN_CLICKED(IDC_DICE_BUTTON6, &CYachtDice1Dlg::OnBnClickedDiceButton6)
    ON_BN_CLICKED(IDC_DICE_BUTTON7, &CYachtDice1Dlg::OnBnClickedDiceButton7)
    ON_BN_CLICKED(IDC_DICE_BUTTON8, &CYachtDice1Dlg::OnBnClickedDiceButton8)
    ON_BN_CLICKED(IDC_DICE_BUTTON9, &CYachtDice1Dlg::OnBnClickedDiceButton9)
    ON_BN_CLICKED(IDC_DICE_BUTTON10, &CYachtDice1Dlg::OnBnClickedDiceButton10)
    ON_BN_CLICKED(IDC_DICE_BUTTON11, &CYachtDice1Dlg::OnBnClickedDiceButton11)
    ON_BN_CLICKED(IDC_ChooseCategory, &CYachtDice1Dlg::OnBnClickedChoosecategory)
    ON_BN_CLICKED(IDC_p1_1, &CYachtDice1Dlg::OnBnClickedp1_1)
    ON_BN_CLICKED(IDC_p1_2, &CYachtDice1Dlg::OnBnClickedp1_2)
    ON_BN_CLICKED(IDC_p1_3, &CYachtDice1Dlg::OnBnClickedP1_3)
    ON_BN_CLICKED(IDC_p1_4, &CYachtDice1Dlg::OnBnClickedP1_4)
    ON_BN_CLICKED(IDC_p1_5, &CYachtDice1Dlg::OnBnClickedP1_5)
    ON_BN_CLICKED(IDC_p1_6, &CYachtDice1Dlg::OnBnClickedP1_6)
    ON_BN_CLICKED(IDC_p1_7, &CYachtDice1Dlg::OnBnClickedP1_7)
    ON_BN_CLICKED(IDC_p1_8, &CYachtDice1Dlg::OnBnClickedP1_8)
    ON_BN_CLICKED(IDC_p1_9, &CYachtDice1Dlg::OnBnClickedP1_9)
    ON_BN_CLICKED(IDC_p1_10, &CYachtDice1Dlg::OnBnClickedP1_10)
    ON_BN_CLICKED(IDC_p1_11, &CYachtDice1Dlg::OnBnClickedP1_11)
    ON_BN_CLICKED(IDC_p1_12, &CYachtDice1Dlg::OnBnClickedP1_12)
END_MESSAGE_MAP()


// CYachtDice1Dlg message handlers

BOOL CYachtDice1Dlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // Set the icon for this dialog.  The framework does this automatically
    //  when the application's main window is not a dialog
    SetIcon(m_hIcon, TRUE);			// Set big icon
    SetIcon(m_hIcon, FALSE);		// Set small icon


    // TODO: Add extra initialization here
    pButton2 = (CButton*)GetDlgItem(IDC_DICE_BUTTON2);
    pButton3 = (CButton*)GetDlgItem(IDC_DICE_BUTTON3);
    pButton4 = (CButton*)GetDlgItem(IDC_DICE_BUTTON4);
    pButton5 = (CButton*)GetDlgItem(IDC_DICE_BUTTON5);
    pButton6 = (CButton*)GetDlgItem(IDC_DICE_BUTTON6);
    pButton7 = (CButton*)GetDlgItem(IDC_DICE_BUTTON7);
    pButton8 = (CButton*)GetDlgItem(IDC_DICE_BUTTON8);
    pButton9 = (CButton*)GetDlgItem(IDC_DICE_BUTTON9);
    pButton10 = (CButton*)GetDlgItem(IDC_DICE_BUTTON10);
    pButton11 = (CButton*)GetDlgItem(IDC_DICE_BUTTON11);

    pButton7->EnableWindow(FALSE);
    pButton8->EnableWindow(FALSE);
    pButton9->EnableWindow(FALSE);
    pButton10->EnableWindow(FALSE);
    pButton11->EnableWindow(FALSE);

    back.Load(_T("GameBoard_Background.png"));
    
    // 닉네임
    m_font.CreatePointFont(130, _T("Ravie"));
    GetDlgItem(IDC_STATIC_NAME)->SetFont(&m_font);
    GetDlgItem(IDC_STATIC_NAME2)->SetFont(&m_font);
    SetDlgItemText(IDC_STATIC_NAME, m_strData);

    // 모든 버튼에 owner draw 스타일 적용
    for (int i = IDC_p1_1; i <= IDC_p1_12; i++)
    {
        m_btnPlayers[i - IDC_p1_1].SubclassDlgItem(i, this);
        m_btnPlayers[i - IDC_p1_1].ModifyStyle(0, BS_OWNERDRAW);
        m_btnPlayers[i - IDC_p1_1].EnableWindow(FALSE); // 초기에 비활성화
    }

    return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

HBRUSH CYachtDice1Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

    // 모든 버튼의 배경을 투명하게 설정
    if (nCtlColor == CTLCOLOR_BTN)
    {
        pDC->SetBkMode(TRANSPARENT);
        return (HBRUSH)GetStockObject(NULL_BRUSH);
    }

    if (nCtlColor == CTLCOLOR_STATIC)
    {
        // Picture Control의 배경을 투명하게 설정
        if (pWnd->GetDlgCtrlID() >= IDC_Dices_1 && pWnd->GetDlgCtrlID() <= IDC_Dices_5)
        {
            pDC->SetBkMode(TRANSPARENT);
            return (HBRUSH)GetStockObject(NULL_BRUSH);
        }
    }

    if (nCtlColor == CTLCOLOR_STATIC)
    {
        // Static text의 배경색을 투명하게 설정
        pDC->SetBkMode(TRANSPARENT);
        return (HBRUSH)GetStockObject(NULL_BRUSH);
    }

    return hbr;
}

void CYachtDice1Dlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    // 모든 버튼을 그리는 코드
    for (int i = IDC_p1_1; i <= IDC_p1_12; i++)
    {
        if (nIDCtl == i)
        {
            CDC dc;
            dc.Attach(lpDrawItemStruct->hDC);

            // 버튼의 영역 설정
            CRect rect(lpDrawItemStruct->rcItem);

            // 버튼의 배경을 투명하게 설정
            dc.SetBkMode(TRANSPARENT);

            // 버튼의 텍스트 출력
            CString strText;
            m_btnPlayers[i - IDC_p1_1].GetWindowText(strText);
            dc.DrawText(strText, rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            dc.Detach();
            return;
        }
    }

}

// 비트맵 리소스를 로드하는 함수
HBITMAP LoadBitmapFromResource(HINSTANCE hInstance, int resourceID) {
    return LoadBitmap(hInstance, MAKEINTRESOURCE(resourceID));

}

vector<int> RemoveArr(int idx) {
    vector<int> vec = { 0,1,2,3,4 };

    vec.erase(vec.begin() + idx);

    return vec;
}

void CYachtDice1Dlg::OnBnClickedRoll()
{
    vector<int> indices = { IDB_dice_1, IDB_dice_2, IDB_dice_3, IDB_dice_4, IDB_dice_5, IDB_dice_6 };

    //random_shuffle(indices.begin(), indices.end());

    HINSTANCE hInstance = GetModuleHandle(nullptr);

    for (int j = 0; j < 5; ++j) {
        int i = rand() % 6;
        HBITMAP hBitmap = LoadBitmapFromResource(hInstance, indices[i]);
        if (hBitmap == nullptr) {
            AfxMessageBox(_T("Failed to load bitmap!"));
            return;
        }
        if (arr[j] == 1) {
            PostMessage(WM_USER + 1, j, reinterpret_cast<LPARAM>(hBitmap));
            CString scoreStr;
            scoreStr.Format(_T("%d"), indices[i]);
            switch (j) {
            case 0:
                m_score1.SetWindowText(scoreStr);
                break;
            case 1:
                m_score2.SetWindowText(scoreStr);
                break;
            case 2:
                m_score3.SetWindowText(scoreStr);
                break;
            case 3:
                m_score4.SetWindowText(scoreStr);
                break;
            case 4:
                m_score5.SetWindowText(scoreStr);
                break;
            }

        }

    }

    pButton2->ShowWindow(SW_SHOW);
    pButton3->ShowWindow(SW_SHOW);
    pButton4->ShowWindow(SW_SHOW);
    pButton5->ShowWindow(SW_SHOW);
    pButton6->ShowWindow(SW_SHOW);

}

void CYachtDice1Dlg::AdjustButtonToBitmap(CButton& button, HBITMAP hBitmap)
{
    BITMAP bm;
    GetObject(hBitmap, sizeof(BITMAP), &bm);
    button.SetBitmap(hBitmap);
    //button.SetWindowPos(nullptr, 0, 0, 200, 200, SWP_NOMOVE | SWP_NOZORDER);
}

LRESULT CYachtDice1Dlg::OnUpdateDice(WPARAM wParam, LPARAM lParam)
{
    int diceIndex = static_cast<int>(wParam);
    HBITMAP hBitmap = reinterpret_cast<HBITMAP>(lParam);

    switch (diceIndex)
    {
    case 0:
        AdjustButtonToBitmap(m_dice1, hBitmap);
        break;

    case 1:
        AdjustButtonToBitmap(m_dice2, hBitmap);
        break;

    case 2:
        AdjustButtonToBitmap(m_dice3, hBitmap);
        break;

    case 3:
        AdjustButtonToBitmap(m_dice4, hBitmap);
        break;

    case 4:
        AdjustButtonToBitmap(m_dice5, hBitmap);
        break;
    }

    return 0;
}


// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CYachtDice1Dlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}



void CYachtDice1Dlg::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO: Add your message handler code here
    // Do not call CDialogEx::OnPaint() for painting messages

    CRect rect;//픽쳐 컨트롤의 크기를 저장할 CRect 객체
    GetClientRect(&rect);
    //m_picture_control.GetWindowRect(rect);//GetWindowRect를 사용해서 픽쳐 컨트롤의 크기를 받는다.
    //CDC* dc; //픽쳐 컨트롤의 DC를 가져올  CDC 포인터
    //dc = m_picture_control.GetDC(); //픽쳐 컨트롤의 DC를 얻는다.

    back.StretchBlt(dc.m_hDC, 0, 0, rect.Width(), rect.Height(), SRCCOPY);//이미지를 픽쳐 컨트롤 크기로 조정
}

void CYachtDice1Dlg::OnBnClickedTutorialBtn()
{
    // TODO: Add your control notification handler code here
    CTutorial dlgT;
    dlgT.DoModal();
}

void CYachtDice1Dlg::SetData(const CString& strData)
{
    m_strData = strData;
}

void CYachtDice1Dlg::OnBnClickedDiceButton2()
{
    // TODO: Add your control notification handler code here
    // 버튼 2에서 이미지를 추출합니다.
    HBITMAP hBitmap = (HBITMAP)pButton2->SendMessage(BM_GETIMAGE, IMAGE_BITMAP, 0);

    // 버튼 7에 이미지를 설정합니다.
    pButton7->SetBitmap(hBitmap);

    // 버튼 2에 있는 이미지를 삭제합니다.
    pButton2->SetBitmap(nullptr);
    arr[0] = false;

    pButton2->EnableWindow(FALSE);
    pButton7->EnableWindow(TRUE);
}


void CYachtDice1Dlg::OnBnClickedDiceButton3()
{
    // TODO: Add your control notification handler code here
     // 버튼 3에서 이미지를 추출합니다.
    HBITMAP hBitmap = (HBITMAP)pButton3->SendMessage(BM_GETIMAGE, IMAGE_BITMAP, 0);

    // 버튼 8에 이미지를 설정합니다.
    pButton8->SetBitmap(hBitmap);

    // 버튼 3에 있는 이미지를 삭제합니다.
    pButton3->SetBitmap(nullptr);
    arr[1] = false;

    pButton3->EnableWindow(FALSE);
    pButton8->EnableWindow(TRUE);
}


void CYachtDice1Dlg::OnBnClickedDiceButton4()
{
    // TODO: Add your control notification handler code here
    // 버튼 4에서 이미지를 추출합니다.
    HBITMAP hBitmap = (HBITMAP)pButton4->SendMessage(BM_GETIMAGE, IMAGE_BITMAP, 0);

    // 버튼 9에 이미지를 설정합니다.
    pButton9->SetBitmap(hBitmap);

    // 버튼 4에 있는 이미지를 삭제합니다.
    pButton4->SetBitmap(nullptr);
    arr[2] = false;

    pButton4->EnableWindow(FALSE);
    pButton9->EnableWindow(TRUE);
}


void CYachtDice1Dlg::OnBnClickedDiceButton5()
{
    // TODO: Add your control notification handler code here
    // 버튼 5에서 이미지를 추출합니다.
    HBITMAP hBitmap = (HBITMAP)pButton5->SendMessage(BM_GETIMAGE, IMAGE_BITMAP, 0);

    // 버튼 10에 이미지를 설정합니다.
    pButton10->SetBitmap(hBitmap);

    // 버튼 5에 있는 이미지를 삭제합니다.
    pButton5->SetBitmap(nullptr);
    arr[3] = false;

    pButton5->EnableWindow(FALSE);
    pButton10->EnableWindow(TRUE);
}


void CYachtDice1Dlg::OnBnClickedDiceButton6()
{
    // TODO: Add your control notification handler code here
    // 버튼 6에서 이미지를 추출합니다.
    HBITMAP hBitmap = (HBITMAP)pButton6->SendMessage(BM_GETIMAGE, IMAGE_BITMAP, 0);

    // 버튼 11에 이미지를 설정합니다.
    pButton11->SetBitmap(hBitmap);

    // 버튼 6에 있는 이미지를 삭제합니다.
    pButton6->SetBitmap(nullptr);
    arr[4] = false;

    pButton6->EnableWindow(FALSE);
    pButton11->EnableWindow(TRUE);
}


void CYachtDice1Dlg::OnBnClickedDiceButton7()
{
    pButton2->EnableWindow(TRUE);

    // TODO: Add your control notification handler code here
    // 버튼 7에서 이미지를 추출합니다.
    HBITMAP hBitmap = (HBITMAP)pButton7->SendMessage(BM_GETIMAGE, IMAGE_BITMAP, 0);

    // 버튼 2에 이미지를 설정합니다.
    pButton2->SetBitmap(hBitmap);

    // 버튼 7에 있는 이미지를 삭제합니다.
    pButton7->SetBitmap(nullptr);
    arr[0] = true;

    CString str;
    pButton7->GetWindowText(str);

    pButton7->EnableWindow(FALSE);
}


void CYachtDice1Dlg::OnBnClickedDiceButton8()
{
    pButton3->EnableWindow(TRUE);

    // TODO: Add your control notification handler code here
    // 버튼 8에서 이미지를 추출합니다.
    HBITMAP hBitmap = (HBITMAP)pButton8->SendMessage(BM_GETIMAGE, IMAGE_BITMAP, 0);

    // 버튼 3에 이미지를 설정합니다.
    pButton3->SetBitmap(hBitmap);

    // 버튼 8에 있는 이미지를 삭제합니다.
    pButton8->SetBitmap(nullptr);
    arr[1] = true;

    CString str;
    pButton8->GetWindowText(str);

    pButton8->EnableWindow(FALSE);
}


void CYachtDice1Dlg::OnBnClickedDiceButton9()
{
    pButton4->EnableWindow(TRUE);

    // TODO: Add your control notification handler code here
    // 버튼 9에서 이미지를 추출합니다.
    HBITMAP hBitmap = (HBITMAP)pButton9->SendMessage(BM_GETIMAGE, IMAGE_BITMAP, 0);

    // 버튼 4에 이미지를 설정합니다.
    pButton4->SetBitmap(hBitmap);

    // 버튼 9에 있는 이미지를 삭제합니다.
    pButton9->SetBitmap(nullptr);
    arr[2] = true;

    CString str;
    pButton9->GetWindowText(str);

    pButton9->EnableWindow(FALSE);
}


void CYachtDice1Dlg::OnBnClickedDiceButton10()
{
    pButton5->EnableWindow(TRUE);

    // TODO: Add your control notification handler code here
    // 버튼 10에서 이미지를 추출합니다.
    HBITMAP hBitmap = (HBITMAP)pButton10->SendMessage(BM_GETIMAGE, IMAGE_BITMAP, 0);

    // 버튼 5에 이미지를 설정합니다.
    pButton5->SetBitmap(hBitmap);

    // 버튼 10에 있는 이미지를 삭제합니다.
    pButton10->SetBitmap(nullptr);
    arr[3] = true;

    CString str;
    pButton10->GetWindowText(str);

    pButton10->EnableWindow(FALSE);
}


void CYachtDice1Dlg::OnBnClickedDiceButton11()
{
    pButton6->EnableWindow(TRUE);

    // TODO: Add your control notification handler code here
    // 버튼 11에서 이미지를 추출합니다.
    HBITMAP hBitmap = (HBITMAP)pButton11->SendMessage(BM_GETIMAGE, IMAGE_BITMAP, 0);

    // 버튼 6에 이미지를 설정합니다.
    pButton6->SetBitmap(hBitmap);

    // 버튼 11에 있는 이미지를 삭제합니다.
    pButton11->SetBitmap(nullptr);
    arr[4] = true;

    CString str;
    pButton11->GetWindowText(str);

    pButton11->EnableWindow(FALSE);
}

//void CYachtDice1Dlg::OnBnClickedChoosecategory()
//{
//    // dice_result 벡터를 비웁니다.
//    dice_result.clear();
//
//    // pButton7에서 비트맵의 상수 ID를 가져와서 dice_result에 추가합니다.
//    int id7 = GetBitmapResourceID(pButton7);
//    CString str7;
//    pButton7->GetWindowText(str7);
//    // CString을 정수로 변환합니다.
//    int Button7Value = _wtoi(str7);
//    // 변환된 정수 값에 139를 뺀 후, 결과를 dice_result 벡터에 추가합니다.
//    dice_result.push_back(Button7Value - 139);
//
//
//    // pButton8에서 비트맵의 상수 ID를 가져와서 dice_result에 추가합니다.
//    int id8 = GetBitmapResourceID(pButton8);
//    CString str8;
//    pButton8->GetWindowText(str8);
//    int Button8Value = _wtoi(str8);
//    dice_result.push_back(Button8Value - 139);
//
//    // pButton9에서 비트맵의 상수 ID를 가져와서 dice_result에 추가합니다.
//    int id9 = GetBitmapResourceID(pButton9);
//    CString str9;
//    pButton9->GetWindowText(str9);
//    int Button9Value = _wtoi(str9);
//    dice_result.push_back(Button9Value - 139);
//
//    // pButton10에서 비트맵의 상수 ID를 가져와서 dice_result에 추가합니다.
//    int id10 = GetBitmapResourceID(pButton10);
//    CString str10;
//    pButton10->GetWindowText(str10);
//    int Button10Value = _wtoi(str10);
//    dice_result.push_back(Button10Value - 139);
//
//    // pButton11에서 비트맵의 상수 ID를 가져와서 dice_result에 추가합니다.
//    int id11 = GetBitmapResourceID(pButton11);
//    CString str11;
//    pButton11->GetWindowText(str11);
//    int Button11Value = _wtoi(str11);
//    dice_result.push_back(Button11Value - 139);
//
//    //// 모든 버튼에 있던 비트맵을 삭제합니다.
//    //pButton7->SetBitmap(nullptr);
//    //pButton8->SetBitmap(nullptr);
//    //pButton9->SetBitmap(nullptr);
//    //pButton10->SetBitmap(nullptr);
//    //pButton11->SetBitmap(nullptr);
//}

void CYachtDice1Dlg::OnBnClickedChoosecategory()
{
    // dice_result 벡터를 비웁니다.
    dice_result.clear();

    OnBnClickedDiceButton2();
    OnBnClickedDiceButton3();
    OnBnClickedDiceButton4();
    OnBnClickedDiceButton5();
    OnBnClickedDiceButton6();
         
    CString str7;
    pButton7->GetWindowText(str7);
    int Button7Value = _wtoi(str7);
    dice_result.push_back(Button7Value - 139);
     
    CString str8;
    pButton8->GetWindowText(str8);
    int Button8Value = _wtoi(str8);
    dice_result.push_back(Button8Value - 139);

    CString str9;
    pButton9->GetWindowText(str9);
    int Button9Value = _wtoi(str9);
    dice_result.push_back(Button9Value - 139);

    CString str10;
    pButton10->GetWindowText(str10);
    int Button10Value = _wtoi(str10);
    dice_result.push_back(Button10Value - 139);

    CString str11;
    pButton11->GetWindowText(str11);
    int Button11Value = _wtoi(str11);
    dice_result.push_back(Button11Value - 139);
}

void CYachtDice1Dlg::OnBnClickedp1_1()
{
    // 주사위 결과를 업데이트
    //UpdateDiceResultVector();

    // 주사위에서 숫자 1의 개수를 계산
    int countOfOnes = 0;
    for (int die : dice_result) {
        if (die == 1) {
            countOfOnes++;
        }
    }

    // p1_1 버튼에 해당 계산식 적용하여 결과 출력
    int score = countOfOnes * 1; // 숫자 1의 개수에 1을 곱한 값
    CString strScore;
    strScore.Format(_T("%d"), score);
    SetDlgItemText(IDC_p1_1, strScore);

    UpdateScoreBoard();
}


void CYachtDice1Dlg::OnBnClickedp1_2()
{
    // 주사위 결과를 업데이트
    UpdateDiceResultVector();

    // 주사위에서 숫자 2의 개수를 계산
    int countOfTwos = 0;
    for (int die : dice_result) {
        if (die == 2) {
            countOfTwos++;
        }
    }

    // p1_2 버튼에 해당 계산식 적용하여 결과 출력
    int score = countOfTwos * 2; // 숫자 2의 개수에 2를 곱한 값
    CString strScore;
    strScore.Format(_T("%d"), score);
    SetDlgItemText(IDC_p1_1, strScore);
 
    UpdateScoreBoard();
}


void CYachtDice1Dlg::OnBnClickedP1_3()
{
    // 주사위 결과를 업데이트
    UpdateDiceResultVector();

    // 주사위에서 숫자 3의 개수를 계산
    int countOfThrees = 0;
    for (int die : dice_result) {
        if (die == 3) {
            countOfThrees++;
        }
    }

    // p1_3 버튼에 해당 계산식 적용하여 결과 출력
    int score = countOfThrees * 3; // 숫자 3의 개수에 3을 곱한 값
    CString strScore;
    strScore.Format(_T("%d"), score);
    SetDlgItemText(IDC_p1_1, strScore);
 
    UpdateScoreBoard();
}


void CYachtDice1Dlg::OnBnClickedP1_4()
{
    // 주사위 결과를 업데이트
    UpdateDiceResultVector();

    // 주사위에서 숫자 4의 개수를 계산
    int countOfFours = 0;
    for (int die : dice_result) {
        if (die == 4) {
            countOfFours++;
        }
    }

    // p1_4 버튼에 해당 계산식 적용하여 결과 출력
    int score = countOfFours * 4; // 숫자 4의 개수에 4를 곱한 값
    CString strScore;
    strScore.Format(_T("%d"), score);
    SetDlgItemText(IDC_p1_1, strScore);
 
    UpdateScoreBoard();
}


void CYachtDice1Dlg::OnBnClickedP1_5()
{
    // 주사위 결과를 업데이트
    UpdateDiceResultVector();

    // 주사위에서 숫자 5의 개수를 계산
    int countOfFives = 0;
    for (int die : dice_result) {
        if (die == 5) {
            countOfFives++;
        }
    }

    // p1_5 버튼에 해당 계산식 적용하여 결과 출력
    int score = countOfFives * 5; // 숫자 5의 개수에 5를 곱한 값
    CString strScore;
    strScore.Format(_T("%d"), score);
    SetDlgItemText(IDC_p1_1, strScore);
 
     UpdateScoreBoard();
}


void CYachtDice1Dlg::OnBnClickedP1_6()
{
    // 주사위 결과를 업데이트
    UpdateDiceResultVector();

    // 주사위에서 숫자 6의 개수를 계산
    int countOfsixes = 0;
    for (int die : dice_result) {
        if (die == 6) {
            countOfsixes++;
        }
    }

    // p1_6 버튼에 해당 계산식 적용하여 결과 출력
    int score = countOfsixes * 6; // 숫자 6의 개수에 6을 곱한 값
    CString strScore;
    strScore.Format(_T("%d"), score);
    SetDlgItemText(IDC_p1_1, strScore);
 
    UpdateScoreBoard();
}


void CYachtDice1Dlg::OnBnClickedP1_7()
{
    // 주사위 결과를 업데이트
    UpdateDiceResultVector();

    // 주사위 숫자들의 합을 계산
    int sum = 0;
    for (int die : dice_result) {
        sum += die;
    }

    // p1_7 버튼에 계산된 합계를 출력
    CString strSum;
    strSum.Format(_T("%d"), sum);
    SetDlgItemText(IDC_p1_7, strSum);
 
    UpdateScoreBoard();
}


void CYachtDice1Dlg::OnBnClickedP1_8()
{
    // 주사위 결과를 업데이트
    UpdateDiceResultVector();

    // 배열에 같은 수 4개 이상이면 해당 합계 출력
    int count[7] = { 0 };
    for (int die : dice_result) {
        count[die]++;
    }
    for (int i = 1; i <= 6; i++) {
        if (count[i] >= 4) {
            // p1_8 버튼에 계산된 합계를 출력
            CString strScore;
            strScore.Format(_T("%d"), accumulate(dice_result.begin(), dice_result.end(), 0));
            SetDlgItemText(IDC_p1_8, strScore);
            return;
        }
    }
    // 조건에 맞는 경우가 없을 때는 0 출력
    SetDlgItemText(IDC_p1_8, _T("0"));
 
    UpdateScoreBoard();
}


void CYachtDice1Dlg::OnBnClickedP1_9()
{
    // 주사위 결과를 업데이트
    UpdateDiceResultVector();

    // 배열에 Full House가 되면 해당 합계 출력
    int count[7] = { 0 };
    for (int die : dice_result) {
        count[die]++;
    }
    bool twoSame = false, threeSame = false;
    for (int i = 1; i <= 6; i++) {
        if (count[i] == 2) {
            twoSame = true;
        }
        if (count[i] == 3) {
            threeSame = true;
        }
    }
    if (twoSame && threeSame) {
        // p1_9 버튼에 계산된 합계를 출력
        CString strScore;
        strScore.Format(_T("%d"), accumulate(dice_result.begin(), dice_result.end(), 0));
        SetDlgItemText(IDC_p1_9, strScore);
    }
    else {
        // 조건에 맞는 경우가 없을 때는 0 출력
        SetDlgItemText(IDC_p1_9, _T("0"));
    }
 
    UpdateScoreBoard();
}


void CYachtDice1Dlg::OnBnClickedP1_10()
{
    // 주사위 결과를 업데이트
    UpdateDiceResultVector();

    // 배열에 Small Straight가 되면 해당 합계 출력
    vector<int> uniqueDice(dice_result.begin(), dice_result.end());
    sort(uniqueDice.begin(), uniqueDice.end());

    vector<vector<int>> smallStraightPatterns = {
        {1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}, {1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}
    };

    for (const auto& pattern : smallStraightPatterns) {
        bool found = true;
        for (int i = 0; i < 4; i++) {
            if (find(uniqueDice.begin(), uniqueDice.end(), pattern[i]) == uniqueDice.end()) {
                found = false;
                break;
            }
        }
        if (found) {
            // p1_10 버튼에 계산된 합계를 출력
            SetDlgItemText(IDC_p1_10, _T("15"));
            return;
        }
    }
    // 조건에 맞는 경우가 없을 때는 0 출력
    SetDlgItemText(IDC_p1_10, _T("0"));
 
    UpdateScoreBoard();
}


void CYachtDice1Dlg::OnBnClickedP1_11()
{
    // 주사위 결과를 업데이트
    UpdateDiceResultVector();

    // 배열에 Large Straight가 되면 해당 합계 출력
    vector<int> uniqueDice(dice_result.begin(), dice_result.end());
    sort(uniqueDice.begin(), uniqueDice.end());

    if ((uniqueDice == vector<int>{1, 2, 3, 4, 5}) || (uniqueDice == vector<int>{2, 3, 4, 5, 6})) {
        // p1_11 버튼에 계산된 합계를 출력
        SetDlgItemText(IDC_p1_11, _T("30"));
    }
    else {
        // 조건에 맞는 경우가 없을 때는 0 출력
        SetDlgItemText(IDC_p1_11, _T("0"));
    }
    UpdateScoreBoard();
}


void CYachtDice1Dlg::OnBnClickedP1_12()
{
    // 주사위 결과를 업데이트
    UpdateDiceResultVector();

    // 배열에 Yacht가 되면 해당 합계 출력
    int count[7] = { 0 };
    for (int die : dice_result) {
        count[die]++;
    }
    if (count[dice_result[0]] == 5) {
        // p1_12 버튼에 계산된 합계를 출력
        SetDlgItemText(IDC_p1_12, _T("50"));
    }
    else {
        // 조건에 맞는 경우가 없을 때는 0 출력
        SetDlgItemText(IDC_p1_12, _T("0"));
    }
    UpdateScoreBoard();
}

void CYachtDice1Dlg::UpdateScoreBoard()
{
    // p1_1부터 p1_6까지의 값을 합산
    int sub = 0;
    for (int i = 0; i < 6; i++) {
        CString str;
        m_p1[i].GetWindowText(str);
        int value = _ttoi(str);
        sub += value;
    }

    // p1_sub에 합계 출력
    CString sumStr;
    sumStr.Format(_T("%d"), sub);
    m_p1Sub.SetWindowText(sumStr);

    // p1_sub이 65 이상인 경우 p1_bonus에 35 출력
    int bonus = (sub >= 65) ? 35 : 0;
    CString bonusStr;
    bonusStr.Format(_T("%d"), bonus);
    m_p1Bonus.SetWindowText(bonusStr);

    // sub + bonus + p1_7부터 p1_12까지의 값을 합산
    int total = sub + bonus;
    for (int i = 6; i < 12; i++) {
        CString str;
        m_p1[i].GetWindowText(str);
        int value = _ttoi(str);
        total += value;
    }

    // p1_total에 합계 출력
    CString totalStr;
    totalStr.Format(_T("%d"), total);
    m_p1Total.SetWindowText(totalStr);
}