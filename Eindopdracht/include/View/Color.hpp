#pragma once
#include <cstdint>
#include <SDL_pixels.h>

class Color
{
public:
	explicit Color();
	explicit Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

	static const SDL_Color& to_sdl(const Color& color);

	[[nodiscard]] uint8_t r() const;
	void set_r(uint8_t r);
	[[nodiscard]] uint8_t g() const;
	void set_g(uint8_t g);
	[[nodiscard]] uint8_t b() const;
	void set_b(uint8_t b);
	[[nodiscard]] uint8_t a() const;
	void set_a(uint8_t a);

	static const Color& white() { return white_; }
	static const Color& red() { return red_; }
	static const Color& green() { return green_; }
	static const Color& blue() { return blue_; }
	static const Color& black() { return black_; }
	static const Color& yellow() { return yellow_; }

private:
	uint8_t r_;
	uint8_t g_;
	uint8_t b_;
	uint8_t a_;

	static Color white_;
	static Color red_;
	static Color green_;
	static Color blue_;
	static Color black_;
	static Color yellow_;
};
