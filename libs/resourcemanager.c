#include "resourcemanager.h"

void    RMG_setBasePath         (char   path[]) {

}

void    RMG_registerResources   () {

}

void    getNumLinesInFile       (char   path[], int *numLines) {

}

void    readFileLine            (char   path[], int line) {

}

void    getJsonString           (char*  string, char*   filePath, char* key) {
    FILE*   jsonFile;
    char    buffer[10240];

    struct json_object*     parsed_json;
    struct json_object*     key_content_object;

    jsonFile    =   fopen(filePath, "r");
    fread(buffer, 10240, 1, jsonFile);
    fclose(jsonFile);
    
    parsed_json =   json_tokener_parse(buffer);
    json_object_object_get_ex(parsed_json, key, &key_content_object);

    strncpy(string, json_object_get_string(key_content_object), json_object_get_string_len(key_content_object));
}

void    getJsonFloat            (float* value, char*    filePath, char* key) {
    FILE*   jsonFile;
    char    buffer[10240];

    struct json_object*     parsed_json;
    struct json_object*     key_content_object;

    jsonFile    =   fopen(filePath, "r");
    fread(buffer, 10240, 1, jsonFile);
    fclose(jsonFile);
    
    parsed_json =   json_tokener_parse(buffer);
    json_object_object_get_ex(parsed_json, key, &key_content_object);

    *value  =   (float)json_object_get_double(key_content_object);
}

void    getJsonArrayAtIndex     (char*  string, char*   filePath, char* arrayKey, int   arrayIndex) {
    FILE*   jsonFile;
    char    buffer[10240];

    struct json_object*     parsed_json;
    struct json_object*     array_object;
    struct json_object*     key_content_object;
    jsonFile    =   fopen(filePath, "r");
    fread(buffer, 10240, 1, jsonFile);
    fclose(jsonFile);
    
    parsed_json =   json_tokener_parse(buffer);
    json_object_object_get_ex(parsed_json, arrayKey, &array_object);
    json_object_array_get_idx(array_object, arrayIndex);

    strncpy(string, json_object_get_string(key_content_object), json_object_get_string_len(key_content_object));
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
