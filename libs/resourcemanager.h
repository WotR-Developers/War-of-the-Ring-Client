#ifndef FOURTH_AGE_CLIENT_RESOURCEMANAGER
#define FOURTH_AGE_CLIENT_RESOURCEMANAGER

/* The number of objects to be loaded. */
#define     OBJECT_COUNT    100

/* For logging. */
#include "logger.h"

/* To use dynamic memory management. */
#include <stdlib.h>

/* To read files. */
#include <stdio.h>
#include <ctype.h>

/* To use string operations. */
#include <string.h>

/* To read JSON files. */
#include <json-c/json.h>

/* To get access to the definitions to avoid magic numbers. */
#include "../game_defines.h"


char    unitPaths[UNIT_COUNT][MAX_PATH_LENGTH];
char    settlementPaths[SETTLEMENT_COUNT][MAX_PATH_LENGTH];
char    mountPaths[MOUNT_COUNT][MAX_PATH_LENGTH];
char    factionPaths[FACTION_COUNT][MAX_PATH_LENGTH];
char    buildingPaths[BUILDING_COUNT][MAX_PATH_LENGTH];
char    weaponPaths[WEAPON_COUNT][MAX_PATH_LENGTH];

struct  ShaderInformation {
    char    vsShaderPath[ASSET_STRING_LENGTH];
    char    fsShaderPath[ASSET_STRING_LENGTH]; 
};

struct MentalInformation {
    float   morale;
    char    moraleAttributes[MAX_MENTAL_ATTRIBUTES_PER_UNIT][ASSET_STRING_LENGTH];
    float   heat;
};



struct  UnitGeneralInformation {
    char    name[ASSET_STRING_LENGTH]; 
    char    type[ASSET_STRING_LENGTH] ;
    char    category[ASSET_STRING_LENGTH];
    char    unitClass[ASSET_STRING_LENGTH];
};

struct  UnitAssetInformation {
    char    mountName[ASSET_STRING_LENGTH];
    char    weaponNames[MAX_WEAPONS_PER_UNIT][ASSET_STRING_LENGTH]; 
    char    modelPath[ASSET_STRING_LENGTH];
    char    texturePath[ASSET_STRING_LENGTH];
    char    generalModelPath[ASSET_STRING_LENGTH];
    char    generalTexturePath[ASSET_STRING_LENGTH];
    char    spritePath[ASSET_STRING_LENGTH];
    struct ShaderInformation    shaders;
    struct ShaderInformation    spriteShaders;
};

struct  UnitStatsInformation {
    float   recruitCost;
    float   upkeepCost;
    float   health;
    float   attack;
    float   meleeDefense;
    float   chargeDistance;
    float   fireDelay;
    struct MentalInformation    mental;
    float   movementSpeed;
    char    formations[MAX_FORMATIONS_PER_UNIT][ASSET_STRING_LENGTH];
    char    attributes[MAX_ATTRIBUTES_PER_UNIT][ASSET_STRING_LENGTH]; 
};



struct  SettlementGeneralInformation {
    char    name[ASSET_STRING_LENGTH];
    char    type[ASSET_STRING_LENGTH]; 
};

struct  SettlementAssetInformation {
    char    settlementFile[ASSET_STRING_LENGTH];
    char    spritePath[ASSET_STRING_LENGTH];
    struct ShaderInformation    shaders;
};

struct  SettlementStatsInformation {
    float   positionX;
    float   positionY;
};



struct  MountGeneralInformation {
    char    name[ASSET_STRING_LENGTH];
    char    category[ASSET_STRING_LENGTH];
};

struct  MountAssetInformation {
    char    modelPath[ASSET_STRING_LENGTH];
    char    texturePath[ASSET_STRING_LENGTH];
    struct ShaderInformation    shaders;
};

struct  MountStatsInformation {
    float   movementSpeed;
    float   health;
    float   chargeDistance;
    float   chargeBonus;
    struct MentalInformation    mental;
};



