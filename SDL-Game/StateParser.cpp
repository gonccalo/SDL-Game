#include "StateParser.h"
#include "TextureManager.h"
#include "Game.h"

bool StateParser::parseState(const char *stateFile, std::string stateID, std::vector<GameObject*> *pObjects, std::vector<std::string> *pTextureIDs) {
	TiXmlDocument xmlDoc;

	if (!xmlDoc.LoadFile(stateFile)) {
		return false; // erro a carregar o ficheiro
	}

	TiXmlElement* pRoot = xmlDoc.RootElement();
	TiXmlElement* pStateRoot = 0;
	//get state ROOT
	for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		if (e->Value() == stateID) {
			pStateRoot = e;
			break;
		}
	}
	//get Textures root
	TiXmlElement* pTextureRoot = 0;
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("TEXTURES")) {
			pTextureRoot = e;
			break;
		}
	}
	parseTextures(pTextureRoot, pTextureIDs);

	//get objects root
	TiXmlElement* pObjectRoot = 0;
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("OBJECTS")) {
			pObjectRoot = e;
			break;
		}
	}
	parseObjects(pObjectRoot, pObjects);
	return true;
}

void StateParser::parseTextures(TiXmlElement* pStateRoot, std::vector<std::string> *pTextureIDs) {
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		std::string filenameAttribute = e->Attribute("filename");
		std::string idAttribute = e->Attribute("ID");
		pTextureIDs->push_back(idAttribute);
		TheTextureManager::Instance()->load(filenameAttribute, idAttribute, TheGame::Instance()->getRenderer());
	}
}

void StateParser::parseObjects(TiXmlElement* pStateRoot, std::vector<GameObject*> *pObjects) {
	for (TiXmlElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
		int x, y, width, height, numFrames, callBackID, animSpeed;
		std::string textureID;

		e->Attribute("x", &x);
		e->Attribute("y", &y);
		e->Attribute("width", &width);
		e->Attribute("height", &height);
		e->Attribute("numFrames", &numFrames);
		e->Attribute("callbackID", &callBackID);
		e->Attribute("animSpeed", &animSpeed);
		textureID = e->Attribute("textureID");

		GameObject* pGameObject = TheGameObjectFactory::Instance()->create(e->Attribute("type"));
		pGameObject->load(new LoaderParams(x, y, width, height, textureID, numFrames, callBackID, animSpeed));
		pObjects->push_back(pGameObject);
	}
}