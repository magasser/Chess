#ifndef ASSET_H
#define ASSET_H

#include "core.h"

#include <stdio.h>

#define ASSETS_PATH "resources/assets"

char *get_asset_path(const char *asset) {
    uint32_t assetsPathLength = strlen(ASSETS_PATH);
    uint32_t assetLength = strlen(asset);

    char *assetPath = (char *)malloc(sizeof(char) * (assetsPathLength + assetLength + 1));

    if (assetPath == NULL) {
        perror("Failed to allocate memory for asset path");
        exit(EXIT_FAILURE);
    }

    strcpy(assetPath, ASSETS_PATH);
    strcat(assetPath, "/");
    strcat(assetPath, asset);

    return assetPath;
}

#endif