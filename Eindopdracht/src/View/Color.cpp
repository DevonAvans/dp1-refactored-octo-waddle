#include "View/Color.hpp"

Color::Color()
	: r_{255}, g_{255}, b_{255}, a_{1}
{
}

Color::Color(const uint8_t red, const uint8_t green, const uint8_t blue, const uint8_t alpha)
	: r_{red}, g_{green}, b_{blue}, a_{alpha}
{
}

const SDL_Color& Color::to_sdl(const Color& color)
{
	return {color.r(), color.g(), color.b(), color.a()};
}

uint8_t Color::r() const
{
	return r_;
}

void Color::set_r(const uint8_t r)
{
	r_ = r;
}

uint8_t Color::g() const
{
	return g_;
}

void Color::set_g(const uint8_t g)
{
	g_ = g;
}

uint8_t Color::b() const
{
	return b_;
}

void Color::set_b(const uint8_t b)
{
	b_ = b;
}

uint8_t Color::a() const
{
	return a_;
}

void Color::set_a(const uint8_t a)
{
	a_ = a;
}

Color Color::white_{255, 255, 255, 255};
Color Color::red_{255, 0, 0, 255};
Color Color::green_{0, 255, 0, 255};
Color Color::blue_{0, 0, 255, 255};
Color Color::black_{0, 0, 255, 255};
Color Color::yellow_{255, 255, 0, 255};