struct  FactionGeneralInformation {
    char    name[ASSET_STRING_LENGTH];
    char    description[MAX_FACTION_DESC_LENGTH];
    char    ai[ASSET_STRING_LENGTH]; 
};

struct  FactionAssetInformation {
    char    bannerTexturePath[ASSET_STRING_LENGTH]; 
};

struct  FactionStatsInformation {
    char    settlements[MAX_PREOWNED_SETTLEMENTS][ASSET_STRING_LENGTH];
    char    allies[MAX_DIPLOMATIC_COUNT][ASSET_STRING_LENGTH];
    char    enemies[MAX_DIPLOMATIC_COUNT][ASSET_STRING_LENGTH];
    char    names[MAX_NAMES_PER_FACTION][ASSET_STRING_LENGTH]; 
};



struct  BuildingGeneralInformation {
    char    name[ASSET_STRING_LENGTH];
    char    type[ASSET_STRING_LENGTH];
};

struct  BuildingAssetInformation {
    char    modelPath[ASSET_STRING_LENGTH];
    char    texturePath[ASSET_STRING_LENGTH];
    struct ShaderInformation    shaders;
};

struct  BuildingStatsInformation {
    float   buildingCost;
    float   hitPoints;
};



struct  WeaponGeneralInformation {
    char    name[ASSET_STRING_LENGTH];
    char    type[ASSET_STRING_LENGTH];
};

struct  WeaponAssetInformation {
    char    modelPath[ASSET_STRING_LENGTH];
    char    texturePath[ASSET_STRING_LENGTH];
    struct ShaderInformation    shaders;
};

struct  WeaponStatsInformation {
    float   struckDamage;
    float   stabDamage;
};

/* Contains the OS-specific path set at startup containing the assets base path. */
char    basePath[MAX_PATH_LENGTH];

void    RMG_setBasePath         (char   path[]);

void    RMG_registerResources   ();

void    getNumLinesInFile       (char*  string, char    path[], int *numLines);

void    readFileLine            (char   path[], int pathLen, int    line);

void    getJsonString           (char*  string, char*   filePath, char* key);

void    getJsonFloat            (float* value, char*    filePath, char* key);

void    getJsonArrayAtIndex     (char*  string, char*   filePath, char* arrayKey, int   arrayIndex);



struct UnitGeneralInformation   getUnitGeneralInformation   (char*   name);

struct UnitAssetInformation     getUnitAssetInformation     (char*  name);

struct UnitStatsInformation     getUnitStatsInformation     (char*  name);



struct SettlementGeneralInformation     getSettlementGeneralInformation     (char*  name);

struct SettlementAssetInformation       getSettlementAssetInformation       (char*  name);

struct SettlementStatsInformation       getSettlementStatsInformation       (char*  name);



struct MountGeneralInformation      getMountGeneralInformation      (char*  name);

struct MountAssetInformation        getMountAssetInformation        (char*  name);

struct MountStatsInformation        getMountStatsInformation        (char*  name);



struct FactionGeneralInformation    getFactionGeneralInformation    (char*  name);

struct FactionAssetInformation      getFactionAssetInformation      (char*  name);

struct FactionStatsInformation      getFactionStatsInformation      (char*  name);



struct BuildingGeneralInformation   getBuildingGeneralInformation   (char*  name);

struct BuildingAssetInformation     getBuildingAssetInformation     (char*  name);

struct BuildingStatsInformation     getBuildingStatsInformation     (char*  name);



struct WeaponGeneralInformation     getWeaponGeneralInformation     (char*  name);

struct WeaponAssetInformation       getWeaponAssetInformation       (char*  name);

struct WeaponStatsInformation       getWeaponStatsInformation       (char*  name);



/* Free pointer which have been dynamically allocated. */
void    RMG_free            ();

#endif
