def setup
  set_window_size(640, 480)
  set_window_pos(1150, 100)
  set_background(255, 255, 255)

  @hue = 0
  @rate = 0
end

def ease_in(t)
  v = 3.0 * t ** 3 - 2.0 * t ** 2
  (v > 0.0) ? v : -v
end

def ease_out(t)
  1.0 - ease_in(1.0 - t)
end

def update
  @hue += 1
  @hue = 0 if @hue >= 255

  @rate += 0.01
  @rate = 0.0 if @rate >= 1.0
end

def assert(val)
  raise if !val
end

def draw
  x = 10; y = 50
  description("Color.new", x, y)
  c = Color.new(128, 128, 128)
  set_color(c.r, c.g, c.b)
  circle(x + 32, y + 32, 32)

  x = 110; y = 50
  description("Color.hex", x, y)
  set_color(Color.hex(0xD27EB3))
  circle(x + 32, y + 32, 32)

  x = 210; y = 50
  description("Color.hsb", x, y)
  set_color(Color.hsb(@hue, 200, 255))
  circle(x + 32, y + 32, 32)
  
  x = 310; y = 50
  description("clone", x, y)
  clone_color = c.clone
  clone_color.r = 180
  clone_color.g = 90
  clone_color.b = 180
  clone_color.a = 128
  set_color(c)
  circle(x, y + 32, 32)
  set_color(clone_color)
  circle(x + 32, y + 32, 32)

  x = 410; y = 50
  description("to_hex", x, y)
  c = Color.new(100, 255, 0)
  set_color(0, 0, 0)
  text("(#{c.r},#{c.g},#{c.b})", x, y + 25)
  text("0x#{c.to_hex.to_s(16)}", x, y + 50)

  x = 10; y = 150
  description("base", x, y)
  c = Color.hex(0x3DB680)
  set_color(c)
  circle(x + 32, y + 32, 32)

  x = 110; y = 150
  description("invert", x, y)
  set_color(c.invert)
  circle(x + 32, y + 32, 32)

  x = 210; y = 150
  description("normalize", x, y)
  set_color(c.normalize)
  circle(x + 32, y + 32, 32)

  x = 310; y = 150
  description("lerp(white, #{@rate})", x, y)
  set_color(c.lerp(Color.new(255, 255, 255), @rate))
  circle(x + 32, y + 32, 32)

  x = 10; y = 250
  description("to_hsb", x, y)
  c = Color.new(100, 255, 0)
  set_color(c)
  rect(x + 95, y + 12, 16, 16)
  set_color(0, 0, 0)
  text("(#{c.r},#{c.g},#{c.b})", x, y + 25)
  text("hue: #{c.hue}\nsaturation: #{c.saturation}\nbrightness: #{c.brightness}\nlightness: #{c.lightness}", x, y + 50)

  x = 210; y = 250
  description("op", x, y)
  c1 = Color.new( 50, 100, 150)
  c2 = Color.new(150, 100,  50)
  c3 = Color.new( 50, 100, 150)

  description("c1 == c2", x, y + 15)
  assert(c1 == c3)

  description("c1 != c2", x, y + 30)
  assert(c1 != c2)

  description("c1 + 100.0", x, y + 45)
  assert(c1 + 100 == Color.new(150, 200, 250))

  description("c1 + c2", x, y + 60)
  assert(c1 + c2 == Color.new(200, 200, 200))

  description("c1 - 10.0", x, y + 75)
  assert(c1 - 10 == Color.new( 40,  90, 140))

  description("c1 - c2", x, y + 90)
  assert(c1 - c2 == Color.new(156,   0, 100))

  description("c1 * 0.5", x, y + 105)
  assert(c1 * 0.5 == Color.new( 25,  50,  75))

  description("c1 * c2", x, y + 120)
  assert(c1 * Color.new(128, 128, 128) == Color.new( 25, 50, 75))

  description("c1 / 2.0", x, y + 135)
  assert(c1 / 2 == Color.new( 25,  50,  75))

  description("c1 / c2", x, y + 150)
  assert(c1 / Color.new(128, 128, 255) == Color.new( 99, 199, 150))

  # debug info
  set_color(0, 0, 0)
  text(DebugInfo.fps, 10, 15)
end

# ----------------------------------------------------------

def description(text, x, y)
  set_color(0, 0, 0)
  text(text, x, y)
end

