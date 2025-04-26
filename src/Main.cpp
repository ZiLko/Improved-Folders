#include <Geode/modify/SetFolderPopup.hpp>
#include <Geode/modify/LevelBrowserLayer.hpp>
#include <Geode/modify/EditLevelLayer.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

#include "FolderPopup.hpp"
#include "Utils.hpp"

$on_mod(Loaded) {
    for (SearchType type : { SearchType::MyLevels, SearchType::SavedLevels }) {
        matjson::Value saveFolder = Utils::getSaveFolder(type);
        Utils::removeMissingFolders(&saveFolder, type);
        Mod::get()->setSavedValue(Utils::getSaveFolderId(type), saveFolder);
    }
}

class $modify(SetFolderPopup) {
    
    static SetFolderPopup* create(int value, bool isCreated, gd::string title) {
        SetFolderPopup* ret = SetFolderPopup::create(value, isCreated, title);

        if (Mod::get()->getSettingValue<bool>("disable")) return ret;

        ret->setVisible(false);

        Loader::get()->queueInMainThread([ret] {
            FolderPopup::create(ret, GameManager::get()->getGameVariable("0168"))->show();
        });

        return ret;
    }

};

class $modify(LevelInfoLayer) {

    bool init(GJGameLevel* level, bool challenge) {
        if (!LevelInfoLayer::init(level, challenge)) return false;

        if (m_folderLabel && Mod::get()->getSettingValue<bool>("hide-button-id"))
            m_folderLabel->setVisible(false);

        return true;
    }

};

class $modify(EditLevelLayer) {

    bool init(GJGameLevel* level) {
        if (!EditLevelLayer::init(level)) return false;

        if (m_folderLabel && Mod::get()->getSettingValue<bool>("hide-button-id"))
            m_folderLabel->setVisible(false);

        return true;
    }

};

class $modify(LevelBrowserLayer) {
    
    gd::string getSearchTitle() {
        std::string ret = LevelBrowserLayer::getSearchTitle();

        if (Mod::get()->getSettingValue<bool>("disable")) return ret;

        if (m_folderText && Mod::get()->getSettingValue<bool>("hide-button-id"))
            m_folderText->setVisible(false);

        if (!Mod::get()->getSettingValue<bool>("hide-title-id")) return ret;
        
        if (m_searchObject->m_folder != 0) {
            int startIndex, endIndex;

            for (int i = 0; i < ret.size(); i++) {
                if (ret[i] != ':') continue;

                for (int j = i - 1; j >= 0; j--)
                    if (!isdigit(ret[j])) {
                        startIndex = j + 1;
                        break;
                    }
                
                endIndex = i + 2;
                break;
            }
            
            startIndex = std::clamp(startIndex, 0, static_cast<int>(ret.size()) - 1);
            endIndex = std::clamp(endIndex, 0, static_cast<int>(ret.size()) - 1);
            ret.erase(std::next(ret.begin(), startIndex), std::next(ret.begin(), endIndex));
        }

        return ret;
    } 

};