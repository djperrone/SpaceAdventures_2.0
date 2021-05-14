#pragma once

enum class ComponentType
{
	None = 0,
	TransformComponent,
	TextureComponent,
	ColliderComponent
};

#define COMPONENT_CLASS_TYPE(type) static ComponentType GetStaticType() {return ComponentType::##type;}\
								virtual ComponentType GetComponentType() const override {return GetStaticType();}
								//virtual const char* GetName() const override {return #type;}

//#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}


class Component
{
public:	

	virtual ComponentType GetComponentType() const { return ComponentType::None; }
	virtual void Init() {}
	virtual void Update() {}
	virtual void Draw() {}
	virtual ~Component() {}
	//virtual void Update() = 0;
};