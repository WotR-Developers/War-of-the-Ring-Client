#include "resourcemanager.h"

void    RMG_setBasePath         (char   path[]) {
    strcpy(basePath, path);
}

void    RMG_registerResources   () {
    char    unitPath[2 * MAX_PATH_LENGTH];
    char    settlementPath[2 * MAX_PATH_LENGTH];
    char    mountPath[2 * MAX_PATH_LENGTH];
    char    factionPath[2 * MAX_PATH_LENGTH];
    char    buildingPath[2 * MAX_PATH_LENGTH];
    char    weaponPath[2 * MAX_PATH_LENGTH];

    strcpy(unitPath, basePath);
    strcpy(settlementPath, basePath);
    strcpy(mountPath, basePath);
    strcpy(factionPath, basePath);
    strcpy(buildingPath, basePath);
    strcpy(weaponPath, basePath);

    strcat(unitPath, "units.txt");
    strcat(settlementPath, "settlements.txt");
    strcat(mountPath, "mounts.txt");
    strcat(factionPath, "factions.txt");
    strcat(buildingPath, "buildings.txt");
    strcat(weaponPath, "weapons.txt");

    FILE*   unitFile        =   fopen(unitPath, "r");
    FILE*   settlementFile  =   fopen(settlementPath, "r");
    FILE*   mountFile       =   fopen(mountPath, "r");
    FILE*   factionFile     =   fopen(factionPath, "r");
    FILE*   buildingFile    =   fopen(buildingPath, "r");
    FILE*   weaponFile      =   fopen(weaponPath, "r");

    if  (!unitFile) {
        LOG_error("File not found error.", unitPath);
        return;
    } 
    if  (!settlementFile) {
        LOG_error("File not found error.", settlementPath);
        return;
    }

    if  (!mountFile) {
        LOG_error("File not found error.", mountPath);
        return;
    }
    if  (!factionFile) {
        LOG_error("File not found error.", factionPath);
        return;
    }
    if  (!buildingFile) {
        LOG_error("File not found error.", buildingPath);
        return;
    }
    if  (!weaponFile) {
        LOG_error("File not found error.", weaponPath);
        return;
    }
    
    char    buffer[128];

    for     (int i = 0; i < UNIT_COUNT; ++i) {
        fgets(buffer, sizeof(buffer), unitFile);
        buffer[(strlen(buffer)) - 1]    =   '\0';
        strcpy(unitPaths[i], basePath);
        strcat(unitPaths[i], "units/");
        strcat(unitPaths[i], buffer);
        strcat(unitPaths[i], ".json");
    }

    for     (int i = 0; i < SETTLEMENT_COUNT; ++i) {
        fgets(buffer, sizeof(buffer), settlementFile);
        buffer[(strlen(buffer)) - 1]    =   '\0';
        strcpy(settlementPaths[i], basePath);
        strcat(settlementPaths[i], "settlements/");
        strcat(settlementPaths[i], buffer);
        strcat(settlementPaths[i], ".json");
    }
    
    for     (int i = 0; i < MOUNT_COUNT; ++i) {
        fgets(buffer, sizeof(buffer), mountFile);
        buffer[(strlen(buffer)) - 1]    =   '\0';
        strcpy(mountPaths[i], basePath);
        strcat(mountPaths[i], "mounts/");
        strcat(mountPaths[i], buffer);
        strcat(mountPaths[i], ".json");
    }

    for     (int i = 0; i < FACTION_COUNT; ++i) {
        fgets(buffer, sizeof(buffer), factionFile);
        buffer[(strlen(buffer)) - 1]    =   '\0';
        strcpy(factionPaths[i], basePath);
        strcat(factionPaths[i], "factions/");
        strcat(factionPaths[i], buffer);
        strcat(factionPaths[i], ".json");
    }

    for     (int i = 0; i < BUILDING_COUNT; ++i) {
        fgets(buffer, sizeof(buffer), buildingFile);
        buffer[(strlen(buffer)) - 1]    =   '\0';
        strcpy(buildingPaths[i], basePath);
        strcat(buildingPaths[i], "buildings/");
        strcat(buildingPaths[i], buffer);
        strcat(buildingPaths[i], ".json");
    }

    for     (int i = 0; i < WEAPON_COUNT; ++i) {
        fgets(buffer, sizeof(buffer), weaponFile);
        buffer[(strlen(buffer)) - 1]    =   '\0';
        strcpy(weaponPaths[i], basePath);
        strcat(weaponPaths[i], "weapons/");
        strcat(weaponPaths[i], buffer);
        strcat(weaponPaths[i], ".json");
    }

    fclose(unitFile);
    fclose(settlementFile);
    fclose(mountFile);
    fclose(factionFile);
    fclose(buildingFile);
    fclose(weaponFile);
}

