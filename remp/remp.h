#ifndef ReMP_H
#define ReMP_H

extern enginefuncs_t gEngfuncReMP;

// Custom PrecacheModel?
int ReMP_PrecacheModel(const char* model);
int ReMP_PrecacheSound(const char* sound);
unsigned short ReMP_PrecacheEvent(int type, const char* psz);

#endif