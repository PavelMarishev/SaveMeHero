#pragma once

#include <tmxlite/Map.hpp>
#include <tmxlite/TileLayer.hpp>

using namespace tmx;
using namespace std;

class Objects {
private:
	vector<Object,allocator<Object>>objects;

public:
	Objects(){}
	Objects(const tmx::Map& map, std::size_t idx){
		const auto& layers = map.getLayers();
		if (layers[idx]->getType() == tmx::Layer::Type::Object)
		{
			objects = dynamic_cast<tmx::ObjectGroup*>(layers[idx].get())->getObjects();

		}
	
	}
	void setObjects(const tmx::Map& map, std::size_t idx) {
		const auto& layers = map.getLayers();
		if (layers[idx]->getType() == tmx::Layer::Type::Object)
		{
			objects = dynamic_cast<tmx::ObjectGroup*>(layers[idx].get())->getObjects();

		}
	}
	vector<Object, allocator<Object>> getAllObjects(){
		return objects;
	}
	Object getObject(string name) {

		for (const auto& object : objects) {
			if (object.getName() == name) {
				return object;
			}
		}
	}

};