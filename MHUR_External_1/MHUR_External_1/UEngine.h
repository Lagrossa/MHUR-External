#pragma once
class UEngine {
public:
	enum class Engine {
		GameInstance = 0xD28,
	};

	enum class GameInstance {
		LocalPlayers = 0x38,
	};

	enum class LocalPlayers {
		LocalPlayer = 0x0,
	};

	enum class LocalPlayer {
		PlayerController = 0x30,
	};

	enum class PlayerController {
		PlayerState = 0x228,
		Pawn = 0x250, // Time Dilation
		AcknowledgedPawn = 0x2A0, // CharacterBattle

		// Aimbot, potentially
		ControlRotationPitch = 0x288,
		ControlRotationYaw = 0x28C,
		ControlRotationRoll = 0x290,
	};

	enum class PlayerState {
		//CustomTimeDilation = 0x98,
		PawnPrivate = 0x280, // Character Param, movement
		PlayerNamePrivate = 0x300, // DEREF TWICE
		squadId = 0x350,
		MainHealth = 0x538, // Current
		DyingHealth = 0x53C,		
		Dying = 0x540, // ?
		Dead = 0x540, // ?
		MaxHealth = 0x558,
		CurrentShield = 0x71C,
		MaxShield = 0x720,
		PlusUltra = 0x8F8,
		TotalDamageDone = 0x98C,
		BuffParam = 0xB80,
		NumberOfSpectators = 0xF50,
		EmblemCodes = 0xF58,
	};

	enum class Pawn {
		CharacterParam = 0x7C0,
	};

	enum class CharacterParam {
		gravity = 0xB4, // Base is -1480
		maxFallSpeed = 0xB8, // Base is -4000
		initialWalkSpeed = 0xDC, // 400 base
		lastWalkSpeed = 0xE0, //600
		initialRunSpeed = 0xF8, // 800
		lastRunSpeed = 0x1000, //1000
		runTurnRate = 0x108, //.05

		jumpForwardSpeed = 0x144, //150 
		wallJumpHeight = 0x174, //200
		walljumpInitialSpeed = 0x178, //600
		walljumpLastSpeed = 0x17C, //600

		wallCrawlInitialSpeed = 0x1BC, //700
		//wallCrawlInitialSpeed = 0x178, //600

		dodgeInitialSpeed = 0x1D0, // 900
		dodgeLastSpeed = 0x1D4, // 1000 

		crawlingMoveSpeedRate = 0x230, //1
	};

	enum class BuffParam {
		reloadAdjustRate = 0xB4,
		gravityAdjustRate = 0xCC,
		jumpAdjustRate = 0xD0,
	};

};

