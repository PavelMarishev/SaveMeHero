#pragma once

#include <tmxlite/Map.hpp>
#include <tmxlite/TileLayer.hpp>

using namespace tmx;
using namespace std;

class Objects {
private:
	vector<Object,allocator<Object>>objects;
	vector<sf::FloatRect> objRects;

public:
	Objects(){}
	Objects(const tmx::Map& map, std::size_t idx){
		const auto& layers = map.getLayers();
		if (layers[idx]->getType() == tmx::Layer::Type::Object)
		{
			objects = dynamic_cast<tmx::ObjectGroup*>(layers[idx].get())->getObjects();
			for (int i = 0; i < objects.size(); i++) {
				tmx::FloatRect ob = objects[i].getAABB();
				sf::FloatRect rec(ob.left, ob.top, ob.width, ob.height);
				objRects.push_back(rec);
			}
		}
	
	
	}
	vector<sf::FloatRect> getRects() {
		return objRects;
	}

	Object getObject(int i) {
		return objects[i];
	}
	int getSize() {
		return objects.size();
	}
	void setObjects(const tmx::Map& map, std::size_t idx) {
		const auto& layers = map.getLayers();
		if (layers[idx]->getType() == tmx::Layer::Type::Object)
		{
			objects = dynamic_cast<tmx::ObjectGroup*>(layers[idx].get())->getObjects();
			for (int i = 0; i < objects.size(); i++) {
				tmx::FloatRect ob = objects[i].getAABB();
				sf::FloatRect rec(ob.left, ob.top, ob.width, ob.height);
				objRects.push_back(rec);
			}
		}

	}
	vector<Object, allocator<Object>> getAllObjects(){
		return objects;
	}
	Object getObjectByName(string name) {

		for (const auto& object : objects) {
			if (object.getName() == name) {
				return object;
			}
		}
	}

};