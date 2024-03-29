#include <sge_editor.h>

#include <sge_render/mesh/RenderMesh.h>
#include <sge_render/command/RenderCommand.h>
#include <sge_render/vertex/Vertex.h>
#include <sge_render/vertex/VertexLayoutManager.h>

namespace sge {

class MainWin : public NativeUIWindow {
	using Base = NativeUIWindow;
public:
	void onCreate(CreateDesc& desc) {
		Base::onCreate(desc);

		RenderContext::CreateDesc renderContextDesc;
		renderContextDesc.window = this;

		_renderContext.reset(RenderContext::create(renderContextDesc));
	}

	virtual void onCloseButton() override {
		NativeUIApp::current()->quit(0);
	}

	virtual void onDraw() {
		Base::onDraw();
		if (_renderContext) {
			_renderContext->render();
		}
		drawNeeded();
	}

	UPtr<RenderContext>	_renderContext;
};

class EditorApp : public NativeUIApp {
	using Base = NativeUIApp; // even change name still not affect below func
public:
	virtual void onCreate(CreateDesc& desc) override {
		{
			String file = getExecutableFilename();
			String path = FilePath::getDir(file);
			path.append("/../../../../../../examples/Test101");
			setCurrentDir(path);

			auto dir = getCurrentDir();
			SGE_LOG("dir = {}", dir);
		}

		Base::onCreate(desc);

		Renderer::CreateDesc renderDesc;
		//renderDesc.apiType = OpenGL;
		Renderer::create(renderDesc);

	//---
		NativeUIWindow::CreateDesc winDesc;
		winDesc.isMainWindow = true;
		_mainWin.create(winDesc);
		_mainWin.setWindowTitle("SGE Editor");

	}

private:
	MainWin		_mainWin;
};

}

int main() {
	sge::EditorApp app;
	sge::EditorApp::CreateDesc desc;
	app.run(desc);

	return 0;
}
