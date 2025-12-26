void ProtocolGame::sendAttachParticleEffect(uint32_t creatureId, const std::string& name)
{
    if (!isMehah) return;
    
    NetworkMessage playermsg;
    playermsg.reset();
    playermsg.addByte(0x39); // GameServerAttachParticleEffect
    playermsg.add<uint32_t>(creatureId);
    playermsg.addString(name);
    writeToOutputBuffer(playermsg);
}

void ProtocolGame::sendDetachParticleEffect(uint32_t creatureId, const std::string& name)
{
    if (!isMehah) return;
    
    NetworkMessage playermsg;
    playermsg.reset();
    playermsg.addByte(0x3A); // GameServerDetachParticleEffect
    playermsg.add<uint32_t>(creatureId);
    playermsg.addString(name);
    writeToOutputBuffer(playermsg);
}

void ProtocolGame::sendAttachParticleEffectToPosition(const std::string& name, const Position& pos)
{
    if (!isMehah) return;
    
    NetworkMessage playermsg;
    playermsg.reset();
    playermsg.addByte(0x3D); // GameServerAttachParticlePosition
    playermsg.addString(name);
    playermsg.addPosition(pos);
    writeToOutputBuffer(playermsg);
}

void ProtocolGame::sendDetachParticleEffectFromPosition(const std::string& name, const Position& pos)
{
    if (!isMehah) return;
    
    NetworkMessage playermsg;
    playermsg.reset();
    playermsg.addByte(0x3E); // GameServerDetachParticlePosition
    playermsg.addString(name);
    playermsg.addPosition(pos);
    writeToOutputBuffer(playermsg);
}
