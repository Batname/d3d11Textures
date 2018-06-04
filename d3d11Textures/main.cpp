#include <DimencoHMDCustomPresent.h>

int WINAPI WinMain(HINSTANCE hInstance,	//Main windows function
	HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine,
	int nShowCmd)
{

	DimencoHMDCustomPresent *dimencoHMDCustomPresent = new DimencoHMDCustomPresent();

	if(!dimencoHMDCustomPresent->InitializeWindow(1, true))
	{
		MessageBox(0, L"Window Initialization - Failed",
			L"Error", MB_OK);
		return 0;
	}

	if(!dimencoHMDCustomPresent->InitializeDirect3d11App())	//Initialize Direct3D
	{
		MessageBox(0, L"Direct3D Initialization - Failed",
			L"Error", MB_OK);
		return 0;
	}

	if(!dimencoHMDCustomPresent->InitScene())	//Initialize our scene
	{
		MessageBox(0, L"Scene Initialization - Failed",
			L"Error", MB_OK);
		return 0;
	}

	dimencoHMDCustomPresent->RunRenderThread();

	Sleep(1000);

	dimencoHMDCustomPresent->SetTestRenderTargets(0);

	Sleep(3000);

	dimencoHMDCustomPresent->SetTestImageRenderTargets(2);

	Sleep(3000);

	dimencoHMDCustomPresent->StopRenderThread();

	delete dimencoHMDCustomPresent;

	return 0;
}
