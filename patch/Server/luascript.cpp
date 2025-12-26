// Registrar as funções
void LuaScriptInterface::registerFunctions()
{
    // Creature
    registerMethod("Creature", "attachParticleEffect", LuaScriptInterface::luaCreatureAttachParticleEffect);
    registerMethod("Creature", "detachParticleEffect", LuaScriptInterface::luaCreatureDetachParticleEffect);
    
    // Game
    registerMethod("Game", "sendAttachParticleEffect", LuaScriptInterface::luaGameSendAttachParticleEffect);
    registerMethod("Game", "sendDetachParticleEffect", LuaScriptInterface::luaGameSendDetachParticleEffect);
}






int LuaScriptInterface::luaCreatureAttachParticleEffect(lua_State* L)
{
    // creature:attachParticleEffect(effectName)
    Creature* creature = getUserdata<Creature>(L, 1);
    if (!creature) {
        lua_pushnil(L);
        return 1;
    }
    
    const std::string effectName = getString(L, 2);
    
    SpectatorVec spectators;
    g_game.map.getSpectators(spectators, creature->getPosition(), true, true);
    
    for (Creature* spectator : spectators) {
        if (Player* tmpPlayer = spectator->getPlayer()) {
            tmpPlayer->sendAttachParticleEffect(creature->getID(), effectName);
        }
    }
    
    pushBoolean(L, true);
    return 1;
}

int LuaScriptInterface::luaCreatureDetachParticleEffect(lua_State* L)
{
    // creature:detachParticleEffect(effectName)
    Creature* creature = getUserdata<Creature>(L, 1);
    if (!creature) {
        lua_pushnil(L);
        return 1;
    }
    
    const std::string effectName = getString(L, 2);
    
    SpectatorVec spectators;
    g_game.map.getSpectators(spectators, creature->getPosition(), true, true);
    
    for (Creature* spectator : spectators) {
        if (Player* tmpPlayer = spectator->getPlayer()) {
            tmpPlayer->sendDetachParticleEffect(creature->getID(), effectName);
        }
    }
    
    pushBoolean(L, true);
    return 1;
}

int LuaScriptInterface::luaGameSendAttachParticleEffect(lua_State* L)
{
    // Game.sendAttachParticleEffect(effectName, position)
    const std::string effectName = getString(L, 1);
    const Position& position = getPosition(L, 2);
    
    SpectatorVec spectators;
    g_game.map.getSpectators(spectators, position, true, true);
    
    for (Creature* spectator : spectators) {
        if (Player* tmpPlayer = spectator->getPlayer()) {
            tmpPlayer->sendAttachParticleEffectToPosition(effectName, position);
        }
    }
    
    pushBoolean(L, true);
    return 1;
}

int LuaScriptInterface::luaGameSendDetachParticleEffect(lua_State* L)
{
    // Game.sendDetachParticleEffect(effectName, position)
    const std::string effectName = getString(L, 1);
    const Position& position = getPosition(L, 2);
    
    SpectatorVec spectators;
    g_game.map.getSpectators(spectators, position, true, true);
    
    for (Creature* spectator : spectators) {
        if (Player* tmpPlayer = spectator->getPlayer()) {
            tmpPlayer->sendDetachParticleEffectFromPosition(effectName, position);
        }
    }
    
    pushBoolean(L, true);
    return 1;
}
