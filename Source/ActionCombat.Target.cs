// Copyright (C) 2025 Stoic Ronin Studio. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ActionCombatTarget : TargetRules
{
	public ActionCombatTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "ActionCombat" } );
	}
}
