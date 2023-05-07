#pragma once

namespace sge {

template<class T>
class ComPtr : public NonCopyable { //work like shareptr 
public:
	ComPtr() = default;

	ComPtr(const ComPtr& r)	{ reset(r._p); }
	ComPtr(ComPtr && r)		{ reset(r._p); r._p = nullptr; }// copy contructor ////&& Like move semactic /foward 

	void operator=(const ComPtr& r) { if (r._p == _p) return; reset(r._p); }					//operator= reset to rhs 
	void operator=(ComPtr && r)		{ if (r._p == _p) return; reset(r._p); r._p = nullptr; }	//&& Like move semactic /foward / r-value reference.

	~ComPtr() noexcept { reset(nullptr); } //reset to nullptr on dtor
	//noexcept - the function is declared not to throw any exceptions.
	T* operator->() noexcept		{ return _p; } //convert the Com pointer to a raw pointer when ->
	operator T*() noexcept			{ return _p; } //convert the Com pointer to a raw pointer when  T* _depthStencil

			T* ptr() noexcept		{ return _p; }//_depthStencil.ptr()
	const	T* ptr() const noexcept	{ return _p; }

	void reset(T* p) {
		if (p == _p) return; // no need reset if already nullptr 
		if (_p) {
			_p->Release(); // automatically release com object, Release() to properly manage the object lifetime
			_p = nullptr;  // After calling Release(), to be sure that you don't have a dangling reference to a previously released COM object
		}

		_p = p;
		if (_p) {
			_p->AddRef(); //assign ptr add Ref count , DX11 obj create add first reference count
		}
	}

	T** ptrForInit() noexcept { reset(nullptr); return &_p; }

// as the DX11 need a pointer of pointer 
//virtual HRESULT STDMETHODCALLTYPE CreateDepthStencilView(
//	/* [annotation] */
//	_In_  ID3D11Resource* pResource,
//	/* [annotation] */
//	_In_opt_  const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
//	/* [annotation] */
//	_COM_Outptr_opt_  ID3D11DepthStencilView** ppDepthStencilView) = 0;


	T* detach() { T* o = _p; _ p = nullptr; return o; }
private:
	T* _p = nullptr;
};

}
