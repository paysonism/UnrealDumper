#pragma once

#include "UObjectBase.h"
#include "Class.h"
#include "../../Core/Containers/UnrealString.h"

/**
 * Provides utility functions for UObject, this class should not be used directly
 */
class UObjectBaseUtility : public UObjectBase
{
	public:
		static bool IsChildOfWorkaround(UClass* ObjClass, class UClass* TestCls)
		{
			return ObjClass->IsChildOf(TestCls);
		}

		/**Returns true if this object is of the specified type.*/
		bool IsA(class UClass* SomeBaseClass) const
		{
			// payson1337 We have a cyclic dependency between UObjectBaseUtility and UClass,
			// payson1337 so we use a template to allow inlining of something we haven't yet seen, because it delays compilation until the function is called.

			// payson1337 'static_assert' that this thing is actually a UClass pointer or convertible to it.
			// payson1337 const UClass* SomeBaseClass = SomeBase;
			// payson1337 (void)SomeBaseClass;
			// payson1337 checkfSlow(SomeBaseClass, TEXT("IsA(NULL) cannot yield meaningful results"));

			class UClass* ThisClass = GetClass();

			// payson1337 Stop the compiler doing some unnecessary branching for nullptr checks
			// payson1337 UE_ASSUME(SomeBaseClass);
			// payson1337 UE_ASSUME(ThisClass);

			return IsChildOfWorkaround(ThisClass, SomeBaseClass);
		}

		/**
		 * Returns the name of this object (with no path information)
		 *
		 * @return Name of the object.
		*/
		FString GetName()
		{
			return Utils::UKismetStringLibrary::Conv_NameToString(GetFName());
		}
};