#pragma once

#include <unordered_map>
#include <array>
#include "Component.h"
#include <memory>
#include "TransformComponent.h"
#include "TextureComponent.h"
#include "ColliderComponent.h"
#include <bitset>

//class TextureComponent;
//class TransformComponent;

using Group = std::size_t;
using ComponentID = std::size_t;


class ComponentManager
{
private:
	std::unordered_map<ComponentType, Component> components_map;
	std::vector<std::unique_ptr<Component>> components;
	std::array<std::shared_ptr<Component>, 32> componentArray;
public:
	ComponentManager()
	{

	}

	template <typename T, typename... Args>
	void AddComponent(Args&&... args)
	{
		//std::cout << "testing " << static_cast<int>(T::GetStaticType()) << std::endl;

		std::shared_ptr<T> component = std::make_shared<T>(std::forward<Args>(args)...);
		//T* component = new T(std::forward<Args>(args)...);
		componentArray[static_cast<int>(T::GetStaticType())] = component;


		//std::unique_ptr<Component> uPtr{ component.get() };
		//components.emplace_back(std::move(component));

		//T* component(new T(std::forward<Args>(args)...));
		//components.emplace_back(std::move(component));
		//T::ComponentTypeID;
		//c_array[T::ComponentTypeID] = component;
	}

	template <typename T>
	T& GetComponent()
	{
		//std::cout <<"testing2 " << static_cast<int>(T::GetStaticType() )<< std::endl;
		auto ptr = componentArray[static_cast<int>(T::GetStaticType())];
		//auto ptr(componentArray[getComponentTypeID<T>()]);

		return *static_cast<T*>(ptr.get());
		//return *static_cast<T*>(ptr);
		//return NULL;
	}
};