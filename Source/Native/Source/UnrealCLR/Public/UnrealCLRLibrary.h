/*
 * Copyright (c) 2020 Stanislav Denisov (nxrighthere@gmail.com)
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser General Public License
 * (LGPL) version 3 with a static linking exception which accompanies this
 * distribution.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 */

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "UnrealCLRLibrary.generated.h"

USTRUCT(BlueprintType)
struct UNREALCLR_API FManagedFunction {
	GENERATED_BODY()

	public:

	void* Pointer;

	FManagedFunction();
};

UCLASS()
class UUnrealCLRLibrary : public UBlueprintFunctionLibrary {
	GENERATED_UCLASS_BODY()

	public:

	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = ".NET", meta = (ToolTip = "Executes the managed function with optional object reference argument"))
	static void ExecuteManagedFunction(FManagedFunction ManagedFunction, UObject* Object);

	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = ".NET", meta = (ToolTip = "Finds the managed function from loaded assembly, optional parameter suppresses errors if the function was not found"))
	static FManagedFunction FindManagedFunction(FString Method, bool Optional, bool& Result);
};

UCLASS()
class UUnrealCLRCharacter : public UObject {
	GENERATED_UCLASS_BODY()

	public:

	void* LandedCallback;

	UFUNCTION()
	void Landed(const FHitResult& Hit);
};