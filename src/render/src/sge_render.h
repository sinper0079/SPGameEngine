#pragma once


namespace sge {

	class  D3DRenderBase : NonCopyable {
	public:
		// define the screen resolution
		#define SCREEN_WIDTH  800
		#define SCREEN_HEIGHT 600
		using RGBA = float[4];
		// global declarations
		IDXGISwapChain* swapchain;             // the pointer to the swap chain interface
		ID3D11Device* dev;                     // the pointer to our Direct3D device interface
		ID3D11DeviceContext* devcon;           // the pointer to our Direct3D device context
		ID3D11RenderTargetView* backbuffer;    // the pointer to our back buffer
		ID3D11InputLayout* pLayout;            // the pointer to the input layout
		ID3D11VertexShader* pVS;               // the pointer to the vertex shader
		ID3D11PixelShader* pPS;                // the pointer to the pixel shader
		ID3D11Buffer* pVBuffer;                // the pointer to the vertex buffer
		
		// a struct to define a single vertex
		struct VERTEX { FLOAT X, Y, Z; RGBA Color; };

		// function prototypes
		void InitD3D(HWND hWnd);    // sets up and initializes Direct3D
		void RenderFrame(void);     // renders a single frame
		void CleanD3D(void);        // closes Direct3D and releases memory
		void InitGraphics(void);    // creates the shape to render
		void InitPipeline(void);    // loads and prepares the shaders
	};
}