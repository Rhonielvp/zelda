#pragma once

#include "../entity.hpp"
#include "../map/level.hpp"
#include "mob/action.hpp"
#include "mob/ai.hpp"
#include "../math/vec2.hpp"
#include "../math/dir.hpp"

class Mob : public Entity {
public:
    typedef Entity super;
    Mob(const char* name, Level* level, float x, float y, float width, float height, Action* idle_action_);

    bool CanMove() const;
    const Dir& facing() const;
    bool moving() const;

    void set_AI(AI* ai);
    void ChangeAction(Action *action);
    void Move(Dir direction, double delta);
    void Update(double delta);
    void Render() const;

private:
    Level* level_;
    AI* ai_;
    Action* idle_action_;
    Action* current_action_;
    Dir facing_;
    int facing_candidate_;
    bool moving_;
};