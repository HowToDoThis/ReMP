#ifndef Version_H
#define Version_H

#define VersionBase "1.0.0.0"

#if _DEBUG
#define Version VersionBase "-Dev"
#else
#define Version VersionBase
#endif

#endif