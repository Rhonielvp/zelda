#include "link.hpp"
#include "action/move.hpp"

SpriteSheet* Link::MOVE_SPRITE_SHEET;
std::vector<Animation*> Link::MOVE_ANIMATIONS;

void Link::Load() {
    MOVE_SPRITE_SHEET = new SpriteSheet("charset/link/move_shield.png", 147, 108, 21, 27);
    MOVE_ANIMATIONS = {
            new Animation(MOVE_SPRITE_SHEET->GetSprites(0, 7), 3, 60, vec2f(0.0f, -12.0f)),
            new Animation(MOVE_SPRITE_SHEET->GetSprites(1, 7), 3, 60, vec2f(0.0f, -12.0f)),
            new Animation(MOVE_SPRITE_SHEET->GetSprites(2, 7), 3, 60, vec2f(0.0f, -12.0f)),
            new Animation(MOVE_SPRITE_SHEET->GetSprites(3, 7), 3, 60, vec2f(0.0f, -12.0f))
    };

    MOVE_ANIMATIONS[Dir::DOWN.index()]->set_ping_pong(true);
    MOVE_ANIMATIONS[Dir::UP.index()]->set_ping_pong(true);
}

Link::Link(Level* level) :
        super(
                "link",
                level,
                0.0f, 0.0f, 19.0f, 14.0f,
                new ::Move(this, MOVE_ANIMATIONS)
        )
{}