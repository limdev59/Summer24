#include "pch.h"
#include "framework.h"
#include "Summer24.h"

#include "CCore.h"

#define MAX_LOADSTRING 100

HINSTANCE hInst;
HWND hWnd;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR    lpCmdLine, _In_ int       nCmdShow)
{
    // hInstance : 실행된 프로그램의 시작 주소
    // hPrevInstance : 의미 없음
    // lpCmdLine : 게임 프로그래밍에선 의미가 없음

    // 의미 없음
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SUMMER24, szWindowClass, MAX_LOADSTRING);

    // 윈도우 정보 등록
    MyRegisterClass(hInstance);

    // 창을 만드는 작업을 수행 (창 생성)
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    if (FAILED(CCore::Instance()->Init(hWnd, Vec2{ 1200, 768 }))) {
        MessageBox(nullptr, L"Core 객체 초기화 실패", L"error", MB_OK);
        return FALSE;
    }

    // 단축키 - 단축키가 눌렸는가 안눌렸는가를 검사하는 부분
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SUMMER24));

    MSG msg;
    while (true) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            // 큐를 계속 보고 있어 -> true, false 
            if (WM_QUIT == msg.message)
                break;
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else {
            CCore::Instance()->Progress();
        }
    }
    return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDC_SUMMER24));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_SUMMER24);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

    hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:  // 무효화 영역이 발생한 경우
        //     // 무효화 : 화면을 갱시하거나 다시 그릴 때를 의미함
        //     // 무효화 영역 : 다른 위도우 창에 가려졌거나 다시 누를 때 겹쳐던 부분
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        //        
        //         HPEN redPen = CreatePen(BS_SOLID, 1, RGB(255, 0, 0));
        //         HBRUSH blackBrush = (HBRUSH)GetStockObject(BLACK_BRUSH);

        //         HPEN defaultPen = (HPEN)SelectObject(hdc, redPen);
        //         HBRUSH defaultBrush = (HBRUSH)SelectObject(hdc, blackBrush);

        //         if (act) {
        //             Rectangle(hdc, ptLT.x, ptLT.y, ptRB.x, ptRB.y);
        //         }

        //         for (size_t i = 0; i < vecInfo.size(); ++i) {
        //             Rectangle(hdc, vecInfo[i].objPos.x - vecInfo[i].objScale.x / 2
        //                 , vecInfo[i].objPos.y - vecInfo[i].objScale.y / 2
        //                 , vecInfo[i].objPos.x + vecInfo[i].objScale.x / 2
        //                 , vecInfo[i].objPos.y + vecInfo[i].objScale.y / 2);
        //         }

        //         SelectObject(hdc, defaultPen);
        //         SelectObject(hdc, defaultBrush);
        //         DeleteObject(redPen);
        //         DeleteObject(defaultBrush);

        EndPaint(hWnd, &ps);
    }
    break;

    ///* case WM_KEYDOWN:
    // {
    //     switch (wParam) {
    //     case VK_UP:
    //         objPos.y -= 10;
    //         InvalidateRect(hWnd, nullptr, true);
    //         break;
    //     case VK_DOWN:
    //         objPos.y += 10;
    //         InvalidateRect(hWnd, nullptr, true);
    //         break;
    //     case VK_LEFT:
    //         objPos.x -= 10;
    //         InvalidateRect(hWnd, nullptr, true);
    //         break;
    //     case VK_RIGHT:
    //         objPos.x += 10;
    //         InvalidateRect(hWnd, nullptr, true);
    //         break;
    //     }
    // }
    // break;*/

    // case WM_LBUTTONDOWN: 
    // {
    //     ptLT.x = LOWORD(lParam);
    //     ptLT.y = HIWORD(lParam);
    //     act = true;
    // }
    // break;
    // case WM_MOUSEMOVE:
    // {
    //     ptRB.x = LOWORD(lParam);
    //     ptRB.y = HIWORD(lParam);
    //     InvalidateRect(hWnd, nullptr, true);
    // }
    //     break;
    // case WM_LBUTTONUP:
    // {
    //     objInfo info = {};
    //     info.objPos.x = (ptLT.x + ptRB.x) / 2;
    //     info.objPos.y = (ptLT.y + ptRB.y) / 2;

    //     info.objScale.x = abs(ptLT.x - ptRB.x);
    //     info.objScale.y = abs(ptLT.y - ptRB.y);

    //     vecInfo.push_back(info);
    //     act = false;
    //     InvalidateRect(hWnd, nullptr, true);
    // }
    //     break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}