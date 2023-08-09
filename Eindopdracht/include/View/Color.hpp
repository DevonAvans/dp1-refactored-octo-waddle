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
	static const Color& orange() { return orange_; }
	static const Color& cyan() { return cyan_; }
	static const Color& magenta() { return magenta_; }
	static const Color& pink() { return pink_; }
	static const Color& purple() { return purple_; }
	static const Color& yellow() { return yellow_; }
	static const Color& black() { return black_; }
	static const Color& grey() { return grey_; }
	static const Color& brown() { return brown_; }
	static const Color& transparent() { return transparent_; }

private:
	uint8_t r_;
	uint8_t g_;
	uint8_t b_;
	uint8_t a_;

	static Color white_;
	static Color red_;
	static Color green_;
	static Color blue_;
	static Color orange_;
	static Color cyan_;
	static Color magenta_;
	static Color pink_;
	static Color purple_;
	static Color yellow_;
	static Color black_;
	static Color grey_;
	static Color brown_;
	static Color transparent_;
};
