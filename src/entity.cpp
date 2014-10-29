#include "entity.hpp"
#include "debug.hpp"

Entity::Entity(float width, float height) :
        super(0, 0, width, height),
        health_(20),
        type_(UNKNOWN),
        die_effect_(0)
{}

Entity::Entity(float x, float y, float width, float height) :
        super(x, y, width, height),
        health_(20),
        type_(UNKNOWN),
        die_effect_(0)
{}

bool Entity::IsAlive() const {
    return health_ > 0;
}

void Entity::Kill() {
    health_ = 0;
}

bool Entity::moving() const {
    return false;
}

bool Entity::IsEntity() const {
    return true;
}

int Entity::health() const {
    return health_;
}

void Entity::Damage(Entity* from, int damage) {
    health_ -= damage;
}

bool Entity::IsMob() const {
    return false;
}

bool Entity::SortByYCoordinateAsc::operator()(Entity* e1, Entity* e2) const {
    return e1->y() < e2->y() or (e1->y() == e2->y() and e1->x() < e2->x());
}

float Entity::Distance(Entity* entity) const {
    return center().dist(entity->center());
}

EntityType Entity::type() const {
    return type_;
}

bool Entity::IsFinallyDead() const {
    return not current_effect_ or current_effect_->IsFinished();
}

void Entity::Dead() {
    // Do nothing
}

void Entity::Die() {
    if(die_effect_)
        ChangeEffect(die_effect_);
}

Entity::~Entity() {
    if(die_effect_)
        delete die_effect_;
}
