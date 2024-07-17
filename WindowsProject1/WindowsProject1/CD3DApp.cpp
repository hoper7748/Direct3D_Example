#include "CD3DApp.h"

HRESULT CD3DApp::InitD3D(HWND hWnd)
{
    m_hWnd = hWnd;

    if (NULL == (m_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
        return E_FAIL;

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

    if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &d3dpp, &m_pd3dDevice)))
    {
        return E_FAIL;
    }

    OnInit();

	return S_OK;
}

void CD3DApp::Update()
{
    OnUpdate();
}

void CD3DApp::Render()
{
    if (NULL == m_pd3dDevice)
    {
        return;
    }

    m_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

    // Begin the scene
    if (SUCCEEDED(m_pd3dDevice->BeginScene()))
    {
        OnRender();
        // end the scene
        m_pd3dDevice->EndScene();
    }

    //// Begin the scene
    //g_pd3dDevice->BeginScene();

    //// 여기서 실제 렌더링 코드가 들어간다.
    //
    //// end the scene
    //g_pd3dDevice->EndScene();

    // 씬이 끝나면 초기화
    m_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

void CD3DApp::CleanUp()
{
    OnRelease();

    if (m_pd3dDevice != NULL)
        m_pd3dDevice->Release();

    if (m_pD3D != NULL)
        m_pD3D->Release();
}

CD3DApp::CD3DApp()
{
}

CD3DApp::~CD3DApp()
{
}
