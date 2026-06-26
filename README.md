# Metin2 Discord Rich Presence

Discord Rich Presence integration for a legacy MMORPG client.

## Features

- Shows server name
- Shows character name
- Shows current map
- Supports race/class image keys
- Supports empire small image keys
- Uses Discord Game SDK activity updates

## Example Presence

```text
EzyMT2
Character: Mars
Map: Yongan
Large image: discordbackground
Small image: empire_shinsoo
```

## Files

```text
src/DiscordPresenceManager.h
src/DiscordPresenceManager.cpp
src/IntegrationNotes.md
```

## Setup

1. Create an application in the Discord Developer Portal.
2. Add your Rich Presence art assets:
   - `discordbackground`
   - `warrior_m`, `warrior_w`
   - `ninja_m`, `ninja_w`
   - `sura_m`, `sura_w`
   - `shaman_m`, `shaman_w`
   - `empire_shinsoo`
   - `empire_chunjo`
   - `empire_jinno`
3. Replace `YOUR_DISCORD_APPLICATION_ID` in `DiscordPresenceManager.cpp`.
4. Link the Discord Game SDK library in your client project.
5. Call `Initialize()` on client start.
6. Call `UpdatePresence()` after login, map change, or character change.
7. Call `RunCallbacks()` every frame or periodically.
8. Call `Shutdown()` when closing the client.

## Notes

This repository is a clean portfolio-friendly version of the feature.  
It does not include private server files, game assets, or proprietary client source.
