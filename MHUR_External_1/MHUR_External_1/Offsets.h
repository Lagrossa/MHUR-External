#pragma once
#include <cstdint>
#include <iostream>
#include <vector>
#include "UEngine.h"

#define OFFSET(name, value) constexpr const uint32_t name = value

namespace Offsets
{
	OFFSET(GWORLD, 0x77c5290);
	OFFSET(GOBJECTS, 0x76787d0);
	OFFSET(FNAMEPOOL, 0x763c480);
	OFFSET(GENGINE, 0x77C1978);

    //Yeah so I need a better method to do this
    std::vector<unsigned int> gravityOffsets = {
        (unsigned int)UEngine::GameInstance::LocalPlayers,
        (unsigned int)UEngine::LocalPlayers::LocalPlayer, (unsigned int)UEngine::LocalPlayer::PlayerController, (unsigned int)UEngine::PlayerController::PlayerState,
        (unsigned int)UEngine::PlayerState::BuffParam, (unsigned int)UEngine::BuffParam::gravityAdjustRate,
    };

    std::vector<unsigned int> jumpOffsets = {
        (unsigned int)UEngine::GameInstance::LocalPlayers,
        (unsigned int)UEngine::LocalPlayers::LocalPlayer, (unsigned int)UEngine::LocalPlayer::PlayerController, (unsigned int)UEngine::PlayerController::PlayerState,
        (unsigned int)UEngine::PlayerState::BuffParam, (unsigned int)UEngine::BuffParam::jumpAdjustRate,
    };

    std::vector<unsigned int> cooldownOffsets = {
        (unsigned int)UEngine::GameInstance::LocalPlayers,
        (unsigned int)UEngine::LocalPlayers::LocalPlayer, (unsigned int)UEngine::LocalPlayer::PlayerController, (unsigned int)UEngine::PlayerController::PlayerState,
        (unsigned int)UEngine::PlayerState::BuffParam, (unsigned int)UEngine::BuffParam::reloadAdjustRate,
    };

    std::vector<unsigned int> runTurnRateOffsets = {
        (unsigned int)UEngine::GameInstance::LocalPlayers,
        (unsigned int)UEngine::LocalPlayers::LocalPlayer, (unsigned int)UEngine::LocalPlayer::PlayerController, (unsigned int)UEngine::PlayerController::PlayerState,
        (unsigned int)UEngine::PlayerState::PawnPrivate, (unsigned int)UEngine::Pawn::CharacterParam, (unsigned int)UEngine::CharacterParam::runTurnRate,
    };

    std::vector<unsigned int> crawlSpeedOffsets = {
        (unsigned int)UEngine::GameInstance::LocalPlayers,
        (unsigned int)UEngine::LocalPlayers::LocalPlayer, (unsigned int)UEngine::LocalPlayer::PlayerController, (unsigned int)UEngine::PlayerController::PlayerState,
        (unsigned int)UEngine::PlayerState::PawnPrivate, (unsigned int)UEngine::Pawn::CharacterParam, (unsigned int)UEngine::CharacterParam::crawlingMoveSpeedRate,
    };

    std::vector<unsigned int> rollInitialSpeedOffsets = {
        (unsigned int)UEngine::GameInstance::LocalPlayers,
        (unsigned int)UEngine::LocalPlayers::LocalPlayer, (unsigned int)UEngine::LocalPlayer::PlayerController, (unsigned int)UEngine::PlayerController::PlayerState,
        (unsigned int)UEngine::PlayerState::PawnPrivate, (unsigned int)UEngine::Pawn::CharacterParam, (unsigned int)UEngine::CharacterParam::dodgeInitialSpeed,
    };

    std::vector<unsigned int> rollFinalSpeedOffsets = {
        (unsigned int)UEngine::GameInstance::LocalPlayers,
        (unsigned int)UEngine::LocalPlayers::LocalPlayer, (unsigned int)UEngine::LocalPlayer::PlayerController, (unsigned int)UEngine::PlayerController::PlayerState,
        (unsigned int)UEngine::PlayerState::PawnPrivate, (unsigned int)UEngine::Pawn::CharacterParam, (unsigned int)UEngine::CharacterParam::dodgeLastSpeed,
    };

    std::vector<unsigned int> dashInitialSpeedOffsets = {
        (unsigned int)UEngine::GameInstance::LocalPlayers,
        (unsigned int)UEngine::LocalPlayers::LocalPlayer, (unsigned int)UEngine::LocalPlayer::PlayerController, (unsigned int)UEngine::PlayerController::PlayerState,
        (unsigned int)UEngine::PlayerState::PawnPrivate, (unsigned int)UEngine::Pawn::CharacterParam, (unsigned int)UEngine::CharacterParam::initialRunSpeed,
    };
}

#undef OFFSET