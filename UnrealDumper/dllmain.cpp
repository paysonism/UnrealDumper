#include "pch.h"
#include <thread>
#include "utils.h"
#include "dumper.h"
#include "CoreUObject/UObject/UObjectBaseUtility.h"
#include <iostream>
#include <filesystem>

#include "buildSettings.h"
#include "offsets/CoreUObject.h"

static void Main() {
    SetConsoleTitleA("Unreal Dumper - github.com/paysonism");
    AllocConsole();
    FILE* file;
    freopen_s(&file, "CONOUT$", "w", stdout);

    #ifdef SEARCH_OFFSETS 
    system("color 5");
        printf("\n Dumping...");

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        if (!OffsetsFinder::FindAll()) {
            printf("Check which offsets were found and patch them in the source.\n");
            return;
        }
    #else
        Offsets::ProcessEvent = 0;
    #endif

    Offsets::UProperty::PropertyFlags = 0x38;
    Offsets::UProperty::ArrayDim = 0x30;

    #ifdef PRINT_OFFSETS
        printf("Base: %p\n", GetModuleHandle(0));
        printf("ProcessEvent: %p\n", Offsets::ProcessEvent);
        printf("StaticFindObject: %p\n", Offsets::StaticFindObject);
        printf("GObjects: %p\n", Offsets::GObjects);

        printf("    UFunction:\n");
        printf("        Func: %p\n", Offsets::UFunction::Func);

        printf("    UObject:\n");
        printf("        InternalIndex: %p\n", Offsets::UObject::InternalIndex);
        printf("        ProcessEvent VTable Index: %p\n", Offsets::UObject::ProcessEvent);

        printf("    UObjectBase:\n");
        printf("        NamePrivate: %p\n", Offsets::UObjectBase::NamePrivate);
        printf("        ClassPrivate: %p\n", Offsets::UObjectBase::ClassPrivate);

        printf("    UStruct:\n");
        printf("        ChildProperties: %p\n", Offsets::UStruct::ChildProperties);
        printf("        SuperStruct: %p\n", Offsets::UStruct::SuperStruct);

        printf("    UObjectPropertyBase:\n");
        printf("        PropertyClass: %p\n", Offsets::UObjectPropertyBase::PropertyClass);

        printf("    UProperty:\n");
        printf("        ElementSize: %p\n", CoreUObjectOffsetFinder::_UProperty::FindElementSize());
        printf("        Offset_Internal: %p\n", Offsets::UProperty::Offset_Internal);

        printf("    UField:\n");
        printf("        Next: %p\n", Offsets::UField::Next);
    #endif

	// payson1337 Note: Just temp, you can remove this if you dont inject on startup
    std::this_thread::sleep_for(std::chrono::milliseconds(1000 * 15));

    MakeDirs();
    wprintf(L"SDK Path: %s\\SDK\\\n", GetCurrentDir().c_str());

    #ifdef DUMP_OBJECT_NAMES
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Dumper::DumpObjectNames, 0, 0, 0); // payson1337 Tbh if we dump object names and sdk we might as well just loop objects once
    #endif

    #if defined(DUMP_AS_JSON) || defined(DUMP_AS_SDK)
        auto Start = std::chrono::high_resolution_clock::now();
        Dumper::Dump();
        printf("\n Successfully Dumped :)");
#endif
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
        CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)&Main, nullptr, NULL, nullptr);

    return TRUE;
}

