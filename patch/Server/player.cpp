
void Player::sendAttachParticleEffect(uint32_t creatureId, const std::string& effectName)
{
    if (client) {
        client->sendAttachParticleEffect(creatureId, effectName);
    }
}

void Player::sendDetachParticleEffect(uint32_t creatureId, const std::string& effectName)
{
    if (client) {
        client->sendDetachParticleEffect(creatureId, effectName);
    }
}

void Player::sendAttachParticleEffectToPosition(const std::string& effectName, const Position& pos)
{
    if (client) {
        client->sendAttachParticleEffectToPosition(effectName, pos);
    }
}

void Player::sendDetachParticleEffectFromPosition(const std::string& effectName, const Position& pos)
{
    if (client) {
        client->sendDetachParticleEffectFromPosition(effectName, pos);
    }
}
