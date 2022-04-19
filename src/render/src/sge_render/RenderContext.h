#pragma once

namespace sge {
class RenderCmd_Draw;
class VertexLayout;

struct RenderContext_CreateDesc {
	NativeUIWindow*	window = nullptr;
};

class RenderContext : public NonCopyable {
public:
	using CreateDesc = RenderContext_CreateDesc;

	static RenderContext*	create(CreateDesc& desc);

	void render();
	void draw(RenderCmd_Draw& cmd);
	RenderContext(CreateDesc& desc);
	virtual ~RenderContext() = default;

protected:
	virtual void onBeginRender() {};
	virtual void onTestDraw() {};
	VertexLayout* CreateVertexLayout() {return nullptr;}
	virtual void onDraw(RenderCmd_Draw& cmd) {};
	virtual void onEndRender() {};
	virtual void onClearColorAndDepthBuffer() {}
	virtual void onSwapBuffers() {}
};


}