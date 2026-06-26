#include "DiscordPresenceManager.h"

// Configure your include path to the Discord Game SDK before enabling this include.
// #include "discord_game_sdk.h"

#include <ctime>
#include <iostream>

// Replace with your Discord Application ID.
static constexpr std::int64_t DISCORD_CLIENT_ID = 000000000000000000;

DiscordPresenceManager& DiscordPresenceManager::Instance()
{
    static DiscordPresenceManager instance;
    return instance;
}

bool DiscordPresenceManager::Initialize()
{
    if (m_initialized)
        return true;

    // Example for Discord Game SDK:
    //
    // discord::Core* rawCore{};
    // auto result = discord::Core::Create(
    //     DISCORD_CLIENT_ID,
    //     DiscordCreateFlags_Default,
    //     &rawCore
    // );
    //
    // if (result != discord::Result::Ok || !rawCore)
    // {
    //     std::cerr << "Failed to initialize Discord Rich Presence.\n";
    //     return false;
    // }
    //
    // m_core.reset(rawCore);
    // m_initialized = true;

    // Portfolio-safe placeholder.
    // Enable the Discord SDK block above in the real client.
    m_initialized = true;
    return true;
}

void DiscordPresenceManager::Shutdown()
{
    if (!m_initialized)
        return;

    // if (m_core)
    // {
    //     discord::Activity activity{};
    //     m_core->ActivityManager().ClearActivity([](discord::Result) {});
    //     m_core.reset();
    // }

    m_initialized = false;
}

void DiscordPresenceManager::RunCallbacks()
{
    if (!m_initialized)
        return;

    // if (m_core)
    //     m_core->RunCallbacks();
}

void DiscordPresenceManager::UpdatePresence(
    const std::string& characterName,
    const std::string& mapName,
    int race,
    int empire
)
{
    if (!m_initialized)
        return;

    const std::string readableMapName = NormalizeMapName(mapName);
    const std::string raceImage = GetRaceImageKey(race);
    const std::string empireImage = GetEmpireImageKey(empire);

    // Example for Discord Game SDK:
    //
    // discord::Activity activity{};
    // activity.SetType(discord::ActivityType::Playing);
    // activity.SetDetails(("Character: " + characterName).c_str());
    // activity.SetState(("Map: " + readableMapName).c_str());
    //
    // activity.GetAssets().SetLargeImage("discordbackground");
    // activity.GetAssets().SetLargeText("EzyMT2");
    // activity.GetAssets().SetSmallImage(empireImage.c_str());
    // activity.GetAssets().SetSmallText(readableMapName.c_str());
    //
    // activity.GetTimestamps().SetStart(std::time(nullptr));
    //
    // m_core->ActivityManager().UpdateActivity(
    //     activity,
    //     [](discord::Result result)
    //     {
    //         if (result != discord::Result::Ok)
    //             std::cerr << "Failed to update Discord Rich Presence.\n";
    //     }
    // );

    std::cout
        << "[DiscordPresence] "
        << "Character=" << characterName
        << " Map=" << readableMapName
        << " RaceImage=" << raceImage
        << " EmpireImage=" << empireImage
        << "\n";
}

std::string DiscordPresenceManager::GetRaceImageKey(int race) const
{
    // Adjust these IDs to match your client race/job constants.
    switch (race)
    {
        case 0: return "warrior_m";
        case 1: return "ninja_w";
        case 2: return "sura_m";
        case 3: return "shaman_w";
        case 4: return "warrior_w";
        case 5: return "ninja_m";
        case 6: return "sura_w";
        case 7: return "shaman_m";
        default: return "discordbackground";
    }
}

std::string DiscordPresenceManager::GetEmpireImageKey(int empire) const
{
    switch (empire)
    {
        case 1: return "empire_shinsoo";
        case 2: return "empire_chunjo";
        case 3: return "empire_jinno";
        default: return "discordbackground";
    }
}

std::string DiscordPresenceManager::NormalizeMapName(const std::string& mapName) const
{
    if (mapName == "metin2_map_a1")
        return "Yongan";

    if (mapName == "metin2_map_b1")
        return "Joan";

    if (mapName == "metin2_map_c1")
        return "Pyungmoo";

    return mapName.empty() ? "Unknown Map" : mapName;
}
