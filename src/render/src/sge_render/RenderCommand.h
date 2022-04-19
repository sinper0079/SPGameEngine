#pragma once


namespace sge {
	enum class PrimitiveType 
	{
		triangles,
		sphere,
		capsule,
		cube,
		line
	};

	class ShaderPass {
	//	ComPtr<DX11_ID3DVertexShader>	vertexShader;
		//ComPtr<DX11_ID3DPixelShader>	pixelShader; // see how to do opengl later
	};
	class Shader {
	public:
		Vector<ShaderPass*> passes;
		
	};

	enum class VertexSamatic 
	{
		Pos, 
		Uv0,
		Uv1,
		Uv2,
		Uv3,
		Uv7,
		Color
	};

	enum class RenderDataType 
	{
		float32,
		float32x2,
		float32x3,
		float32x4,
		int8,
		int16,
		int32,
		int64,
		int32x4,
		unorm8x4
	};

	struct VertexLayout{
		struct Element {
			VertexSamatic vertexSamatic;
			RenderDataType renderDataType;
		};
		Vector<Element> elements;
	};

	struct Color4b {
		u8 r,g,b,a;

	};
	
	template<class T>
	struct Tuple3 {T x,y,z;};
	

	using Tuple3f  = Tuple3 <float>;
	using Tuple3d =  Tuple3 <double>;

	struct Vertex_PosColor {
		Tuple3f pos;
		Color4b color;
		static VertexLayout* layout;
	};

	struct Vec3f {
		float x,y,z,padding;
	};


	class RenderCmdBase : public NonCopyable {
		enum class CmdType
		{
			None,
			SetViewPort,
			Draw,
		};
	};

	class EditMesh {

	public:
		static const int kMaxUV = 8;
		Vector<Vec3f> pos;
		Vector<Vec2f> uv[kMaxUV];
		Vector<Color4b>color;
	};

	class RenderMesh {
	public:
		void create (const EditMesh& mesh){
		
			if ( mesh.pos.size() == mesh.color.size())
			for (int i =0; i<mesh.pos.size(); i++){

				//auto  pos_u8= reinterpret_cast<u8*>(&mesh.pos[0].x);
				//vertexData.emplace_back<u8>(pos_u8);
			}
		
		};

		//void setVertexLayout(VertexLayout* Layout){
		//
		//}

		//template <class V> V* verte(){};
		//template <class V> void setSize(int n){
		//	int byteSize= vertexLayout->stride*n;
		//	vertexData.resize(byteSize);
		//};
	protected:
		Vector<u8> vertexData;
		VertexLayout* vertexLayout;	
		//UPtr<VertexBuffer> vertexBuffer;
		//UPtr<IndexBuffer>  indexBuffer;
	};

	class RenderCmd_Draw :RenderCmdBase {

	public:
		PrimitiveType primitive = PrimitiveType::triangles;

		VertexLayout* layout;
		/*VertexBuffer
		IndexBuffer*/
		RenderMesh* mesh;
		ShaderPass* shaderPass;
		int vertexCount;
	};

}

