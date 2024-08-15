#include <stdio.h>
#include <tchar.h>

// DX Header
#include <d3dx9math.h>

D3DXVECTOR3* D3DXVec3Normalized(D3DXVECTOR3* p_vOut, D3DXVECTOR3* p_vIn)
{
	FLOAT length = sqrt((p_vIn->x * p_vIn->x) + (p_vIn->y * p_vIn->y) + (p_vIn->z * p_vIn->z));
	//p_vOut = new D3DXVECTOR3(p_vIn->x / length, p_vIn->y / length, p_vIn->z / length);
	//p_vOut = D3DXVECTOR3(p_vIn->x / length, p_vIn->y / length, p_vIn->.z/ length);
	p_vOut->x = p_vIn->x / length;
	p_vOut->y = p_vIn->y / length;
	p_vOut->z = p_vIn->z / length;
	return p_vOut;
}


int _tmain(int argc, _TCHAR* argv[])
{
	D3DXVECTOR3 v1(0.0f, 3.0f, 0.0f);

	D3DXVECTOR3 v2(3.0f, 0.0f, 0.0f);

	D3DXVECTOR3 v3;

	D3DXVECTOR3 v4(3.0f, 3.0f, 0.0f);

	float fLength; 

	//// ������ ��
	//v3 = v1 + v2;
	//printf("�� : %f %f %f \n", v3.x, v3.y ,v3.z);

	//D3DXVec3Add(&v3, &v1, &v2);
	//printf("�� : %f %f %f \n", v3.x, v3.y, v3.z);

	//// ������ ��
	//v3 = v1 - v2;
	//printf("�� : %f %f %f \n", v3.x, v3.y, v3.z);

	//D3DXVec3Subtract(&v3, &v1, &v2);
	//printf("�� : %f %f %f \n", v3.x, v3.y, v3.z);


	//// ������ ũ��
	//fLength = D3DXVec3Length(&v4);
	//printf("ũ�� : %f \n", fLength);

	//// ������ ũ�� ��ȯ
	//float fScale = 2.0f;
	//D3DXVECTOR3 v5(2.0f, 1.0f, 0.0f);

	//D3DXVec3Scale(&v5, &v5, fScale);
	//printf("���� ������ �� : %f %f %f \n", v5.x, v5.y, v5.z);

	// ���� ����
	//D3DXVECTOR3 v6(2.0f, 2.0f, 3.0f);
	//D3DXVECTOR3 vResult;
	//float fNormalize;

	//D3DXVec3Normalized(&vResult, &v6);

	//printf("���� ���� : %f %f %f \n", vResult.x, vResult.y, vResult.z);
	//fNormalize = D3DXVec3Length(&vResult);
	//printf("���� ������ ũ�� : %f \n", fNormalize);
	
	D3DXVECTOR3 v7(3.0f, .0f, 0.f);
	D3DXVECTOR3 v8(-3.0, 0.0f, 0.0f);

	float fCos, fDot, fScale;

	fDot = D3DXVec3Dot(&v7, &v8);
	fScale = D3DXVec3Length(&v7) * D3DXVec3Length(&v8);
	fCos = fDot / fScale;

	printf("���� : %f \n", fCos);

	return 0;



	return 0;
	 
}