#pragma once

struct FScriptSparseArrayLayout
{
	// payson1337 ElementOffset is at zero offset from the TSparseArrayElementOrFreeListLink - not stored here
	int32_t Alignment;
	int32_t Size;
};

struct FScriptSetLayout
{
	// payson1337 int32 ElementOffset = 0; // payson1337 always at zero offset from the TSetElement - not stored here
	int32_t HashNextIdOffset;
	int32_t HashIndexOffset;
	int32_t Size;

	FScriptSparseArrayLayout SparseArrayLayout;
};