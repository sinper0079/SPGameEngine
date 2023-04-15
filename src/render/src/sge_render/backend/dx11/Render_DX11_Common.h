#pragma once

#if SGE_RENDER_HAS_DX11

#include <d3d11.h>
#include <d3d11_4.h>  // follow window SDK , no x version 
#include <dxgi1_4.h>

#include <d3dcompiler.h> // if xbox store can not include this , cant call complie file function ,need to same byte code 

#pragma comment(lib, "d3d11.lib") // need include lib
#pragma comment(lib, "d3dcompiler.lib")
//#pragma comment is a compiler directive which indicates Visual C++ to leave a comment in the generated object file. The comment can then be read by the linker when it processes object files.
//
//#pragma comment(lib, libname) tells the linker to add the 'libname' library to the list of library dependencies, as if you had added it in the project properties at Linker->Input->Additional dependencies

namespace sge {

class Renderer_DX11;

//For even change version only change here
using DX11_IDXGIFactory			= IDXGIFactory1; 
using DX11_IDXGIDevice			= IDXGIDevice; 
using DX11_IDXGIAdapter			= IDXGIAdapter3; 
using DX11_IDXGISwapChain		= IDXGISwapChain;

using DX11_ID3DDevice			= ID3D11Device1; // display card 
using DX11_ID3DDeviceContext	= ID3D11DeviceContext4; //context mean that window
using DX11_ID3DDebug			= ID3D11Debug;

using DX11_ID3DTexture1D		= ID3D11Texture1D;
using DX11_ID3DTexture2D		= ID3D11Texture2D;
using DX11_ID3DTexture3D		= ID3D11Texture3D;

using DX11_ID3DRenderTargetView	= ID3D11RenderTargetView;
using DX11_ID3DDepthStencilView	= ID3D11DepthStencilView;

using DX11_ID3DBuffer			= ID3D11Buffer; // no diff for vs and ps, all call buffer
using DX11_ID3DBlob				= ID3DBlob;

using DX11_ID3DVertexShader		= ID3D11VertexShader;
using DX11_ID3DPixelShader		= ID3D11PixelShader;
using DX11_ID3DInputLayout		= ID3D11InputLayout;

struct DX11Util {
	DX11Util() = delete;

	static void throwIfError	(HRESULT hr) { 
		if (!_checkError(hr)) { reportError(); throw SGE_ERROR("HRESULT = {}", hr); }
	}
	static bool assertIfError	(HRESULT hr) {
		if (!_checkError(hr)) { reportError(); SGE_ASSERT(false); 
		return false; }
		return true;
	}
	static void reportError();

	static Renderer_DX11*			renderer();
	static DX11_ID3DDevice*			d3dDevice();
	static DX11_ID3DDeviceContext*	d3dDeviceContext();

private:
	static bool _checkError(HRESULT hr) {
		if (FAILED(hr))
			return false;
		return true;
	}
};

inline
void DX11Util::reportError() {
#if 0 && _DEBUG
	auto* d = renderer()->d3dDebug();
	if (d) {
		d->ReportLiveDeviceObjects(D3D11_RLDO_DETAIL);
	}
#endif
}

} // namespace

#endif