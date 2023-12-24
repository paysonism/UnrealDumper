#pragma once

#include "Array.h"

// payson1337 struct FStringFormatArg;
// payson1337 template<typename InKeyType, typename InValueType, typename SetAllocator, typename KeyFuncs > class TMap;

// payson1337 typedef TMap<FString, FStringFormatArg> FStringFormatNamedArguments;
// payson1337 typedef TArray<FStringFormatArg> FStringFormatOrderedArguments;

// payson1337 TCHAR* GetData(FString&);
// payson1337 const TCHAR* GetData(const FString&);
// payson1337 int32_t        GetNum(const FString& String);
/**
 * A dynamically sizeable string.
 * @see https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/StringHandling/FString/
 *
 * When dealing with UTF-8 literals, the following advice is recommended:
 *
 * - Do not use the u8"..." prefix (gives the wrong array type until C++20).
 * - Use UTF8TEXT("...") for array literals (type is const UTF8CHAR[n]).
 * - Use "..."_U8SV for string view literals (type is FUtf8StringView).
 * - Use \uxxxx or \Uxxxxxxxx escape sequences rather than \x to specify Unicode code points.
 */

class FString : private TArray<wchar_t>
{
    public:
        FString() = default;

        FString(const wchar_t* other)
        {
            Max = Count = *other ? std::wcslen(other) + 1 : 0;

            if (Count)
            {
                Data = const_cast<wchar_t*>(other);
            }
        };

        inline bool IsValid() const
        {
            return Data != nullptr;
        }

        inline const wchar_t* c_str() const
        {
            return Data;
        }

        std::string ToString();
};