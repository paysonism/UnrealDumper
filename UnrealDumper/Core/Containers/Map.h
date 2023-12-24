#pragma once

// payson1337 template <typename KeyType, typename ValueType>
// payson1337 using TPair = TTuple<KeyType, ValueType>; // payson1337 THIS IS PROPER

template <typename KeyType, typename ValueType>
class TPair
{
public:
	KeyType Key;
	ValueType Value;
};