#include "renderer.h"

#include <SDL_image.h>

#include "asset.h"

#define TILE_SIZE 60

char *get_piece_asset(Piece *piece);
SDL_Texture *create_piece_texture(SDL_Renderer *renderer, Piece *piece);
void render_tiles(SDL_Renderer *renderer, uint32_t tileSize, SDL_Point topLeft);
void render_pieces(SDL_Renderer *renderer, uint32_t tileSize, PieceState *pieces, uint8_t count, SDL_Point topLeft);

void render_board(SDL_Window *window, Board *board) {

    uint32_t width, height;
    SDL_GetWindowSize(window, &width, &height);

    SDL_Point topLeft = {
        width / 2 - TILE_SIZE * 4,
        height / 2 - TILE_SIZE * 4
    };

    SDL_Renderer *renderer = SDL_GetRenderer(window);

    render_tiles(renderer, TILE_SIZE, topLeft);
    render_pieces(renderer, TILE_SIZE, board->pieces, BOARD_PIECE_COUNT, topLeft);
}

void render_tiles(SDL_Renderer *renderer, uint32_t tileSize, SDL_Point topLeft) {
    for (uint8_t y = 0; y < 8; y++) {
        for (uint8_t x = 0; x < 8; x++) {
            uint32_t color = y % 2 == x % 2 ? 220 : 35;

            SDL_Rect tile = {
                topLeft.x + tileSize * x,
                topLeft.y + tileSize * y,
                tileSize,
                tileSize
            };

            SDL_SetRenderDrawColor(renderer, color, color, color, 255);
            SDL_RenderFillRect(renderer, &tile);
        }
    }
}

void render_pieces(SDL_Renderer *renderer, uint32_t tileSize, PieceState *pieces, uint8_t count, SDL_Point topLeft) {
    for (uint8_t i = 0; i < count; i++) {
        if (!pieces[i].isAlive) {
            continue;
        }

        // TODO: Improve texture management to avoid allocations
        SDL_Texture *texture = create_piece_texture(renderer, &pieces[i].piece);

        SDL_Rect pieceRect = {
            topLeft.x + tileSize * (pieces[i].rank - 1),
            topLeft.y + tileSize * (pieces[i].file - 1),
            tileSize,
            tileSize
        };

        SDL_RenderCopy(renderer, texture, NULL, &pieceRect);
    }
}

SDL_Surface *IMG_Load_RW(SDL_RWops *src, int freesrc);

SDL_Texture *create_piece_texture(SDL_Renderer *renderer, Piece *piece) {
    char *pieceAsset = get_piece_asset(piece);

    SDL_Texture *texture = IMG_LoadTexture(renderer, pieceAsset);

    if (texture == NULL) {
        perror("Failed to load texture for piece asset");
        exit(EXIT_FAILURE);
    }

    //free(pieceAsset);

    return texture;
}

char *get_piece_asset(Piece *piece) {
    switch (piece->color) {
    case BLACK:
        switch (piece->kind) {
        case PAWN:
            return get_asset_path("pieces/black_pawn.svg");
        case KNIGHT:
            return get_asset_path("pieces/black_knight.svg");
        case BISHOP:
            return get_asset_path("pieces/black_bishop.svg");
        case ROOK:
            return get_asset_path("pieces/black_rook.svg");
        case QUEEN:
            return get_asset_path("pieces/black_queen.svg");
        case KING:
            return get_asset_path("pieces/black_king.svg");
        default:
            return get_asset_path("error.svg");
        }
        break;
    case WHITE:
        switch (piece->kind) {
        case PAWN:
            return get_asset_path("pieces/white_pawn.svg");
        case KNIGHT:
            return get_asset_path("pieces/white_knight.svg");
        case BISHOP:
            return get_asset_path("pieces/white_bishop.svg");
        case ROOK:
            return get_asset_path("pieces/white_rook.svg");
        case QUEEN:
            return get_asset_path("pieces/white_queen.svg");
        case KING:
            return get_asset_path("pieces/white_king.svg");
        default:
            return get_asset_path("error.svg");
        }
        break;
    default:
        return get_asset_path("error.svg");
    }
}