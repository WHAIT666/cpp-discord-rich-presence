# Integration Notes

## Where to call this in a Metin2-like client

### Startup

Call once when the client initializes:

```cpp
DiscordPresenceManager::Instance().Initialize();
```

### Main loop

Call periodically:

```cpp
DiscordPresenceManager::Instance().RunCallbacks();
```

### After login / map load / character change

Call:

```cpp
DiscordPresenceManager::Instance().UpdatePresence(
    characterName,
    mapName,
    race,
    empire
);
```

## Useful places to look in the client source

Depending on your source structure, the integration usually touches files similar to:

```text
UserInterface.cpp
PythonApplication.cpp
PythonPlayer.cpp
PythonNetworkStream.cpp
PythonBackground.cpp
PythonMiniMap.cpp
```

## Local search terms

Use these in your source folder to find your original implementation:

```text
Discord
RichPresence
discordbackground
UpdateActivity
ActivityManager
RunCallbacks
empire_shinsoo
Yongan
Pyungmoo
```

## Portfolio presentation

Recommended repository name:

```text
metin2-discord-rich-presence
```

Recommended CV line:

```text
Integrated Discord Rich Presence into a legacy MMORPG client using the Discord Game SDK, displaying character, map and faction state dynamically.
```
