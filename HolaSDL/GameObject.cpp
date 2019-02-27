#include "GameObject.h"

GameObject::GameObject() :
		GameObject(nullptr) {
}

GameObject::GameObject(SDLGame* game) :
		game_(game), active_(true), width_(), height_(), position_(), velocity_(), acceleration_(0, 0),
			rotation_(0.0) {
}

GameObject::~GameObject() {
}

SDLGame* GameObject::getGame() const {
	return game_;
}

void GameObject::setGame(SDLGame* game) {
	game_ = game;
}

bool GameObject::isActive() const {
	return active_;
}
void GameObject::setActive(bool active) {
	active_ = active;
}

bool GameObject::toggleActive() {
	active_ = !active_;
	return active_;
}

double GameObject::getWidth() const {
	return width_;
}

void GameObject::setWidth(double width) {
	width_ = width;
}

double GameObject::getHeight() const {
	return height_;
}

void GameObject::setHeight(double height) {
	height_ = height;
}

const Vector2D& GameObject::getPosition() const {
	return position_;
}

void GameObject::setPosition(const Vector2D &pos) {
	position_.set(pos);
}

const Vector2D& GameObject::getVelocity() const {
	return velocity_;
}

void GameObject::setVelocity(const Vector2D &vel) {
	velocity_.set(vel);
}

const Vector2D& GameObject::getAcceleration() const {
	return acceleration_;
}

void GameObject::scale(double s) {
	double w = width_ / 2;
	double h = height_ / 2;
	width_ *= s;
	height_ *= s;
	double w1 = width_ / 2;
	double h1 = height_ / 2;
	if (s < 1) {
		position_ = position_ + ((Vector2D(w, h) + position_) - (Vector2D(w1, h1) + position_));
	}
	else if (s > 1) {
		position_ = position_ - ((Vector2D(w1, h1) + position_)- (Vector2D(w, h) + position_));
	}
}

Texture* GameObject::getAnimation()
{
	return animation.texture_;
}

void GameObject::setTexture(Texture* texture)
{
	animation.texture_ = texture;
}

SDL_Rect* GameObject::getFrameRect()
{
	SDL_Rect* rect = new SDL_Rect;
	rect->h = animation.frameHeight;
	rect->w = animation.frameWidth;
	rect->x = (animation.frameWidth * (animation.currentFrame % animation.columns));
	rect->y = (animation.frameHeight * (int)(animation.currentFrame / animation.columns));
	return rect;
}

void GameObject::setAcceleration(const Vector2D &vel) {
	acceleration_.set(vel);
}

double GameObject::getRotation() const {
	return rotation_;
}

void GameObject::setRotation(double angle) {
	rotation_ = angle;
}

SDL_Rect GameObject::getRect()
{
	SDL_Rect rect;
	rect.h = height_;
	rect.w = width_;
	rect.x = position_.getX();
	rect.y = position_.getY();
	return rect;
}

void GameObject::render(Uint32 time)
{

	animation.texture_->render(getRect(), getFrameRect());


	if (time - lastRender >= 1000 / framesPerSecond) {	//animations update only when a certain time has passed
		animation.currentFrame = (animation.currentFrame + 1) % animation.totalFrames;

		lastRender = time;
	}
}
