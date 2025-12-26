//adicionar no switch
                // case Proto::GameServerCreatureTyping:
                    // parseCreatureTyping(msg);
                    // break;  abaixo disso


                // Particles
				case Proto::GameServerAttachParticleEffect:
					parseAttachParticleEffect(msg);
					break;
				case Proto::GameServerDetachParticleEffect:
					parseDetachParticleEffect(msg);
					break;
				case Proto::GameServerAttachParticlePosition:
					parseAttachParticlePosition(msg);
					break;
				case Proto::GameServerDetachParticlePosition:
					parseDetachParticlePosition(msg);
					break;					
							







//adicionar no fim
// Particle
void ProtocolGame::parseAttachParticleEffect(const InputMessagePtr& msg)
{
    const uint32_t creatureId = msg->getU32();
    const auto effectName = msg->getString();
    
    const auto creature = g_map.getCreatureById(creatureId);
    if (!creature) {
        g_logger.traceError("ProtocolGame::parseAttachParticleEffect: could not get creature with id ", creatureId);
        return;
    }
    
    creature->attachParticleEffect(effectName);
}

void ProtocolGame::parseDetachParticleEffect(const InputMessagePtr& msg)
{
    const uint32_t creatureId = msg->getU32();
    const auto effectName = msg->getString();
    
    const auto creature = g_map.getCreatureById(creatureId);
    if (!creature) {
        g_logger.traceError("ProtocolGame::parseDetachParticleEffect: could not get creature with id ", creatureId);
        return;
    }
    
    creature->detachParticleEffectByName(effectName);
}

void ProtocolGame::parseAttachParticlePosition(const InputMessagePtr& msg)
{
    const auto effectName = msg->getString();
    const auto pos = getPosition(msg);
    
    const auto tile = g_map.getTile(pos);
    if (!tile) {
        g_logger.traceError("ProtocolGame::parseAttachParticlePosition: could not get tile at position ", pos);
        return;
    }
    
    tile->attachParticleEffect(effectName);
}

void ProtocolGame::parseDetachParticlePosition(const InputMessagePtr& msg)
{
    const auto effectName = msg->getString();
    const auto pos = getPosition(msg);
    
    const auto tile = g_map.getTile(pos);
    if (!tile) {
        g_logger.traceError("ProtocolGame::parseDetachParticlePosition: could not get tile at position ", pos);
        return;
    }
    
    tile->detachParticleEffectByName(effectName);
}


