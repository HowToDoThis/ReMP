#pragma once

class CMemoryPool
{
public:
	CMemoryPool(int blockSize, int numElements);
	~CMemoryPool();

	void *Alloc(unsigned int amount);
	void Free(void *memblock);
	int Count() { return _blocksAllocated; }
	void AddNewBlob();

public:
	enum { MAX_BLOBS = 16 };

	int _blockSize;
	int _blocksPerBlob;
	int _numElements;
	void *_memBlob[MAX_BLOBS];
	void *_headOfFreeList;
	int _numBlobs;
	int _peakAlloc;
	int _blocksAllocated;
};
