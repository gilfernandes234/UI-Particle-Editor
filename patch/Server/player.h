
void sendAttachParticleEffect(uint32_t creatureId, const std::string& effectName);
void sendDetachParticleEffect(uint32_t creatureId, const std::string& effectName);
void sendAttachParticleEffectToPosition(const std::string& effectName, const Position& pos);
void sendDetachParticleEffectFromPosition(const std::string& effectName, const Position& pos);