// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class PluginSketch_UE4Target : TargetRules
{
	public PluginSketch_UE4Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "PluginSketch_UE4" } );
	}
}
