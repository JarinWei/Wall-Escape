
#ifndef INC_MAP_H
#define INC_MAP_H

extern uint32_t game_map[64*64];

inline uint32_t get_tile( int32_t x, int32_t y )
{
    return game_map[ (63-y)*64 + x ];
}

#endif /* INC_MAP_H */
