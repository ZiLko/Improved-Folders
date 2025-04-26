#include "Includes.hpp"

class Utils {

public:

    static CCSprite* createTogglerSprite(const char*, bool, bool);

    static CCDictionary* getLevelFolders(SearchType);

    static CCArrayExt<GJGameLevel*> getLevels(int, SearchType);
    static CCArrayExt<GJGameLevel*> getAllLevels(SearchType);

    static std::vector<Item> getAllFolders(bool, SearchType);
    static std::vector<Item> getItemsForPath(const std::vector<int>&, int, bool, SearchType);

    static std::vector<int> getFolderPath(int, bool, SearchType);

    static matjson::Value getSaveFolder(SearchType);
    
    static std::string getFolderName(int, SearchType);
    static std::string toLower(std::string);
    static std::string getSaveFolderId(SearchType);
    static std::string getFormattedTime(float);
    static std::string getFormattedAmount(int);

    static int getNewFolderId(SearchType);
    static int getLevelCount(int, SearchType);
    static int getFolderCount(const matjson::Value&, int);
    
    static bool isSubFolder(matjson::Value, int, SearchType);
    static bool folderExists(int, SearchType);
    
    static void saveSubFolder(int, int, const std::vector<int>&, matjson::Value, SearchType);
    static void moveFolder(int, int, const std::vector<int>&, SearchType);
    static void removeMissingFolders(matjson::Value*, SearchType);
    static void removeFolder(int, SearchType);
    static void removeSubFolders(const matjson::Value&, SearchType);

};