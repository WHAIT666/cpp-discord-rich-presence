#pragma once

#include <cstdint>
#include <memory>
#include <string>

// Forward declarations for Discord Game SDK.
// Include discord_game_sdk.h in the .cpp file after configuring your include path.
namespace discord
{
    class Core;
}

class DiscordPresenceManager
{
public:
    static DiscordPresenceManager& Instance();

    bool Initialize();
    void Shutdown();

    void RunCallbacks();

    void UpdatePresence(
        const std::string& characterName,
        const std::string& mapName,
        int race,
        int empire
    );

private:
    DiscordPresenceManager() = default;
    ~DiscordPresenceManager() = default;

    DiscordPresenceManager(const DiscordPresenceManager&) = delete;
    DiscordPresenceManager& operator=(const DiscordPresenceManager&) = delete;

    std::string GetRaceImageKey(int race) const;
    std::string GetEmpireImageKey(int empire) const;
    std::string NormalizeMapName(const std::string& mapName) const;

private:
    std::unique_ptr<discord::Core> m_core;
    bool m_initialized = false;
};
