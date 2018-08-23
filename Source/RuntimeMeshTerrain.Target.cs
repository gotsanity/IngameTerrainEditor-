// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class RuntimeMeshTerrainTarget : TargetRules
{
    public RuntimeMeshTerrainTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;

        ExtraModuleNames.AddRange(new string[] { "RuntimeMeshTerrain" });
    }
}
