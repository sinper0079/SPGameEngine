#pragma once

#include "../base/Error.h"
#include "sge_core.h"
namespace sge {


class Object {

	virtual const TypeInfo*	 getType(); 
};

class Entity : public Object { 
	Vector <UPtr<Component>> Components;

	template <class T> SGE_INLINE void addComponent(T* comp){ Components->emplace_back(comp) };
	template <class T> SGE_INLINE T* getComponent() {
		for (size_t i ; i<Components.size(); i++) {
			auto comp = dynamic_cast<T>(components[i]);
			if (comp)  return comp; 
		}
	};

protected: 

};


class Component{
	Entity* _entity = nullptr;
};


class TransformComponent : public Component {
	Vec3f	localPosition;
	Quat4f	localRotation;
	Vec3f	localScale;

};

class System{
	
};



class MeshRenderCompoenent : public RenderComponent 
{


};

class RenderComponent
{
	~RenderComponent(){
		//remove from list 
	}
	virtual void onRender(){};
};

class RenderSystem {
	Vector<RenderComponent*> list;
};


class FieldInfo {

public:
	String name;
	size_t offset;
	const TypeInfo* type = nullptr;
};



class TypeInfo {
public:
	String name;
	FieldInfo fields;
};

class TypeManager {

	void registerType(){};
};



}