void    getNumLinesInFile       (char*  string, char    path[], int *numLines) {
    FILE*   file    =   fopen(path, "r");
    if  (!file)
        LOG_error("File not found exception", path);

    int     charc;
    while   (!feof(file)) {
        charc   =   fgetc(file);
        if      (charc == '\n') {
            ++(*numLines);
        }
    }
    return;
}

void    readFileLine            (char   path[], int pathLen, int    line) {
    FILE*   file    =   fopen(path, "r");
    if  (!file)
        LOG_error("File not found exception", path);
    int     turn   =   0;
    while   (fgets(path, pathLen, file)) {
        if      (turn == line)
            break;
        else
            continue;
    }
    return;
}

void    getJsonString           (char*  string, char*   filePath, char* key) {
    FILE*   jsonFile;
    char    buffer[10240];

    struct json_object*     parsed_json;
    struct json_object*     key_content_object;

    jsonFile    =   fopen(filePath, "r");
    if  (!jsonFile)
        LOG_error("File not found exception", filePath);

    fread(buffer, 10240, 1, jsonFile);
    fclose(jsonFile);
    
    parsed_json =   json_tokener_parse(buffer);
    json_object_object_get_ex(parsed_json, key, &key_content_object);

    strncpy(string, json_object_get_string(key_content_object), json_object_get_string_len(key_content_object));
    return;
}

void    getJsonFloat            (float* value, char*    filePath, char* key) {
    FILE*   jsonFile;
    char    buffer[10240];

    struct json_object*     parsed_json;
    struct json_object*     key_content_object;

    jsonFile    =   fopen(filePath, "r");
    if  (!jsonFile)
        LOG_error("File not found exception", filePath);

    fread(buffer, 10240, 1, jsonFile);
    fclose(jsonFile);
    
    parsed_json =   json_tokener_parse(buffer);
    json_object_object_get_ex(parsed_json, key, &key_content_object);

    *value  =   (float)json_object_get_double(key_content_object);
    return;
}

void    getJsonArrayAtIndex     (char*  string, char*   filePath, char* arrayKey, int   arrayIndex) {
    FILE*   jsonFile;
    char    buffer[10240];

    struct json_object*     parsed_json;
    struct json_object*     array_object;
    struct json_object*     key_content_object;
    jsonFile    =   fopen(filePath, "r");
    if  (!jsonFile)
        LOG_error("File not found exception", filePath);

    fread(buffer, 10240, 1, jsonFile);
    fclose(jsonFile);
    
    parsed_json =   json_tokener_parse(buffer);
    json_object_object_get_ex(parsed_json, arrayKey, &array_object);
    json_object_array_get_idx(array_object, arrayIndex);

    strncpy(string, json_object_get_string(key_content_object), json_object_get_string_len(key_content_object));
    return;
}

struct UnitGeneralInformation   getUnitGeneralInformation   (char*   name) {

}

struct UnitAssetInformation     getUnitAssetInformation     (char*  name) {

}

struct UnitStatsInformation     getUnitStatsInformation     (char*  name) {

}

struct SettlementGeneralInformation     getSettlementGeneralInformation     (char*  name) {

}

struct SettlementAssetInformation       getSettlementAssetInformation       (char*  name) {

}

struct SettlementStatsInformation       getSettlementStatsInformation       (char*  name) {

}

struct MountGeneralInformation      getMountGeneralInformation      (char*  name) {

}

struct MountAssetInformation        getMountAssetInformation        (char*  name) {

}

struct MountStatsInformation        getMountStatsInformation        (char*  name) {

}

struct FactionGeneralInformation    getFactionGeneralInformation    (char*  name) {

}

struct FactionAssetInformation      getFactionAssetInformation      (char*  name) {

}

struct FactionStatsInformation      getFactionStatsInformation      (char*  name) {

}

struct BuildingGeneralInformation   getBuildingGeneralInformation   (char*  name) {

}

struct BuildingAssetInformation     getBuildingAssetInformation     (char*  name) {

}

struct BuildingStatsInformation     getBuildingStatsInformation     (char*  name)  {

}

struct WeaponGeneralInformation     getWeaponGeneralInformation     (char*  name) {

}

struct WeaponAssetInformation       getWeaponAssetInformation       (char*  name) {

}

struct WeaponStatsInformation       getWeaponStatsInformation       (char*  name) {

}

void    RMG_free    () {
}
